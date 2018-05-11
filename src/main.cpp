#include <iostream>
#include <fstream>

#include "simulation.hpp"
#include "bigbrother.hpp"

using namespace std;

int main() {
  size_t tempo = 0;
  BigBrother::BigBrother();

  while(tempo < simulation::tempo_sim) {

    tempo++;
  }

  return 0;
}
