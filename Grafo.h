#define LIMITECARACTERES 50

typedef struct no {
  char nomeVertice[LIMITECARACTERES];
  struct no * prox;
} no;

typedef struct Grafo {
  int numVertices;
  int* visitado;
  struct no ** listaAdj;
} Grafo;

no * criarNo(char * nome);
Grafo * criarGrafo(int vertices);
int listasOcupadas(Grafo * grafo);
int buscarVertice(char * nome, Grafo * grafo);
void adicionarConexao(Grafo * grafo, char * v1, char * v2);
void imprimirGrafo(Grafo * grafo);
void destruirGrafo(Grafo * grafo);
