// l123b - t2 - diogorm
// programa para digitar números dentro do limite de tempo
// Diogo rocha marques
// 2023-10-24

#include "tecla.h"
#include "tela.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// definições de constantes
// quantas letras gerar

#define L_LETRAS 10
// quantos segundos para digitar
#define TEMPO 20

// funções a implementar
// retorna a posição de n em M[t][], ou -1
char acha_palavras(int t, char M[t][16], int l);
// remove o dado na posição p de v[t], deslocando os v[>t]
void remove_pos(int t, char M[t][16], int p);

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
void preenche_Mat(
    int t,
    char M[t][16]); //é utilizado 16 por que a maior palavra tem 15 letras
// mostra o matriz de números
void mostra_Mat(int t, char M[t][16]);
// limpa a linha de entrada
void espera_enter(); // Não esta sendo mais usada pq esta sendo usado
                     // tecla_ini(); e tecla_fim();

int palavras(char P[][16]);

int main() {
  tela_ini();
  tecla_ini();
  // inicializa o gerador de letras aleatórios
  srand(time(0));

  apresentacao();

  do {
    jogo();
  } while (quer_jogar_de_novo());

  encerramento();
  tecla_fim();
  tela_fim();
}

void jogo() {
  // inicializa o matriz de letras a digitar
  int l_letras = L_LETRAS;
  char letras[l_letras][16];
  preenche_Mat(l_letras, letras);

  // inicializa timer
  long t0 = time(0);

  while (true) {
    int resta = TEMPO - (time(0) - t0);
    if (resta <= 0) {
      printf("Tempo esgotado\n");
      break;
    }

    if (l_letras <= '\0') {
      printf("Parabéns, você acertou todos, e sobraram %d segundos!\n", resta);
      break;
    }

    mostra_Mat(l_letras, letras);

    tela_limpa();

    printf("você tem %d segundos\n", resta);
    printf("digite uma das letras ");
    char letra = tecla_le_char();

    char pos = acha_palavras(l_letras, letras, letra);

    if (pos < 0) {
      printf("letra %c não encontrada\n", letra);
    } else {
      remove_pos(l_letras, letras, pos);

      while (letras[pos][0] != '\0') {
        mostra_Mat(l_letras, letras);
        printf("digite uma das letras ");
        char letra = tecla_le_char();

        char pos = acha_palavras(l_letras, letras, letra);

        if (pos < 0) {
          printf("letra %c não encontrada\n", letra);
        } else {
          remove_pos(l_letras, letras, pos);
        }
      }
    }
  }
  tela_atualiza();
}

int palavra(char P[][16]) {
  FILE *palavra; // cria um ponteiro para o arquivo

  palavra = fopen("palavras.txt", "r"); // abre o arquivo para leitura
  char linha[16]; // cria um vetor de 16 caracteres, 16 é o tamanho da maior
                  // palavra
  if (palavra == NULL) {
    printf("Erro ao abrir o arquivo"); /*verifica tanto se o arquivo foi aberto
                                        e s tem palavras dentro, se não tiver
                                        ele printa o erro*/
    return 0;
  }
  int i = 0;
  while ((fgets(linha, sizeof(linha), palavra)) != NULL && i < 920) {
    // remove o caracter da linha se estiver presente
    int tamanho_palavra = strlen(linha);
    if (tamanho_palavra > 0 && linha[tamanho_palavra - 1] == '\n') {
      linha[tamanho_palavra - 1] = '\0';
    }
    // converte para minusculo as palavras maiusculas e ve se as palavras são
    // validas
    int valido = 1;
    for (int j = 0; linha[j] != '\0'; j++) {
      if (linha[j] >= 'A' && linha[j] <= 'Z') {
        linha[j] = linha[j] - 'A' + 'a';
      } else if (linha[j] < 'a' || linha[j] > 'z') {
        valido = 0;
        break;
      }
    }
    if (valido) {
      strcpy(P[i], linha);
      i++;
    }
  }
  fclose(palavra);
  return i;
}

void espera_enter() {
  while (tecla_le_char() != '\n') {
    ; /* não faz nada */
  }
}

void apresentacao() {
  printf("Você deve digitar as que aparecerão na tela.\n");
  printf("A ordem não é importante.\n");
  printf("Tecle <enter> para iniciar. ");
  espera_enter();
}

void encerramento() { printf("Até a próxima.\n"); }

bool quer_jogar_de_novo() {
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

void preenche_Mat(int t, char M[t][16]) {
  char matriz[920][16];
  int n = palavra(matriz);
  for (int j = 0; j < t; j++) {
    int sort_num = rand() % n;
    strcpy(M[j], matriz[sort_num]);
  }
}

void mostra_Mat(int t, char M[t][16]) {
  printf("\n");
  int contador = 1;

  for (int i = 0; i < t; i++) {
    printf("%d- %s", contador,
           M[i]); // Não é utilizado a matriz pq o %s precisa apenas da
    // posição da linha a ser lida
    contador++;
    printf("\n");
  }
  printf(" \n\n");
}

char acha_palavras(int t, char M[t][16], int l) {
  // loop para percorrer o matriz
  for (int i = 0; i < t; i++) {
    // verifica se o numero digitado é igual a o numero da posição i do matriz e
    // se for ele retorna a posição
    if (l == M[i][0]) {
      return i;
    }
  }
  // caso não for achado ele retorna -1
  return -1;
}

void remove_pos(int t, char M[t][16], int p) {
  // criei uma variavel para salvar o valor da posição i
  int tam = strlen(M[p]);
  // um loop para fazer a posição p percorrer até a posição t - 1
  for (int i = 0; i < tam; i++) {
    // ele vai levando o valor da posição p para a proxima posição a direita
    M[p][i] = M[p][i + 1];
  }
}
