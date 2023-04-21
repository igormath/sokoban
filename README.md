# **Sokoban Fase 2**
Versão do nível 2 do jogo Sokoban implementado em C utilizando a biblioteca [Raylib](https://github.com/raysan5/raylib). Esta implementação foi avaliada como projeto da disciplina Programação 1 do curso de Sistemas de Informação da Universidade de Pernambuco.

## **Descrição**
Sokoban é um jogo do tipo "puzzle" onde o jogador controla um personagem que precisa mover caixas para determinados locais dentro do mapa. Nesta versão, o objetivo é colocar a caixa no local correto para terminar o nível. O jogo é perdido se o personagem ficar preso ou não conseguir movimentar a caixa.

![Print-screen do jogo em funcionamento](https://raw.githubusercontent.com/igormath/sokoban/main/assets/Screenshot%20from%202023-04-19%2018-44-03.png)

## **Como jogar**
Para jogar Sokoban, utilize as seguintes teclas:

- W: mover para cima
- A: mover para a esquerda
- S: mover para baixo
- D: mover para a direita <br>

Empurre a caixa para o local marcado com o objetivo. Quando a caixa estiver no local especificado, uma mensagem é exibida na tela.

## **Requisitos**

Para compilar o jogo é necessário ter a coleção [GCC](https://gcc.gnu.org/install/) e a biblioteca [Raylib](https://www.raylib.com/) devidamente instalados em seu sistema.


## **Como compilar**

No Linux, execute o seguinte comando na pasta raiz do projeto:

`make`

O jogo então será compilado.

## **Como executar**
Após compilar o jogo, execute o seguinte comando também na pasta raiz do projeto:

`./game`

O jogo será iniciado e você poderá começar a jogar.

## **Créditos**
Este jogo foi implementado por [Igor Matheus](https://github.com/igormath). A biblioteca Raylib é desenvolvida e mantida por Raylib Team. Texturas feitas por [Kenney](www.kenney.nl) sob licença Creative Commons Zero. Música por [Paulo Akio](https://www.youtube.com/watch?v=0xAa_EKix6w)
