#ifndef GAME_H
#define GAME_H

#include "company.hpp"
#include <unordered_map>

class Game
{
public:
    void run();
    void help();

private:
    bool get_status();
    void user_move();
    void check();

    Company company;
    bool    status = 1;
    int     turn   = 0;

    std::unordered_map< std::string, int > map{
        {"lp", 1}, {"zinz", 2}, {"zmag", 3}, {"zmkt", 4}, {"zrob", 5}, {"kred", 6}, {"kt", 7}, {"pomoc", 8}};
};
class Loan
{
public:
    Loan(double debt, int installment_left) : debt_(debt), installment_left_(installment_left){};
    double pay_installment();

    int    installment_left_;
    double debt_;
};

#endif // !GAME_H