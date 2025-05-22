#include <iostream>
#include "utils.h"

using namespace std;

const int IF=1, THEN=2, ELSE=3, BEGIN=4, END=5, PRINT=6, SEMI=7, NUM=8, EQ=9;

int token = getToken();

void advance() {token=getToken();}

void eat(int t) {if (token == t) advance(); else error();}

void S();
void L();
void E();

void S() {
  switch(token) {
    case IF: eat(IF); E(); eat(THEN); S(); eat(ELSE); S(); break;
    case BEGIN: eat(BEGIN); S(); L(); break;
    case PRINT: eat(PRINT); E(); break;
    default: error();
  }
}

void L() {
  switch(token) {
    case END: eat(END); break;
    case SEMI: eat(SEMI); S(); L(); break;
    default: error();
  }
}

void E() { eat(NUM); eat(EQ); eat(NUM); }

auto main() -> int {
  cout << "hello world\n";
}
