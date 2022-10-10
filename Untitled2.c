/*Escribe una función recursiva cifras que reciba un número
en base 10 y devuelva cuántas cifras tiene ese número.*/
#include<stdio.h>
int cifras (int, int);
int main(){
    int n;
    puts("Introduce un numero: "); scanf("%d",&n);
    printf("\nEl numero introducido tiene %d cifras.\n", cifras(n,0));
    return 0;
}
//Cabecera: E entero: n, E entero tam
//Precondicion: Variables inicializadas
//Postcondicion: Devuelve el numero de cifras que tiene el numero escrito
int cifras(int n, int tam){
    return n?cifras(n/10,tam+1) : tam;   // Nota 1
}

/*Nota 1: Si n es verdadero (distinto de 0)entonces ejecuta lo primero. En caso contrario, es decir,
que n sea 0, devuelve el valor de tam, que es la variable que contiene el tamaño de dicho numero*/
