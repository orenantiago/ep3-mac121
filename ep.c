#include <stdio.h>
#include <stdlib.h> 
#define debug(args...) printf(args)

void troca(int v[], int n) {
    int aux, *w, cont, i, nmaiores;
    w = malloc(n * sizeof(int));
    cont = 0;
    aux = 0;
    
    while(cont < n) {
        w[cont] = v[aux];
        cont++;
        aux = (aux + 2) % n;
    }

    cont = 0;
    aux = 0;
    

    for(i = 0; i < n; i++)
        printf("%d ", w[i]);
    printf("\n");

    free(w);
}

void sort();

int main(int argc, char const *argv[])
{
    int v[7] = {1, 7, 4, 3, 2, 5, 6};
    troca(v, 7);
    return 0;
}