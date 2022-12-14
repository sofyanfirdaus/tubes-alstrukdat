CC := gcc
CFLAGS := -std=c11 -g
CINCLUDES := -Isrc -Isrc/adt -Isrc/commands -Isrc/logger -Isrc/parser
CLIBS := -lm

DIRS := $(dir $(wildcard src/adt/*/))

ADTS := $(foreach dir,$(DIRS),$(wildcard $(dir)*.c))
COMMANDS := $(wildcard src/commands/*.c)
SOURCES := $(wildcard src/*.c) $(ADTS) $(COMMANDS) src/logger/logger.c src/parser/parser.c
TARGET := bin

TEST_SOURCES = $(wildcard src/tests/*.c)
TEST_BIN = $(TEST_SOURCES:src/tests/%.c=bin/tests/%)

.SILENT: clean run-test

build:
	@mkdir -p bin
	$(CC) $(CFLAGS) $(CINCLUDES) $(SOURCES) $(CLIBS) -o $(TARGET)/main

test: build-test

build-test: $(TEST_BIN)

$(TEST_BIN): $(TARGET)/tests/%: src/tests/%.c
	@mkdir -p bin/tests
	$(CC) $(CFLAGS) $(CINCLUDES) $< src/parser/parser.c $(ADTS) $(CLIBS) -o $@

run-test:
	$(foreach bin, $(TEST_BIN), $(bin);)

clean:
	rm -rf bin

test-foodlist:
	$(CC) $(CFLAGS) $(CINCLUDES) src/tests/test_foodlist.c $(ADTS) $(CLIBS) -o test

test-map:
	$(CC) $(CFLAGS) $(CINCLUDES) src/parser.c src/tests/test_map.c $(ADTS) $(CLIBS) -o test
