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
     std::size_t open_light();

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
    for (auto i = 0; i < 14; i++) {
        roads_->push_back(new Road());
    } for (auto i = 0; i < 6; i++) {
        structures::ArrayList<Road>* roads = new ArrayList<Road>(3);

        tlights_->push_back(new TrafficLight(roads_->at(i))
    }
    structures::ArrayList<Road>* roads13 = new ArrayList<Road>(3);
    roads13->push_back(roads_->at(10));
    roads13->push_back(roads_->at(11));
    roads13->push_back(roads_->at(12));
    tlights_->push_back(new TrafficLight(roads_->at(13), roads13));

    structures::ArrayList<Road>* roads14 = new ArrayList<Road>(3);
    roads14->push_back(roads_->at(7));
    roads14->push_back(roads_->at(8));
    roads14->push_back(roads_->at(9));
    tlights_->push_back(new TrafficLight(roads_->at(14), roads14));
    // Criar polícia
    structures::ArrayList<Road>* origins = new ArrayList<Road>(6);
    structures::ArrayList<Road>* destinations = new ArrayList<Road>(6);
    for (auto i = 0; i < 6; i++) {
        origins->push_back(roads_->at(i));
    } for (auto i = 6; i < 12; i++) {
        destinations->push_back(roads_->at(i));
    }
    police_ = Police(origins, destinations);
    // Criar carros e iniciar os eventos
}

void BigBrother::end_simulation() {events_.clear();}

void BigBrother::set_in_motion() {
    time_.add(events_.dequeue()());
    if (time_.seconds()%15 > 9) {
        blitz();
    }
    std::function<std::size_t()> call = &open_light;
    events_.enqueue(call);
}

std::size_t BigBrother::open_light() {
    return tlights_->at(rand()%8).open_light();
}

void BigBrother::blitz() {
}

std::size_t BigBrother::queue_size() {return events_.size();}

#endif
