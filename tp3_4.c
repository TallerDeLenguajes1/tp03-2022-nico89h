#include <stdio.h>
#include <stdlib.h>
/*
Modifique el ejercicio nro 2 para que, en lugar de ingresar un número fijo de nombres, el
usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación
*/
int main(){
    //prueba de el punto 4 del tp3
    int cantidad;
    printf("Cuantos nombres vas a ingresar? ");
    scanf("%d",&cantidad);
    char **V;//puntero doble, cada uno de los elementos del puntero apuntara a otra direccion de memoria
    V=(char **) (malloc(sizeof(char *)*cantidad));//guardo la cantidad de veces que ingresa nombres
    for (int i = 0; i < cantidad; i++)
    {
        //mi objetivo es hacer que los n elementos de el arreglo puedan obtener una cadena cada uno
        V[i]=(char *)(malloc(100*sizeof(char)));
    }
    for (int i = 0; i < cantidad; i++)
    {
        printf("Dame el primer nombre \n");
        scanf("%s",&V[i][0]);
    }
    int a=0;
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s",V[i]);
        for ( a = 0; V[i][a]!='\0'; a++)
        {
            printf("--%c--",V[i][a]);            
        }
        printf("\n");
    }
    for (int e = 0; e < cantidad; e++)
    {
        free(V[e]);
    }
    free(V);
    //elimino las memorias dinamicas
    return 0;
}