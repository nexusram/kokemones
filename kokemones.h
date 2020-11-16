#ifndef KOKEMONES_H_INCLUDED
#define KOKEMONES_H_INCLUDED
#include "pokedex.h"
#include "mochila.h"

//estructuras pokemones
typedef struct{
    int nro;
    char nombre[30];
    char tipo[15];
    int nivel;
    char ataques[4][20];
    int cantAtaques;
} stats;

typedef struct{
    stats estadisticas;
    struct pokemonEnEquipo * sig;
} pokemonEnEquipo;

void mostrarEquipo(pokemonEnEquipo *);
void mostrarPokemon(stats);
void cargarArchivoEquipo(pokemonEnEquipo *);
void mostrarPokemonEquipo(char aMostrar[20], pokemonEnEquipo * equipo);
pokemonEnEquipo * inicListaEquipo();
pokemonEnEquipo * crearNodoEquipo(stats);
pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo *);
pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo *, pokemonEnEquipo *);
pokemonEnEquipo * cargarEquipo(pokemonEnEquipo *);
stats cargarPokemon();

pokemonEnEquipo * modificarPokemones(pokemonEnEquipo * lista);
pokemonEnEquipo * modificarPokemon(pokemonEnEquipo * lista, char aModificar[20]);
pokemonEnEquipo * modificarStat(pokemonEnEquipo * );
pokemonEnEquipo * borrarPokemon(char *, pokemonEnEquipo * );

#endif // KOKEMONES_H_INCLUDED
