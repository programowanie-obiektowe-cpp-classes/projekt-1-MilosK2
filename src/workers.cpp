#include "workers.hpp"
#include <iostream>
#include "config.hpp"

void Worker::print()
{
    std::cout << "Rob. " << name_ << ", pensja: " << salary << ", rozmiar buta: " << shoe_ << std::endl;
}
void Engineer::print()
{
    std::cout << "In¾. " << name_ << ", pensja: " << salary << ", wydziaˆ: " << faculty_ << std::endl;
}
void Storeman::print()
{
    std::cout << "Mag. " << name_ << ", pensja: " << salary << ", uprawnienia na w¢zek: " << (forklift_ ? "tak" : "nie")
              << std::endl;
}
void Marketer::print()
{
    std::cout << "Mkt. " << name_ << ", pensja: " << salary << ", liczba followers¢w: " << follows_ << std::endl;
}

const double Engineer::CI = ENGINNER_EFFICIENCY;