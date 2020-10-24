#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
/*inicia la cabecera de la lista*/
Cab *iniciarCabecera(){
    Cab *head = (Cab*)malloc(sizeof(Cab));
    head->first = NULL;
    head->last = NULL;
}
/*Genera un nuevo nodo*/
DobleNodo *nuevoDobleNodo(Cliente client){
    DobleNodo *aux =(DobleNodo*)malloc(sizeof(DobleNodo));
    aux->cliente = client;
    aux->next = NULL;
    aux->prev = NULL;
    return aux;
}

/*Ordenamiento de burbuja para lista doblememnte enlazada*/
void *ordenar_lista(Cab *lista){
    if(lista){
        DobleNodo *pivot = NULL, *current = NULL;
        Cliente  client = lista->first->cliente;
        pivot = lista->first;
        while(pivot != lista->last){
            current = pivot->next;
            while(current != NULL){
                if(pivot->cliente.id >= current->cliente.id){
                    printf("realizando el cambio de variable\n");
                    client = pivot->cliente;
                    pivot->cliente = current->cliente;
                    current->cliente = client;
                }
                current = current->next;
            }
            pivot = pivot->next;
        }
    }
}

/*Devuelve el id del nodo*/
int obtener_indice(Cab *lista, int idx){
    if(lista){
        if(idx <= lista->elementos){
            int cont = 1;
            DobleNodo *aux = NULL;
            aux = lista->first;
            while(cont< idx){
                aux = aux->next;
                cont++;
            }
            return cont;
        }else{
            printf("Elemento fuera de rango\n");
            return 0;
        }
        }else{
        printf("lista vacia");
        return 0;
    }
}

/*Muesta en pantalla el contenido de la lista*/
void imprimirListaDoble(Cab *lista){
    if(lista){
        DobleNodo *aux = NULL;
        aux = lista->first;
        while(aux !=NULL){
            mostrarCliente(aux->cliente);
            aux = aux->next;
        }
    }else{
        printf("Lista vacia");
    }
}

/*Devuelve un nodo para operar sobre el mismo*/
DobleNodo *obtener_nodo(Cab **lista, int idx){
    if(*lista){
        if(idx<= (*lista)->elementos){
            DobleNodo* aux = (*lista)->first;
            while(aux->cliente.id != idx)
                aux = aux->next;

            if(aux->cliente.id == idx)
                return aux;

        }else
            printf("El elemento no esta en la lista");

    }else
        printf("Lista vacia");
    return NULL;
}

/*elimina un nodo por id*/
void eliminar_nodo_doble(Cab *lista){
    DobleNodo *actual = (DobleNodo*)malloc(sizeof(DobleNodo));
    DobleNodo *primero =lista->first;
    actual = lista->first;
    DobleNodo *anterior =(DobleNodo*)malloc(sizeof(DobleNodo));
    anterior =NULL;
    int id = 0, encontrado = 0;
    printf("ingrese id\n");scanf("%d",&id);fflush(stdin);

    if(primero != NULL){
        while(actual !=NULL &&encontrado != 1){
            if(actual->cliente.id == id){

                if(actual == lista->first){
                    lista->first = lista->first->next;
                    lista->first->prev = NULL;
                }else if(actual == lista->last){
                    anterior->next = NULL;
                    lista->last
                     = anterior;
                }else{
                    anterior->next = actual->next;
                    actual->next->prev = anterior;
                    printf("DobleNodo eliminado\n");
                    encontrado = 1;
                }
                anterior = actual;
                actual = actual->next;
            }
            if(encontrado == 0){
                printf("Elemento no encontrado\n");
            }else
                free(anterior);
        }
    }else
        printf("\n Lista vacia\n");
}

/*Carga la lista de manera ordenada*/
void cargaOrdenadoDoble(Cab **cab, Cliente client){

    DobleNodo *aux;
    DobleNodo *nodo=NULL;
    nodo=nuevoDobleNodo(client);
    if ((*cab)->first==NULL)
    {
        (*cab)->first=nodo;
        (*cab)->last=nodo;
    }
    else
    {
        system("pause");
        if ((*cab)->first->cliente.id > nodo->cliente.id)
        {
            nodo->next=(*cab)->first;
            (*cab)->first->prev=nodo;
            (*cab)->first=nodo;
        }
        else
        {
            aux=(*cab)->first;
            while ((aux!=NULL) && (aux->cliente.id < nodo->cliente.id))
                aux=aux->next;
            if (aux!=NULL)
            {
                nodo->prev=aux->prev;
                aux->prev->next=nodo;
                aux->prev=nodo;
                nodo->next=aux;
            }
            else
            {
                nodo->prev=(*cab)->last;
                (*cab)->last->next=nodo;
                (*cab)->last=nodo;
            }
        }
    }
}
/*Iniciamos la cabecera de la lista*/
/*void inicializarCab(Cab **cab){
    (*cab)->first=NULL;
    (*cab)->last=NULL;
}
*/

/*Levantamos los datos del cliente desde un archivo*/
void cargarDatos2(Cab **lista){
    FILE *p = fopen("clientes.txt","r");
    if(p){
        Cliente client;
        while(fscanf(p,"%d %f %d %d %d %s",&client.id,&client.venta,&client.fecha.dd,&client.fecha.mm,&client.fecha.yy,client.apynom) == 6)
            cargaOrdenadoDoble(lista,client);

    }else
        printf("No se pudo abrir el archivo\n");
    fclose(p);

}


/*Guardamos los datos en el fichero txt*/
void guardarDatosDoble(Cab **lista){
    FILE *f = fopen("clientes.txt","w");
    if((*lista)->first && f){
        DobleNodo *aux =(*lista)->first;
        while(aux){
            fprintf(f,"%d %s %f %d %d %d",aux->cliente.id,aux->cliente.apynom,aux->cliente.venta,aux->cliente.fecha.dd,aux->cliente.fecha.mm,aux->cliente.fecha.yy);
            aux = aux->next;
        }
    }else
        printf("Ocurrio un error al guardar los datos\n");
    fclose(f);
}

