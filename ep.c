#include <stdio.h>
#include <stdlib.h> 
#define debug(args...) printf(args)

int * trocaVetor(int v[], int n) {
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

    return(w);
}

void imprimeVetor(int v[], n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void troca (int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void sort(int v[], int n) {
    int * pares, * impares, i, j, k, trocou, ok;
    trocou = 1;
    ok = 1;
    
    if (n % 2 == 0) {
        pares = malloc((n/2) * sizeof(int));
        impares = malloc((n/2) * sizeof(int));
        j = 0;
        
        for (i = 0; i < n; i += 2) {
            pares[j] = v[i];
            impares[j++] = v[i + 1];
        }
        /*utilizo um bubble sort para ordenar o vetor com os numeros nos indices pares 
        e o vetor com os numeros nos indices impares*/
        for (i = 0; i < n / 2 && trocou; i++) {
            trocou = 0;
            for (j = 0; j < (n / 2) - i - 1; j++) {
                if (pares[j] > pares[j + 1]) {
                    troca(pares, j, j + 1);
                    trocou = 1;
                }
                if (impares[j] > impares[j + 1]) {
                    troca(impares, j, j + 1);
                    trocou = 1;
                }
            }
        }

        for (i = 0; i < n / 2 && ok; i++)
            if(pares[i] > impares [i])
                ok = 0;

        if (ok) {
            printf("vetor ordenado\n");
            j = 0;
            for(i = 0; i < n / 2; i++) {
                v[j++] = pares[i];
                v[j++] = impares[i];
            }
            imprimeVetor(v, n);

        }

    }
    //w = trocaVetor(v, n);
    //free(w);
}

int main(int argc, char const *argv[])
{
    int v[7] = {1, 7, 4, 3, 2, 5, 6};
    trocaVetor(v, 7);
    return 0;
}