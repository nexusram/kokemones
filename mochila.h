#ifndef MOCHILA_H_INCLUDED
#define MOCHILA_H_INCLUDED

//estructuras mochila
typedef struct {
    char nombre[20];
    char tipo[20];
    struct items * sig;
} items;///lista

typedef struct{
    char tipo[30];
    items * lista;
} mochila; ///arreglo

typedef struct{
    char nombre[20];
    char tipo[20];
}registro;

void inicMochila(mochila *);
items * inicListaItems();
items * CrearNodoItem (char nombre[20],char tipo[20]);
int BuscaPosCategoria (mochila adl[3],char tipo [], int validos);
int AgregarCategoria (mochila adl[3], char tipo [], int validos);
items * AgregarAlPpio (items * lista, items * NuevoNodo);
void AgregarItem (mochila adl[]);
void MostrarListaItems (items * lista);
void MostrarMochila (mochila adl[]);
void MostarUnaCategoria (mochila adl [],int i);
void cargarArchivoMochila(mochila adl []);
void leerArchivoMochila(mochila adl[]);
void borrarItem(char nombre[20], mochila adl[]);

#endif // MOCHILA_H_INCLUDED

