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

    structures::ArrayList<std::size_t> proba = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsa = Arraylist<Road>(3);
    proba.push_back(simulation::S1_O_norte_norte);
    proba.push_back(simulation::S1_O_centro_leste);
    proba.push_back(simulation::S1_O_leste_sul);
    roadsa.push_back(roads_->at(6));
    roadsa.push_back(roads_->at(12));
    roadsa.push_back(roads_->at(7));
    tlights_->push_back(new TrafficLight(roads_->at(0), roadsa, proba));

    structures::ArrayList<std::size_t> probb = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsb = Arraylist<Road>(3);
    probb.push_back(simulation::S1_N_centro_leste);
    probb.push_back(simulation::S1_N_sul_sul);
    probb.push_back(simulation::S1_N_oeste_oeste);
    roadsb.push_back(roads_->at(12));
    roadsb.push_back(roads_->at(7));
    roadsb.push_back(roads_->at(8));
    tlights_->push_back(new TrafficLight(roads_->at(1), roadsb, probb));

    structures::ArrayList<std::size_t> probc = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsc = Arraylist<Road>(3);
    probc.push_back(simulation::S1_C_norte_norte);
    probc.push_back(simulation::S1_C_oeste_oeste);
    probc.push_back(simulation::S1_C_sul_sul);
    roadsc.push_back(roads_->at(6));
    roadsc.push_back(roads_->at(8));
    roadsc.push_back(roads_->at(7));
    tlights_->push_back(new TrafficLight(roads_->at(13), roadsc, probc));

    structures::ArrayList<std::size_t> probd = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsd = Arraylist<Road>(3);
    probd.push_back(simulation::S1_S_oeste_oeste);
    probd.push_back(simulation::S1_S_norte_norte);
    probd.push_back(simulation::S1_S_centro_leste);
    roadsd.push_back(roads_->at(8));
    roadsd.push_back(roads_->at(6));
    roadsd.push_back(roads_->at(12));
    tlights_->push_back(new TrafficLight(roads_->at(2), roadsd, probd));

    ///////////////////////////////////////////////////

    structures::ArrayList<std::size_t> probe = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadse = Arraylist<Road>(3);
    probe.push_back(simulation::S2_C_norte_norte);
    probe.push_back(simulation::S2_C_leste_leste);
    probe.push_back(simulation::S2_C_sul_sul);
    roadse.push_back(roads_->at(11));
    roadse.push_back(roads_->at(9));
    roadse.push_back(roads_->at(10));
    tlights_->push_back(new TrafficLight(roads_->at(12), roadse, probe));

    structures::ArrayList<std::size_t> probf = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsf = Arraylist<Road>(3);
    probf.push_back(simulation::S2_N_leste_leste);
    probf.push_back(simulation::S2_N_sul_sul);
    probf.push_back(simulation::S2_N_centro_oeste);
    roadsf.push_back(roads_->at(9));
    roadsf.push_back(roads_->at(10));
    roadsf.push_back(roads_->at(13));
    tlights_->push_back(new TrafficLight(roads_->at(3), roadsf, probf));

    structures::ArrayList<std::size_t> probg = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsg = Arraylist<Road>(3);
    probg.push_back(simulation::S2_L_sul_sul);
    probg.push_back(simulation::S2_L_centro_leste);
    probg.push_back(simulation::S2_L_norte_norte);
    roadsg.push_back(roads_->at(10));
    roadsg.push_back(roads_->at(13));
    roadsg.push_back(roads_->at(11));
    tlights_->push_back(new TrafficLight(roads_->at(4), roadsg, probg));

    structures::ArrayList<std::size_t> probh = ArrayList<std::size_t>(3);
    structures::ArrayList<Road>* roadsh = Arraylist<Road>(3);
    probh.push_back(simulation::S2_S_centro_oeste);
    probh.push_back(simulation::S2_S_leste_sul);
    probh.push_back(simulation::S2_S_leste_leste);
    roadsh.push_back(roads_->at(13));
    roadsh.push_back(roads_->at(11));
    roadsh.push_back(roads_->at(9));
    tlights_->push_back(new TrafficLight(roads_->at(5), roadsh, probh));

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
