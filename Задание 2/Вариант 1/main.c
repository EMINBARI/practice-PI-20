#include <stdio.h>

///Вариант 1 - Задание 2
///Дана структура Дробь, состоит из двух полей целого типа (числитель и знаменатель).
///Необходимо написать функцию сложения двух дробей.

typedef struct fraction{
    int numerator;
    int denominator;
} Fraction;

int isZero(Fraction fraction){
    if(fraction.numerator == 0){
        return 1;
    } else return 0;
}

int isInf(Fraction fraction){
    if(fraction.numerator != 0 & fraction.denominator == 0 ){
        return 1;
    } else return 0;
}

void multiplyFractions(Fraction a, Fraction b){

    Fraction result;

    if(isZero(a) & isZero(b)) {
        result.numerator = 0;
        result.denominator = 0;
        printf( "%i/%i * %i/%i", a.numerator, a.denominator,b.numerator, b.denominator);
        printf( " = %i", result.numerator);
        return;
    }

    else if ((isZero(a) & !isInf(b)) | (isZero(b) & !isInf(a))){
            result.numerator = 0;
            result.denominator = 0;
            printf( "%i/%i * %i/%i", a.numerator, a.denominator,b.numerator, b.denominator);
            printf( " = %i", result.numerator);
            return;
    }

    else if (isInf(a) | isInf(b)){
        printf( "%i/%i * %i/%i", a.numerator, a.denominator,b.numerator, b.denominator);
        printf( " = Ошибка", result.numerator, result.denominator);
        return;
    }

    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;

    printf( "\nРезультат умножения: %i/%i * %i/%i", a.numerator, a.denominator,b.numerator, b.denominator);
    printf( " = %i/%i", result.numerator, result.denominator);
}

int main() {
    int an;
    int ad;
    int bn;
    int bd;

    printf("\nВведите числитель первой дроби: ");
    scanf("%d", &an);
    printf("Введите знаменатель первой дроби: ");
    scanf("%d", &ad);
    printf("\nВведите числитель второй дроби: ");
    scanf("%d", &bn);
    printf("Введите знаменатель второй дроби: ");
    scanf("%d", &bd);

    struct fraction a = {an,ad};
    struct fraction b = {bn,bd};

    multiplyFractions(a,b);

    return 0;
}
