#include <stdio.h>
#include <stdlib.h> 
#define debug(args...) printf(args)

int separa(int v[], int ini, int fim)
{
    int i = ini, f = fim, pivo = v[ini];

    while(i < f) {
        while (v[f] > pivo && i < f) f--;
        if (f > i) v[i] = v[f];
        while (v[i] <= pivo && i < f) i++;
        if (f > i) v[f] = v[i];
    }

    v[i] = pivo;
    return i;
}

void quickSort(int v[], int inicio, int fim)
{
    int meio;

    if (fim > inicio) {
        meio = separa(v, inicio, fim);
        quickSort(v, inicio, meio - 1);
        quickSort(v, meio + 1, fim);
    }
}

int busca(int v[],int i, int n, int x)
{
    int j;
    for (j = i; j < n; j++)
        if(v[j] == x) return j; 
}

int * trocaVetor(int v[], int n) 
{
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
    
    /*for(i = 0; i < n; i++)
        printf("%d ", w[i]);
    printf("\n");*/

    return(w);
}

void imprimeVetor(int v[], int n) 
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void troca (int v[], int i, int j) 
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void sort(int v[], int n) 
{
    int i, j, trocou, ok, * coordenadas, trocas = 0, * aux, * ordenado, * aux2;
    ok = 1;
    
    if (n % 2) {
        coordenadas = malloc(n * n * sizeof(int));
        ordenado = malloc(n * sizeof(int));
        aux = malloc(n * sizeof(int));
        aux2 = malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
            aux2[i] = v[i];
        quickSort(aux2, 0, n - 1);
        ordenado = trocaVetor(aux2, n);
        aux = trocaVetor(v, n);

        for (i = 0; i < n; i++) {
            if(v[i] != ordenado[i]) {
                j = busca(v, i + 1, n, ordenado[i]);
                while(j != i + 1) {
                    troca(v, j, j - 1);
                    coordenadas[trocas++] = ((j - 1)* 2) % n;
                    j--;
                }
            }
        }
        for (i = 0; i < trocas; i++) {
            printf("%d\n", coordenadas[i]);
        }
    }
    else{
        /*utilizo um bubble sort para ordenar o vetor com os numeros nos indices pares 
        e o vetor com os numeros nos indices impares*/
        coordenadas = malloc((n * n / 2) * sizeof(int));
        trocou = 1;
        
        while (trocou) {
            trocou = 0;
            for(j = 0; j < n - 2; j += 2) {
                if (v[j + 2] < v[j]) {
                    troca(v, j + 2, j);
                    coordenadas[trocas++] = j;
                    trocou = 1;
                }
            }
            for(j = 1; j < n - 2; j += 2) {
                if (v[j + 2] < v[j]) {
                    troca(v, j + 2, j);
                    coordenadas[trocas++] = j;
                    trocou = 1;
                }
            }
        }
        for (i = 1; i < n && ok; i++)
            if(v[i] < v[i - 1])
                ok = 0;

        if (ok) {
            imprimeVetor(coordenadas, trocas);
            printf("vetor ordenado\n");
            imprimeVetor(v, n);

        }
        else {
            printf("impossivel\n");
        }


    }
    free(coordenadas);
}

/*por enquanto só funciona com vetor de tamanho par*/
int main(int argc, char const *argv[])
{
    int * v, n, i;
    
    scanf("%d", &n);

    v = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    sort(v, n);
    return 0;
}