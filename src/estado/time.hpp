//! Copyright [2018] <Helena Kunz Aires>
//! Copyright [2018] <Arthur Mesquita Pickius>

#ifndef TIME_HPP
#define TIME_HPP

#include <cstdlib>
#include <string>

//! Classe Tempo
/* Serve como medida de tempo da simulação, marcando horas, minutos e segundos.
 * A adição de tempo é feita apenas por segundos
 */
class Time {
 public:
     Time();

     void add(std::size_t seconds);
     std::string time();
     std::size_t seconds();

 private:
     std::size_t hour_{0u}, minute_{0u}, second_{0u};
};

Time::Time() {}

void Time::add(std::size_t seconds) {
    second_ += seconds;
    if (second_ >= 60) {
        second_ = second_ % 60;
        minute_ = (seconds - second_) / 60;
    }
}

std::string Time::time() {
    return std::to_string(hour_) + ":" + std::to_string(minute_) + ":" + std::to_string(second_);
}

std::size_t Time::seconds() {
    return second_ + (minute_ * 60) + (hour_ * 60 * 60);
}

#endif
