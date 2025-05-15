#include <iostream>

using namespace std;

const int NUMERO_DE_ESTADOS = 13;
const int NUMERO_DE_CARACTERES_VALIDOS = 41;

const char CARACTERES_VALIDOS[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+',  'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',  'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', '\n', ' '};

const int arestas[NUMERO_DE_ESTADOS][NUMERO_DE_CARACTERES_VALIDOS] = {
    /* 0 1 2 3 4 5 6 7 8 9 - + a b c d e f g h i j k l m n o p q r s t u v w x y
       z . \n " " */

    /* estado 1 */ {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 0,  4, 4,
                    4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4,  4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 13, 12},

    /* estado 2 */ {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4,
                    4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},

    /* estado 3 */ {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},

    /* estado 4 */ {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},

    /* estado 5 */ {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    /* estado 6 */ {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    /* estado 7 */ {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0},

    /* estado 8 */ {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    /* estado 9 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0},

    /* estado 10 */ {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  10, 10,
                     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                     10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0,  11, 0},

    /* estado 11 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    /* estado 12 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12},

    /* estado 13 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

const string VALOR_ESTADOS[NUMERO_DE_ESTADOS] = {
    /* estado 1 */ "",
    /* estado 2 */ "ID",
    /* estado 3 */ "IF",
    /* estado 4 */ "ID",
    /* estado 5 */ "error",
    /* estado 6 */ "REAL",
    /* estado 7 */ "NUM",
    /* estado 8 */ "REAL",
    /* estado 9 */ "error",
    /* estado 10 */ "",
    /* estado 11 */ "comment",
    /* estado 12 */ "whitespace",
    /* estado 13 */ "error"};

const int ESTADO_INICIAL = 1;
const int ESTADOS_FINAIS[NUMERO_DE_ESTADOS - 1] = {2, 3, 4,  5,  6,  7,
                                                   8, 9, 10, 11, 12, 13};

string trim(string x) {
  // tira espaço do começo
  char i = x[0];
  while (i == ' ' && x.length() >= 1) {
    i = x[0];
    x = x.substr(1);
  }

  char j = x[0];
  while (j == ' ' && x.length() >= 1) {
    j = x[0];
    x = x.substr(0, x.length() - 1);
  }

  return x;
}

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
      if (estado_atual == 1 && !valido) {
        proximo_estado = 13;
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
          string exibir = trim(maior_sequencia);
          if (!exibir.empty())
            cout << trim(maior_sequencia) << " "
                 << VALOR_ESTADOS[estado_atual - 1] << "\n";
          else
            cout << VALOR_ESTADOS[estado_atual - 1] << "\n";
          i = indice_ultimo_fim - 1;
        }

        // se nao
        if (maior_sequencia.empty()) {
          cout << "ERRO\n";
          i = indice_ultimo_fim - 1; // vai tentar de novo
          indice_ultimo_fim++;       //
        }

        estado_atual = ESTADO_INICIAL;
        maior_sequencia = "";
        sequencia_atual = "";

        if (!valido && estado_atual != 1) {
          i += 1;
        };
      }
    }
  }
}
