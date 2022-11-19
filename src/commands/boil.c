#include "commands.h"
#include "parser.h"

boolean execute_boil() {
    boolean success;

    printBoilList(foodlist);
    printf("\n");
    printf("Kirim 0 untuk exit.\n");
    int choice = 1;
    while (choice != 0) {
        printf("\n");
        printf("Enter command: ");
        start_parser(stdin);
        choice = parse_int();
        Food food;
        Resep resep;
        if (getFoodWithIdxAction(foodlist, BOIL, choice, &food)) {
            if (getResepWithFood(&resep, resepList, food)) {
                if (canMakeFromResep(resep, simulator)) {
                    enqueuePrioQueue(&Inventory(simulator), (PQInfo){ food, ExpirationTime(food) });
                    printf("\n");
                    printf("Berhasil merebus makanan menjadi %s.", STR_VALUE(food.name));
                    printf("\n");
                    for (int j = 0; j < CHILD_COUNT(ROOT(resep)); j++) {
                        Food consumed;
                        removeAtPrioqueue(&Inventory(simulator),
                                          getFirstFoundFoodPrioqueue(Inventory(simulator), INFO(NEXT(ROOT(resep), j))),
                                          &consumed);
                        printf("Consumed: %s", STR_VALUE(consumed.name));
                        printf("\n");
                    }

                    add_program_time(TIMEToMenit(food.processing_time));
                    success = true;
                } else {
                    printf("\n");
                    printf("Gagal merebus makanan menjadi %s.", STR_VALUE(food.name));
                    printf("\n");

                    for (int j = 0; j < CHILD_COUNT(ROOT(resep)); j++) {
                        if (getFirstFoundFoodPrioqueue(Inventory(simulator), INFO(NEXT(ROOT(resep), j))) == IDX_UNDEF) {
                            getFoodById(foodlist, INFO(NEXT(ROOT(resep), j)), &food);
                            printf("Missing: %s", STR_VALUE(food.name));
                            printf("\n");
                        }
                    }
                }
            }
        } else if (choice != 0) {
            printf("Pilihan tidak valid.\n");
        }
    }

    return success;
}
