#include <stdio.h>
#include "grafo.h"

//------------------------------------------------------------------------------
const unsigned int max_nome = 1024;

//------------------------------------------------------------------------------
// escreve l em output na forma
//
// (x_1, ..., x_n)
//
// onde x_i: 1 <= i <= n são os elementos de l

static Lista escreve_lista(FILE *output, Lista l) {

  fprintf(output, "(");

  for ( No n=primeiro_no(l); n; n=proximo_no(n) ) {

    fprintf(output, "%s", nome(vert(n)));
        
    if ( proximo_no(n) )

      fprintf(output, ", ");
  }
        
  fprintf(output, ")\n");

  return l;
}
//------------------------------------------------------------------------------
// escreve g em output na forma
//
// v_1: l_1
// v_2: l_2
// ...
// v_n: l_n
//
// onde v_i: 1 <= i <= n são os vértices de g e l_i: 1 <= i <= n é a lista de 
// vizinhos de v_i tal como escrita por escreve_lista()

static Grafo escreve_grafo(FILE *output, Grafo g) {

  for ( No n=primeiro_no(vertices(g)); n; n=proximo_no(n) ) {

    fprintf(output, "%s: ", nome(vert(n)));

    escreve_lista(output, vizinhanca(vert(n)));
  }
  
  return g;
}
//------------------------------------------------------------------------------
// lê um grafo sem vértices isolados em input e devolve um 'grafo'
// que o representa
//
// o grafo é lido como uma sequência de arestas, sem repetições
//
// cada aresta é um par vértices separados por brancos
//
// cada vértice é uma 'string' sem brancos
//
// não é feita nenhuma checagem de consistência quanto à entrada

static Grafo le_grafo(FILE *input) {

  Grafo g = cria_grafo();

  if ( ! g )

    return NULL;

  char u[max_nome], v[max_nome];

  while ( fscanf(input, "%s %s", u, v) == 2 )

    if ( ! poe_aresta(g, acha_vertice(g,u,1), acha_vertice(g,v,1)) ) {

      destroi_grafo(g);

      return NULL;
    }

  return g;
}
//------------------------------------------------------------------------------
int main(void) {

  return ! destroi_grafo(escreve_grafo(stdout, le_grafo(stdin)));
}
