#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

int comprobarId(struct empleado empleados[100], int num_emp, int id);
void mostrarMenu(){
    printf("\nIntroduce la opcion que desee realizar:\n");
    printf("1- Alta empleado\n");
    printf("2- Baja empleado\n");
    printf("3- Listar empleados\n");
    printf("4- Consultar datos empleado\n");
    printf("5- Modificar sueldo\n");
    printf("6- Modificar horas\n");
    printf("7- Salir\n");
}

void listarEmpleados(struct empleado empleados[100], int num_emp){
    printf("Listando los datos del empleado: \n");
    for (int i=0; i<num_emp; i++){
        printf("Nombre: %s\n", empleados[i].nombre);
        printf("Id del empleado: %d\n", empleados[i].id);
        printf("Sueldo: %.2f\n", empleados[i].sueldo);
        printf("Horas semanales: %d\n",empleados[i].horas);
        printf("\n");
    }
}

int alta(struct empleado empleados[100], int num_emp){
    int creado = 0;
    struct empleado emp;

    fflush(stdin);
    printf("Introduce nombre y apellidos\n");
    gets(emp.nombre);

    printf("Introduce Id del empleado\n");
    scanf("%d",&emp.id);

    printf("Introduce sueldo\n");
    scanf("%f",&emp.sueldo);

    printf("Introduce horas semanales trabajadas\n");
    scanf("%d",&emp.horas);

    int existe = comprobarId(empleados,num_emp,emp.id);

    if (num_emp < 100){
        if(existe == 0){
            empleados[num_emp] = emp;
            creado = 1;
        }
        else{
            printf("No se puede crear empleado. ID duplicado\n");
        }
    }
    else{
        printf("No se puede dar de alta el empleado. Cupo alcanzado");
    }

    return creado;

}

int baja(struct empleado empleados[100], int num_emp){
    int eliminado = 0;
    int id, indice;

    printf("Introduce el Id del empleado a dar de baja\n");
    scanf("%d",&id);

    int existe = comprobarId(empleados,num_emp,id);

    if (existe == 1){
        for (int i=0; i<num_emp; i++){
            if (empleados[i].id == id){
                indice = i;
            }
        }

        for (int j=indice; j<num_emp-1; j++){
            empleados[j] = empleados[j+1];
            struct empleado aux;
            empleados[j+1] = aux;
        }
        eliminado = 1;
    }
    else{
        printf("No se puede dar de baja el empleado. ID no existe\n");
    }

    return eliminado;

}

void consultarDatosEmpleado(struct empleado empleados[100], int num_emp){
    int id;
    printf("Introduce id del empleado cuyos datos quieres consultar\n");
    scanf("%d",&id);

    int existe = comprobarId(empleados,num_emp,id);
    if (existe == 1){
        for (int i=0; i<num_emp; i++){
            if (empleados[i].id == id){
                printf("Listando datos del empleado con id: %d\n", empleados[i].id);
                printf("Nombre: %s\n",empleados[i].nombre);
                printf("Sueldo: %.2f\n", empleados[i].sueldo);
                printf("Horas semanales: %d\n",empleados[i].horas);

            }
        }
    }
    else{
        printf("No se puede consultar los datos del empleado. ID no existe\n");
    }

}

void modificarSueldo(struct empleado empleados[100], int num_emp){

    int id;

    printf("Introduce id del empleado cuyo sueldo quieres modificar\n");
    scanf("%d",&id);

    int existe = comprobarId(empleados,num_emp,id);

    if (existe == 1){
        float nuevo_sueldo;
        printf("Introduce el nuevo sueldo del empleado\n");
        scanf("%f",&nuevo_sueldo);
        for(int i=0; i<num_emp; i++){
            if (empleados[i].id == id){
                empleados[i].sueldo = nuevo_sueldo;
                printf("Sueldo actualizado\n");
            }
        }

    }
    else{
        printf("No se puede modificar el sueldo del empleado. ID no existe\n");
    }
}

void modificarHoras(struct empleado empleados[100], int num_emp){

    int id;

    printf("Introduce id del empleado cuyas horas quieres modificar\n");
    scanf("%d",&id);

    int existe = comprobarId(empleados,num_emp,id);

    if (existe == 1){
        int nuevas_horas;
        printf("Introduce las nuevas horas semanales del empleado\n");
        scanf("%d",&nuevas_horas);

        for(int i=0; i<num_emp; i++){
            if (empleados[i].id == id){
                empleados[i].horas = nuevas_horas;
                printf("Horas actualizadas\n");
            }
        }

    }
    else{
        printf("No se pueden modificar las horas del empleado. ID no existe\n");
    }
}

int comprobarId(struct empleado empleados[100], int num_emp, int id){

    int resultado = 0;

    for (int i=0; i<num_emp; i++){
        if (empleados[i].id == id){
            resultado = 1;
        }
    }

    return resultado;

}
