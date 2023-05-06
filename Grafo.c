#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grafo.h"

/* INICIO ESTRUTURAS E FUNCOES RELATIVAS AO GRAFO */

no * criarNo(char * nome) {
  no * novoNo = (no * ) malloc(sizeof(no));
  strcpy(novoNo -> nomeVertice, nome);
  novoNo -> prox = NULL;
  return novoNo;
}

Grafo * criarGrafo(int vertices) {
  Grafo * grafo = (Grafo * ) malloc(sizeof(Grafo));
  grafo -> numVertices = vertices;
  grafo -> listaAdj = (struct no ** )
  malloc(vertices * sizeof(struct no * ));
    grafo -> visitado = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; i++) {
    grafo -> listaAdj[i] = NULL;
    grafo -> visitado[i] = 0;
  }
  return grafo;

}

int listasOcupadas(Grafo * grafo) {
  int i, j = 0;
  for (i = 0; i < grafo -> numVertices; i++) {
    if (grafo -> listaAdj[i] != NULL)
      j++;
  }
  return j;

}

int buscarVertice(char * nome, Grafo * grafo) {
  for (int i = 0; i < listasOcupadas(grafo); i++) {
    // printf("total listas ocupadas: %d", listasOcupadas(grafo));
    // printf("iteracao %d\n", i);
    // printf("nome na lista: %s\n", grafo -> listaAdj[i] -> nomeVertice);
    // printf("nome sendo usado p busca: %s\n", nome);
    if (strcmp(grafo -> listaAdj[i] -> nomeVertice, nome) == 0)
      return i;
  }
  return -1;
}

void adicionarConexao(Grafo * grafo, char * v1, char * v2) {
  int p = buscarVertice(v1, grafo);
  int n = listasOcupadas(grafo);

  if (p == -1) {
    grafo -> listaAdj[n] = criarNo(v1);
    grafo -> listaAdj[n] -> prox = criarNo(v2);
    printf("criou %s\n", grafo -> listaAdj[n] -> prox);
  } else {
    no * noatual = grafo -> listaAdj[p];
    while (noatual != NULL) {
      if (noatual -> prox == NULL) {
        noatual -> prox = criarNo(v2);
        break;
      }
      noatual = noatual -> prox;
    }
  }
}

void imprimirGrafo(Grafo * grafo) {
  for (int i = 0; i < grafo -> numVertices; i++) {
    struct no * temp = grafo -> listaAdj[i];
    if(temp == NULL)
        break;
    printf("\n%s:", grafo -> listaAdj[i] -> nomeVertice);
    while ((temp -> prox) != NULL) {
      printf("%s->", temp -> prox -> nomeVertice);
      temp = temp -> prox;
    }
    printf("NULL\n");
  }
}

void destruirGrafo(Grafo * grafo) {
  for (int i = 0; i < grafo -> numVertices; i++) {
    no * temp = grafo -> listaAdj[i];
    while (temp != NULL) {
      no * p = temp;
      temp = temp -> prox;
      free(p);
    }
  }
  free(grafo -> listaAdj);
  free(grafo);
}

/* FIM ESTRUTURAS E FUNCOES RELATIVAS AO GRAFO */