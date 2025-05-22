#include <iostream>
#include <list>
#include <optional>
#include <vector>

using namespace std;

class Estado {
private:
  string nome;
  bool final;
  string token;
  list<Estado> listaAdj;

public:
  Estado(string n, bool f, string t) : nome(n), final(f), token(t) {}
};

class AFD {
private:
  int numVertices;
  list<Estado> vertices;
  String inicial;

public:
  AFD() {
    numVertices = 0;
    vertices = nullptr;
    inicial = "";
  };

  AFD(int n, list<Estado> v) {
    numVertices = n;
    vertices = v;
  }
};

auto main() -> int { cout << "hello world\n"; }
