/*Diseñe una función recursiva que determine si en un vector A de n enteros existen
dos parejas consecutivas de elementos tales que sus sumas sean idénticas.*/
#include<stdio.h>
#define N 4

int parejas(int[],int);
void inicializa(int [],int);

int main()
{
    int A[N];
    printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0);

    parejas(A,0) ? printf("\nSi") : printf("\nNo");
    puts(" hay dos parejas consecutivas que sumen lo mismo.");
    return 0;
}

//Cabecera: Procedimiento inicializa(E/S vector: A, E entero i)
//Precondicion:recibe el vector y el indice, que va incrementando
//Postcondicion: inicializa el vector
void inicializa(int A[], int i)
{
    if(i<N)
    {
        printf("Introduce un valor para A[%d]: ", i);
        scanf("%d", &A[i]);
        inicializa(A,i+1);
    }

}
//Cabecera: Entero funcion parejas(E/S vector: a, E entero: i)
//Precondicion: Varaibles inicializadas
//Postcondicion: devuelve 1 si hay dos parejas consecutivas que sumen lo mismo en el vector
int parejas(int a[],int i)
{
    if(i==N-3) //Si llegamos al final (tengamos en cuenta que hemos de comparar el valor de a[i]+a[i+1] con a[i+2] y a[i+3]
        return 0;
    else
    {
        if(a[i]+a[i+1]==a[i+2]+a[i+3])//Si la igualdad anterior se cumple, devolvemos 1
        {
            printf("\n\nComo %d+%d=%d+%d=%d, entonces:\n\n",a[i],a[i+1],a[i+2],a[i+3],a[i]+a[i+1]);
            return 1;
        }
        else
            parejas(a,i+1);//Si no es igual, vamos al siguiente elemento. La funcion acaba cuando se llega al final y no se ha encontrado pareja
    }
}
