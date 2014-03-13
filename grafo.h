//-----------------------------------------------------------------------------
// grafo

typedef struct grafo *Grafo;

//-----------------------------------------------------------------------------
// vértice de grafo

typedef struct vertice *Vertice;

//-----------------------------------------------------------------------------
// lista encadeada

typedef struct lista *Lista;

//-----------------------------------------------------------------------------
// nó de lista encadeada
 
typedef struct no *No;

//=============================================================================
// devolve o primeiro nó da lista l, ou NULL se l é vazia

No primeiro_no(Lista l);

//------------------------------------------------------------------------------
// devolve o sucessor do nó n na lista encadeada 
// ou NULL se n for o último nó de l

No proximo_no(No n);

//------------------------------------------------------------------------------
// devolve o vertice armazenado em n

Vertice vert(No n);

//------------------------------------------------------------------------------
// devolve o nome do vértice v

char *nome(Vertice v);

//------------------------------------------------------------------------------
// devolve a vizinhança de v

Lista vizinhanca(Vertice v);

//------------------------------------------------------------------------------
// aloca um struct grafo, inicializa-o com um grafo vazio e devolve seu endereço
// ou NULL em caso de erro

Grafo cria_grafo(void);

//------------------------------------------------------------------------------
// desaloca toda a memória usada em g
// 
// devolve 1 em caso de sucesso e 0 caso contrário

int destroi_grafo(Grafo g);

//------------------------------------------------------------------------------
// devolve a lista de vértices de g

Lista vertices(Grafo g);

//------------------------------------------------------------------------------
// devolve o vertice de g que tem nome igual a s
//
// se não existe tal vértice e acrescenta != 0, acrescenta um vertice assim a g
// 
// caso contrário, devolve NULL

Vertice acha_vertice(Grafo g, char *s, int acrescenta);

//------------------------------------------------------------------------------
// acrescenta uma aresta em g ligando os vertices u e v sem verificar se
// u e v já são vizinhos

Grafo poe_aresta(Grafo g, Vertice u, Vertice v);


