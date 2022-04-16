//se deberan obtener 5 nombres , en los cuales todos se deben obtener de manera dinamica
#include <stdio.h>
int main(){
    char *V[5];//el puntero tiene x el momento solo 5 espacios
    //en dicho puntero se deben guardar 5 cadenas en cada espacio
    for (int i = 0; i < 5; i++)
    {
        V[i]=(char *) malloc(100*sizeof(char));//de esta manera la variable V, sera bidimensional,cada elemento tedra un espacio reservado de 100 caracteres, guardando en cada uno un arrefglo
    }
    for (int e = 0; e < 5; e++)
    {
        puts("Dame un arreglo");
        gets(V[e]);// cada elemento tendra asi un arreglo
        printf("\n");
    }
    int a=0;
    for (int r = 0; r < 5; r++)
    {
        for (int i = 0; V[r][i]!='\0'; i++)
        {
            printf("--%c--",V[r][i]);
        }
        printf("\n");
    }
    for (int t = 0; t < t; t++)
    {
        free(V[t]);
    }
       
}
#include <stdlib.h>
int main(){
    char *V[5];//el puntero tiene x el momento solo 5 espacios
    //en dicho puntero se deben guardar 5 cadenas en cada espacio
    for (int i = 0; i < 5; i++)
    {
        V[i]=(char *) malloc(100*sizeof(char));//de esta manera la variable V, sera bidimensional,cada elemento tedra un espacio reservado de 100 caracteres, guardando en cada uno un arrefglo
    }
    for (int e = 0; e < 5; e++)
    {
        puts("Dame un arreglo");
        gets(V[e]);// cada elemento tendra asi un arreglo
        printf("\n");
    }
    int a=0;
    for (int r = 0; r < 5; r++)
    {
        for (int i = 0; V[r][i]!='\0'; i++)
        {
            printf("--%c--",V[r][i]);
        }
        printf("\n");
    }
    for (int t = 0; t < t; t++)
    {
        free(V[t]);
    }
       
}