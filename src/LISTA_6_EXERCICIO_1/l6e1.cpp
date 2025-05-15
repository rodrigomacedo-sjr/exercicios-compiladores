#include <iostream>

using namespace std;

const int NUMERO_DE_ESTADOS = 22;
const int NUMERO_DE_CARACTERES_VALIDOS = 38;

const char CARACTERES_VALIDOS[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

/*
 * 0 1 2 3 4 5 6 7 8 9 - + a b c d e f g h i j k l m n o p q r s t u v w x y z
 */
const int arestas[NUMERO_DE_ESTADOS][NUMERO_DE_CARACTERES_VALIDOS] = {
    /* estado 1 */ {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 17, 0,
                    0,  11, 0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,
                    0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0},
    /* estado 2 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0,
                    0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 3 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 4 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 5 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 6 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 7 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0},
    /* estado 8 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 9 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0},
    /* estado 10 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 11 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0},
    /* estado 12 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,  0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 13, 0, 0, 0, 0, 0, 0},
    /* estado 13 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0},
    /* estado 14 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0},
    /* estado 15 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 16 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 17 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 18 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* estado 19 */ {19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 0, 0, 0,
                     0,  0,  0,  20, 0,  0,  0,  0,  0,  0,  0, 0, 0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
    /* estado 20 */ {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 21, 21, 0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    /* estado 21 */ {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
    /* estado 22 */ {22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 0, 0, 0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0,
                     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0},
};

const string VALOR_ESTADOS[NUMERO_DE_ESTADOS] = {
    /* estado 1 */ "",
    /* estado 2 */ "",
    /* estado 3 */ "ELE",
    /* estado 4 */ "",
    /* estado 5 */ "",
    /* estado 6 */ "ELA",
    /* estado 7 */ "",
    /* estado 8 */ "DELE",
    /* estado 9 */ "",
    /* estado 10 */ "DELA",
    /* estado 11 */ "",
    /* estado 12 */ "",
    /* estado 13 */ "GATO",
    /* estado 14 */ "CARRO",
    /* estado 15 */ "GATOS",
    /* estado 16 */ "CARROS",
    /* estado 17 */ "MAIS",
    /* estado 18 */ "MENOS",
    /* estado 19 */ "INTEIRO",
    /* estado 20 */ "",
    /* estado 21 */ "",
    /* estado 22 */ "REAL"};

const int ESTADO_INICIAL = 1;
const int ESTADOS_FINAIS[] = {3, 6, 8, 10, 13, 14, 15, 16, 17, 18, 19, 22};

string trim(string x) {
  // tira espaço do começo
  char i = x[0];
  while (i == ' ' && x.length() >= 1) {
    i = x[0];
    x = x.substr(1);
  }

  char j = x[x.length() - 1];
  while (j == ' ' && x.length() >= 1) {
    j = x[0];
    x = x.substr(0, x.length() - 1);
  }

  return x;
}

int main(void) {

  // ler a linha atual
  string linha_atual;
  int ultimo_final = 0;
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
    for (int i = 0; i <= linha_atual.length(); i++) {
      // iniciei a percorrer o grafo
      // verifico se com o caractere atual, tenho para onde ir.
      char caractere_atual = linha_atual[i];

      valido = false;
      proximo_estado = 0;
      for (int j = 0; j < NUMERO_DE_CARACTERES_VALIDOS; j++) {
        if (caractere_atual == CARACTERES_VALIDOS[j]) {
          //  o atual corresponde ao indice j, tenho para onde ir
          valido = true;
          if (arestas[estado_atual - 1][j] != 0) {
            proximo_estado = arestas[estado_atual - 1][j]; // posicao j
            break;
          }
        }
      }

      bool debug = false;
      if (debug) {
        cout << "letra " << i << " \n";
        cout << "char atual: " << caractere_atual
             << " |  valido: " << (valido ? "true" : "false") << " \n";
        cout << "seq. atual: " << sequencia_atual
             << " |  maior seq.:" << maior_sequencia << " \n";
        cout << "estado atual: " << estado_atual
             << " |  proximo estado: " << proximo_estado << " \n";
        cout << "\n";
      }

      // o estado atual é final? se sim, adiciono o ultimo caractere consumido a
      // maior sequencia, o indice onde estou vira o indice do ultimo fim
      for (int x : ESTADOS_FINAIS) {
        if (x == estado_atual) {
          maior_sequencia = sequencia_atual;
          ultimo_final = estado_atual;
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

      // ignora espaço sozinho
      if (caractere_atual == ' ' && sequencia_atual.empty()) {
        i = indice_ultimo_fim;
        indice_ultimo_fim++;
        continue;
      }

      // não tenho para onde ir
      if (proximo_estado == 0) {

        // existe alguma maior sequencia possivel?
        // se sim
        if (!maior_sequencia.empty()) {

          string valor = VALOR_ESTADOS[ultimo_final];

          if (valor == "REAL" || valor == "INTEIRO") {
            cout << valor << " " << maior_sequencia << "\n";
          } else {
            cout << valor << "\n";
          }
          i = indice_ultimo_fim - 1;
        }

        // se nao
        if (maior_sequencia.empty()) {
          cout << "ERRO\n";
          i = indice_ultimo_fim;
          indice_ultimo_fim++;
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
  cout << "\n";
}
