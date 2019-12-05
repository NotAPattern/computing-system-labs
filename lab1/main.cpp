//#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
//calculate ((A * X + B) div (C * X + D)) div E

int main() {
	int a = 0,
		b = 0,
		x = 0,
		d = 0,
		e = 0,
		c = 0,
		y = 0,
		z = 0;
	setlocale(LC_ALL, "Russian");
	printf("This program calculate: ((A * X + B) div (C * X + D)) div E\n");
	printf("Enter value A:\n");
	scanf_s("%i", &a);
	printf("Enter value B:\n");
	scanf_s("%i", &b);
	printf("Enter value C:\n");
	scanf_s("%i", &c);
	printf("Enter value D:\n");
	scanf_s("%i", &d);
	printf("Enter value E:\n");
	scanf_s("%i", &e);
	printf("Enter value X:\n");
	scanf_s("%i", &x);

	/*
	a = -2147483648;
	b =  2147483647;
	result = -1 KEK LOL;
	*/

	// ((-7 * 2 + (-2)) / (-1 * 2 + (-2))) / 2 = 2
	z = ((a * x + b) / (c * x + d)) / e;

	_asm
	{
		mov eax, a
		imul x
		add b, eax
		mov eax, x
		imul c
		add d, eax
		mov eax, b
		cdq
		idiv d
		cdq
		idiv e
		mov y, eax
	}

	printf("Result on Asm: %i\n", y);
	printf("Result on C++: %i\n", z);
	system("pause");
	return 0;
}