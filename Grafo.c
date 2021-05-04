/*implementação de grafo usando uma lista adjacente*/
#include<stdio.h>
#include <stdlib.h>

typedef struct adjacente{
    int peso;
    int vertice;
    struct adjacente *prox;
}adjacente;

typedef struct vertice{
    adjacente *cab;
}vertice;

typedef struct grafo{
    int aresta;
    int vertice;
    vertice *adj;
}grafo;

void imprimirgrafo(grafo *g)
{
    if (g == NULL ) printf("Vertice -> NULL\n");
    else{
        printf("Vértices: %d ---- Aréstas %d. \n", g->vertice, g->aresta);
        for (int i = 0; i < g->vertice; i++)
        {
            printf("V(%d)-> ", i);
            adjacente *adj = g->adj[i].cab;
            while (adj != NULL)
            {
                printf("(V%d , Peso(%d))", adj->vertice, adj->peso);
                adj = adj->prox;
            }
            printf("\n");
        }
    }
}

adjacente *cria_adjacente(int peso, int v){

    adjacente *temp; 
    temp = (adjacente*) malloc(sizeof(adjacente));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}

int cria_aresta(grafo *g, int vi, int vf, int p) /*aresta dirigida*/
{
    /*condições de existencia*/   
    if (!g) return 0;
    if ((vf< 0) || (vf >=  g->vertice))  return 0;
    if( (vi < 0) || (vi >= g->vertice)) return 0;
    adjacente *novo; 
    novo = cria_adjacente(p, vf);
    novo->prox = g->adj[vi].cab;
    g->adj[vi].cab = novo;
    g->aresta++;
    return 1;
}

grafo *inicializando_grafo(int v)
{
    grafo *g;
    g = (grafo*) malloc(sizeof(grafo));

    g->vertice = v;
    g->aresta = 0;
    g->adj = (vertice*) malloc(v*sizeof(vertice));
    int i;
    for (i = 0; i < v; i++)
    {
        g->adj[i].cab = NULL;
    }
    return g;    
}

int main()
{
    grafo *g = inicializando_grafo(5);
    cria_aresta(g, 0, 1, 2);
    cria_aresta(g, 1, 2, 4);
    cria_aresta(g, 2, 0, 12);
    cria_aresta(g, 2, 4, 40);
    cria_aresta(g, 3, 1, 3);
    cria_aresta(g, 4, 3, 8);

    imprimirgrafo(g);
    return 0;
}
