#define _CRT_SECURE_NO_WARNINGS


//Практика 6
#include <stdio.h>
#include <locale.h>
#include <math.h>  

int prac1(int yeas);
double prac2(double x);
int prac3(int A, int B);



int main() {
    setlocale(LC_ALL, "Ru");
    printf("Практика 4\n");
    printf("Задание 1\n\n");
    int yeas;
    printf("Впишите год: ");
    scanf("%d", &yeas);
    int year = prac1(yeas);
    if (year = 1) {
        printf("Год %d високосный\n", yeas);
    }
    else {
        printf("Год %d не високосный\n", yeas);
    }
    printf("Задание 2\n\n");
    
	double x;
    printf("Введите x: ");
    scanf("%lf", &x);
    double F = prac2(x);
    printf("F(%.6g) = %.6f  (%s)\n", x, F,
        (x > 3.6) ? "x > 3.6" : "x <= 3.6");
    printf("Задание 3\n\n");

    int A, B;
    printf("Введите A: ");
    scanf("%d", &A);
    printf("Введите B: ");
    scanf("%d", &B);

    int a = prac3(A, B);
    if (a == 1) {
        printf("Ошибка: деление на ноль\n");
    }
    else {
        printf("%s\n", (A % B == 0) ? "Да" : "Нет");
    }
    return 0;
}


int prac1(int yeas) {
    int a = 0;
    if (yeas % 4 == 0 && yeas % 100 != 0 || yeas % 400 == 0) {
        a = 1;
    }
    else {
        a = 0;
    }
    return a;
}

double prac2(double x) {
    // если x = 4, то F(4) = 45 * 4^2 + 5 = 725
    // если x = 2 , то F(2) = (5* 2)/(10 * 2^2 + 1) = 0,243902
    double F;
    if (x > 3.6) {
        F = 45 * pow(x, 2) + 5;
    }
    else {
        F = (5.0 * x) / (10.0 * pow(x, 2) + 1.0);
    }
    return F;
}


int prac3(int A, int B) {
    int a = 0;
    if (B == 0) {
        a = 1;
    }
    else {
        a = 0;
    }
    return a;
}