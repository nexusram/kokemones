#include "kokemones.h"
#include <stdlib.h>
#include <stdio.h>

#define ARCHIVO_EQUIPO "equipo.dat"

pokemonEnEquipo * inicListaEquipo(){
    return NULL;
}

pokemonEnEquipo * crearNodoEquipo(stats dato){
    pokemonEnEquipo * aux = malloc(sizeof(pokemonEnEquipo));

    aux->estadisticas = dato;
    aux->sig = NULL;

    return aux;
}

pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo * lista, pokemonEnEquipo * nuevo){
    if(lista == NULL){
        lista = nuevo;
    }else{
        nuevo->sig = lista;
        lista = nuevo;
    }

    return lista;
}

void cargarArchivoEquipo(pokemonEnEquipo * lista){
    FILE * parch = fopen(ARCHIVO_EQUIPO,"wb");
    pokemonEnEquipo * aux = lista;
    stats dato;

    if(parch != NULL){
        dato = aux->estadisticas;
        fwrite(&dato,sizeof(stats),1,parch);
        if(aux!=NULL){
            aux = aux->sig;
        }
    }

    fclose(parch);
}

pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo * lista){
    FILE * parch = fopen(ARCHIVO_EQUIPO,"rb");
    pokemonEnEquipo * nuevo;
    stats dato;

    if(parch != NULL){
        while(fread(&dato,sizeof(stats),1,parch) > 0){
            nuevo = crearNodoEquipo(dato);
            lista = agregarPpioEquipo(lista,nuevo);
        }
    }

    return lista;
}
