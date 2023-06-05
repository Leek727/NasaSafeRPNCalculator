#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>

double calculate(double x, double y, char op){
    assert(op != '\0');

    if (op == '+'){
        return x + y;
    }
    else if (op == '-'){
        return x - y;
    }
    else if (op == '*'){
        return x * y;
    }
    else if (op == '/'){
        return x / y;
    }
    else if (op == '^'){
        return pow(x, y);
    }
    else {
        return DBL_MAX;
    }
}

int main() {
    // no buffer overflow in sight
    char expression[1000];

    if (fgets(expression, 1000, stdin) == NULL) {
        printf("Read expression failed!\n");
        return 1;
    }
    assert(expression != NULL);

    // split input and declare stack
    char *token = strtok(expression, " ");
    double stack[1000];
    double tempResult = 0;


    // loop over tokens - upper bound 1000 - calculate result
    int stackIndex = 0;
    for (int i = 0; i < 1000 && token != NULL; i++){
        double val = atof(token);
        if (val != 0.0){
            // if valid number, push to stack
            stack[stackIndex] = val;
            stackIndex++;
        }

        // if operator, pop last two, calculate, and push result
        else {
            // calc and check return error value
            tempResult = calculate(stack[stackIndex-2], stack[stackIndex-1], token[0]);
            if (tempResult == DBL_MAX){
                (void) printf("Calculation error. Unsupported operator?\n");
                return 1;
            }
            
            // write result
            stack[stackIndex-2] = tempResult;
            stackIndex--;
        }

        // get next token
        token = strtok(NULL, " ");
    }

    // ignore return value
    (void) printf("Result : %f\n", stack[0]);
    return 0;
}