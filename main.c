#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "kokemones.h"
#include "pokedex.h"
#include "mochila.h"

pokemonEnEquipo * menuKokemones(pokemonEnEquipo *);
pokedex * menuPokedex();
void menuMochila();

int main()
{
    pokedex * arbolPokedex = inicPokedex();
    pokemonEnEquipo * equipo = inicListaEquipo();
    mochila mochilita[3];
    mochilita = inicMochila();
    char control = 's', control2 = 's';
    int opcion = 0;

    printf("Bienvenido al sistema kokemones, Ingresalos a todos!\n\n");
    printf("Deseas Utilizar los datos cargados previamente en los archivos, no ingrese s si no hay datos cargados previamente\n");
    fflush(stdin);
    scanf("%c",&control2);

    if(control2 == 's'){
        printf("Tenes un equipo guardado? (s/n)\n");
        fflush(stdin);
        scanf("%c",&control2);
        if(control2 == 's'){
            equipo = leerArchivoEquipo(equipo);
        }

        printf("Tenes kokemones guardados en la pokedex? (s/n)\n");
        fflush(stdin);
        scanf("%c",&control2);
        if(control2 == 's'){
            arbolPokedex = leerPokedex(arbolPokedex);
        }

        printf("Tenes items guardados en la mochila? (s/n)\n");
        fflush(stdin);
        scanf("%c",&control2);
        if(control2 == 's'){
            //leerMochila(mochilita);
        }
    }

    while(control == 's'){

        printf("\nMenu Principal\n\n");
        printf("1. Menu Mi Equipo\n2. Menu Pokedex\n3. Menu Mochila\n4. Guardar Cambios\n0. Salir \n\nIngresa el numero del menu que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
        case 1:
            equipo = menuKokemones(equipo);
            break;
        case 2:
            arbolPokedex = menuPokedex(equipo,arbolPokedex);
            break;
        case 3:
            menuMochila();
            break;
        case 4:
            cargarArchivoEquipo(equipo);
            cargarArchivoPokedex(arbolPokedex);
            //cargarMochila(mochilita);
           printf("\nGuardando cambios ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
            printf("\nSe ha guardado con exito, ahora los archivos estan actualizados\n");
            Sleep(1000);
           break;
        case 0:
            control = 'n';
            printf("\nSaliendo del menu principal y cerrando el programa ");
            for(int i = 0; i < 3; i++){
                Sleep(600);
                printf(".");
            }
            printf("\n");
            break;
        default:
            printf("\nOpcion no valida\n");
            break;
        }
    }


    return 0;
}

pokemonEnEquipo * menuKokemones(pokemonEnEquipo * equipo){
    int opcion = 0;
    char control = 's';
    stats estadisticas;
    char aBorrar [20];
    char aMostrar[20];

    while(control == 's'){
        printf("\nMenu Mi Equipo\n\n");
        printf("1. Ingresar equipo\n2. Modificar kokemon\n3. Mostrar equipo \n4. Mostrar un kokemon \n5. Borrar kokemon \n6. Guardar cambios\n0. Salir \n\nIngresa el numero de la funcion que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                equipo = cargarEquipo(equipo);
                break;
            case 2:
                equipo = modificarPokemones(equipo);
                break;
            case 3:
                mostrarEquipo(equipo);
                break;
            case 4:
                printf("\n\nIngrese el nombre del kokemon a mostrar (kokemon que este en tu equipo)\n");
                fflush(stdin);
                scanf("%s",&aBorrar);
                mostrarPokemonEquipo(aBorrar, equipo);
                break;
            case 5:
                printf("\nIngrese el nombre del kokemon a borrar\n");
                fflush(stdin);
                scanf("%s",&aBorrar);
                equipo = borrarPokemon(aBorrar,equipo);
                break;
            case 6:
                cargarArchivoEquipo(equipo);
                printf("\nGuardando cambios ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
                printf("\nSe ha guardado con exito, ahora los archivos estan actualizados\n");
                Sleep(1000);
                break;
            case 0:
                control = 'n';
                printf("\nSaliendo del menu mi equipo ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
                printf("\n");
                break;
            default:
                printf("Numero ingresado no valido\n");
                break;
        }
    }
    return equipo;
}

pokedex * menuPokedex(pokemonEnEquipo * equipo, pokedex * arbolPokedex){
    int opcion = 0, encontrado = 0, nro = 0, aBuscar;
    char control = 's';
    pokemon nuevo;
    char aModificar[20];

    while(control == 's'){
        printf("\nMenu Kokedex\n\n");
        printf("1. Agregar kokemon\n2. Modificar kokemon\n3. Mostrar kokedex \n4. Buscar un kokemon\n5. Guardar cambios\n0. Salir del menu kokedex \n\nIngresa el numero de la funcion que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                nuevo = cargarPokemonPokedex();
                arbolPokedex = insertarNodoPokedex(arbolPokedex,nuevo);
                break;
            case 2:
                printf("\nIngrese el nombre del kokemon a modificar\n");
                fflush(stdin);
                scanf("%s",&aModificar);
                arbolPokedex = modificarPokemonEnPokedex(aModificar,arbolPokedex);
                break;
            case 3:
                printf("\n---->Mostrando kokedex<----\n");
                mostrarPokedex(arbolPokedex);
                break;
            case 4:
                printf("\nIngrese el nro del kokemon a buscar\n");
                scanf("%d",&nro);
                printf("\n");
                aBuscar = buscarEnPokedex(nro,arbolPokedex);
                if(aBuscar == 0){
                    printf("kokemon encontrado con exito!\n");
                }else{
                    printf("No se ha encontrado al kokemon");
                }
                break;
            case 5:
                cargarArchivoPokedex(arbolPokedex);
                printf("\nGuardando cambios ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
                printf("\nSe han guardado con exito, ahora los archivos estan actualizados\n");
                break;
            case 0:
                control = 'n';
                printf("\nSaliendo del menu kokedex ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
                Sleep(1000);
                printf("\n");
                break;
            default:
                printf("\nNumero ingresado no valido\n");
            break;
        }
    }

    return arbolPokedex;
}

void menuMochila(mochila mochilita[3]){
    int opcion = 0;
    char control = 's';
    char nuevoItem[2][20];
    items * listaItems = inicListaItems();
    items * nuevoItemNodo;
    char aMostrar[20];
    char aBorrar[20];

    while(control == 's'){
        printf("\nMenu Mochila\n\n");
        printf("1. Agregar Item\n2. Modificar item\n3. Mostrar items \n4. Mostrar los items de una categoria\n5. Guardar cambios\n6. Borrar Item\n0. Salir del menu kokedex \n\nIngresa el numero de la funcion que deseas usar\n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                cargarNuevoItem(nuevoItem);
                nuevoItemNodo = crearNodoItem(nuevoItem);
                agregarItemMochila();
                break;
            case 2:
                printf("\nIngrese el nombre del item a modificar\n");
                fflush(stdin);
                scanf("%s",&aModificar);
                arbolPokedex = modificarPokemonEnPokedex(aModificar,arbolPokedex);
                break;
            case 3:
                printf("\n---->Mostrando mochila<----\n\n");
                mostrarmochila(mochilita);
                break;
            case 4:
                printf("\nIngrese el nombre de la categoria a mostrar\n");
                scanf("%s",&aMostrar);
                printf("\n");

                buscarEnMochila(aMostrar,mochilita);

                break;
            case 5:
                cargarMochilaAArchivo(mochila);
                printf("\nGuardando cambios ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
                printf("\nSe han guardado con exito, ahora los archivos estan actualizados\n");
                break;
            case 6:
                printf("\nIngrese el nombre del item a borrar\n");
                scanf("%s",&aBorrar);
                printf("\n");
                break;
            case 0:
                control = 'n';
                printf("\nSaliendo del menu mochila ");
                for(int i = 0; i < 3; i++){
                    Sleep(600);
                    printf(".");
                }
                Sleep(1000);
                printf("\n");
                break;
            default:
                printf("\nNumero ingresado no valido\n");
            break;
        }
    }
}
