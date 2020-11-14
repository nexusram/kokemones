#ifndef KOKEMONES_H_INCLUDED
#define KOKEMONES_H_INCLUDED

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

//estructuras mochila
typedef struct {
    char nombre[20];
    struct items * sig;
} items;

typedef struct{
    char tipo[30];
    items * lista;
} mochila;

//estructuras pokedex
typedef struct{
    int nro;
    char nombre[30];
    char tipo[15];
}pokemon;

typedef struct{
    pokemon dato;
    struct pokedex * izq;
    struct pokedex * der;
} pokedex;

void mostrarEquipo(pokemonEnEquipo *);
void mostrarPokemon(stats);
void cargarArchivoEquipo(pokemonEnEquipo *);
pokemonEnEquipo * inicListaEquipo();
pokemonEnEquipo * crearNodoEquipo(stats);
pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo *);
pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo *, pokemonEnEquipo *);
pokemonEnEquipo * cargarEquipo(pokemonEnEquipo *);
stats cargarPokemon();

#endif // KOKEMONES_H_INCLUDED
