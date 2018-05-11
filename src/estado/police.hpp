//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Arthur Mesquita Pickcius>

#ifndef POLICE_HPP
#define POLICE_HPP

#include "time.hpp"
#include "../simulation.hpp"

//! Classe Polícia
/* É a classe responsável por criar e destruir carros quando eles entram na/saem da simulação.
 */
class Police {
 public:
     Police();
     Police(structures::ArrayList<Road> creators, structures::ArrayList<Road> destructors);

     void blitz(Time now);

     void create_car(Road road);
     void delete_car(Road road);

 private:
     struct Frequency {
       std::size_t freq;
       std::size_t var;

       Frequency(std::size_t frequency, std::size_t variation) : freq{frequency}, var{variation} {}
     }
     structures::ArrayList<Road> creators_;
     structures::ArrayList<Frequency> ctimes_;
     structures::ArrayList<Road> destructors_;
     Time last_time_;
};

Police::Police(structures::ArrayList<Road> creators, structures::ArrayList<Road> destructors) : creators_{creators}, destructors_{destructors}, last_time_{Time()} {
    ctimes_ = ArrayList<std::size_t>(creators.max_size());
    srand(0);

    ctimes_.push_back(Frequency(simulation::Oeste_fonte_f, simulation::Oeste_fonte_var));
    ctimes_.push_back(Frequency(simulation::N1sul_fonte_f, simulation::N1sul_fonte_var));
    ctimes_.push_back(Frequency(simulation::S1norte_fonte_f, simulation::S1norte_fonte_var));
    ctimes_.push_back(Frequency(simulation::N2sul_fonte_f, simulation::N2sul_fonte_var));
    ctimes_.push_back(Frequency(simulation::Leste_fonte_f, simulation::Leste_fonte_var));
    ctimes_.push_back(Frequency(simulation::S2norte_fonte_f, simulation::S2norte_fonte_var));

    for (auto i = 1u; i < ctimes_.max_size()+1; i++) {
        ctimes_.push_back(Frequency());
    }
}

void Police::blitz(Time now) {
}

#endif
