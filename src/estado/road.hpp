//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef ROAD_HPP
#define ROAD_HPP

#include <cstdint>
#include <iostream>

#include "../structures/array_queue.hpp"
#include "car.hpp"

//! Classe Pista
/* Representa a estrutura por onde os carros passarão.
 * Tem um tamanho fixo (o que indica uma quantidade máxima de carros), uma lista de destinos e uma velocidade.
 */
class Road {
 public:
     Road();
     explicit Road(std::size_t max_size, std::size_t velocity);

     void add_car(Car car);
     Car remove_car();

 private:
     std::size_t size_;
     std::size_t max_size_;
     std::size_t velocity_;
     structures::ArrayQueue<Car> traffic_;
}

Road::Road() {
    srand(0);
    Road((rand()%41)+40,
            (rand()%21)+20);
}

Road::Road(std::size_t max_size, std::size_t velocity) : max_size_{max_size}, velocity_{velocity}, size_{0u}, traffic_{new ArrayQueue<Car>((int)max_size/4)} {}

void Road::add_car(Car car) {}

Car Road::remove_car() {}

#endif
