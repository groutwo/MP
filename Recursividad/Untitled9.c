/*9.- Diseña un algoritmo que calcule de forma recursiva la suma de todos los
elementos i de un vector a de n enteros que cumplen la siguiente propiedad:
1 <= i <= Cota Superior{n/2}-1: a[ i ]>a[ 2*i ] ^  a[ i ]>a[ 2*i + 1 ]*/
#include<stdio.h>
#define N 5

int sumavector(int[],int,int,int);
void inicializa(int [], int);
int main()
{
    int a[N], sol, m=N%2; //Si N es par, m=0, luego la cota superior será igual que dividir normalmente entre dos (no habrá resto)
    //printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(a,0);
    puts("");
    sol=sumavector(a,0,0,m);
    printf("\nLa suma de los elementos que cumplen esa propiedad es: %d", sol);
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

//Cabecera: Funcion sumavector(E/S vector: a, E entero suma, E entero i, E entero m)
//Precondicion:variables inicializadas
//Postcondicion:devuelve la suma de los elementos que cumplen la propiedad
int sumavector(int a[],int suma, int i,int m)
{

    if (i > N/2+m-1)   //el -1 lo pone en el enunciado;
        return suma;   //forma parte de la propiedad a cumplir
    else
    {
        if(i==0) //como 2*0=0, no sumaria bien el 1er elemento
        {
            if(a[0] > a[1] && a[0] > a[2])
            {
                suma+=a[0];
                printf("\tEl elemento %i cumple la propiedad, luego se suma %d\n", i+1,a[i]);
            }
        }
        if (a[i] > a[2*i] && a[i] > a[2*i+1])
        {
            suma+=a[i];
            printf("\tEl elemento %i cumple la propiedad, luego se suma %d\n", i+1,a[i]);
        }
        sumavector(a,suma, i+1);
    }
}
