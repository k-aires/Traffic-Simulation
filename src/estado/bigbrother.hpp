//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Arthur Mesquita Pickcius>

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
#include "time.hpp"

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
     structures::LinkedQueue<std::function<std::size_t()>> events_;
     structures::ArrayList<Road>* roads_;
     structures::ArrayList<TrafficLight>* tlights_;
     Police police_;
     Time time_;
};

BigBrother::BigBrother() : events_{structures::LinkedQueue<std::function<std::size_t()>>()}, roads_{new structures::ArrayList<Road>(14)}, tlights_{new structures::ArrayList<TrafficLight>(8)}, time_{Time()} {
     srand(0);
     start_simulation();
}

void BigBrother::start_simulation() {
    // Criar pistas e semáforos
    // Criar polícia
    // Criar carros e iniciar os eventos
}

void BigBrother::end_simulation() {events_.clear();}

void BigBrother::set_in_motion() {
    time_.add(events_.dequeue()());
    if (time_.seconds()%15 > 9) {
        blitz();
    }
    TrafficLight* fuck = &tlights_->at(rand()%8);
    std::function<std::size_t()> call = &fuck->open_light;
    events_.enqueue(call);
}

void BigBrother::blitz() {
}

std::size_t BigBrother::queue_size() {return events_.size();}

#endif
