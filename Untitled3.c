/*Dado un vector A de n enteros ordenado crecientemente, diseñe una
función recursiva que devuelva su moda, es decir, el valor más
frecuente de A.*/
#include<stdio.h>
#define N 3
int moda (int [], int, int, int, int);
void inicializa(int[], int);
int main()
{
    int A[N];
    printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(A,0);
    printf("\nEl numero mas repetido, y por tanto la moda es: %d\n", moda(A,0,12345,1,0)); //El 12345 es un numero cualquiera, pues pasara a ser la moda
    return 0;
}

//Cabecera: Procedimiento inicializa(E/S vector: A, E entero i)
//Precondicion:recibe el vector y el indice, que va incrementando
//Postcondicion: inicializa el vector
void inicializa(int A[], int i){
    if(i<N){
        printf("Introduce un valor para A[%d]: ", i);
        scanf("%d", &A[i]);
        inicializa(A,i+1);
    }

}

//Cabecera: Entero funcion moda(E/S vector: a, E entero: i, E entero: sol, E entero: aux1, E entero: aux2)
//Precondicion: Varaibles inicializadas
//Postcondicion: devuelve 1 si hay dos parejas consecutivas que sumen lo mismo en el vector
int moda(int v[],int i,int sol,int aux1, int aux2)
{ 														  //aux2 siempre tiene la cantidad de veces que se
    if(i==N)                                              //repite la moda del momento(cuando esta recorriendo el vector)
        return sol;                                       //aux1 contiene el n de veces que se repite v[i]
    else
	{
        if(v[i]==v[i+1])//Punto 1 (referenciado en la aclaracion)
            aux1++;
        else
		{
            if (aux1>aux2)
			{
                sol=v[i];
                aux2=aux1;
                aux1=1;
			}
		}
		return moda(v,i+1,sol,aux1,aux2);
	}
}
/* Las variables empleadas son:
    v   --> Es el vector que se le pasa a la funcion, el cual se define en tiempo de ejecucion por estar definido en el programa
    n   --> Contiene el numero de elementos que contiene el vector, y se utiliza para que, junto con la siguiente variable, saber cuando acabar la funcion
    i   --> Es la variable indice que se encarga de ir recorriendo el vector, por eso va desde 0 hasta n
    sol --> Solucion del problema. En caso haber varias modas, la solucion será el primer elemento
    aux1--> Contador con el numero de veces que se repite el elemento actual
    aux2--> Contador con el numero de veces que se repite la moda del momento (es decir, la moda actual, por donde va el indice)
___________________________________________________________________________________________________________________________________________________________

El planteamiento es el siguiente: (para el vector  int v[6]={0,2,2,2,4,4}; )
    Partimos del punto 1, en el cual vamos acomulando el numero de veces que se encuentra el elemento por el que va el indice(por eso aux1 empieza en 1).

    Así hasta que dejan de ser iguales, momento en el cual, comprobamos si aux1 es mayor que aux2. Como en el primer caso se cumple, la moda pasa a ser 0.
    De aqui pasamos al siguiente elemento, que es 2.Dicho numero se encuentra 3 veces, luego aux1 será 3.

    Como 3 es mayor que el numero de veces que estaba el 0, que era 1 (es decir, el 0 estaba una sola vez), entonces aux2 pasa a ser 3, y la solucion será
    el elemento que se encuentra 3 veces. Importante, a aux1 le volvemos a dar el valor 1.

    Cuando pasa al siguiente elemento, que es 4 como se encuentra dos veces, aux1 valdrá 2, pero como 2 es menor que 3, no se sustituirá como en el caso
    anterior.


    Cuando i sea igual que n, devolvemos la solucion (caso base); es decir, cuando lleguemos al final del vector, devolvemos aquel que se repite más veces. ^^
*/
