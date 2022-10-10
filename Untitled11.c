/*11.- En un vector de enteros se genera un «cambio de tendencia» cuando dada una
secuencia creciente o decreciente de números que ocupan posiciones consecutivas
del vector, el elemento que le sucede es inferior o superior respectivamente. Dado
un vector de N enteros, diseñe una función recursiva que calcule el número de
«cambios de tendencia» que contiene dicho vector.*/
#include<stdio.h>
#define N 5

int turnaround(int[], int, int, int );
void inicializa(int [],int);

int main()
{
    int A[N];
    printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0);

    printf("\n\nHay %d cambios de tendencia",turnaround(A,0,0,0));
    return 0;
}

void inicializa(int A[], int i)
{
    if(i<N)
    {
        printf("Introduce un valor para A[%d]: ", i+1);
        scanf("%d", &A[i]);
        inicializa(A,i+1);
    }

}

int turnaround(int a[],int i,int aux,int sol)
{
    if(i==N-1)//Nota3
        return sol;
    if(i==0)
    {
        if(a[i]<a[i+1])//nota2
            aux=1; //Si es creciente, aux es 1
        else
            aux=-1;//En caso contrario, aux es -1
    }
    else
    {
        printf("\nEn este momento, el indice vale %d",i); //Nota1
        if(a[i]<a[i+1] && aux==-1)
        {
            sol++;
            aux=1;
            printf("\nComo %d<%d y aux=-1, sol=%d",a[i],a[i+1],sol);
        }

        if(a[i]>a[i+1] && aux==1)
        {
            sol++;
            aux=-1;
            printf("\nComo %d>%d y aux=1, sol=%d",a[i],a[i+1],sol);

        }
        /*Las otras dos condiciones que faltan son:
            a[i]<a[i+1] && aux==1, en cuyo caso el anterior era creciente (aux es 1), y este tambien,luego no hay cambio de tendencia
            a[i]>a[i+1] && aux==-1, en cuyo caso el anterior era decreciente (aux es -1), y este tambien,luego tampoco hay cambio de tendencia
        */
    }
    turnaround(a,i+1,aux,sol);
}

/*Nota1: El ultimo que mostrará será N-2 porque realmente empieza en la posicion 0, pero éste no aparece debido a la primera comparacion(nota2), la cual
permite saber si es o no creciente y tenerlo en cuenta para saber si sumar al contador que lleva la cuenta de los cambios de tendencia que lleva el vector.

El otro motivo por el cual es N-2, es porque en la comparacion del indice con el final del vector(Nota3), se compara con N-1, ya que si se deja con N, cuando
se hace la comparacion de a[i] con el siguiente, dicho elemento estaría fuera del vector. Luego para controlar este caso, hacemos que la funcion recursiva acabe
cuando el indice sea igual al tamaño total del vector menos 1, devolviendo el acumulador de las veces que se ha llevado a cabo un cambio de tendencia.*/
