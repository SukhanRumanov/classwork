#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PARAM_B 1.0
#define GRAPH_WIDTH 60
#define MAX_POINTS 60
#define GRAPH_HEIGHT 20

double Y(double x);
double V(double x);
int check_x(double x, int num);
double F(double x, int num);
void tabulate(int num, double x1, double x2, double step);
void graphic(int num, double x1, double x2, double step);
//int in_interval(double x, double x1, double x2, int t);


// проверка введённого диапазона: 1 - ок, 0 - ошибка
int check_range(double x1, double x2, double step) {
	if (step <= 0) {
		puts("Ошибка: шаг должен быть положительным.");
		return 0;
	}
	if (x1 > x2) {
		puts("Ошибка: x1 должно быть не больше x2.");
		return 0;
	}
	return 1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int num = 1;
	int menu = 1;
	while (menu != 0) {
		printf("\nМеню (сейчас функция %d):\n", num);
		puts("1. Выбор функции");
		puts("2. Значение в точке");
		puts("3. Табулирование функции");
		puts("4. График функции");
		puts("5. Выход");
		printf("Выберите пункт меню: ");

		if (scanf("%d", &menu) == 1) {
			if (menu == 1) {
				int n;
				printf("Выберите функцию (1 - Y(x), 2 - V(x)): ");
				if (scanf("%d", &n) == 1 && (n == 1 || n == 2)) {
					num = n;
				}
				else {
					puts("Ошибка: недопустимый номер функции.");
				}
			}
			else if (menu == 2) {
				double x;
				printf("Введите значение x: ");
				if (scanf("%lf", &x) != 1) {
					puts("Ошибка ввода");
					continue;
				}
				if (check_x(x, num)) {
					printf("F(%lf) = %lf\n", x, F(x, num));
				}
				else {
					puts("Ошибка: недопустимое значение x для выбранной функции.");
				}
			}
			else if (menu == 3 || menu == 4) {
				double x1, x2, step;
				printf("Введите начальное значение x1: ");
				int ok = scanf("%lf", &x1);
				printf("Введите конечное значение x2: ");
				ok += scanf("%lf", &x2);
				printf("Введите шаг табулирования: ");
				ok += scanf("%lf", &step);
				if (ok != 3) {
					puts("Ошибка ввода");
					continue;
				}
				if (!check_range(x1, x2, step)) {
					continue;
				}
				if (menu == 3) {
					tabulate(num, x1, x2, step);
				}
				else {
					graphic(num, x1, x2, step);
				}
			}
			else if (menu == 5) {
				puts("Выход из программы.");
				break;
			}
			else {
				puts("Попробуйте снова");
			}
		}
		else {
			puts("Ошибка ввода");
			menu = 0;
			break;
		}
	}
	return 0;
}

//1
double Y(double x) {
	return atan(PARAM_B * x) / (1 + pow(sin(x), 2));
}

//2
double V(double x) {
	double result;
	if (x > 0 && x <= 5) {
		result = pow(sin(x), 3) - sqrt(log(fabs(sin(x))));
	}
	else if (x > 5 && x < 10) {
		result = 0.75 * exp(x);
	}
	else {
		result = 3 * pow(sin(x), 3) + cos(x);
	}
	return result;
}

// 1 - все хорошо, 0 - ошибка
int check_x(double x, int num) {
	if (num == 1) {
		return 1;
	}
	else {
		if (x <= 0) {
			return 0;
		}
		if (x <= 5) {
			if (log(fabs(sin(x))) < 0) {
				return 0;
			}
		}
		return 1;
	}
}

// выбор функции относительно номера функции
double F(double x, int num) {
	if (num == 1) {
		return Y(x);
	}
	else {
		return V(x);
	}
}

void tabulate(int num, double x1, double x2, double step) {
	puts("      x         F(x)");
	for (double x = x1; x <= x2; x += step) {
		if (check_x(x, num)) {
			printf("%10.4lf %12.6lf\n", x, F(x, num));
		}
		else {
			printf("%10.4lf   не определена\n", x);
		}
	}
}

void graphic(int num, double x1, double x2, double step) {
	double ymin = 0, ymax = 0;
	int found = 0;
	int count = 0;
	double x;
	int i, j;

	for (x = x1; x <= x2 && count < MAX_POINTS; x += step) {
		count++;
		if (!check_x(x, num)) continue;
		double y = F(x, num);
		if (!found || y < ymin) ymin = y;
		if (!found || y > ymax) ymax = y;
		found = 1;
	}
	if (found == 0) {
		printf("Функция не определена ни в одной точке интервала.\n");
		return;
	}
	if (ymax - ymin < 0.000001) ymax = ymin + 1;

	// вывод сверху вниз: строка i, потом все точки x
	for (i = 0; i < GRAPH_HEIGHT; i++) {
		double yrow = ymax - i * (ymax - ymin) / (GRAPH_HEIGHT - 1);
		printf("%9.3lf |", yrow);

		j = 0;
		for (x = x1; x <= x2 && j < MAX_POINTS; x += step) {
			j++;
			if (check_x(x, num)) {
				double y = F(x, num);
				int row = (int)((ymax - y) / (ymax - ymin) * (GRAPH_HEIGHT - 1) + 0.5);
				if (row == i) printf("*");
				else printf(" ");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	// ось x
	printf("          +");
	for (j = 0; j < count; j++) printf("-");
	printf("\n");
	printf("           x от %.3lf до %.3lf\n", x1, x1 + (count - 1) * step);

	if (x <= x2) {
		printf("Не все точки поместились на экран, остальные не показаны.\n");
	}
}

/*int in_interval(double x, double x1, double x2, int t) {
	if (t == 1) {
		return (x > x1 && x < x2);
	}
	else if (t == 2) {
		return (x >= x1 && x < x2);
	}
	else if (t == 3) {
		return (x > x1 && x <= x2);
	}
	else {
		return (x >= x1 && x <= x2);
	}
}*/