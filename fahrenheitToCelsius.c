#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void printFahrenheitToCelsius(int fahrenheit);
float fahrenheitToCelsius(int fahrenheit);

/* This program will print out a table with fahrenheit to celsius conversion */

int main(){
    int fahrenheit;

    printf("%3s | %4s\n", "F", "C");
    printf("-------------\n");

    for(fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP){
        printFahrenheitToCelsius(fahrenheit);
    }

    return 0;
}

void printFahrenheitToCelsius(int fahrenheit){
    printf("%3d | %6.1f\n", fahrenheit, fahrenheitToCelsius(fahrenheit));
}

float fahrenheitToCelsius(int fahrenheit){
    return (5.0/9.0) * (fahrenheit - 32);
}
