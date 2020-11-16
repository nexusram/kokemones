#include "pokedex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ARCHIVO_POKEDEX "pokedex.dat"

pokedex * insertarNodoPokedex(pokedex * arbolPokedex, pokemon dato){

    if(arbolPokedex==NULL){
        arbolPokedex = crearNodoPokedex(dato);
    }else{
        if(dato.nro > arbolPokedex->dato.nro){
            arbolPokedex->der = insertarNodoPokedex(arbolPokedex->der, dato);
        }
        else{
            arbolPokedex->izq = insertarNodoPokedex(arbolPokedex->izq, dato);
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

int buscarEnPokedex(int nro, pokedex * arbolPokedex){
    int encontrado = -1;

    if(arbolPokedex != NULL){
        if(encontrado != 0 && arbolPokedex->dato.nro == nro){
            encontrado = 0;
            mostrarPokemonEnPokedex(arbolPokedex->dato);
        }
        if(encontrado == -1){
            encontrado = buscarEnPokedex(nro,arbolPokedex->der);
            encontrado = buscarEnPokedex(nro,arbolPokedex->izq);
        }
    }

    return encontrado;
}

pokedex * modificarPokemonEnPokedex(char AModificar[20], pokedex * arbolPokedex){
    if(arbolPokedex!=NULL){
        if(strcmp(AModificar,arbolPokedex->dato.nombre) == 0){
            printf("\nKokemon encontrado con exito\n");
            printf("Ingrese los nuevos datos\n");
            pokemon nuevosDatos = cargarPokemonPokedex();
            arbolPokedex->dato = nuevosDatos;
        }
        arbolPokedex->izq = modificarPokemonEnPokedex(AModificar,arbolPokedex->izq);
        arbolPokedex->der = modificarPokemonEnPokedex(AModificar,arbolPokedex->der);
    }

    return arbolPokedex;
}

pokedex * leerPokedex(pokedex * arbolPokedex){
    FILE * parch = fopen(ARCHIVO_POKEDEX,"rb");

    pokemon aux;

    if(parch!=NULL){
        while(fread(&aux,sizeof(pokemon),1,parch)>0){
            arbolPokedex = insertarNodoPokedex(arbolPokedex,aux);
        }
    }

    fclose(parch);

    return arbolPokedex;
}

void cargarArchivoPokedex(pokedex * arbolPokedex){
    FILE * parch = fopen(ARCHIVO_POKEDEX,"wb");
    pokemon dato[500];
    int validos = 0, i = 0;

    if(parch != NULL){
        validos = leerYpasarAArreglo(arbolPokedex,dato,0);
        while(i < validos){
            fwrite(&dato[i],sizeof(pokemon),1,parch);
            i++;
        }
    }

    fclose(parch);
}

int leerYpasarAArreglo(pokedex * arbolPokedex, pokemon arreglo[500], int validos){
    int i = 0;

    if(arbolPokedex!=NULL){
        arreglo[i] = arbolPokedex->dato;
        i++;
        i = i + leerYpasarAArreglo(arbolPokedex->der,arreglo,validos);
        i = i + leerYpasarAArreglo(arbolPokedex->izq,arreglo,validos);
    }

    return i;
}

void mostrarPokedex(pokedex * arbolPokedex){
    if(arbolPokedex!=NULL){
        mostrarPokedex(arbolPokedex->izq);
        mostrarPokemonEnPokedex(arbolPokedex->dato);
        mostrarPokedex(arbolPokedex->der);
    }
}

void mostrarPokemonEnPokedex(pokemon estadisticas){
    printf("Nombre: %s\n",estadisticas.nombre);
    printf("Nro: %d\n",estadisticas.nro);
    printf("Tipo: %s\n\n",estadisticas.tipo);
}

pokemon cargarPokemonPokedex(){
    pokemon nuevoPokemon;
    char control = 's';

    printf("\nIngrese el numero de su kokemon\n");
    scanf("%d",&nuevoPokemon.nro);

    printf("\nIngrese el tipo de su kokemon\n");
    fflush(stdin);
    scanf("%s",&nuevoPokemon.tipo);

    printf("\nIngrese el nombre de su kokemon\n");
    fflush(stdin);
    scanf("%s",&nuevoPokemon.nombre);

    return nuevoPokemon;
}
