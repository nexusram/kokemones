#include "mochila.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ARCHIVO_MOCHILA "mochila.dat"

///Agregar item

void inicMochila(mochila arr[3])
{
    for(int i = 0; i < 3; i++)
    {
        arr[i].lista = inicListaItems();
    }
    strcpy(arr[0].tipo,"Objetos");
    strcpy(arr[1].tipo,"Objetos clave");
    strcpy(arr[2].tipo,"Kokeballs");
}

items * inicListaItems()
{
    return NULL;
}

items * CrearNodoItem (char nombre[20],char tipo[20])
{
    items * aux = (items *)malloc(sizeof(items));
    strcpy(aux->nombre,nombre);
    strcpy(aux->tipo, tipo);
    aux->sig = NULL;

    return aux;
}


int BuscaPosCategoria (mochila adl[3],char tipo [], int validos)
{
    int respuesta = -1;
    int indice = 0;

    while ((indice < validos)&&(respuesta == -1))
    {
        if (strcmp(adl[indice].tipo, tipo) == 0)
        {
            respuesta = indice;
        }
        indice ++;
    }
    return respuesta;
}

int AgregarCategoria (mochila adl[3], char tipo [], int validos)
{
    strcpy(adl[validos].tipo, tipo);///copia el nombre del tipo
    adl[validos].lista = inicListaItems();///inicializa la lista asociada al tipo
    validos ++;///incrementa la cantidad de validos

    return validos;
}


items * AgregarAlPpio (items * lista, items * NuevoNodo)
{
    if (lista == NULL)
    {
        lista = NuevoNodo;
    }
    else
    {
        NuevoNodo->sig = lista;
        lista = NuevoNodo;
    }
    return lista;
}

void AgregarItem (mochila adl[])
{
    items * aux ;
    char nombre [20];
    char tipo [20];
    char Categoria[3][20]= {"Objetos","Objetos Clave","Kokeballs"};
    char control = 's';
    int validos = 0;
    int opcion =0;

    while (control == 's')
    {
        printf("\nIngrese la Categoria: ");
        printf("\n1 Objetos\n2 Objetos Claves\n3 Kokeballs\n");
        fflush(stdin);
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            strcpy(tipo,Categoria[0]);
            break;
        case 2:
            strcpy(tipo,Categoria[1]);
            break;
        case 3:
            strcpy(tipo,Categoria[2]);
            break;
        default:
            printf("\nNumero no valido, ingrese 1, 2 0 3");
            break;
        }
        printf("%s", tipo);
        printf("\nIngrese el nombre del item: ");
        fflush(stdin);
        scanf("%s", &nombre);

        aux = CrearNodoItem(nombre,tipo);
        adl[opcion-1].lista =AgregarAlPpio(adl[opcion-1].lista,aux);

        printf("\nDesea cargar mas items? Presione s o n");
        fflush(stdin);
        scanf("%c", &control);
    }

}
void modificarItem(char ItemAModificar[20], mochila adl[])
{
    items * aux;
    int indice = 0;
    int verificacion = -1;

    ///verificar que exista en la lista
    if ((adl[0].lista == NULL)&&(adl[1].lista == NULL)&&(adl[2].lista == NULL))
    {
        printf("\nNo hay items cargados en la mochila\n");
    }
    else
    {
        for(indice = 0; indice < 3; indice++)
        {
            aux = adl[indice].lista;

            while(aux != NULL)
            {
                if(strcmp(ItemAModificar,aux->nombre) == 0)
                {
                    printf("\nItem encontrado con exito\n");
                    verificacion =0;
                    printf("\nIngrese el nuevo nombre\n");
                    fflush(stdin);
                    scanf("%s", &aux->nombre);
                }
                aux = aux->sig;
            }
        }
        if (verificacion == -1)
        {
            printf("\nEl item que desea modificar no esta cargado en la lista");
        }
    }

}

///Opcion 3 Mostrar items y mochila
void MostrarListaItems (items * lista)
{
    items * seguidora = lista;

    if (seguidora != NULL)
    {
        printf("\nNombre: %s", seguidora->nombre);
        MostrarListaItems(seguidora->sig);
    }
}

void MostrarMochila (mochila adl[])
{
    int i = 0;

    for(i=0; i<3; i++)
    {
        MostarUnaCategoria(adl,i);
    }
}

///Opcion 4 mostrar por categoria

void MostarUnaCategoria (mochila adl [],int i)
{
    if (adl[i].lista != NULL)
    {
        printf("\n---Inicio de la lista de %s----\n",adl[i].tipo);
        MostrarListaItems(adl[i].lista);
        printf("\n\n---Fin de la lista de %s---\n",adl[i].tipo);
    }
    else
    {
        printf("\n----La lista de %s esta vacia----\n", adl[i].tipo);
    }

}

///Opcion 5

void cargarArchivoMochila(mochila adl [])
{
    FILE * parch = fopen(ARCHIVO_MOCHILA,"wb");

    items * aux;
    int i =0;
    registro registroAux;

    if(parch != NULL)
    {
        for (i=0; i<3; i++)
        {
            aux = adl[i].lista;

            while (aux != NULL)
            {
                strcpy(registroAux.nombre,aux->nombre);
                strcpy(registroAux.tipo,aux->tipo);
                fwrite(&registroAux,sizeof(registro),1,parch);
                aux = aux->sig;
            }
        }
    }
    fclose(parch);
}

void leerArchivoMochila(mochila adl[])
{
    FILE * parch = fopen(ARCHIVO_MOCHILA,"rb");
    items * nuevo;
    registro aux;

    if(parch != NULL)
    {
        while(fread(&aux,sizeof(registro),1,parch) > 0)
        {
            nuevo = CrearNodoItem(aux.nombre, aux.tipo);
            if (stricmp(aux.tipo,adl[0].tipo) == 0)
            {
                adl[0].lista = AgregarAlPpio(adl[0].lista,nuevo);

            }
            else if (stricmp(aux.tipo,adl[1].tipo) == 0)
            {
                adl[1].lista = AgregarAlPpio(adl[1].lista,nuevo);

            }
            else if (stricmp(aux.tipo,adl[2].tipo) == 0)
            {
                adl[2].lista = AgregarAlPpio(adl[2].lista,nuevo);
            }
        }
    }

}
void borrarItem(char nombre[20], mochila adl[])
{
    int i = 0;
    items * seg;
    items * ante;
    int verificacion = -1;

    for(i=0; i< 3; i++)
    {
        if((adl[i].lista != NULL) && (strcmp(nombre, adl[i].lista->nombre)==0 ))
        {
            items * aux = adl[i].lista;
            adl[i].lista = adl[i].lista->sig;
            free(aux);
            verificacion = 0;
        }
        else
        {
            seg = adl[i].lista;
            while((seg != NULL) && (strcmp(nombre, seg->nombre)!=0 ))
            {
                ante = seg;
                seg = seg->sig;
            }
            if(seg!=NULL)
            {
                ante->sig = seg->sig;
                free(seg);
                verificacion = 0;
            }
        }
    }
    if (verificacion == -1)
    {
        printf("El item que quiere borrar no se encuentra cargado\n");
    }else if (verificacion == 0)
    {
        printf("El item ha sido eliminado con exito!\n");
    }
}
