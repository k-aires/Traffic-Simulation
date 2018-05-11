#include <iostream>
#include <fstream>

#include "simulation.hpp"
#include "bigbrother.hpp"

using namespace std;

int main() {
  size_t tempo = 0;
  auto bigBrother = BigBrother();

  while(tempo < simulation::tempo_sim) {
    
    tempo++;
  }

  bigBrother.end_simulation();
  return 0;
}
