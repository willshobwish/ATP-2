// Exemplo do livro "Projeto de Algoritmos – Pascal e C", Prof. Nivio Ziviani, UFMG
// Alguns cometarios foram acrescdentados
// main(): mesmos passos de lista em arranjo (vetor)

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;   // ponteiro para o proximo struct
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;  // ponteiro para struct
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));  // alocacao dinamica
  Lista -> Ultimo = Lista -> Primeiro; // apontam para a mesma celula
  Lista -> Primeiro -> Prox = NULL;    // o prox eh NULL porque so tem essa celula
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));  // aloca uma nova celula em Prox do Ultimo
  Lista -> Ultimo = Lista -> Ultimo -> Prox; // O ultimo anterior recebe o endereco da nova celula alocada
  Lista -> Ultimo -> Item = x; // atribui o item
  Lista -> Ultimo -> Prox = NULL;  //  Prox do novo ultimo eh NULL
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) // p endereco da celula a ser removida
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p -> Prox;  // q aponta para a celula a ser removida
                   // [p]->Prox aponta para celula a ser removida
  *Item = q -> Item;
  p -> Prox = q -> Prox;  // atualizacao da celular [p]
                           // [p]->Prox aponta para o proximo da celula removida q, indicado por [q]->Prox
                           // isto eh, a celula q eh pulada
  if (p -> Prox == NULL) Lista -> Ultimo = p;  // se q era a ultima celula, o ponteiro Ultimo precisa ser atualizado
  free(q);
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}

/* ========================================================================== */

int main(int argc, char *argv[])
{ struct timeval t;

  TipoLista lista;
  TipoItem item;
  int vetor[MAX];
  TipoApontador p;
  int i, j, k, n;
  float  tamanho=0;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  FLVazia(&lista);


  /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
  for(i = 0; i < MAX; i++) vetor[i] = i + 1;
  for(i = 0; i < MAX; i++)
    { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na lista */
  for (i = 0; i < MAX; i++)
    { item.Chave = vetor[i];
      Insere(item, &lista);
      tamanho++;
      printf("Inseriu: %d \n", item.Chave);
    }
  Imprime(lista);

  /*Retira cada chave da lista */
  for(i = 0; i < MAX; i++)
    { /*escolhe uma chave aleatoriamente */
      k = (int) ((tamanho) * rand() / (RAND_MAX + 1.0));
      p = lista.Primeiro;
      /*retira chave apontada */
      Retira(p, &lista, &item);
      tamanho--;
      printf("Retirou: %d\n", item.Chave);
    }
  Imprime (lista);
  return(0);
}
