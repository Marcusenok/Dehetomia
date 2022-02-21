#include <iostream>
#include <time.h>

// ввод пользователем длинны масива
int dlinna_massiva1() {
	int a;
	do {
		printf_s("Длина от 100: ");
		scanf_s("%d", &a);
	} while (a < 100);
	return a;
}

// заполнение массива пользователем
void zapolnenie_massiva(int dlinna, float mass[]) {
	float a;
	for (int i = 0; i < dlinna; i++) {
		mass[i] = i * 0.5 + 2 * i * i + 7;
	}
	for (int i = 0; i < dlinna; i++) {
		printf_s("mas[%d] = %f\n", i, mass[i]);
	}
}

void dinatomia_b(int dlinna, float mass[], float b) {
	int answer = -1, c;
	int nachalo = 0, konec = dlinna;
	if (dlinna % 2 == 1) {
		if (b > mass[dlinna - 2]) { answer = dlinna - 2; }
		konec -= 1;
	}
	do {
		c = (nachalo + konec) / 2;
		if (mass[c - 1] > b) konec = c;
		else nachalo = c;
		if (konec == nachalo + 1) answer = nachalo - 1;
	} while (answer == -1);
	printf_s("Число %.1f нужно поставить на позицию %d\nпосле числа %.1f перед числом %.1f\n",b , answer, mass[nachalo - 1], mass[nachalo]);
}

void dinatomia_с(int dlinna, float mass[], float c) {
	float answer = -1;
	int nachalo = 0, konec = dlinna, pos, f;
	if (dlinna % 2 == 1) {
		if (c == mass[dlinna - 1])  answer = mass[dlinna - 1];
		konec -= 1;
	}
	do {
		f = (nachalo + konec) / 2;
		if (mass[f - 1] > c) konec = f;
		else nachalo = f;
		printf_s("%d      %d\n", nachalo, konec);
		if (konec == nachalo + 1) {
			if (c == mass[nachalo]) {answer = mass[nachalo - 3]; pos = nachalo - 3;}
			else answer = mass[konec - 3]; pos = konec - 3;
		}
	} while (konec != nachalo + 1);
	if (answer != -1) printf_s("Число %f имеет равное число", c);
	else printf_s("Не имеет равного числа");
}

int main() {
	setlocale(LC_ALL, "RUS");
	int dlinna_masiva, a_random;
	dlinna_masiva = dlinna_massiva1();
	float mass[100];
	zapolnenie_massiva(dlinna_masiva, mass);
	float b; printf_s("Введите B:"); scanf_s("%f", &b);
	dinatomia_b(dlinna_masiva, mass, b);
	float c; printf_s("Введите C:"); scanf_s("%f", &c);
	dinatomia_с(dlinna_masiva, mass, c);
	system("pause");
	return 1;
}