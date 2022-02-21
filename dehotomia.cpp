#include <iostream>
#include <time.h>

// ввод пользователем длинны масива
int dlinna_massiva1() {
	int a;
	do {
		printf_s("Dlinna ot 100: ");
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
	printf_s("Число %f нужно поставить на позицию %d\nпосле числа %f перед числом %f\n",b , answer, mass[nachalo - 1], mass[nachalo]);
}

int main() {
	setlocale(LC_ALL, "RUS");
	int dlinna_masiva, a_random;
	dlinna_masiva = dlinna_massiva1();
	float mass[100];
	zapolnenie_massiva(dlinna_masiva, mass);
	float b; printf_s("Vvedite B:"); scanf_s("%f", &b);
	dinatomia_b(dlinna_masiva, mass, b);
	return 1;
}