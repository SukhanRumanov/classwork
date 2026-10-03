#define _CRT_SECURE_NO_WARNINGS


//Практика 5
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define E 2.71828182845904523536
#define M_PI            3.14159265358979323846


void dz1();
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
	printf("ДЗ\n\n");
    dz1();
    return 0;
}


void prac1() {
    double gr;
    scanf("%lf", &gr);
    double rad = gr * M_PI / 180.0;
    double sin_val = sin(rad);
    printf("%.0f grad = %.6f\n", gr, sin_val);
}


void prac2() {
    double x;
    scanf("%lf", &x);
    double k = -4.0;
    double a = log(fabs(-1.0 * k * x));
    double b = pow(E, 2.0 * x) + a * x;
    double y = x * pow(a, 3.0) + pow(b, 2.0);
    printf("\ny = %.1f\n", y);
}


void prac3() {
    int A, B, C;
    int condition1;
    int condition2;

    printf("Enter A, B and C: ");
    scanf("%d %d %d", &A, &B, &C);

    condition1 = (A % 2 == 0 && B % 2 != 0) ||
        (A % 2 != 0 && B % 2 == 0);

    condition2 = (A % 3 == 0) &&
        (B % 3 == 0) &&
        (C % 3 == 0);

    printf("Condition a (1 - yes, 0 - no): %d\n", condition1);
    printf("Condition b (1 - yes, 0 - no): %d\n", condition2);
}

void dz1() {
    double x = 2.444;
	double y = 0.869 * pow(10, -2);
	double z = -0.13 * pow(10, 3);

	double num1 = pow(x, y + 1) + pow(E, y -1);
	double mun1 = 1 + x * fabs(y - tan(z));

	double drob1 = num1 / mun1;
    
    double num2 = drob1 * (1 + fabs(y - x));
    double drob2 = (pow(fabs(y - x), 2)) / 2;
    double drob3 = (pow(fabs(y - x), 3)) / 3;

	double h = num2 + drob2 - drob3;
	printf("h = %.5f\n", h);
}