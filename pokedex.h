#ifndef POKEDEX_H_INCLUDED
#define POKEDEX_H_INCLUDED

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

pokedex * modificarPokemonEnPokedex(pokemon, pokedex *);
pokedex * insertarNodoPokedex(pokedex *, pokemon);
pokedex * inicPokedex();
pokedex * crearNodoPokedex();
int buscarEnPokedex(pokemon, pokedex *);

#endif // POKEDEX_H_INCLUDED
