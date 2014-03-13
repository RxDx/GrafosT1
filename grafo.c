#include "grafo.h"

//------------------------------------------------------------------------------
typedef struct grafo {

  // preencha aqui

} *Grafo;
//------------------------------------------------------------------------------
typedef struct vertice {

  // preencha aqui

} *Vertice;
//------------------------------------------------------------------------------
typedef struct lista {
  No inicio;
  int tam;
} *Lista;
//------------------------------------------------------------------------------
typedef struct no {
  int val;
  struct no *proximo;
} *No;
//=============================================================================
No primeiro_no(Lista l) {
  if (l->inicio) {
    return l->inicio;
  }

  return 0;
}
//------------------------------------------------------------------------------
No proximo_no(No n) { 
  if (n->proximo) {
    return n->proximo;
  }

  return 0;
}
//------------------------------------------------------------------------------
Vertice vert(No n) { 

  // preencha aqui
}

//------------------------------------------------------------------------------
char *nome(Vertice v) { 
  
  // preencha aqui
}
//------------------------------------------------------------------------------
Lista vizinhanca(Vertice v) { 
  
  // preencha aqui
}
//------------------------------------------------------------------------------
Grafo cria_grafo(void) {

  // preencha aqui
}
//------------------------------------------------------------------------------
int destroi_grafo(Grafo g) {

  // preencha aqui
}
//------------------------------------------------------------------------------
Lista vertices(Grafo g) { 

  // preencha aqui
}
//------------------------------------------------------------------------------
Vertice acha_vertice(Grafo g, char *s, int acrescenta) {

  // preencha aqui
}
//------------------------------------------------------------------------------
Grafo poe_aresta(Grafo g, Vertice u, Vertice v) {

  // preencha aqui
}

