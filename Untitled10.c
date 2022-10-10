/*10.- Diseña un algoritmo que determine de forma recursiva si en un
vector A de n enteros se cumple:

Para todo i, tal que i sea mayor o igual que uno, pero menor o igual
que la cota superior de n/2, menos uno; se cumple la siguiente propiedad:

                A[i]=A[n-i+1]
*/
#include<stdio.h>
#define N 5
int propiedad_vector(int[],int,int);
void inicializa(int [], int);
int main()
{
    int a[N], sol, m=N%2; //Si N es par, m=0, luego la cota superior será igual que dividir normalmente entre dos (no habrá resto)
    //printf("Sabiendo que el vector tiene %d elementos:\n\n",N);
    inicializa(a,0);
    propiedad_vector(a,0,m)? printf("\nSi") : printf("\nNo");
    puts(" es un vector que cumple la propiedad.");
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

//Cabecera: Entero funcion propiedad_vector (E/S vector: A, E entero: i, E entero: m)
//Precondicion: Variables inicializadas
//Postcondicion: Devuelve 1 (Verdadero) si se cumple la propiedad para todo los elementos

int propiedad_vector(int A[], int i,int m)
{
    printf("\n\tComparamos %d con %d para acabar la funcion\n", i+1 , (N/2)+m);

    if (i+1 > (N/2)+m)//Si sobrepasa el limite del vector es porque todos las comparaciones son iguales
        return 1;
    printf("Comparamos %d con %d\n", A[i],A[N-i-1]);

    if ( A[i]!=A[N-i-1]) //Comentario1
        return 0;       //Si alguno de ellos es distinto, acaba; devolviendo F

    propiedad_vector(A,i+1,m);
}

/*Comentario1: El enunciado nos dice que la propiedad es A[i]=A[n-i+1]; no
obstante, esto falla debido a que supera el tamaño maximo del vector, ya que
por ejemplo en el primer caso en C, compara A[0] y A[n-0+1]; es decir, dos
elemento mas allá de lo reservado.
Para solucionarlo, basta con cambiar el uno que suma al indice del segundo
comparador, de modo que en vez de sumando, esté restando.Asi podrá hacer lo que
pide; comparar el primero con el ultimo, el segundo con el penultimo y asi
sucesivamente, hasta que llega a la mitad del vector.

Por ejemplo, sea el vector A=[3,6,9,6,3], y teniendo como propiedad A[i]=A[n-i-1]:

    ¿A[0]=A[5-0-1]? Si, porque ambos valen 3;
    ¿A[1]=A[5-1-1]? Si, porque ambos valen 6;

    y como 5%2=1, entonces m=1, luego entra en el primer if con:
    4 > (5/2)+1 --> 4 > 3 . Como  se cumple , devuelve V.
        PD, se ha añadido el " = " para los vectores con tamaño par, para que compare
        los elementos centrales. En los vectores impares hace una comparacion innecesaria
        (compara el elemento central consigo mismo
*/
