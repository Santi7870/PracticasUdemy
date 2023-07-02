#include <stdio.h>

int main()
{
    FILE *f;
    f = fopen("numeros.txt","r");
    int suma = 0,numero;

    while(feof(f) == 0){
        fscanf(f,"%d", &numero);
        suma = suma + numero;

    }

    printf("La suma de todos los numeros del fichero es: %d\n", suma);

    fclose(f);
}
