// Exemplo do livro "Projeto de Algoritmos – Pascal e C", Prof. Nivio Ziviani, UFMG
// Algumas adaptacoes foram incluidas

/* ========================================================================== */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          1000

typedef int TipoChave;   // elemento para a busca ou insercao/remocao

typedef int TipoApontador; // aponta para uma posicao da lista

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];   // elementos da lista
  TipoApontador Primeiro, Ultimo;   // posicoes referentes aos primeiro e ultimo elementos
} TipoLista;                        // ultimo eh o indice da posicao livre

/* ========================================================================== */

void FLVazia(TipoLista *Lista)    // criacao de uma lista vazia; Primeiro == Ultimo
{ Lista -> Primeiro = INICIOARRANJO;
  Lista -> Ultimo = Lista -> Primeiro;
}  /* FLVazia */

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);  // teste para lista vazia
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{ if (Lista -> Ultimo > MAXTAM) printf("Lista esta cheia\n"); // Nao ha mais espaco
  else { Lista -> Item[Lista -> Ultimo - 1] = x;  // Em C, primeiro indice eh ZERO
         Lista -> Ultimo++;   // atualiza Ultimo apos insercao
       }
}  /* Insere */

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ int Aux;

  if (Vazia(*Lista) || p >= Lista -> Ultimo || p < 1) // verifica se a posicao eh valida
                                                        // adaptado: p < 1
  { printf(" Erro   Posicao nao existe %d\n",p);  // adaptado: %d
    return;
  }
  *Item = Lista -> Item[p - 1]; // copia do elemento removido
  printf("Retirado Posicao: %d Item: %d\n",p,Lista->Item[p-1].Chave); // adaptado
  Lista -> Ultimo--; // atualiza a posicao do ultimo
  for (Aux = p; Aux < Lista -> Ultimo; Aux++) // rearranja o vetor; sem espacos nao ocupados
    Lista -> Item[Aux - 1] = Lista -> Item[Aux];
}  /* Retira */

void Imprime(TipoLista Lista)
{ int Aux;

  for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 2); Aux++)
    printf("%d\n", Lista.Item[Aux].Chave);
}  /* Imprime */

/* ========================================================================== */

int main(int argc, char *argv[])
{ struct timeval t;

  TipoLista lista;
  TipoItem item;
  int vetor[MAXTAM];
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 10;
  FLVazia(&lista);

  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
    { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na lista */
  for (i = 0; i < max; i++)
    { item.Chave = vetor[i];
      Insere(item, &lista);
      printf("Inseriu: %d \n", item.Chave);
    }
  printf("Lista apos insercao inicial:\n"); // adaptado
  Imprime(lista);

  /*Retira cada chave da lista */
  for(i = 0; i < max; i++)
    { /*escolhe uma chave aleatoriamente */
      //j = (int) ((lista.Ultimo - 1) * rand() / (RAND_MAX + 1.0)); // original
      j = (int) (10.0 * rand()/(RAND_MAX + 1.0)); // adaptado
      /* tenta retirar chave apontada */
      Retira(j, &lista, &item);
      printf("Lista apos remocao:\n");
      Imprime(lista); // adaptado
      //printf("Retirou: %d\n", item.Chave); // original
    }
  printf("\n\n\nLista final:\n"); // adaptado
  Imprime (lista);
  return(0);
}
