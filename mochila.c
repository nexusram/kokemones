#include "mochila.h"
#include <stdlib.h>
#include <stdio.h>

void inicMochila(mochila arr[3]){
    for(int i = 0; i < 3; i++){
        arr[i]->lista = inicListaItems;
    }
}

items * inicListaItems(){
    return NULL;
}
