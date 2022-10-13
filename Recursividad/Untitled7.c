/*7.- Dado un vector n de enteros, se dice que un elemento del vector es elemento
mayoritario si este entero aparece estrictamente más de n/2 veces en dicho vector.
Diseña un algoritmo que determine de forma recursiva si el vector A[1..n] contiene
un elemento mayoritario y la primera posición que ocupa.*/

#include<stdio.h>
#define N 10
int mayoritario(int[],int,int,int,int,int);
void inicializa(int [], int);
int main()
{
    int A[N], sol;
    //printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0);
    puts("");
    sol=mayoritario(A,0,1,0,1,0);
    if(sol==-1)
        puts("No hay elemento mayoritario.");
    else
    {
        printf("La 1ra posicion del elemento mayoritario es %d\n", sol+1);//Para que empiece a contar desde la posicion 1
        printf("Dicho elemento es %d", A[sol]);
    }
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

//Cabecera: Funcion mayoritario(E/S vector: A, E entero i, E entero j, E entero sol, E entero aux, E entero pos)
//Precondicion:Variables inicializdas
/*Postcondicion:
    Si ha encontrado un numero con la propiedad que pide el enunciado, devuelve la
posicion en la que se encuentra el primer numero

    En caso contrario, es decir, que no exista ningun elemento que se encuentre de forma
mayoritaria, devuelve un numero negativo que, tras comparar el resultado en la funcion
principal, mostrará en pantalla un mensaje con la solucion del enunciado*/


int mayoritario(int A[],int i,int j,int sol,int aux,int pos)
{

    if(sol>(N/2))
        return pos;
    if(j==N)//Es decir, el segundo indice se ha pasado del vector
    {
        aux=1;
        i++;
        if(i==N-1)//Es decir, el primer indice se encuentre en el ultimo elemento
            return -1;
        j=i+1;
    }
    if(A[i]==A[j])
        aux++;
    if(aux>sol)
    {
        pos=i;
        sol=aux;
    }
    mayoritario(A,i,j+1,sol,aux,pos);
}

