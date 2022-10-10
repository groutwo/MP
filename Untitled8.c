/*Dado un vector A de n enteros y un número natural k, 1 <= k <= n, diseñe un
procedimiento recursivo que intercambie los k primeros elementos de A con los
elementos de las k ultimas posiciones, sin hacer uso de un vector auxiliar.*/
#include<stdio.h>
#define N 5
int in(int[],int,int,int,int,int);
void inicializa(int [], int);
void intercambia(int[],int, int,int);
void muestra_vector(int [], int);
int main()
{
    int A[N], k;
    printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0);
    puts("\nIntroduce un valor para k (1 <= k <= n)");
    scanf("%d", &k);
    intercambia(A,k,0,N-1);
    puts("El vector con los elementos cambiados es: ");
    muestra_vector(A,0);

    return 0;
}
//Cabecera: Procedimiento inicializa(E/S vector: A, E entero i)
//Precondicion:recibe el vector y el indice, que va incrementando
//Postcondicion: inicializa el vector
void inicializa(int A[], int i)
{
    if(i<N)
    {
        printf("Introduce un valor para el elemento %d: ", i+1);
        scanf("%d", &A[i]);
        inicializa(A,i+1);
    }
}
//Cab:procedimiento intercambia (E/S vector: A, E entero k, E entero i, E entero n)
//Pre: variables inicializadas y k < N/2
//Post: intercambia los k primeros elementos del vector con los k ultimos

void intercambia(int A[], int k, int i, int n) // Simplemente, realizamos el metodo de la burbuja,
{                                              // y en cada llamada cambiamos la posicion de los elementos del vector
    if(i<k)
    {
        int aux=A[i];
        A[i]=A[n];
        A[n]=aux;
        intercambia(A,k,i+1,n-1);
    }
}

//Cabecera: Procedimiento muestra_vector(E/S vector: A, E entero i)
//Precondicion:recibe el vector y el indice, que va incrementando
//Postcondicion: muestra el vector con los valores intercambiados
void muestra_vector(int A[], int i)
{
    if(i<N)
    {
        printf("%d ", A[i]);
        muestra_vector(A,i+1);
    }
}
