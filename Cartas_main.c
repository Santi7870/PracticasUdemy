#include <stdio.h>
#include <stdlib.h>
#include "utiles.h"
#include "blackjack.h"

int main()
{
    int opcion;

    menu();
    scanf("%d",&opcion);

    while(opcion != 0){
        if (opcion == 1){
            jugar_partida();
        }
        else if(opcion == 2){
            cargar_partidas();
        }
        fflush(stdin);
        menu();
        scanf("%d",&opcion);
    }

    printf("Adios\n");
}
