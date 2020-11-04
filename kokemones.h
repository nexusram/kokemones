#ifndef KOKEMONES_H_INCLUDED
#define KOKEMONES_H_INCLUDED

//estructuras pokemones
typedef struct{
    int nro;
    char nombre[30];
    char tipo[15];
    int nivel;
    char ataque[20][4];
    int hp;
    int atk;
    int def;
    int spd;
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

void cargarArchivoEquipo(pokemonEnEquipo *);
pokemonEnEquipo * inicListaEquipo();
pokemonEnEquipo * crearNodoEquipo(stats);
pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo *);
pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo *, pokemonEnEquipo *);


#endif // KOKEMONES_H_INCLUDED
