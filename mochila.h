#ifndef MOCHILA_H_INCLUDED
#define MOCHILA_H_INCLUDED

//estructuras mochila
typedef struct {
    char nombre[20];
    char tipo[20];
    struct items * sig;
} items;

typedef struct{
    char tipo[30];
    items * lista;
} mochila;

void inicMochila(mochila *);
items * inciListaItems();
void cargarMochilaAArchivo(mochila);
void leerMochila(mochila)
#endif // MOCHILA_H_INCLUDED
