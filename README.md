# Proyecto kokemones

# Integrantes:
- Emanuel Cacheda
- Federico Lanci
- Mariela Valentini

# Work Daily

# 27/10
Formación del equipo de trabajo;

# 28/10
Elección de la temática a desarrollar;

# 03/11
Reunión de grupo por zoom, elección de estructuras, distribución de tareas;

# 04/11

Se crearon las siguientes estructuras:
- pokemon
- pokedex
- mochila
- items
- pokemonEnEquipo
- stats

Se creó la librería pokemonEnEquipo.

Se crearon las siguientes funciones en kokemones.c:

- void cargarArchivoEquipo(pokemonEnEquipo *);
- pokemonEnEquipo * inicListaEquipo();
- pokemonEnEquipo * crearNodoEquipo(stats);
- pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo *);
- pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo *, pokemonEnEquipo *);

# 05/11

Se crearon los siguientes archivos:

- pokedex.c
- mochila.c

Se crearon las siguientes librerías:

- pokedex.h
- mochila.h

# 06/11

Se actualizó la estructura stats por ser muy engorrosa para el usuario ingresar tantos datos.

Se crearon las siguientes funciones:

- stats cargarPokemon();
- pokemonEnEquipo * cargarEquipo(pokemonEnEquipo * equipo);

Dentro de la funcion cargarEquipo() se llamaron a varias funciones sin definir que se deben hacer para su correcto funcionamiento:

- int buscarEnPokedex(stats): recibe los stats de un determinado pokemon, lo busca en la pokedex y retorna -1 si no lo encuentra
- void agregarDeEquipoAPokedex(stats): recibe los stats de un determinado pokemon y lo agrega al arbol

# 13/11

Se crearon las siguientes funciones:

- stats cargarPokemon();
- void mostrarEquipo(pokemonEnEquipo *);
- void mostrarPokemon(stats);

# 15/11

Se modificaron las importaciones entre archivos

Se crearon las siguientes funciones en kokemones.c

- pokemonEnEquipo * modificarPokemon(pokemonEnEquipo * , char *, pokedex * );
- pokemonEnEquipo * modificarPokemon(pokemonEnEquipo * , char *, pokedex * );
- pokemonEnEquipo * modificarStat(pokemonEnEquipo * );
- pokemonEnEquipo * borrarPokemon(char *, pokemonEnEquipo * );

Se crearon las siguientes funciones en pokedex.c

- pokedex * modificarPokemonEnPokedex(pokemon, pokedex *);
- pokedex * insertarNodoPokedex(pokedex *, pokemon);
- pokedex * inicPokedex();
- pokedex * crearNodoPokedex();
- int buscarEnPokedex(pokemon, pokedex *);
- pokedex * leerPokedex(pokedex * );
- void cargarArchivoPokedex(pokedex * );
- int leerYpasarAArreglo(pokedex * , pokemon *, int );

# 16/11

Se creó el menu principal y los menúes para las 3 estructuras principales

Se crearon las siguientes funciones en main.c:
- pokemonEnEquipo * menuKokemones(pokemonEnEquipo *);
- pokedex * menuPokedex();
- void menuMochila(mochila *);

Se definieron las siguientes funciones en mochila.h:
- void inicMochila(mochila *);
- items * inciListaItems();
- void cargarMochilaAArchivo(mochila);
- void leerMochila(mochila);

Se modificó la estructura items:

typedef struct {
    char nombre[20];
    char tipo[20];
    struct items * sig;
} items;

Se solucionaron diversos errores en las funciones de kokemones.c y pokedex.c, en el proceso se modificaron parámetros y retornos de varias funciones.
Quedando asi las definiciones de las funciones de kokemonex.h y pokedex.h:

Funciones kokemones.h:
- void mostrarEquipo(pokemonEnEquipo *);
- void mostrarPokemon(stats);
- void cargarArchivoEquipo(pokemonEnEquipo *);
- void mostrarPokemonEquipo(char aMostrar[20], pokemonEnEquipo * equipo);
- pokemonEnEquipo * inicListaEquipo();
- pokemonEnEquipo * crearNodoEquipo(stats);
- pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo *);
- pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo *, pokemonEnEquipo *);
- pokemonEnEquipo * cargarEquipo(pokemonEnEquipo *);
- pokemonEnEquipo * modificarPokemones(pokemonEnEquipo * lista);
- pokemonEnEquipo * modificarPokemon(pokemonEnEquipo * lista, char aModificar[20]);
- pokemonEnEquipo * modificarStat(pokemonEnEquipo * );
- pokemonEnEquipo * borrarPokemon(char *, pokemonEnEquipo * );
- stats cargarPokemon();

Funciones pokedex.h:
- pokedex * modificarPokemonEnPokedex(char *, pokedex * );
- pokedex * insertarNodoPokedex(pokedex *, pokemon);
- pokedex * inicPokedex();
- pokedex * crearNodoPokedex();
- int buscarEnPokedex(int, pokedex *);
- pokedex * leerPokedex(pokedex * );
- void cargarArchivoPokedex(pokedex * );
- int leerYpasarAArreglo(pokedex * , pokemon *, int );
- pokemon cargarPokemonPokedex();











