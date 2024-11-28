#include "workers.hpp"
#include <iostream>
#include "config.hpp"

void Worker::print() const
{
    std::cout << "Rob. " << name_ << ", pensja: " << salary << ", rozmiar buta: " << shoe_ << std::endl;
}
void Engineer::print() const
{
    std::cout << "In�. " << name_ << ", pensja: " << salary << ", wydzia�: " << faculty_ << std::endl;
}
void Storeman::print() const
{
    std::cout << "Mag. " << name_ << ", pensja: " << salary << ", uprawnienia na w�zek: " << (forklift_ ? "tak" : "nie")
              << std::endl;
}
void Marketer::print() const
{
    std::cout << "Mkt. " << name_ << ", pensja: " << salary << ", liczba followers�w: " << follows_ << std::endl;
}

const double Engineer::CI = ENGINNER_EFFICIENCY;