#include "pokedex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ARCHIVO_POKEDEX "pokedex.dat"

pokedex * insertarNodoPokedex(pokedex * arbolPokedex, pokemon dato){

    if(arbolPokedex==NULL){
        arbolPokedex = crearNodoArbol(dato);
    }else{
        if(dato.nro > arbolPokedex->dato.nro){
            arbolPokedex->der = insertar(arbolPokedex->der, dato);
        }
        else{
            arbolPokedex->izq = insertar(arbolPokedex->izq, dato);
        }
    }

    return arbolPokedex;
}

pokedex * inicPokedex(){
    return NULL;
}

pokedex * crearNodoPokedex(pokemon nuevo){
    pokedex * auxPokedex = malloc(sizeof(pokedex));

    auxPokedex->dato = nuevo;
    auxPokedex->der = NULL;
    auxPokedex->izq = NULL;

    return auxPokedex;
}

int buscarEnPokedex(pokemon dato, pokedex * arbolPokedex){
    int encontrado = -1;

    if(arbolPokedex != NULL){
        if(encontrado != 0 && arbolPokedex->dato.nro == dato.nro){
            encontrado = 0;
        }
        if(encontrado == -1){
            encontrado = buscarEnPokedex(dato,arbolPokedex->der);
            encontrado = buscarEnPokedex(dato,arbolPokedex->izq);
        }
    }

    return encontrado;
}

pokedex * modificarPokemonEnPokedex(pokemon pokemonAModificar, pokedex * arbolPokedex){
    if(arbolPokedex!=NULL){
        if(strcmp(pokemonAModificar.nombre,arbolPokedex->dato.nombre) == 0){
            arbolPokedex->dato = pokemonAModificar;
        }
        arbolPokedex->izq = modificarPokemonEnPokedex(pokemonAModificar,arbolPokedex->izq);
        arbolPokedex->der = modificarPokemonEnPokedex(pokemonAModificar,arbolPokedex->der);
    }

    return arbolPokedex;
}

pokedex * leerPokedex(pokedex * arbolPokedex){
    FILE * parch = fopen(ARCHIVO_POKEDEX,"rb");
    pokemon aux;
    arbolPokedex = inicPokedex();

    if(parch!=NULL){
        while(fread(&aux,sizeof(pokemon),1,parch)>0){
            arbolPokedex = insertarNodoPokedex(arbolPokedex,aux);
        }
    }

    fclose(parch);

    return arbolPokedex;
}

void cargarArchivoEquipo(pokedex * arbolPokedex){
    FILE * parch = fopen(ARCHIVO_POKEDEX,"wb");
    pokemon dato[500];
    int validos = 0, i = 0;

    if(parch != NULL){
        validos = leerYpasarAArreglo(arbolPokedex,dato);
        while(i < validos){
            fwrite(&dato[i],sizeof(pokemon),1,parch);
            i++;
        }
    }

    fclose(parch);
}

int leerYpasarAArreglo(pokedex * arbolPokedex, pokemon arreglo[500]){
    int i = 0;

    if(arbolPokedex!=NULL){
        arreglo[i] = arbolPokedex->dato;
        i++;
        i = i + leerYpasarAArreglo(arbolPokedex->der);
        i = i + leerYpasarAArreglo(arbolPokedex->izq);
    }

    return i;
}
