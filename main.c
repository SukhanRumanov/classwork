#define _CRT_SECURE_NO_WARNINGS


//Практика 4
#include <stdio.h>
#include <locale.h>
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

void dz1() {
	int A, B, condition;
	printf("A = ");
	scanf("%d", &A);
	printf("B = ");
	scanf("%d", &B);

	condition = (A % 2 == 0 && B % 2 == 1) || (A % 2 == 1 && B % 2 == 0);
	printf("Победили ли в раунде? (1 - да, 0 - нет): %d\n", condition);
}

void prac1() {
    char c = '!';

    int i = 2;

    float f = 3.14f;

    double d = 5e-12;
    printf("char: %c\n", c);
    printf("int: %d\n", i);
    printf("float: %f\n", f);
    printf("double: %e\n", d);

    //1a
    double f1;
    scanf("%lf", &f1);
    int f1_int = (int)f1;
    double f1_frac = f1 - f1_int;
    printf("Integer part: %d\n", f1_int);
    printf("Fractional part: %g\n", f1_frac);
    //1b
    char c1;
    scanf(" %c", &c1);
    printf("Character in 16: %x\n", c1);
    printf("Character in 10: %d\n", c1);
    //1в
    int i1;
    scanf("%d", &i1);
    double res = 1.0 / i1;
    printf("Decimal: %g\n", res);

}

void prac2() {
    int x;
    float y;
    double z;

    int a = 5;
    int b = 2;

    x = a / b;
    y = a / b;
    z = a / b;

    printf("Integer division: %d\n", x);
    printf("Float division: %f\n", y);
    printf("Double division: %lf\n", z);
    // продолжение
    y = (float)a / b;
    z = (double)a / b;
    printf("Float division with casting: %f\n", y);
    printf("Double division with casting: %lf\n", z);
}

void prac3() {
    int N;
    scanf("%d", &N);
    int last_digit = N % 10;
    int second_last_digit = (N / 10) % 10;
    int third_last_digit = (N / 100) % 10;
    printf("Last digit: %d\n", last_digit);
    printf("Third last digit: %d\n", third_last_digit);
    printf("Sum: %d\n", second_last_digit + last_digit + third_last_digit);
}