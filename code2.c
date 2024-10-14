//Cooper Wright | Lab05 | EECS 348

#include <stdio.h>
#define SIZE 5

int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m1Plusm2[SIZE][SIZE]){ 
    
    for (int i = 0 ; i < SIZE ; i++){ //loop rows 
        for (int j = 0 ; j < SIZE ; j++){ //loop cols
            m1Plusm2[i][j] = m1[i][j] + m2[i][j]; //add respective spots in matrices together
        }
    }

    return 0;
}

int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m1Timesm2[SIZE][SIZE]){

    int dotProduct;
    for (int i = 0 ; i < SIZE ; i++){ //loop rows
        for (int j = 0 ; j < SIZE ; j++){ //loop cols
            dotProduct = 0; //reset
            for (int k = 0 ; k < SIZE ; k++){ //loop dotproduct
                dotProduct = dotProduct + m1[i][k] * m2[k][j]; //matrix multiplication is dotproduct of row x cols
            }
            m1Timesm2[i][j] = dotProduct; //set output
        }
    }

    return 0;
}

int transposeMatrix(int m1[SIZE][SIZE], int m1T[SIZE][SIZE]){

    for (int i = 0 ; i < SIZE ; i++){ //loop rows
        for (int j = 0 ; j < SIZE ; j++){ //loop cols
            m1T[i][j] = m1[j][i]; //just flip rows and cols for transpose
        }
    }
    return 0;
}

int printMatrix(int m[SIZE][SIZE]){

    for (int a = 0 ; a < SIZE ; a++){ //loop rows
            for (int b = 0 ; b < SIZE ; b++){ //loop cols
                printf("%i ", m[a][b]); //print
            }
        printf("\n"); //new line after each col
        }

    return 0;
}

int main() {
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };
    int m2test[SIZE][4] = { //for testing multiplication
    {25, 24, 23, 22},
    {20, 19, 18, 17},
    {15, 14, 13, 12},
    {10, 9, 8, 7},
    {5, 4, 3, 2}
    };
    int m2test2[4][SIZE] = { //for testing multiplication
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    };

    if (sizeof(m1) != sizeof(m2)){ //check if sizes are same if not, cant add
        printf("\nMatrices are not same size cannot add...");
    }
    else{
        int m1Plusm2[SIZE][SIZE]; //create output matrix
        addMatrices(m1,m2,m1Plusm2);
        printf("--- m1 + m2 ---\n");
        printMatrix(m1Plusm2);
    }

    float rows1 = sizeof(m1) / sizeof(m1[0]); //get rows of m1
    float cols2 = sizeof(m2[0]) / sizeof(m2[0][0]); //get cols of m2

    if (rows1 != cols2){ //check if rows in m1 and cols in m2 are same if not, cant multiply
        printf("\nMatrices are not compatable for multiplication...");
    }
    else{
        int m1Timesm2[SIZE][SIZE]; //create output matrix
        multiplyMatrices(m1,m2,m1Timesm2);
        printf("\n--- m1 x m2 ---\n");
        printMatrix(m1Timesm2);
    }

    int m1T[SIZE][SIZE]; //create output matrix
    transposeMatrix(m1,m1T);
    printf("\n--- m1 Tran ---\n");
    printMatrix(m1T);

return 0;
}