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
#include "../simulation.hpp"

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
    srand(0);
    // Criar pistas e semáforos
    roads_->push_back(Road(simulation::Oeste_fonte_s, simulation::Oeste_fonte_v));
    roads_->push_back(Road(simulation::N1norte_sumidouro_s, simulation::N1norte_sumidouro_v));
    roads_->push_back(Road(simulation::S1norte_fonte_s, simulation::S1norte_fonte_v));
    roads_->push_back(Road(simulation::N2sul_fonte_s, simulation::N2sul_fonte_v));
    roads_->push_back(Road(simulation::Leste_fonte_s, simulation::Leste_fonte_v));

    roads_->push_back(Road(simulation::S2norte_fonte_s, simulation::S2norte_fonte_v));
    roads_->push_back(Road(simulation::N1norte_sumidouro_s, simulation::N1norte_sumidouro_v));
    roads_->push_back(Road(simulation::S1sul_sumidouro_s, simulation::S1sul_sumidouro_v));
    roads_->push_back(Road(simulation::Oeste_sumidouro_s, simulation::Oeste_sumidouro_v));
    roads_->push_back(Road(simulation::Leste_sumidouro_s, simulation::Leste_sumidouro_v));

    roads_->push_back(Road(simulation::S2sul_sumidouro_s, simulation::S2sul_sumidouro_v));
    roads_->push_back(Road(simulation::N2norte_sumidouro_s, simulation::N2norte_sumidouro_v));
    roads_->push_back(Road(simulation::Centro_leste_s, simulation::Centro_leste_v));
    roads_->push_back(Road(simulation::Centro_oeste_s, simulation::Centro_oeste_v));

    for (auto i = 0; i < 6; i++) {
        structures::ArrayList<Road>* roads = new structures::ArrayList<Road>(3);

        tlights_->push_back(new TrafficLight(*roads_->at(i)));
    }
    structures::ArrayList<Road>* roads13 = new structures::ArrayList<Road>(3);
    roads13->push_back(roads_->at(10));
    roads13->push_back(roads_->at(11));
    roads13->push_back(roads_->at(12));
    tlights_->push_back(new TrafficLight(roads_->at(13), roads13));

    structures::ArrayList<Road>* roads14 = new structures::ArrayList<Road>(3);
    roads14->push_back(roads_->at(7));
    roads14->push_back(roads_->at(8));
    roads14->push_back(roads_->at(9));
    tlights_->push_back(new TrafficLight(roads_->at(14), roads14));
    // Criar polícia
    structures::ArrayList<Road>* origins = new structures::ArrayList<Road>(6);
    structures::ArrayList<Road>* destinations = new structures::ArrayList<Road>(6);
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
