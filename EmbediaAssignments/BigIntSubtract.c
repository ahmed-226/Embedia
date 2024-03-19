#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bigint {
    char *digits; 
    int length;   
};

int compare(struct Bigint num1, struct Bigint num2) {
    if (num1.length > num2.length) {
        return 1;
    } else if (num1.length < num2.length) {
        return -1;
    } else {
        return strcmp(num1.digits, num2.digits);
    }
}

struct Bigint subtract(struct Bigint num1, struct Bigint num2) {
    struct Bigint result;
    int borrow = 0;
    
    int cmp = compare(num1, num2);
    
    struct Bigint larger, smaller;
    if (cmp > 0) {
        larger = num1;
        smaller = num2;
    } else if (cmp < 0) {
        larger = num2;
        smaller = num1;
    } else {
        
        result.digits = strdup("0");
        result.length = 1;
        return result;
    }

    result.digits = (char *)malloc((larger.length + 2) * sizeof(char)); 
    
    result.length = 0;
    
    for (int i = larger.length - 1; i >= 0; i--) {
        int digit1 = larger.digits[i] - '0';
        int digit2 = (i >= larger.length - smaller.length) ? smaller.digits[i - (larger.length - smaller.length)] - '0' : 0;
        int sub = digit1 - digit2 - borrow;

        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        
        result.digits[i] = sub + '0';
        result.length++;
    }
    
    while (result.length > 1 && result.digits[0] == '0') {
    for (int i = 0; i < result.length - 1; i++) {
        result.digits[i] = result.digits[i + 1];
    }
    result.digits[result.length - 1] = '\0';
    result.length--;
    }
    
    if (cmp < 0) {
    for (int i = result.length; i >= 0; i--) {
        result.digits[i + 1] = result.digits[i];
    }
    result.digits[0] = '-';
    result.length++;
    }
    
    result.digits[result.length] = '\0';

    return result;
}

void Solution(){
    struct Bigint num1, num2, result;
    char num1_str[100]; 
    char num2_str[100]; 

    printf("Enter first number: ");
    scanf("%s", num1_str);

    printf("Enter second number: ");
    scanf("%s", num2_str);
    
    num1.digits = strdup(num1_str);
    num1.length = strlen(num1_str);
    
    num2.digits = strdup(num2_str);
    num2.length = strlen(num2_str);
    
    result = subtract(num1, num2);
    
    printf("Result of subtraction: %s\n", result.digits);
    
    free(num1.digits);
    free(num2.digits);
    free(result.digits);
}

int main() {
    
    Solution();
    return 0;
}