#include "kokemones.h"
#include "pokedex.h"
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

pokemonEnEquipo * cargarEquipo(pokemonEnEquipo * equipo){

    char control = 's';
    int enPokedex = 0;
    pokemonEnEquipo * nuevo;
    stats dato;

    while(control == 's'){

        dato = cargarPokemon();
        nuevo = crearNodoEquipo(dato);

        enPokedex = buscarEnPokedex(nuevo->estadisticas);

        if(enPokedex == -1){
            agregarDeEquipoAPokedex(dato);
        }

        equipo = agregarPpioEquipo(equipo,nuevo);

        printf("\nDesea ingresar otro pokemon?\n");
        fflush(stdin);
        scanf("%c",&control);
    }

    printf("\nDeseas guardar este equipo en el archivo? (s/n)");
    printf("\nSe borrara el equipo que tenias guardado antes\n");
    fflush(stdin);
    scanf("%c"&control);

    if(control == 's'){
        cargarArchivoEquipo(equipo);
    }

    return equipo;
}

stats cargarPokemon(){
    stats nuevoPokemon;

    printf("\nIngrese el nivel de su pokemon\n");
    scanf("%d",&nuevoPokemon.nivel);

    printf("\nIngrese el numero de su pokemon\n");
    scanf("%d",&nuevoPokemon.nro);

    printf("\nIngrese el tipo de su pokemon\n");
    fflush(stdin);
    scanf("%s",&nuevoPokemon.tipo);

    printf("\nIngrese el nombre de su pokemon\n");
    fflush(stdin);
    scanf("%s",&nuevoPokemon.nombre);

    for(int i = 0; i < 4; i++){
        printf("\nIngrese el ataque nro %d\n",i+1);
        fflush(stdin);
        scanf("%s",&nuevoPokemon.ataques[i]);
    }
}
