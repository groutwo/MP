/*Dado un vector ordenado crecientemente A[1..n], n >= 1, diseña un algoritmo que
calcule de forma recursiva la longitud de la escalera más larga, es decir, la longitud
de la secuencia más larga de valores consecutivos que se encuentre en A.*/
#include<stdio.h>
#define N 13
int longitud(int[],int,int,int);
void inicializa(int [], int);
int main()
{
    int A[N];
    printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0); puts("");
    printf("La longitud de la escalera mas larga es %d\n", longitud(A,0,0,1));
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

//Cabecera: Entero funcion longitud(E/S vector: A, E entero:i, E entero: sol, E entero: aux)
//Precondicion:Variables inicializadas
//Postcondicion: devuelve la longitud de la escalera más larga
int longitud(int A[],int i,int sol,int aux)
{
    if(i==N-1) //Si llegamos al final, devolvemos el mayor valor, ya que puede ser que, como en el vector [6,6,8,8,8], sol tendria 2 (las veces que se repite
        return (aux>sol)?aux:sol; //el 6), y aux sería 3, luego hemos de hacer esta ultima comparacion
    else
    {
        if(A[i]+1==A[i+1])//Si son valores consecutivos, sumamos uno a la variable auxiliar
            aux++;
        else
            if (aux>=sol) //Si no son iguales, ha acabado la consecutividad de la cadena, luego vemos a ver cual es mayor
        {
            sol=aux;
            aux=1;
        }
        printf("Tenemos %d y %d, luego aux vale %d\n", A[i]+1,A[i+1],aux);
        longitud(A, i+1, sol, aux);
    }
}
