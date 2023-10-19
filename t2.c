// l123b - t1 - diogorm
// programa para digitar números dentro do limite de tempo
// Diogo rocha marques 
// 2023-10-01

/// Você só pode alterar o nome e data acima, e os locais marcados,
///   no final do arquivo.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// definições de constantes
// quantos números gerar
#define N_NUM 10
// quantos segundos para digitar
#define TEMPO 20

// funções a implementar
// retorna a posição de n em v[t], ou -1
int acha_num(int t, char v[t], int n);
// remove o dado na posição p de v[t], deslocando os v[>t]
void remove_pos(int t, char v[t], int p);

// funções auxiliares
// apresenta o programa
void apresentacao();
// encerra o programa
void encerramento();
// executa uma partida
void jogo();
// verifica a vontade do jogador
bool quer_jogar_de_novo();
// preenche v[t] com números
void preenche_vet(int t, char v[t]);
// mostra o vetor de números
void mostra_vet(int t, char v[t]);
// limpa a linha de entrada
void espera_enter();


int main()
{
  // inicializa o geraint max, int mindor de números aleatórios
  srand(time(0));

  apresentacao();

  do {
    jogo();
  } while(quer_jogar_de_novo());

  encerramento();
}

void gera_letra(letra) {
  int max = rand();
  int min = rand();

  char letra =(max - min ) +1;
  putchar(letra + 'a');
}

void jogo()
{
  // inicializa o vetor de números a digitar
  char n_num = N_NUM;
  char numeros[N_NUM];
  preenche_vet(n_num, numeros);

  // inicializa timer
  long t0 = time(0);

  while (true) {
    int resta = TEMPO - (time(0) - t0);
    if (resta <= 0) {
      printf("Tempo esgotado\n");
      break;
    }

    if (n_num <= 0) {
      printf("Parabéns, você acertou todos, e sobraram %d segundos!\n", resta);
      break;
    }

    mostra_vet(n_num, numeros);
    printf("você tem %d segundos\n", resta);
    printf("digite um dos números ");
    int num;
    scanf("%d", &num);
    espera_enter();
    int pos = acha_num(n_num, numeros, num);
    if (pos < 0) {
      printf("número %d não encontrado\n", num);
    } else {
      remove_pos(n_num, numeros, pos);
      n_num--;
    }
  }
}

void espera_enter()
{
  while (getchar() != '\n') {
    ; /* não faz nada */
  }
}

void apresentacao()
{
  printf("Você deve digitar os números que aparecerão na tela.\n");
  printf("A ordem não é importante.\n");
  printf("Tecle <enter> para iniciar. ");
  espera_enter();
}

void encerramento()
{
  printf("Até a próxima.\n");
}

bool quer_jogar_de_novo()
{
  // limpa a entrada
  espera_enter();

  printf("Digite 's' para jogar de novo ");
  while (true) {
    char c = getchar();
    if (c == '\n') {
      return false;
    } else if (c == 's' || c == 'S') {
      espera_enter();
      return true;
    }
  }
}

void preenche_vet(int t, char v[t])
{
  for (int i = 0; i < t; i++) {
    // gera um número aleatório entre 0 e 999
    v[i] = rand() % 1000;
  }
}

void mostra_vet(int t, char v[t])
{
  printf("\n[");
  for (int i = 0; i < t; i++) {
    printf(" %d", v[i]);
  }
  printf(" ]\n\n");
}

int acha_num(int t, char v[t], int n)
{
  /// você deve alterar abaixo desta linha 
  
  //loop para percorrer o vetor
    for (int i = 0; i < t; i++) {
      // verifica se o numero digitado inté igual a o numero da posição i do vetor e se for ele retorna a posição 
       if (n == v[i]) {        
           return i;
       }
    }
    // caso não for achado ele retorna -1
    return -1;

  
  /// você deve alterar acima desta linha  
}

void remove_pos(int t, char v[t], int p)
{
  /// você deve alterar abaixo desta linha  
    // criei uma variavel para salvar o valor da posição i 
    int auxiliar;
    // um loop para fazer a posição p percorrer até a posição t - 1
    for (int i = p; i < t-1; i++) {
        auxiliar = v[i];               // ele vai levando o valor da posição p para a proxima posição a direita 
        v[i] = v[i+1];
        v[i+1] = auxiliar;
    }
   /// você deve alterar acima desta linha  
}
