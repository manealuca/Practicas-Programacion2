#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"lib.h"

//abre el archivo en modo lectura si no existe lo crea
void iniciarArchivo(char file[]){
    FILE *p = fopen(file,"r");
    if(p!=NULL){
        if(fclose(p))printf("No se pudo creaar el archivo");
    }else{
        FILE *p = fopen(file,"w");
        if(p!=NULL)if(fclose(p))printf("No se pudo crear el archivo");
    }
}

void incertarPrimero(Nodo **lista){
    Nodo *nod = (Nodo*)malloc(sizeof(Nodo*));
    agregarNodo(&nod,nuevoCliente());
    nod->next = *lista;
    *lista  = nod;
    (*lista)->next = nod->next;
}

//valida la apertura del archivo
int validarArchivo(FILE *p){
    if(p)
        return 1;
    else{
        printf("No se pudo abrir el archivo\n");
        return 0;
    }
}


