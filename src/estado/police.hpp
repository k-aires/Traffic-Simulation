//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Arthur Mesquita Pickcius>

#ifndef POLICE_HPP
#define POLICE_HPP

#include "time.hpp"

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
     structures::ArrayList<Road> creators_;
     structures::ArrayList<std::size_t> ctimes_;
     structures::ArrayList<Road> destructors_;
     Time last_time_;
};

Police::Police(structures::ArrayList<Road> creators, structures::ArrayList<Road> destructors) : creators_{creators}, destructors_{destructors}, last_time_{Time()} {
    ctimes_ = ArrayList<std::size_t>(creators.max_size());
    srand(0);
    for (auto i = 1u; i < ctimes_.max_size()+1; i++) {
        ctimes_.push_back(rand()%10+rand()%10+i);
    }
}

void Police::blitz(Time now) {
}

#endif
