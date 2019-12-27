#include <stdio.h>
#include <locale.h>
#include <cstdlib>

int main(){
	setlocale(LC_ALL, "Russian");

	int A[3], B[3], C[3], x, y, sumasm, sum = 0;

	printf("Данная программа вычисляет значение выражения: Summ (|Ai|) * X + Summ (|Bi|) * X * Y + Summ (Ci)\n");

	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента A[%i]:\n", i + 1);
		scanf_s("%i", &A[i]);
	}

	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента B[%i]:\n", i + 1);
		scanf_s("%i", &B[i]);
	}

	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента C[%i]:\n", i + 1);
		scanf_s("%i", &C[i]);
	}

	printf("Введите число X:\n");
	scanf_s("%i", &x);
	printf("Введите число Y:\n");
	scanf_s("%i", &y);

	for (int i = 0; i < 3; i++) {
		sum += (abs(A[i]) * x) + (abs(B[i]) * x * y) + (C[i]);
	}

	_asm
	{
		mov eax, 0
		mov esi, 0
		mov ecx, 3
		lea ebx, A
		cycle1:
			;1 massiv
			mov esi, [ebx]
			cmp esi, 0
			jge m1
			neg esi
		m1:
			add eax, esi
			add ebx, 4
			loop cycle1
			imul x
			mov sumasm, eax
			mov eax, 0
			mov ecx, 3
			lea ebx, B
		cycle2:
			;2 massiv
			mov esi, [ebx]
			cmp esi, 0
			jge m2
			neg esi
		m2:
			add eax, esi
			add ebx, 4
			loop cycle2
			imul x
			imul y
			add sumasm, eax
			mov eax, 0
			mov ecx, 3
			lea ebx, C
		cycle3:
			;3 massiv
			mov esi, [ebx]
		m3:
			add eax, esi
			add ebx, 4
			loop cycle3
			add sumasm, eax
	}
	printf("Result on Asm: %i\n", sumasm);
	printf("Result on C++: %i\n", sum);
	system("pause");
	return 0;
}

/*
	int A[3], B[3], C[3], x, y, sum = 0;

	printf("Данная программа вычисляет значение выражения: Summ (|Ai|) * X + Summ (|Bi|) * X * Y + Summ (Ci)\n");

	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента A[%i]:\n", i + 1);
		scanf_s("%i", &A[i]);
	}

	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента B[%i]:\n", i + 1);
		scanf_s("%i", &B[i]);
	}

	for (int i = 0; i < 3; i++) {
		printf("Введите значение элемента C[%i]:\n", i + 1);
		scanf_s("%i", &C[i]);
	}

	printf("Введите число X:\n");
	scanf_s("%i", &x);
	printf("Введите число Y:\n");
	scanf_s("%i", &y);

	for (int i = 0; i < 3; i++) {
		sum += (abs(A[i]) * x) + (abs(B[i]) * x * y) + (C[i]);
	}

*/