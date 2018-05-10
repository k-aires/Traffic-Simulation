//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef CAR_HPP
#define CAR_HPP

#include <cstdlib>

//! Classe Carro
/* Representa um carro.
 * Tem um tamanho fixo composto de seu tamanho mais 1 metro à frente e 2 metros atrás.
 */
class Car {
 public:
     Car();
     Car(std::size_t size_);

     std::size_t size();

 private:
     std::size_t size_;
};

Car::Car() {
    srand(0);
    size_ = (rand()%3)+6; //Número randômico entre 0 e 2 + 3 para gerar um tamanho entre 3 e 5, somando 1 na frente e 2 atrás
}

Car::Car(std::size_t size) : size_{size+3} {}

std::size_t Car::size() {return size_;}

#endif
