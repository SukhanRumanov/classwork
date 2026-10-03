#define _CRT_SECURE_NO_WARNINGS


//Практика 6
#include <stdio.h>
#include <locale.h>
#include <math.h>  

void prac1();
void prac2();
void prac3();



int main() {
    setlocale(LC_ALL, "Ru");
	printf("Практика 4\n");
	printf("Задание 1\n\n");
    prac1();
	printf("Задание 2\n\n");
    prac2();
    printf("Задание 3\n\n");
    prac3();
    return 0;
}


void prac1(){
    int yeas;
	printf("Впишите год: ");
    scanf("%d", &yeas);
    if (yeas % 4 == 0 && yeas % 100 != 0 || yeas % 400 == 0) {
        printf("Год %d високосный\n", yeas);
    }
    else {
        printf("Год %d не високосный\n", yeas);
	}
}

void prac2() {
    // если x = 4, то F(4) = 45 * 4^2 + 5 = 725
    // если x = 2 , то F(2) = (5* 2)/(10 * 2^2 + 1) = 0,243902
    double x, F;
    printf("Введите x: ");
    scanf("%lf", &x);
    if (x > 3.6) {
        F = 45 * pow(x, 2) + 5;
    }
    else {
        F = (5.0 * x) / (10.0 * pow(x, 2) + 1.0);
    }
    printf("F(%.6g) = %.6f  (%s)\n", x, F,
        (x > 3.6) ? "x > 3.6" : "x <= 3.6");
}


void prac3() {
    int A, B;
	printf("Введите A: ");
    scanf("%d", &A);
    printf("Введите B: ");
    scanf("%d", &B);

    if (B == 0) {
        printf("Ошибка: деление на ноль\n");
    }
    else {
        printf("%s\n" ,(A% B == 0)? "Да": "Нет");
	}
}