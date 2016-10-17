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

/*A função recebe um vetor e o transforma em um vetor pulando os índices
dois a dois, também no vetor índices, os indices onde cada valor associado
ocupava originalmente. Exemplo:
v = [1, 2, 3, 4]
Após a função:
    v = [1, 3, 2, 4]
    i = [0, 2, 1, 3]
*/
void transformaVetor(int v[], int n, int indices[]) 
{
    int aux, *w, cont, i, nmaiores;
    w = malloc(n * sizeof(int));
    cont = 0;
    aux = 0;
    
    while(cont < n) {
        w[cont] = v[aux];
        indices[cont++] = aux;
        aux = (aux + 2) % n;
    }
    
    for(i = 0; i < n; i++)
        v[i] = w[i];

    free(w);
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

void ordenacao(int v[], int n) 
{
    int i, j, trocou = 1, ok = 1, * indices, trocas = 0, * ordenado;
    
    if (n % 2) {
        ordenado = malloc(n * sizeof(int));
        indices = malloc(n * sizeof(int));

        for(i = 0; i < n; i++)
            ordenado[i] = v[i];
        quickSort(ordenado, 0, n - 1);
        
        transformaVetor(ordenado, n, indices);
        transformaVetor(v, n, indices);
        while(trocou) {
            for (i = 0; i < n; i++) {
                trocou = 0;
                if(v[i] != ordenado[i]) {
                    j = busca(v, i + 1, n, ordenado[i]);
                    while(j > i) {
                        troca(v, j, j - 1);
                        printf("%d\n", indices[--j]);
                    }
                    trocou = 1;
                }
            }
        }
        free(ordenado);
    }
    else {
        /*utilizo o bubble sort para ordenar o vetor com os numeros nos 
        indices pares e o vetor com os numeros nos indices impares, depois
        verifico se o vetor está ordenado*/
        indices = malloc((n * n / 2) * sizeof(int));
        
        while (trocou) {
            trocou = 0;
            for(j = 0; j < n - 2; j += 2) {
                if (v[j + 2] < v[j]) {
                    troca(v, j + 2, j);
                    indices[trocas++] = j;
                    trocou = 1;
                }
            }
        }
        trocou = 1;
        while(trocou) {
            trocou = 0;
            for(j = 1; j < n - 2; j += 2) {
                if (v[j + 2] < v[j]) {
                    troca(v, j + 2, j);
                    indices[trocas++] = j;
                    trocou = 1;
                }
            }
        }
        for (i = 1; i < n && ok; i++)
            if(v[i] < v[i - 1])
                ok = 0;

        if (ok) {
            for (i = 0; i < trocas; i++) printf("%d\n", indices[i]);
            printf("\n");
        }
        else {
            printf("Impossivel\n");
        }
    }
    free(indices);
}

int main(int argc, char const *argv[])
{
    int * v, n, i;
    
    scanf("%d", &n);

    v = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    ordenacao(v, n);
    return 0;
}