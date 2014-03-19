#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  no inicio;
  int tam;
} *lista;
//------------------------------------------------------------------------------
typedef struct no {
  vertice vertice;
  struct no *proximo;
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
    g->vertices = aloca_lista();
    return g;
  }
  
  printf("Erro ao criar grafo.\n");
  return NULL;
}
//------------------------------------------------------------------------------
int destroi_grafo(grafo g) {
  if (destroi_lista(g->vertices) != 1) {
    printf("Erro ao desalocar lista.\n");
    return 0;
  }

  free(g);

  return 1;
}
//------------------------------------------------------------------------------
lista vertices(grafo g) {
  return g->vertices;
}
//------------------------------------------------------------------------------
vertice acha_vertice(grafo g, char *s, int acrescenta) {
  no nodo = g->vertices->inicio;
  while (nodo) {
    if (!strcmp(nodo->vertice->nome, s)) {
      return nodo->vertice;
    }

    nodo = nodo->proximo;
  }

  if (acrescenta != 0) {
    vertice novo_vertice = (vertice) malloc(sizeof(vertice));
    if (!novo_vertice) {
      printf("Erro ao alocar vertice.\n");
      return NULL;
    }

    novo_vertice->nome = (char *) malloc(256*sizeof(char));
    novo_vertice->nome = strcpy(novo_vertice->nome, s);
    novo_vertice->arestas = aloca_lista();

    insere_no(g->vertices, novo_vertice);

  	return novo_vertice;
  }

  printf("Erro ao achar vertice.\n");
  return NULL;
}
//------------------------------------------------------------------------------
grafo poe_aresta(grafo g, vertice u, vertice v) {
  if (insere_arestas(u, v) != 1) {
    printf("Erro ao por aresta.\n");
    return NULL;
  }

  return g;
}

//=============================================================================

int destroi_lista(lista l) {
  no nodo = l->inicio;
  while (nodo) {
    l->inicio = nodo->proximo;
    free(nodo);
    nodo = l->inicio;
    l->tam--;
  }

  if (l->tam != 0) {
    printf("Erro ao destroir lista.\n");
    return 0;
  }

  free(l);

  return 1;
}

int insere_arestas(vertice v, vertice u) {
  if (insere_no(v->arestas, u) != 1) {
    printf("Erro ao inserir aresta.\n");
    return 0;
  }

  if (insere_no(u->arestas, v) != 1) {
    printf("Erro ao inserir aresta.\n");
    return 0;
  }

  return 1;
}

int insere_no(lista l, vertice v) {
  no nodo = (no) malloc(sizeof(no));
  if (!nodo) {
    printf("Erro ao alocar o no.\n");
  }

  nodo->vertice = v;
  nodo->proximo = l->inicio;
  l->inicio = nodo;
  l->tam++;

  return 1;
}

lista aloca_lista(void) {
  lista l = (lista) malloc(sizeof(lista));
  if (!l) {
    printf("Erro ao alocar lista.\n");
    return NULL;
  }

  l->inicio = NULL;
  l->tam = 0;

  return l;
}
