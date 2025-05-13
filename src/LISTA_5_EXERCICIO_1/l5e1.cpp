#include <iostream>

using namespace std;

const int NUMERO_DE_ESTADOS = 8;
const int NUMERO_DE_CARACTERES_VALIDOS = 38;

const char CARACTERES_VALIDOS[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const int arestas[NUMERO_DE_ESTADOS][NUMERO_DE_CARACTERES_VALIDOS] = {
    /* 0 1 2 3 4 5 6 7 8 9 - + a b c d e f g h i j k l m n o p q r s t u v w x y
       z */
    /* estado 1 */ {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 2, 2, 2, 2, 2, 2,
                    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    /* estado 2 */ {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2,
                    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    /* estado 3 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 4 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 5 */ {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 6, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 6 */ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 7 */ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 8 */ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

const int ESTADO_INICIAL = 1;
const int ESTADOS_FINAIS[5] = {2, 3, 4, 5, 8};

int main(void) {

  // ler a linha atual
  string linha_atual;
  while (getline(cin, linha_atual)) {

    // guardar a maior sequencia até então, e o indice (do buffer inicial) de
    // onde essa maior sequencia terminava
    string maior_sequencia;
    string sequencia_atual;
    int indice_ultimo_fim = 1;
    bool valido;

    // guardar estado atual
    int estado_atual = ESTADO_INICIAL;
    int proximo_estado = 0;

    // percorrer caractere por caractere, guardando o indice do atual
    // cout << "length: ";
    // cout << linha_atual.length() << endl;
    for (int i = 0; i <= linha_atual.length(); i++) {
      // cout << linha_atual << "\n";
      // cout << "i: " << i << "\n";

      // iniciei a percorrer o grafo
      // verifico se com o caractere atual, tenho para onde ir.
      char caractere_atual = linha_atual[i];
      // cout << "caractere_atual: " << caractere_atual << "\n";
      // cout << "estado_atual: " << estado_atual << "\n";

      valido = false;
      proximo_estado = 0;
      for (int j = 0; j < NUMERO_DE_CARACTERES_VALIDOS; j++) {
        if (caractere_atual == CARACTERES_VALIDOS[j]) {
          // cout << "char atual " << caractere_atual << "\n";
          //  o atual corresponde ao indice j, tenho para onde ir
          // cout << "estado atual: " << estado_atual << "\n";
          valido = true;
          if (arestas[estado_atual - 1][j] != 0) {
            proximo_estado = arestas[estado_atual - 1][j]; // posicao j
            // cout << "proximo: " << proximo_estado << "\n";
            break;
          }
        }
      }
      /*
      cout << "status " << i << " \n";
      cout << caractere_atual << " " << valido << " \n";
      cout << sequencia_atual << " " << maior_sequencia << " \n";
      cout << estado_atual << " " << proximo_estado << " \n";
      cout << "\n";
      */

      // o estado atual é final? se sim, adiciono o ultimo caractere consumido a
      // maior sequencia, o indice onde estou vira o indice do ultimo fim
      for (int x : ESTADOS_FINAIS) {
        if (x == estado_atual) {
          maior_sequencia = sequencia_atual;
          indice_ultimo_fim = i;
          break;
        }
      }

      // tenho para onde ir? se sim eu vou, se não eu processo o que deu
      if (proximo_estado != 0) {
        estado_atual = proximo_estado;
        proximo_estado = 0;
        sequencia_atual += caractere_atual;
        continue;
      }

      // não tenho para onde ir
      if (proximo_estado == 0) {

        // existe alguma maior sequencia possivel?
        // se sim
        if (!maior_sequencia.empty()) {
          cout << maior_sequencia << "\n";
          i = indice_ultimo_fim - 1;
        }

        // se nao
        if (maior_sequencia.empty()) {
          cout << "ERRO\n";
          i = indice_ultimo_fim - 1; // vai tentar de novo
          indice_ultimo_fim++; // 
        }

        estado_atual = ESTADO_INICIAL;
        maior_sequencia = "";
        sequencia_atual = "";

        if (!valido) {
          i += 1;
        };
      }
    }
  }
}
