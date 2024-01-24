# Jogo de Digitação de Palavras

Este é um programa desenvolvido em C para um jogo de digitação de palavras, criado como parte de um trabalho na disciplina de Laboratório de Programação I. Abaixo estão as informações e instruções para compreender e utilizar o código.

## Instruções de Uso

### Compilação:

Certifique-se de ter um compilador C instalado no seu sistema.

```bash
gcc l123b_t2_diogorm.c -o jogo_dig_palavras
```

### Execução:

Após a compilação, execute o programa gerado.

```bash
./jogo_dig_palavras
```

### Regras do Jogo:

- O objetivo é digitar as palavras que aparecerão na tela dentro do tempo limite.
- A ordem das palavras não é importante.
- O jogador tem um tempo limitado para digitar o maior número possível de palavras.

## Funções Implementadas

- `acha_palavras`: Retorna a posição de uma letra na matriz de palavras ou -1 se não encontrar.
- `remove_pos`: Remove a palavra na posição especificada da matriz de palavras.
- `palavras`: Lê palavras de um arquivo e as armazena em uma matriz.

## Funcionalidades Adicionais

- **Dificuldade:** O programa gera uma lista de palavras aleatórias para o jogador digitar.
- **Tempo Limite:** O jogador tem um tempo limite para digitar as palavras.
- **Feedback:** O programa fornece feedback sobre o tempo restante e se a letra digitada é válida.
- **Replay:** Após o jogo, o jogador pode optar por jogar novamente.

## Observações

- O arquivo "palavras.txt" contém uma lista de palavras para o jogo.
- A maior palavra no arquivo tem 15 letras, e é por isso que a matriz tem o tamanho definido como 16.
- Certifique-se de ter o arquivo "palavras.txt" disponível no mesmo diretório do programa ou ajuste o caminho conforme necessário.

Esperamos que você aproveite este jogo de digitação de palavras em C!
