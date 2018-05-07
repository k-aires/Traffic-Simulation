//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef TRAFFC_LIGHT_HPP
#define TRAFFIC_LIGHT_HPP

#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "../structures/array_list.hpp"
#include "road.hpp"

//! Classe Semáforo
/*
 */
class TrafficLight {
 public:
     TrafficLight(Road origin, structures::ArrayList<Road> destinations);
     TrafficLight(Road origin, structures::ArrayList<Road> destinations, structures::ArrayList<int> probabilities);

     &Road origin();
     &Road destinanion();

     void open_light();

 private:
     Road origin_;
     structures::ArrayList<Road> destinations_;
     structures::ArrayList<int> probabilities_;
}

TrafficLight::TrafficLight(Road origin, structures::ArrayList<Road> destinations) : origin_{origin}, destinations_{destinations} {
    srand(0);
    probabilities = new ArrayList<int>(3);
    probabilities[0] = rand()%8 + 1;
    auto helper = 9 - probabilities[0];
    probabilities[1] = rand()%helper + 1;
    probabilities[2] = (helper+1) - probabilities[1];
}

TrafficLight::TrafficLight(Road origin, structures::ArrayList<Road> destinations, structures::ArrayList<int> probabilities) : origin_{origin}, destinations_{destinations}, probabilities_{probabilities} {}

&Road TrafficLight::origin() {return &origin_;}

&Road TrafficLight::destination() {
    srand(0);
    auto prob = rand()%10;

    if (prob < probabilities[0]) {
        return destinations[0];
    } else if (prob < probabilities[0] + probabilities[1]) {
        return destinations[1];
    }

    return destinations[2];
}

void TrafficLight::open_light() { // Terminar
    auto helper = destination();
    if (helper.free()) {
	    auto free_space_ = helper.max_size() - helper.size();
	    auto car_ = origin.remove_car();
	    if (car_.size() < free_space_) {
		    helper.add_car();		    
	    }
    } else {
    }
}

#endif
