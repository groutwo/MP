/*1.-Escribe una funci�n recursiva que calcule el M�ximo Com�n Divisor
de dos n�meros a y b utilizando el algoritmo de Euclides.*/
#include<stdio.h>
int euclides(int, int);
int main(){
    int a,b;
    puts("Introduce los dos numeros a calcular el maximo comun divisor: ");
    scanf("%d%d", &a, &b);
    printf("\nEl MCD de %d y %d es: %d.\n",a,b,euclides(a,b));
    return 0;
}

//Cabecera: Entero funcion euclides(E entero: a, E entero: b)
//Precondicion: Variables inicializadas y a ; ambos negativos
//Precondicion: devuelve el max comun divisor de ambos numeros

int euclides(int a,int b){
 return b ? euclides(b,a%b):a; //si b !=0, llama a la funcion
}
