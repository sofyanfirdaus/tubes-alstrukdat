
#include <stdio.h>
#include "cstring.h"
#include "parser.h"

#include "matrix.h"

int main(){ 
    Matrix map;
    
    FILE *file = fopen("konfigurasi_peta.txt", "r");
    start_parser(file);
    int rows = parse_int();
    int cols = parse_int();
    createMatrix(rows, cols, &map);

    for (int row = 0; row < rows; row++) {
        String line = parse_line();
        for (int col = 0; col < cols; col++) {
            char c = STR_VALUE(line)[col];
            MatElmt(map, row, col) = c;
        }
    }

    displayMatrix(map);
    return 0;
}