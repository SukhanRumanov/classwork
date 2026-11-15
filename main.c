#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PARAM_B 1.0
#define GRAPH_WIDTH 60
#define MAX_POINTS 60
#define GRAPH_HEIGHT 20
#define MAX_G 1000



double Y(double x);
double V(double x);
int check_x(double x, int num);
double F(double x, int num);
int tabulate(int num, double x1, double x2, double step, int type);
int graphic(int num, double x1, double x2, double step);
int clear_input();
int check_range(double x1, double x2, double step);

int main() {
	setlocale(LC_ALL, "Russian");
	int menu = 0;

	while (menu != 6) {
		puts("\nМеню:");
		puts("1. Найти значение F1(x) в точке");
		puts("2. Найти значение F2(x) в точке");
		puts("3. Табулировать F1(x) на интервале");
		puts("4. Табулировать F2(x) на интервале");
		puts("5. Построить график функции");
		puts("6. Завершение работы");
		printf("Выберите пункт меню: ");

		if (scanf("%d", &menu) != 1) {
			puts("Ошибка ввода");
			if (!clear_input()) break;
			continue;
		}

		if (menu == 1 || menu == 2) {
			double x;
			int num = (menu == 1) ? 1 : 2;
			printf("Введите значение x: ");
			if (scanf("%lf", &x) != 1) {
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue;
			}
			if (check_x(x, num)) {
				printf("F%d(%lf) = %lf\n", num, x, F(x, num));
			}
			else {
				puts("Ошибка: недопустимое значение x (не входит в ОДЗ).");
			}
		}
		else if (menu == 3 || menu == 4) {
			double x1, x2, step;
			int type;
			int num = (menu == 3) ? 1 : 2;
			printf("Введите начальное значение x1: ");
			if (scanf("%lf", &x1) != 1) { 
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue; 
			}
			printf("Введите конечное значение x2: ");
			if (scanf("%lf", &x2) != 1) {
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue;
			}
			printf("Введите шаг табулирования: ");
			if (scanf("%lf", &step) != 1) {
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue;
			}

			puts("Выберите тип интервала:");
			puts("1 - отрезок [x1, x2]");
			puts("2 - интервал (x1, x2)");
			puts("3 - полуинтервал [x1, x2)");
			puts("4 - полуинтервал (x1, x2]");
			printf("Тип: ");
			if (scanf("%d", &type) != 1 || type < 1 || type > 4) {
				puts("Ошибка: неверный тип интервала.");
				if (!clear_input()) break;
				continue;
			}

			if (!check_range(x1, x2, step)) continue;
			if (!tabulate(num, x1, x2, step, type)) {
				puts("Функция не определена ни в одной точке интервала.");
			}
		}
		else if (menu == 5) {
			int num;
			double x1, x2, step;
			printf("Выберите функцию для графика (1 - F1, 2 - F2): ");
			if (scanf("%d", &num) != 1 || (num != 1 && num != 2)) {
				puts("Ошибка: недопустимый номер функции.");
				if (!clear_input()) break;
				continue;
			}
			printf("Введите начальное значение x1: ");
			if (scanf("%lf", &x1) != 1) {
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue;
			}
			printf("Введите конечное значение x2: ");
			if (scanf("%lf", &x2) != 1) {
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue;
			}
			printf("Введите шаг: ");
			if (scanf("%lf", &step) != 1) {
				puts("Ошибка ввода");
				if (!clear_input()) break;
				continue;
			}

			if (!check_range(x1, x2, step)) continue;
			int n = graphic(num, x1, x2, step);
			if (n == 2) {
				puts("График построен с ограничением по количеству точек.");
			}
			if(n == 0) {
				puts("Функция не определена ни в одной точке интервала.");
			}
		}
		else if (menu == 6) {
			puts("Выход из программы.");
			break;
		}
		else {
			puts("Неверный пункт меню. Попробуйте снова.");
		}
	}
	return 0;
}

int check_range(double x1, double x2, double step) {
	if (step <= 0) {
		puts("Ошибка: шаг должен быть положительным.");
		return 0;
	}
	if (x1 > x2) {
		puts("Ошибка: x1 должно быть не больше x2.");
		return 0;
	}
	double c = floor((x2 - x1) / step + 1e-9) + 1;
	if (!(c <= MAX_G)) {
		printf("Ошибка: количество точек (%.0lf) превышает максимум (%d).\n", c, MAX_G);
		return 0;
	}
	return 1;
}

int clear_input() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	return c != EOF;
}

double Y(double x) {
	return atan(PARAM_B * x) / (1 + pow(sin(x), 2));
}

double V(double x) {
	double result;
	if (x > 0 && x <= 5) {
		result = sin(pow(x, 3)) - sqrt(log(fabs(sin(x))));
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
			//аргумент логарифма должен быть строго > 0
			double arg = fabs(sin(x));
			if (arg <= 0 || log(arg) < 0) {
				return 0;
			}
		}
		return 1;
	}
}

// выбор функции
double F(double x, int num) {
	if (num == 1) {
		return Y(x);
	}
	else {
		return V(x);
	}
}

int tabulate(int num, double x1, double x2, double step, int type) {
	int flag = 0;
	printf("Табулирование F%d(x) на ", num);
	switch (type) {
	case 1: printf("[%.4lf, %.4lf]\n", x1, x2); break;
	case 2: printf("(%.4lf, %.4lf)\n", x1, x2); break;
	case 3: printf("[%.4lf, %.4lf)\n", x1, x2); break;
	case 4: printf("(%.4lf, %.4lf]\n", x1, x2); break;
	}
	printf("+------------+----------------+\n");
	printf("|      x     |      F(x)      |\n");
	printf("+------------+----------------+\n");

	int n = (int)floor((x2 - x1) / step + 1e-9);
	double EPS = 1e-9;

	for (int i = 0; i <= n; i++) {
		double x = x1 + i * step;

		if (x > x2 + EPS) break;

		int is_left_bound = fabs(x - x1) < EPS;
		int is_right_bound = fabs(x - x2) < EPS;

		if (type == 2 && (is_left_bound || is_right_bound)) continue;   // (x1, x2)
		if (type == 3 && is_right_bound) continue;                      // [x1, x2)
		if (type == 4 && is_left_bound) continue;                       // (x1, x2]

		if (check_x(x, num)) {
			printf("| %10.4lf | %14.6lf |\n", x, F(x, num));
			flag = 1;
		}
		else {
			printf("| %10.4lf | не определена   |\n", x);
		}
	}
	printf("+------------+----------------+\n");
	return flag;
}

int graphic(int num, double x1, double x2, double step) {
	double ymin = 0, ymax = 0;
	int found = 0;
	double x;
	int i, j;

	int n = (int)floor((x2 - x1) / step + 1e-9);
	int def[MAX_POINTS];
	double y_values[MAX_POINTS];
	int count = n + 1;
	if (count > MAX_POINTS) count = MAX_POINTS;
	for (i = 0; i < count; i++) {
		x = x1 + i * step;
		def[i] = check_x(x, num);
		if (!def[i]) continue;
		y_values[i] = F(x, num);
		if (!found || y_values[i] < ymin) ymin = y_values[i];
		if (!found || y_values[i] > ymax) ymax = y_values[i];
		found = 1;
	}
	
	if (found == 0) {
		printf("Функция не определена ни в одной точке интервала.\n");
		return;
	}
	if (ymax - ymin < 0.000001) ymax = ymin + 1;

	double dy = (ymax - ymin) / (GRAPH_HEIGHT - 1);
	double yrow = ymax;

	for (i = 0; i < GRAPH_HEIGHT; i++) {
		printf("%9.3lf |", yrow);

		for (j = 0; j < count; j++) {
			if (!def[j]) {
				printf(" ");
				continue;
			}

			double y = y_values[j];
			int row = (int)((ymax - y) / dy + 0.5);

			if (row == i) printf("*");
			else printf(" ");
		}
		printf("\n");
		yrow = yrow - dy;
	}

	printf("          +");
	for (j = 0; j < count; j++) printf("-");
	printf("\n");
	printf("           x от %.3lf до %.3lf\n", x1, x1 + (count - 1) * step);

	return (n + 1 > MAX_POINTS) ? 2 : 1;
}