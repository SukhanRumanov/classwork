#define _CRT_SECURE_NO_WARNINGS
/*
Практика 3
#include <stdio.h>
#include <locale.h>
int main() {

    int l = 13333;
    int n = 4;
    int k = 4;
    int m = 6;

	int drob = (n % l) * 1000000 / l;
	printf("%0*d.%0*d", k, n / l, m, drob);

    return 0;
}


Практика 4
4.1



#include <stdio.h>
#include <locale.h>
int main() {
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
    return 0;

}



#include <stdio.h>
#include <locale.h>
int main() {
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
	return 0;
}


#include <stdio.h>
#include <locale.h>
int main() {
    int N;
    scanf("%d", &N);
    int last_digit = N % 10;
    int second_last_digit = (N / 10) % 10;
    int third_last_digit = (N / 100) % 10;
    printf("Last digit: %d\n", last_digit);
    printf("Third last digit: %d\n", third_last_digit);
    printf("Sum: %d\n", second_last_digit + last_digit + third_last_digit);
    return 0;

}
Практика 5


#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI            3.14159265358979323846
int main() {
    double gr;
	scanf("%lf", &gr);
	double rad = gr * M_PI / 180.0;
	double sin_val = sin(rad);
	printf("%.0f grad = %.6f\n", gr, sin_val);
    return 0;
}


#include <stdio.h>
#include <locale.h>
#include <math.h>
#define E 2.71828182845904523536
int main() {
	double x;
	scanf("%lf", &x);
    double k = -4.0;
    double a = log(fabs(-1.0 * k * x));
	double b = pow(E, 2.0 * x) + a * x;
    double y = x * pow(a, 3.0) + pow(b, 2.0);
	printf("\ny = %.1f\n", y);
    return 0;
}


#include <stdio.h>

int main() {
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

    // Print the results
    printf("Condition a (1 - yes, 0 - no): %d\n", condition1);
    printf("Condition b (1 - yes, 0 - no): %d\n", condition2);

    return 0;
}
*/
