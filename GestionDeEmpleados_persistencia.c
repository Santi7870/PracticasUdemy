#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

int cargarEmpleados(struct empleado empleados[100]){
    int n_emp = 0;
    FILE *f;
    f = fopen("empleados.txt","r");
    char cadena[255];
    char delimitador[] = ";";

    while (feof(f) == 0){

        struct empleado e;
        fgets(cadena,255,f);
        char *token = strtok(cadena,delimitador);

        if(token != NULL){
            int campo = 1;
            while (token != NULL){
                if (campo == 1){
                    strcpy(e.nombre,token);
                }
                else if(campo == 2){
                    e.id = atoi(token);
                }
                else if(campo == 3){
                    e.sueldo = atof(token);
                }
                else if(campo == 4){
                    e.horas = atoi(token);
                }
                campo++;
                token = strtok(NULL, delimitador);
            }
        }
        empleados[n_emp] = e;
        n_emp++;

    }
    fclose(f);
    return n_emp;
}

void guardarEmpleados(struct empleado empleados[100], int num_emp){
    FILE *f;
    f = fopen("empleados.txt","w");

    for (int i=0; i<num_emp-1; i++){
        fprintf(f, "%s;%d;%.2f;%d\n",empleados[i].nombre,empleados[i].id,empleados[i].sueldo,empleados[i].horas);
    }
    fprintf(f, "%s;%d;%.2f;%d",empleados[num_emp-1].nombre,empleados[num_emp-1].id,empleados[num_emp-1].sueldo,empleados[num_emp-1].horas);

    fclose(f);
}
