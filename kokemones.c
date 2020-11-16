#include "kokemones.h"
#include "pokedex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        while(aux != NULL){
            dato = aux->estadisticas;
            fwrite(&dato,sizeof(stats),1,parch);
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

pokemonEnEquipo * cargarEquipo(pokemonEnEquipo * equipo, pokedex * arbolPokedex){

    char control = 's';
    int enPokedex = 0;
    pokemonEnEquipo * nuevo;
    stats dato;
    pokemon abuscar;
    while(control == 's'){

        dato = cargarPokemon();
        nuevo = crearNodoEquipo(dato);

        abuscar.nro = dato.nro;
        strcpy(abuscar.nombre,dato.nombre);
        strcpy(abuscar.tipo,dato.tipo);

        enPokedex = buscarEnPokedex(abuscar,arbolPokedex);

        if(enPokedex == -1){
           arbolPokedex = insertarNodoPokedex(arbolPokedex,abuscar);
        }

        equipo = agregarPpioEquipo(equipo,nuevo);

        printf("\nDesea ingresar otro pokemon?\n");
        fflush(stdin);
        scanf("%c",&control);
    }

    printf("\nDeseas guardar este equipo en el archivo? (s/n)");
    printf("\nSe borrara el equipo que tenias guardado antes\n");
    fflush(stdin);
    scanf("%c",&control);

    if(control == 's'){
        cargarArchivoEquipo(equipo);
    }

    return equipo;
}

stats cargarPokemon(){
    stats nuevoPokemon;
    char control = 's';

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

    printf("\nIngrese la cantidad de ataques de su pokemon\n");
    scanf("%d",&nuevoPokemon.cantAtaques);

    for(int i = 0; i < nuevoPokemon.cantAtaques; i++){
        printf("\nIngrese el ataque nro %d\n",i+1);
        fflush(stdin);
        scanf("%s",&nuevoPokemon.ataques[i]);
    }

    return nuevoPokemon;
}

void mostrarEquipo(pokemonEnEquipo * lista){
    pokemonEnEquipo * aux;
    int i = 1;

    while(aux!=NULL){
        printf("\n------->Mostrando al pokemon numero %d de tu equipo<-------\n\n", i);
        mostrarPokemon(aux->estadisticas);
        aux = aux->sig;
        i++;
    }
}

void mostrarPokemon(stats estadisticas){
    printf("Nombre: %s\n",estadisticas.nombre);
    printf("Nro: %d\n",estadisticas.nro);
    printf("Cantidad de ataques: %d\n",estadisticas.cantAtaques);
    printf("Nivel: %d\n",estadisticas.nivel);
    printf("Tipo: %s\n",estadisticas.tipo);
    printf("Ataques: \n");

    for(int i = 0; i < estadisticas.cantAtaques; i++){
        printf("- %s\n",estadisticas.ataques[i]);
    }
}

pokemonEnEquipo * modificarPokemones(pokemonEnEquipo * lista, pokedex * arbolPokedex){
    char aModificar[20];

    printf("Estos son los pokemones que tenes en tu equipo\n");
    mostrarEquipo(lista);

    printf("Escribe el nombre del pokemon a modificar\n");
    fflush(stdin);
    scanf("%s",&aModificar);

    lista = modificarPokemon(lista, aModificar, arbolPokedex);

    return lista;
}

pokemonEnEquipo * modificarPokemon(pokemonEnEquipo * lista, char aModificar[20], pokedex * arbolPokedex){
    pokemonEnEquipo * aux = lista;
    int j = 0, opcion = 0;

    if(lista==NULL){
        printf("No hay pokemones en el equipo\n");
    }else{
        while(aux!=NULL && strcmp(aux->estadisticas.nombre, aModificar) != 0){
            aux = aux->sig;
        }
    }

    if(aux!=NULL){
        printf("El pokemon fue encontrado exitosamente\n");

        mostrarPokemon(aux->estadisticas);

        aux = modificarStat(aux);

        pokemon amodificarPokemon;
        amodificarPokemon.nro = aux->estadisticas.nro;
        strcpy(amodificarPokemon.nombre,aux->estadisticas.nombre);
        strcpy(amodificarPokemon.tipo,aux->estadisticas.tipo);

        arbolPokedex = modificarPokemonEnPokedex(amodificarPokemon, arbolPokedex);

    }else{
        printf("El pokemon no se encuentra en tu equipo :( \n");
    }

    return lista;
}

pokemonEnEquipo * modificarStat(pokemonEnEquipo * aux){

        int opcion = 0,i,j;

        printf("Que queres cambiarle?\n");
        printf("1. Nombre\n2.Ataques\n3.Tipo\n4.Nivel\n5.Agregar ataque\n");

        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            printf("Ingrese el nuevo nombre\n");
            fflush(stdin);
            scanf("%s",&aux->estadisticas.nombre);
            break;
        case 2:
            printf("Tienes %d ataques, cual queres modificar?\n", aux->estadisticas.cantAtaques);
            for(i = 0; i < aux->estadisticas.cantAtaques; i++){
                printf("%d. %s\n", i+1, aux->estadisticas.ataques[i]);
            }

            scanf("%d",&j);

            printf("Ingrese el nuevo ataque\n");
            fflush(stdin);
            scanf("%s",&aux->estadisticas.ataques[j-1]);
            break;
        case 3:
            printf("Ingrese el nuevo tipo\n");
            fflush(stdin);
            scanf("%s",&aux->estadisticas.tipo);
            break;
        case 4:
            printf("Ingrese el nuevo nivel\n");
            fflush(stdin);
            scanf("%s",&aux->estadisticas.nivel);
            break;
        case 5:
            if(aux->estadisticas.cantAtaques < 4){
                printf("Ingrese el nuevo ataque\n");
                fflush(stdin);
                scanf("%s",&aux->estadisticas.ataques[aux->estadisticas.cantAtaques-1]);
            }
            break;
        default:
            printf("Numero ingresado no valido, saliendo de la funcion");
            break;
        }
    return aux;
}

pokemonEnEquipo * borrarPokemon(char nombre[20], pokemonEnEquipo * lista){

    pokemonEnEquipo * seg;
    pokemonEnEquipo * ante;

    if((lista != NULL) && (strcmp(nombre, lista->estadisticas.nombre)==0 )) {
        pokemonEnEquipo * aux = lista;
        lista = lista->sig;
        free(aux);
    }else {
      seg = lista;
      while((seg != NULL) && (strcmp(nombre, seg->estadisticas.nombre)!=0 )) {
         ante = seg;
         seg = seg->sig;
      }
      if(seg!=NULL) {
         ante->sig = seg->sig;
         free(seg);
      }
    }

   return lista;
}
