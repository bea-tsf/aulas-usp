#define LIMITECARACTERES 50
#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct no {
  char nomeVertice[LIMITECARACTERES];
  int indice;               //usado para cálculos ao invés de nomeVertice
  int cor;                  //aceita valores BRANCO, CINZA ou PRETO
  struct no * prox;
} no;

typedef struct Grafo {
  int numVertices;
  int* visitado;            //?
  struct no ** listaAdj;
} Grafo;

no * criarNo(char * nome, int indice);
Grafo * criarGrafo(int vertices);
int listasOcupadas(Grafo * grafo);
int buscarVertice(char * nome, Grafo * grafo);
void adicionarConexao(Grafo * grafo, char * v1, char * v2);
void imprimirGrafo(Grafo * grafo);
void destruirGrafo(Grafo * grafo);
