//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef ROAD_HPP
#define ROAD_HPP

#include <cstdint>
#include <iostream>

#include "../structures/array_queue.hpp"

//! Classe Pista
/* Representa a estrutura por onde os carros passarão.
 * Tem um tamanho fixo (o que indica uma quantidade máxima de carros), uma lista de destinos e uma velocidade.
 */
class Road {

 private:
     std::size_t size_;
     std::size_t max_size_;
     std::size_t velocity_;
     structures::ArrayQueue<Car> traffic_;
}

#endif
