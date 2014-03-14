#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

//------------------------------------------------------------------------------
typedef struct grafo {
  lista vertices;
} *grafo;
//------------------------------------------------------------------------------
typedef struct vertice {
  char *nome;
  lista arestas;
} *vertice;
//------------------------------------------------------------------------------
typedef struct lista {
  int tam;
  no inicio;
} *lista;
//------------------------------------------------------------------------------
typedef struct no {
  vertice vertice;
  no proximo;
} *no;
//=============================================================================
no primeiro_no(lista l) {
  return l->inicio;
}
//------------------------------------------------------------------------------
no proximo_no(no n) {
  return n->proximo;
}
//------------------------------------------------------------------------------
vertice vert(no n) {
  return n->vertice;
}

//------------------------------------------------------------------------------
char *nome(vertice v) {
  return v->nome;
}
//------------------------------------------------------------------------------
lista vizinhanca(vertice v) {
  return v->arestas;
}
//------------------------------------------------------------------------------
grafo cria_grafo(void) {
  grafo g = (grafo) malloc(sizeof(grafo));
  if (g) {
    g->vertices = (lista) malloc(sizeof(lista));

    return g;
  }
  
  return NULL;
}
//------------------------------------------------------------------------------
int destroi_grafo(grafo g) {
  return 1;
}
//------------------------------------------------------------------------------
lista vertices(grafo g) {
  return g->vertices;
}
//------------------------------------------------------------------------------
vertice acha_vertice(grafo g, char *s, int acrescenta) {
  no v = g->vertices->inicio;
  while (v) {
    if (v->nome == s) {
      return v;
    }

    v = v->proximo;
  }

  if (acrescenta) {
    // insere vertice no grafo
    // retorna vertice
  }

  return NULL;
}
//------------------------------------------------------------------------------
grafo poe_aresta(grafo g, vertice u, vertice v) {

  // preencha aqui
}

