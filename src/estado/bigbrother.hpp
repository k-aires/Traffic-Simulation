//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef BIG_BROTHER_HPP
#define BIG_BROTHER_HPP

#include <cstdint>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <functional>

#include "../structures/linked_queue.hpp"
#include "road.hpp"
#include "trafficlight.hpp"
#include "police.hpp"

//! Classe Grande Irmão
/* É a classe que organiza os eventos
 * Tem fila de eventos que devem acontecer e organiza os eventos de forma a gerar mais dependendo do evento que acontece
 */
class BigBrother {
 public:
     BigBrother();

     void start_simulation();
     void end_simulation();
     void set_in_motion();

     void blitz(); //Cria ou deleta carros

     std::size_t queue_size();

 private:
     structures::LinkedQueue<std::function<void()>> events_;
     structures::ArrayList<Road> roads_;
     structures::ArrayList<TrafficLight> tlights_;
     Police police_;
};

BigBrother::BigBrother() : events_{new LinkedQueue<std::function<void()>>()}, roads_{new ArrayList<Road>(14)}, tlights_{new ArrayList<TrafficLight>(8)}, police_{nullptr} {
    events_.enqueue(start_simulation);
    srand(0);
}

void BigBrother::start_simulation() {
    // Criar pistas e semáforos
    // Criar polícia
    // Criar carros e iniciar os eventos
}

void BigBrother::end_simutalion() {events_.clear();}

void BigBrother::set_in_motion() {
    events_.dequeue()();
    events_.enqueue(tlights[rand()%8].open_light);
}

void BigBrother::blitz() {
    events_.enqueue(police_.create_car);
    police_.delete_car();
}

std::size_t queue_size() {return events_.size();}

#endif
