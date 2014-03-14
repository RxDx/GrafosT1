//-----------------------------------------------------------------------------
// grafo

typedef struct grafo *grafo;

//-----------------------------------------------------------------------------
// vértice de grafo

typedef struct vertice *vertice;

//-----------------------------------------------------------------------------
// lista encadeada

typedef struct lista *lista;

//-----------------------------------------------------------------------------
// nó de lista encadeada
 
typedef struct no *no;

//=============================================================================
// devolve o primeiro nó da lista l, ou NULL se l é vazia

no primeiro_no(lista l);

//------------------------------------------------------------------------------
// devolve o sucessor do nó n na lista encadeada 
// ou NULL se n for o último nó de l

no proximo_no(no n);

//------------------------------------------------------------------------------
// devolve o vertice armazenado em n

vertice vert(no n);

//------------------------------------------------------------------------------
// devolve o nome do vértice v

char *nome(vertice v);

//------------------------------------------------------------------------------
// devolve a vizinhança de v

lista vizinhanca(vertice v);

//------------------------------------------------------------------------------
// aloca um struct grafo, inicializa-o com um grafo vazio e devolve seu endereço
// ou NULL em caso de erro

grafo cria_grafo(void);

//------------------------------------------------------------------------------
// desaloca toda a memória usada em g
// 
// devolve 1 em caso de sucesso e 0 caso contrário

int destroi_grafo(grafo g);

//------------------------------------------------------------------------------
// devolve a lista de vértices de g

lista vertices(grafo g);

//------------------------------------------------------------------------------
// devolve o vertice de g que tem nome igual a s
//
// se não existe tal vértice e acrescenta != 0, acrescenta um vertice assim a g
// 
// caso contrário, devolve NULL

vertice acha_vertice(grafo g, char *s, int acrescenta);

//------------------------------------------------------------------------------
// acrescenta uma aresta em g ligando os vertices u e v sem verificar se
// u e v já são vizinhos

grafo poe_aresta(grafo g, vertice u, vertice v);


