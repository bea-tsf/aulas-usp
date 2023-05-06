#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafo.h"



/* INICIO DFS */

void DFS(Grafo *grafo, char * vertice) {
    int indiceVertice = buscarVertice(vertice, grafo);
    no* listaAdj = grafo->listaAdj[indiceVertice];
    no* temp = listaAdj;

    grafo->visitado[indiceVertice] = 1;
    printf("Visited %s \n", grafo->listaAdj[indiceVertice]->nomeVertice);

    while(temp != NULL) {
        char verticeConectado[LIMITECARACTERES];
        strcpy(verticeConectado, temp->nomeVertice);
        printf("vertice conectado: %s\n", verticeConectado);
        int indiceConectado = buscarVertice(verticeConectado, grafo);
        printf("%d\n", indiceConectado);
        printf("foi visitado? %d\n", grafo->visitado[indiceConectado]);
        if(grafo->visitado[indiceConectado] == 0) {
            printf("chamando dfs de novo");
            DFS(grafo, verticeConectado);
        }
        temp = temp->prox;
    }

}

int main()
{
    
    int Num=4;

    Grafo* grafo = criarGrafo(Num);

    
    adicionarConexao(grafo, "a", "b");
    adicionarConexao(grafo, "a", "c");
    adicionarConexao(grafo, "b", "c");
    adicionarConexao(grafo, "c", "d");
    printf("%lu", sizeof(grafo->listaAdj));

    imprimirGrafo(grafo);
    // printf("\nDFS:\n");
    printf("%d", buscarVertice("d", grafo));
    // DFS(grafo, "c"); por algum motivo o vertice d nao ta sendo alocado na lista
    destruirGrafo(grafo);
    return 0;
}