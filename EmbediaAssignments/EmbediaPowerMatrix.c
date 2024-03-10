#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_DIGIT_LENGTH 10


int power(int base, int exponent) {
    int result = ceil(pow((double)base, (double)exponent));
    return result;
}

int stringToDigit(char* str) {
    return atoi(str);
}

int isEmbediaPowerMatrix(char matrix[MAX_ROWS][MAX_COLS][MAX_DIGIT_LENGTH], int rows, int cols) {
    for (int i = 1; i < rows - 1; i++) { 
        for (int j = 0; j < cols; j++) {
            int current = stringToDigit(matrix[i][j]);
            int above = stringToDigit(matrix[i - 1][j]);
            int below = stringToDigit(matrix[i + 1][j]);
            // printf("%d ", current); // for test 
            if (power(below, above) != current) {
                return 0;
            }
        }
    }
    return 1;
}

int EmbediaPowerMatrix(){
    int rows, cols;
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 3 || rows > MAX_ROWS || cols < 3 || cols > MAX_COLS) {
        printf("Invalid matrix dimensions.\n");
        return 0;
    }

    char matrix[MAX_ROWS][MAX_COLS][MAX_DIGIT_LENGTH];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%s", matrix[i][j]);
        }
    }

    // for input sequence test 
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("'%s' ", matrix[i][j]);
        }
        printf("\n");
    }

    if (isEmbediaPowerMatrix(matrix, rows, cols)) {
        printf("Expected Output: Embedia Power Matrix\n");
    } else {
        printf("Expected Output: Not an Embedia Power Matrix\n");
    }
}

int main() {
    
    EmbediaPowerMatrix();
    return 0;
}

// test case one
// '3' '2' '2'
// '8' '9' '25'
// '2' '3' '5'

// input
// 3 2 2 8 9 25 2 3 5
//output
// Embedia Power Matrix

// test case two
// '1' '3' '5'
// '3' '7' '11'
// '5' '11' '17'

// input
// 1 3 5 3 7 11 5 11 17
// Not an Embedia Power Matrix

// test case three
// '1' '3' '5'
// '3' '7' '11'
// '5' '11' '17'

// input
//   3 4 2 512 256 49 8 4 7
//  Embedia Power Matrix