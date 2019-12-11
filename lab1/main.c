//
// Created by main on 16.11.2019.
//
// Programm calculate 

#include <stdio.h>
//#include <stdafx.h>


int main(){
    int a = 0, b = 0, c = 0, d = 0, x = 0, z = 0;
    printf("Введите число a: ");
    scanf("%i", &a);
    printf("Введите число b: ");
    scanf("%i", &b);
    printf("Введите число c: ");
    scanf("%i", &c);
    z = (a + b*c) / d;
    //"mov eax, a\n\t"
    //"mov %0, eax\n\t" /* ассемблерная вставка */
    /*: "=r"(b)  выходные операнды
: "r"(a)  входные операнды
: "%eax" разрушаемые регистры */
    /*
                "imul c, b\n\t"
                "add eax, a\n\t"
                "cdq\n\t"
                "idiv d,\n\t"
                "mov x, eax\n\t"
    */
    __asm__ ( ".intel_syntax noprefix\n\t"
                "mov eax, b\n\t"
                "mul \n\t"
                "mov x, eax\n\t"
    );
    asm(".att_syntax prefix");
    printf("Результат вычислений на языке ассемблера: %i\n",x);
    printf("Результат вычислений на языке C: %i\n",z);
}