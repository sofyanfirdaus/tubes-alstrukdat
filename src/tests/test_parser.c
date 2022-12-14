#include <stdio.h>

#include "adt.h"
#include "parser.h"

int main() {
    printf("--- Driver Test Parser ---");
    printf("\n");
    printf("\n");
    FILE* stream = fopen("konfigurasi_makanan.txt", "r");
    start_parser(stream);
    int n = parse_int();
    for (int i = 0; i < n; i++) {
        int id = parse_int();
        String name = parse_line();
        Time expire = parse_time();
        Time delivery = parse_time();
        int food_width = parse_int();
        int food_height = parse_int();
        Size food_size = { food_width, food_height };
        Time processing_time = parse_time();
        enum Action action = parse_action();
        Food f;
        CreateFood(&f, id, name, expire, action, delivery, food_size, processing_time);

        printf("Makanan %d\n", i + 1);
        DisplayFood(f);
    }
    FILE* konfigurasi_resep = fopen("konfigurasi_resep.txt", "r");
    start_parser(konfigurasi_resep);
    n = parse_int();
    for (int i = 0; i < n; i++) {
        int id = parse_int();
        Address parent = newNode(id);
        Tree tree;
        CreateTree(&tree, parent);
        int num_child = parse_int();
        for (int k = 0; k < num_child; k++) {
            int id_child = parse_int();
            Address child = newNode(id_child);
            MakeChildren(parent, child);
        }
        printf("%d\n", parent->childCount);
    }
    printf("\n");
    printf("--------------------------");
    printf("\n");
    printf("\n");
    return 0;
}
