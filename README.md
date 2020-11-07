# Proyecto kokemones

Integrantes:
- Emanuel Cacheda
- Federico Lanci
- Mariela Valentini

# Work Daily

# 4/11

Se crearon las siguientes estructuras:
- pokemon
- pokedex
- mochila
- items
- pokemonEnEquipo
- stats

- Se creó la librería pokemonEnEquipo.

Se crearon las siguientes funciones en kokemones.c:
- void cargarArchivoEquipo(pokemonEnEquipo *);
- pokemonEnEquipo * inicListaEquipo();
- pokemonEnEquipo * crearNodoEquipo(stats);
- pokemonEnEquipo * leerArchivoEquipo(pokemonEnEquipo *);
- pokemonEnEquipo * agregarPpioEquipo(pokemonEnEquipo *, pokemonEnEquipo *);

# 5/11

Se crearon los siguientes archivos:
- pokedex.c
- mochila.c

Se crearon las siguientes librerías:
- pokedex.h
- mochila.h

# 6/11

- Se actualizó la estructura stats por ser muy engorrosa para el usuario ingresar tantos datos.

Se crearon las siguientes funciones:
- stats cargarPokemon();
- pokemonEnEquipo * cargarEquipo(pokemonEnEquipo * equipo);

Dentro de la funcion cargarEquipo() se llamaron a varias funciones sin definir que se deben hacer para su correcto funcionamiento:
- int buscarEnPokedex(stats): recibe los stats de un determinado pokemon, lo busca en la pokedex y retorna -1 si no lo encuentra 
- void agregarDeEquipoAPokedex(stats): recibe los stats de un determinado pokemon y lo agrega al arbol


