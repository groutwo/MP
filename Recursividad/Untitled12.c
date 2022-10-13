/*12.- Dado un vector de enteros estrictamente positivos A[1..n], n >= 1, diseña un
algoritmo que obtenga recursivamente el número de parejas (j,k), 1 <= j <= n, 1 <= k  <= n tales que:
sumatorio desde i=1 hasta j de A[i] = sumatorio desde i=k hasta n de A[i] */
#include<stdio.h>
#define N 5
int parejas(int[], int, int, int);
int sumatorio(int [],int, int, int);
void inicializa(int [], int);

int main()
{
    int A[N];
    printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0);
    printf("\n\nLuego hay %d parejas que cumplen la propiedad pedida%c", parejas(A,0,0,0),7);
    return 0;
}

//Cabecera: Procedimiento inicializa(E/S vector: A, E entero i)
//Precondicion:recibe el vector y el indice, que va incrementando
//Postcondicion: inicializa el vector
void inicializa(int A[], int i)
{
    if(i<N)
    {
        printf("Introduce un valor para A[%d]: ", i+1);
        scanf("%d", &A[i]);
        inicializa(A,i+1);
    }
}

//Cabecera: Entero funcion parejas(E/S vector: A, E entero: j, E entero k, E entero: sol)
//Precondicion: Variables inicializadas
//Postcondicion: Devuelve en numero de parejas que cumplen la condicion dada
int parejas (int A[],int j,int k, int sol)
{
    int v1,v2;
    if(j==N) //Si la j sale fuera del vector, k se incrementa y j vuelve al principio
    {
        k++;j=0;
        if(k==N)//Caso base( que tanto j como k salgan del vector)
            return sol;
    }
    v1=sumatorio(A,0,j,0);//obtenemos el valor de los sumarios para esos limites
    v2=sumatorio(A,k,N-1,0);
    if(v1==v2) //Si ambos sumatorios resultan el mismo numero, se muestra por pantalla
        printf("\nCon j = %d y k = %d, tenemos que, como %d = %d",j+1,k+1,v1,v2),
        sol++;
    parejas(A,j+1,k,sol);
}

//Cabecera: Entero funcion sumatorio(E/S vector: A, E entero: v1, E entero v2, E entero: sol)
//Precondicion: Variables inicializadas y v1 < v2
//Postcondicion: Devuelve el sumatorio desde la posicion v1 hasta v2 del vector introducido
int sumatorio(int A[], int v1, int v2,int sol)
{    if(v1==v2+1)
        return sol;
    sol+=A[v1];
    sumatorio (A,v1+1,v2,sol);//Nota1
}
//return v1>2? sol: sumatorio (A,v1+1,v2,sol+A[v1]); 

//Nota 1: Como es el sumatorio desde v1 hasta v2, cuando v1 sea v2+1, devolvemos la solucion.
    //En caso contrario, hacemos que la variable sol tenga el resultado de sumarlo con el elemento que
    //ocupa la posicion v1 del vector.
