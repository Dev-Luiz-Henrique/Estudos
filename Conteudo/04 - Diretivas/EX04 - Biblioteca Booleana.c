// Crie o arquivo boolean.h com as definicoes necessarias para compor expressoes logicas, 
// a exemplo do programa abaixo, produzindo na saida um valor booleano.

// O programa abaixo produziria: Verdadeiro Falso Verdadeiro.

#include <stdio.h>
#include "boolean.h"

int main() {
  printf("%s ", bool(not false) );
  printf("%s ", bool(false and true) );
  printf("%s ", bool(true or false) );
  return 0;
}
