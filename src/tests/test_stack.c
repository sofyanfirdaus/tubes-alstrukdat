#include <stdio.h>

#include "adt.h"

int main() {
    printf("--- Driver Test Stack ---");
    printf("\n");
    printf("\n");
    Stack s;
    Time program_time;
    Simulator simulator;
    String username;
    Point simulator_location;
    PriorityQueue delivery_list;
    Fridge fridge;

    CreateEmptyStack(&s);

    CreatePrioQueue(&delivery_list, 50);
    CreateFridge(&fridge, 10, 10);
    CreateTime(&program_time, 0, 0, 0);
    CreateSimulator(&simulator, username, simulator_location);
    infoState temp = { simulator, "HAI", delivery_list, program_time, fridge };
    Push(&s, temp);
    Pop(&s, &temp);
    printf("\n");
    printf("-------------------------");
    printf("\n");
    printf("\n");
}
