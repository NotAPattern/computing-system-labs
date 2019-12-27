#include <stdio.h>
#include <locale.h>

int main() {
	int x = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите значение: ");
	scanf_s("%i", &x);
	_asm {
		mov eax, x
		mov ecx, 8
		_start:
			ror	al, 1
			shl	ax, 1
			shr	al, 1
			loop _start
		mov x, eax
		nop
	}
	/*
	var 2:

	MOV ax,1234h
	XOR al,al
	or al,ah
	ROR al,4
	MOV rez,ax

	*/

	// number (	  al     |	  ah    ) -> number	(	 al	   |	ah    )
	// 8	  (0000 0000 | 0000 1000) -> 2048	(0000 1000 | 0000 1000)
	// 9	  (0000 0000 | 0000 1001) -> 2304	(0000 1001 | 0000 0000)
	// ...
	// 255	  (0000 0000 | 1111 1111) -> 65280  (1111 1111 | 0000 0000)

	printf("Получили значение: %i", x);
	return 0;
}