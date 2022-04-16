#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
*/
struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;
struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} typedef Cliente;
void cargarClientes(Cliente *comprador,int cantidad);
void cargarProductos(Producto *elementos, int cantidadProductos);
void mostrar(Cliente *comprador,int cantidad);
void liberar(Cliente *comprador,int cantidad);
int costoProducto(Producto material);
int main(){
    int cantidadClientes;
    printf("Dame la cantidad de clientes a cargar");
    scanf("%d",&cantidadClientes);
    Cliente *clientes;
    clientes=(Cliente *)(malloc(cantidadClientes*sizeof(Cliente)));
    cargarClientes(clientes,cantidadClientes);//cargo los clientes
    mostrar(clientes,cantidadClientes);//muestro por pantalla a los clientes
    liberar(clientes,cantidadClientes);//elimino la memoria dinamica
}

void cargarClientes(Cliente *comprador,int cantidad){
    //aca tendre que cargar la cantidad necesaria de clientes
    //utilizo una variable auxiliar para poder almacenar el dato 
    srand((unsigned)time(NULL));
    char *aux;
    int longitud;
    aux=(char *)(malloc(100*sizeof(char)));
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nDame el nombre del cliente: ");
        fgets(aux,100,stdin);
        fflush(stdin);
        longitud=strlen(aux)+1;
        comprador[i].NombreCliente=(char *)(malloc(longitud * sizeof(char)));
        strcpy(comprador[i].NombreCliente,aux);
        comprador[i].ClienteID=i;
        comprador[i].CantidadProductosAPedir=rand () % 6 + 1;//valor entre 1 y 5
        comprador[i].Productos=(Producto *)(malloc(comprador[i].CantidadProductosAPedir*sizeof(Producto)));
        cargarProductos(comprador[i].Productos,comprador[i].CantidadProductosAPedir);
    }
    free(aux);//le libero a aux la memoria solicitada   
}
/*
struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;
*/
void cargarProductos(Producto *elementos, int cantidadProductos){
    srand((unsigned)time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};//productos a ser guardados
    int indice,longitud;

    for (int i = 0; i < cantidadProductos; i++)
    {
        indice=rand()%5;//el indice va de 0 a 4
        longitud=strlen(TiposProductos[indice])+1;
        elementos[i].TipoProducto=(char *)(malloc(longitud*sizeof(char)));
        strcpy(elementos[i].TipoProducto,TiposProductos[indice]);
        elementos[i].Cantidad=rand()%11+1;//el valor varia de 1 a 10
        elementos[i].ProductoID=i;
        elementos[i].PrecioUnitario=rand()%(100-10)+10;
    }    
}
void mostrar(Cliente *comprador,int cantidad){
    int total=0;
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nNombre del cliente: %s", comprador[i].NombreCliente);
        printf("\nid del cliente : %d", comprador[i].ClienteID);
        printf("\nCantidad de productos: %d", comprador[i].CantidadProductosAPedir);
        for (int e = 0; e < comprador[i].CantidadProductosAPedir; e++)
        {
            printf("\ncantidad del producto: %d", comprador[i].Productos[e].Cantidad);
            printf("\nId del producto: %d", comprador[i].Productos[e].ProductoID);
            printf("\nTipo de el producto %s", comprador[i].Productos[e].TipoProducto);
            printf("\nprecio: %d",comprador[i].Productos[e].PrecioUnitario);
            total=costoProducto(comprador[i].Productos[e])+total;
        }
        printf("\nEl cliente debera pagar: %d", total);
    }
}
//esta funcion liberara toda la memoria solicitada
void liberar(Cliente *comprador,int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        free(comprador[i].NombreCliente);
        for (int e = 0; e < comprador[i].CantidadProductosAPedir; e++)
        {
            free(comprador[i].Productos[e].TipoProducto);
        }
        free(comprador[i].Productos);
    }
    free(comprador);
}

int costoProducto(Producto material){
    return(material.Cantidad*material.PrecioUnitario);
}