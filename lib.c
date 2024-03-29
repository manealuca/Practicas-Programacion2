#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"lib.h"


/*levanta los datos desde un fichero*/
Cliente cargarCliente(FILE* f){
    Cliente client;
    if(fscanf(f,"%d %f %d %d %d %s",&client.id,&client.venta,client.fecha.dd,&client.fecha.mm,&client.fecha.yy,client.apynom) == 6)
        return client;
    else
        return;
}
/*abre el archivo en modo lectura si no existe lo crea*/
void iniciarArchivo(char file[]){
    FILE *p = fopen(file,"r");
    if(p!=NULL){
        if(fclose(p))printf("No se pudo creaar el archivo");
    }else{
        FILE *p = fopen(file,"w");
        if(p!=NULL)if(fclose(p))printf("No se pudo crear el archivo");
    }
}


/*valida la apertura del archivo*/
int validarArchivo(FILE *p){
    if(p)
        return 1;
    else{
        printf("No se pudo abrir el archivo\n");
        return 0;
    }
}

/*cargamos el primary key*/
int datoClave(){
    int id;
    printf("Ingrese id\n");scanf("%d",&id);fflush(stdin);
    system("cls");
    return id;
}


Cliente nuevoCliente(){
    Cliente client;
    return client;
}

void mostrarCliente(Cliente cliente){
    printf("%d\t%s\t%f\t%d\t%d\t%d\n",cliente.id,cliente.apynom,cliente.venta,cliente.fecha.dd,cliente.fecha.mm,cliente.fecha.yy);
}
