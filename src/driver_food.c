#include <stdio.h> 
#include "food.h"
#include "time.h"

int main(){ 
    Time dummy; CreateTime(&dummy, 1, 2, 3);
    enum Action aclov = BUY;
    Food ayam; CreateFood(&ayam, "ayam rasa bebek", dummy, aclov, dummy);
    DisplayFood(ayam);

    return 0;
}