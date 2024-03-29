#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"lib.h"
#include"listas.h"
#include "sublista.h"
/*genera nodo*/
Nodo *agregarNodo(Cliente cliente){
    Nodo*nod = (Nodo*)malloc(sizeof(Nodo));
    nod->snod = NULL;
    nod->next = NULL;
    nod->cliente = cliente;
    /*strcpy((*nod)->apynom,cliente.apynom);
    (*nod)->id = cliente.id;*/
    return nod;
}

/*medir tamanio de la lista*/
int listSize(Nodo *lista){
    int cont = 0;
    while(lista !=NULL){
        cont++;
        lista = lista->next;
    }
    printf("El tamanio de la lista es: %d\n",cont);
    return cont;
}

/*carga ordenada*/
void cargarOrdenado(Nodo **lista,Cliente cliente){
    Nodo *nod = NULL;
    nod = agregarNodo(cliente);
    if(*lista){
        if((*lista)->cliente.id < nod->id){
            nod->next = *lista;
            *lista = nod;
        }else{
            Nodo *aux = *lista;
            while(aux->next && (aux->next->cliente.id > nod->id))
                aux = aux->next;

            if(aux->next && (aux->next->cliente.id == nod->id)){
                printf("\nEl elemento ya se encuentra en la lista\n");
            }
            else{
                if(aux->next && (aux->next->cliente.id >  nod->id))
                    nod->next = aux->next;
            }
            aux->next = nod;
        }
    }else
        *lista = nod;
}

/*buscamos y obtenemos el nodo con el que vamos a operar*/
Nodo *buscarNodo(Nodo *lista){
    int id = datoClave();
    if(lista){
        Nodo *aux = lista;
            while(aux && (aux->id != id))
                aux = aux->next;
            if(id == aux->id)
                return aux;
            else{
                printf("Elemento no encontrado\n");
                return NULL;
            }
    }else
        printf("Lista vacia\n");
        return NULL;
}

void eliminarInicio(Nodo **lista){
    if(*lista){
        Nodo *eliminado = *lista;
        *lista = (*lista)->next;
        free(eliminado);
    }else
        printf("Lista vacia\n");
}

/*eliminar por busqueda*/
int eliminarBusqueda(Nodo **lista ,int id){
    Nodo *nodo = *lista;
    if(nodo){
        if(nodo->id == id){
            if(!nodo->next){
                *lista = NULL;
                free(nodo);
                return 0;
            }else{
                eliminarInicio(lista);
                return 1;
            }
        }else{
            while((nodo->next) && (id != nodo->next->id))
                nodo = nodo->next;
            if( nodo->next &&(id == nodo->next->id)){
                Nodo *eliminado = nodo->next;
                nodo->next = eliminado->next;
                free(eliminado);
                return 1;
            }else {
                printf("No se pudo encontrar el elemento\n");
                return -1;
            }
        }
    }
}

/*Muestea en pantalla la lista enlasada*/
void imprimirLista(Nodo **lista){
    Nodo *aux = *lista;
    if(*lista){
        while(aux !=NULL){
            mostrarCliente(aux->cliente);
            /*ahora se invoca la funcion para mostrar la sublista asosciada al nodo*/

            aux = aux->next;
        }
    }else
        printf("Lista vacia\n");
}

/*cargamos los datos del archivo a una lista*/
void cargarDatos(Nodo **lista){
    FILE *f = fopen("clientes.txt","r");
    /*Archivo de la sublista
    FILE *p = fopen("archivo.txt","r");*/
    if(f){
        Cliente client;
        while(fscanf(f,"%d %f %d %d %d %s",&client.id,&client.venta,&client.fecha.dd,&client.fecha.mm,&client.fecha.yy,client.apynom) == 6){
            /*client = cargarCliente(f);*/
            cargarOrdenado(lista,client);
            /*invocamos a la funcion para cargar la sublista en caso de ser necesario
             cliente2 = cargarSublistaArchivo(lista,p)
            */

        }
    }else
        printf("No se pudo encontrar el archivo");
    fclose(f);
}

/*guardamos los datos en un fichero txt*/
void guardarDatos(Nodo **lista){
    FILE *f = fopen("clientes.txt","w");
    if(*lista){
        Nodo *aux = *lista;
        if(validarArchivo(f)){
            while(aux){
                fprintf(f,"%d %s %f %d %d %d",aux->cliente.id,aux->cliente.apynom,aux->cliente.venta,aux->cliente.fecha.dd,aux->cliente.fecha.mm,aux->cliente.fecha.yy);
                aux = aux->next;
            }

        }
    }else
        printf("Lista vacia\n");
    fclose(f);
}

