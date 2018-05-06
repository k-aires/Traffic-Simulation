//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef TRAFFC_LIGHT_HPP
#define TRAFFIC_LIGHT_HPP

#include <cstdint>
#include <iostream>

#include "../structures/array_list.hpp"
#include "road.hpp"

//! Classe Semáforo
/*
 */
class TrafficLight {

 private:
     Road origin;
     structures::ArrayList<Road> destinations;
}
