#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"lib.h"

/*genera nodo*/
void agregarNodo(Nodo**lista, Cliente cliente){
    *lista = (Nodo*)malloc(sizeof(Nodo));
    (*lista)->snod = NULL;
    (*lista)->next = NULL;
    (*lista)->cliente = cliente;
    strcpy((*lista)->apynom,cliente.apynom);
    (*lista)->id = cliente.id;
}

/*medir tamanio de la lista*/
int listSize(Nodo *lista){
    if(lista != NULL){
        int cont = 0;
        while(lista !=NULL){
            cont++;
            lista = lista->next;
        }
        printf("El tamanio de la lista es: %d\n",cont);
        return cont;
    }else{
        printf("Lista vacia");
        return 0;
    }
}

/*carga ordenada*/
void cargarOrdenado(Nodo **lista,Cliente cliente){
    Nodo *nod = NULL;
    agregarNodo(&nod, cliente);
    if(*lista != NULL){
        if((*lista)->id > nod->id){
            nod->next = *lista;
            *lista = nod;
        }else{
            Nodo *aux = *lista;
            while(aux->next && (aux->next->id != nod->id))
                aux = aux->next;

            if(aux->next && (aux->next->id == nod->id)){
                printf("\nEl elemento ya se encuentra en la lista\n");
                aux = aux->next;
                return;
            }
            if(aux->next && (aux->next->id < nod->id))
                nod->next = aux->next;

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
        if(aux->id ==id)
            return aux;
        else {
            while(aux && (aux->id != id))
                aux = aux->next;
            if(id == aux->id)
                return aux;
            else{
                printf("Elemento no encontrado\n");
                return NULL;
            }
        }

    }else
        printf("Lista vacia\n");
        return NULL;
}

void eliminarInicio(Nodo **lista){
    Nodo *eliminado = *lista;
    *lista = (*lista)->next;
    free(eliminado);
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
            while((nodo && nodo->next) && (id != nodo->next->id))
                nodo == nodo->next;
            if(id == nodo->next->id){
                Nodo *eliminado = nodo->next;
                nodo->next = eliminado->next;
                free(eliminado);
                return 1;
            }else {
                printf("No se pudo encontrar el elemento\n");
                return 0;
            }
        }
    }
}

void imprimirLista(Nodo *lista){
    Nodo *aux = lista;
    if(aux){
        while(!aux){
            mostrarCliente(aux->cliente);
            printf("ID: %d\n",aux->id);
            /*ahora se invoca la funcion para mostrar la sublista asosciada al nodo*/

            aux = aux->next;
        }
    }else
        printf("Lista vacia\n");
}

/*cargamos el primary key*/
int datoClave(){
    int id;
    printf("Ingrese id\n");scanf("%d",&id);fflush(stdin);
    system("cls");
    return id;
}

/*cargamos los datos del archivo a una lista*/
void cargarDatos(Nodo **lista){
    FILE *f = fopen("clientes.txt","r");
    Nodo *aux = *lista;
    if(validarArchivo(f)){
        Cliente client;
        while(!feof(f)){
            client = cargarCliente(f);
            cargarOrdenado(&aux,client);
            aux = aux->next;
        }
        fclose(f);
    }else
        printf("No se pudo encontrar el archivo");
    fclose(f);
}
/*guardamos los datos en un fichero txt*/
void guardarDatosDatos(Nodo *lista){
    FILE *f = fopen("clientes.txt","w");
    if(lista){
        Nodo *aux = lista;
        if(validarArchivo(f)){
            while(aux){
                fprintf(f,"%d\t%s\t%f\t%d\t%d\t%d",aux->cliente.id,aux->cliente.apynom,aux->cliente.venta,aux->cliente.fecha.dd,aux->cliente.fecha.mm,aux->cliente.fecha.yy);
                fprintf(f,"\n");
                aux = aux->next;
            }
            fclose(f);
        }
    }else
        printf("Lista vacia\n");
    fclose(f);
}



