//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Picoxels>

#ifndef POLICE_HPP
#define POLICE_HPP

//! Classe Polícia
/* É a classe responsável por criar e destruir carros quando eles entram na/saem da simulação.
 */
class Police {
 public:
     Police(structures::ArrayList<Road> creators, structures::ArrayList<Road> destructors);

     void create_car();
     void delete_car();

 private:
     structures::ArrayList<Road> creators_;
     structures::ArrayList<Road> destructors_;
}

#endif
