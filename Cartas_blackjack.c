#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "blackjack.h"


const char *tipo_carta[] = {"Trebol", "Corazon", "Diamante", "Pica"};
const char *num_carta[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

int generarCarta();
int puntosCarta(const char* carta);
void menu_secundario();
void mostrarGanador(int n_jugadores);
char* obtenerFecha();
void guardarPartida(int n_jugadores);

void jugar_partida(){
    int n_jugadores;
    fflush(stdin);
    printf("Digite la cantidad de jugadores que participaran (2-4)\n");
    scanf("%d",&n_jugadores);

    while (n_jugadores <= 1 || n_jugadores > 4){
        fflush(stdin);
        printf("Ingrese un numero de jugadores valido\n");
        scanf("%d",&n_jugadores);
    }

    for (int i=1; i<=n_jugadores; i++){
        struct jugador j;
        fflush(stdin);
        printf("Introduce el nombre del jugador %d\n",i);
        gets(j.nombre);
        jugadores[i-1] = j;
        
    }

    for (int i=0; i<n_jugadores; i++){
        printf("TURNO DE: %s\n",jugadores[i].nombre);
        int puntuacion = 0;

            puntuacion = puntuacion + generarCarta();
            puntuacion = puntuacion + generarCarta();
        printf("Puntos totales: %d\n", puntuacion);

        int opcion;
        fflush(stdin);
        menu_secundario();
        scanf("%d",&opcion);
        while (opcion != 2 && puntuacion != 0){
            if (opcion == 1){
                puntuacion = puntuacion + generarCarta();
                if (puntuacion > 21){
                    puntuacion = 0;
                    printf("TE HAS PASADO\n");
                }
                printf("Puntos totales: %d\n", puntuacion);
            }
            if (puntuacion != 0){
                fflush(stdin);
                menu_secundario();
                scanf("%d",&opcion);
            }
        }
        jugadores[i].puntos = puntuacion;


    }

    mostrarGanador(n_jugadores);
    guardarPartida(n_jugadores);

}


void mostrarGanador(int n_jugadores){
    int punt_max=0;
    int index_max;

    for (int i=0; i<n_jugadores; i++){
        if (jugadores[i].puntos > punt_max){
            index_max = i;
            punt_max = jugadores[i].puntos;
        }

    }

    printf("El ganador es: %s con una puntuacion de: %d\n",jugadores[index_max].nombre,jugadores[index_max].puntos);
    printf("%s\n",obtenerFecha());
    printf("=================================================\n\n");
}

int generarCarta(){
    int n_tipo_carta = rand()%4;

    int n_num_carta = rand()%13;

    printf("---------------------------\n");
    printf("%s\n\n",num_carta[n_num_carta]);
    printf("\t%s\n\n",tipo_carta[n_tipo_carta]);
    printf("\t\t\t%s\n",num_carta[n_num_carta]);
    printf("---------------------------\n");

    const char *carta = num_carta[n_num_carta];
    int valor = puntosCarta(carta);

    return valor;
}


void menu(){

    printf("BIENVENIDO AL BLACKJACK\n");
    printf("-------------------------\n");
    printf("[1]Juego Nuevo\n");
    printf("[2]Cargar Partidas\n");
    printf("[0]Salir\n");
    printf("=========================\n");
    printf("Ingresa la opcion (digitar el numero correspondiente)\n");

}

void menu_secundario(){
    printf("Seleccione una opcion: (Digite el numero)\n");
    printf("[1]Dame carta\n");
    printf("[2]Salir\n");
}

int puntosCarta(const char* carta){

    int valor = 0;
    if(strcmp(carta,"2")==0){
        valor = 2;
    }
    else if(strcmp(carta,"3")==0){
        valor = 3;
    }
    else if(strcmp(carta,"4")==0){
        valor = 4;
    }
    else if(strcmp(carta,"5")==0){
        valor= 5;
    }
    else if(strcmp(carta,"6")==0){
        valor= 6;
    }
    else if(strcmp(carta,"7")==0){
        valor= 7;
    }
    else if(strcmp(carta,"8")==0){
        valor= 8;
    }
    else if(strcmp(carta,"9")==0){
        valor= 9;
    }
    else if(strcmp(carta,"10")==0){
        valor = 10;
    }
    else if(strcmp(carta,"J")==0){
        valor = 10;
    }
    else if(strcmp(carta,"Q")==0){
        valor = 10;
    }
    else if(strcmp(carta,"K")==0){
        valor = 10;
    }
    else if(strcmp(carta,"A")==0){
        valor = 11;
    }

    return valor;
}

void guardarPartida(int n_jugadores){
    FILE *f;
    f = fopen ("partidas.txt","a");

    char *fecha = obtenerFecha();

    fprintf(f,"\nFecha:%s--",fecha);

    for (int i=0; i<n_jugadores-1; i++){
        fprintf(f,"Nombre: %s - Puntos: %d;",jugadores[i].nombre, jugadores[i].puntos);
    }
    fprintf(f,"Nombre: %s - Puntos: %d",jugadores[n_jugadores-1].nombre, jugadores[n_jugadores-1].puntos);
    fclose(f);
}

void cargar_partidas(){

    FILE *f;
    f = fopen ("partidas.txt","r");
    char cadena[255];
    while (feof(f) == 0)
    {
        fgets(cadena,255,f);
        printf("%s",cadena);
    }
    printf("\n\n");
    fclose(f);
}

char* obtenerFecha(){
    time_t t;
    struct tm *tm;
    char formateada[100];


    t=time(NULL);
    tm=localtime(&t);
    strftime(formateada, 100, "%d/%m/%Y %H:%M:%S", tm);
    char *fecha = malloc (sizeof (char) * 100);
    strcpy(fecha, formateada);
    return fecha;
}
