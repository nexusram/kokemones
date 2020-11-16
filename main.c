#include <stdio.h>
#include <stdlib.h>
#include "kokemones.h"
#include "pokedex.h"
#include "mochila.h"

void menuKokemones(pokemonEnEquipo *, pokedex *);
void menuPokedex();
void menuMochila();

int main()
{
    pokedex * arbolPokedex = inicPokedex();
    pokemonEnEquipo * equipo = inicListaEquipo();
    mochila mochilita[3];
    char control = 's', control2 = 's';
    int opcion = 0;

    printf("Deseas Utilizar los datos cargados previamente en los archivos (si es que existen)\n");
    fflush(stdin);
    scanf("%c",&control2);

    if(control2 == 's'){
        equipo = leerArchivoEquipo(equipo);
        arbolPokedex = leer(arbolPokedex);
        leerMochila(mochilita);
    }

    while(control == 's'){

        printf("Menu Principal\n");
        printf("1. Menu Mi Equipo\n2. Menu Pokedex\n 3. Menu Mochila\n 4. Guardar Cambios \n Ingresa el numero del menu que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            menuKokemones(equipo,arbolPokedex);
            break;
        case 2:
            menuPokedex();
            break;
        case 3:
            menuMochila();
            break;
        case 4:
            cargarArchivoEquipo(equipo);
            cargarArchivoPokedex(arbolPokedex);
            cargarMochila(mochilita);
        default:
            printf("Opcion no valida");
            break;
        }

        printf("Deseas hacer otra cosa?\n");
        fflush(stdin);
        scanf("%c",&control);

    }


    return 0;
}

void menuKokemones(pokemonEnEquipo * equipo, pokedex * arbolPokedex){
    int opcion = 0;
    char control = 's';
    stats estadisticas, aBorrar;

    while(control == 's'){
        printf("Menu Mi Equipo\n");
        printf("1. Ingresar equipo\n 2. Modificar pokemon\n 3. Mostrar equipo \n 4. Mostrar un pokemon \n 5. Borrar pokemon \n 6. Guardar cambios \n Ingresa el numero de la funcion que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                equipo = cargarEquipo(equipo,arbolPokedex);
                break;
            case 2:
                equipo = modificarPokemones(equipo);
                break;
            case 3:
                mostrarEquipo(equipo);
                break;
            case 4:
                estadisticas = cargarPokemon();
                mostrarPokemon(estadisticas);
                break;
            case 5:
                aBorrar = cargarPokemon();
                equipo = borrarPokemon(aBorrar,equipo);
                break;
            case 6:
                cargarArchivoEquipo(equipo);
                break;
            default:
                printf("Numero ingresado no valido\n");
                break;
        }

        printf("Deseas hacer otra cosa?\n");
        fflush(stdin);
        scanf("%c",&control);
    }
}

void menuPokedex(pokemonEnEquipo * equipo, pokedex * arbolPokedex){
    int opcion = 0, encontrado = 0;
    char control = 's';
    pokemon nuevo;
    pokemon abuscar;

    while(control == 's'){
        printf("Menu Pokedex\n");
        printf("1. Agregar Pokemon\n 2. Modificar pokemon\n 3. Mostrar pokedex \n 4. Buscar un pokemon\n 5. Guardar cambios \n Ingresa el numero de la funcion que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                arbolPokedex = insertarNodoPokedex(equipo,nuevo);
                break;
            case 2:
                nuevo = cargarPokemonPokedex();
                equipo = modificarPokemones(equipo, nuevo);
                break;
            case 3:
                mostrarPokedex(arbolPokedex);
                break;
            case 4:
                abuscar = cargarPokemonPokedex();
                encontrado = buscarEnPokedex(abuscar,arbolPokedex);
                break;
            case 5:
                cargarArchivoPokedex(arbolPokedex);
                break;
            default:
                printf("Numero ingresado no valido\n");
                break;
        }

        printf("Deseas hacer otra cosa?\n");
        fflush(stdin);
        scanf("%c",&control);
    }
}


