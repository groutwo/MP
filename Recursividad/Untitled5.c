/*Si conj(n,k) representa la cantidad de diferentes conjuntos de k personas que pueden
formarse, dadas n personas entre las cuales elegir. Por ejemplo, conj(4,3) = 4,
porque dadas cuatro personas A, B, C y D hay cuatro conjuntos posibles de tres
personas: ABC, ABD, ACD y BCD. En general se cumple la siguiente relación:
conj(n,k) = conj(n-1,k) + conj(n-1,k-1)
Escribe una función recursiva para calcular conj(n,k) para n,k mayores o iguales que 1*/
#include<stdio.h>
void inicializa(int,int);
int conj(int,int);
int main()
{
    int n,k;
    puts("Introduce dos numeros: ");
    scanf("%d%d",&n,&k);
    conj(n,k);
    printf("\nHay %d subconjunto(s) de personas que pueden formarse con %d personas y %d conjuntos\n", conj(n,k),n,k);
    return 0;
}
//Cabecera: entero funcion conj(E entero: n, E entero: k)
//Precondicion: n tiene que ser mayor, y ambos positivos
//Postcondicion: devuelve el combinatorio de n sobre k
int conj(int n, int k)
{ ///Si la condicion es V, devuelve lo primero; sino, se llama a sí misma con valores cambiados
    return (n==k||k==0)?1:conj(n-1,k)+conj(n-1,k-1);
}

