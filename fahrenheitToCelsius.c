#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define LOWER 0

long getValueFromInput(char buffer[], long value);
void headerFormatter();
void printFahrenheitToCelsius(int fahrenheit);
float fahrenheitToCelsius(int fahrenheit);

/* This program will print out a table with fahrenheit to celsius conversion */

int main(){
    int fahrenheit;
    char buffer[1024];
    long upper, step;

    printf("\nThis program will create a table of fahrenheit to celsius conversions.\n\n");

    printf("You will be asked to enter a number to convert values up to.\n");
    upper = getValueFromInput(buffer, upper);

    printf("\n");

    printf("You will be asked to enter a number to indicate intervals between every\n conversion.\n");
    step = getValueFromInput(buffer, step);

    printf("\n");

    headerFormatter();

    for(fahrenheit = LOWER; fahrenheit <= upper; fahrenheit += step){
        printFahrenheitToCelsius(fahrenheit);
    }

    printf("\n Thank you (: \n\n");

    return 0;
}

long getValueFromInput(char buffer[], long value){
    int success;

    do{
        printf("Enter a number:\n");
        if(!fgets(buffer, 1024, stdin)){ return 1; }

        char *endptr;
        errno = 0;
        value = strtol(buffer, &endptr, 10);
        if(errno == ERANGE){
            printf("\nSorry this number is too small or too large.\n");
            success = 0;
        } else if(endptr == buffer){
            printf("\nPlease enter a valid input.\n");
            success = 0;
        }
        else if(*endptr && *endptr != '\n'){
            printf("\nPlease enter a valid input.\n");
            success = 0;
        } else{ success = 1; }

    } while(!success);

    return value;
}

void headerFormatter(){
    printf("%3s | %4s\n", "F", "C");
    printf("-------------\n");
}

void printFahrenheitToCelsius(int fahrenheit){
    printf("%3d | %6.1f\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
}

float fahrenheitToCelsius(int fahrenheit){
    return (5.0/9.0) * (fahrenheit - 32);
}
