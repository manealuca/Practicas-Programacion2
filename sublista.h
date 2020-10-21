#ifndef SUBLISTA_H_INCLUDE_
#define SUBLISTA_H_INCLUDE_
Subnod *agregarSubNodo(Cliente client);
void cargarOrdenadoSublista(Subnod **lista,Cliente cliente);
void cargarSublistaCompleta(Cab **lista,int id,Nodo **list);
Cliente cargarSublistaArchivo(Nodo **lista,FILE *f);

#endif // SUBLISTA_H_
