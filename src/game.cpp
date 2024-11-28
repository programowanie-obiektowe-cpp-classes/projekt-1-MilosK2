#include <iostream>
#include "game.hpp"
#include "config.hpp"
#include "company.hpp"
#include "workers.hpp"

void Game::run()
{   
    while (status) {
        user_move();
        turn++;
        check();
    }
    std::cin;
}

void Game::user_move()
{
    
    std::string inp;
    bool        next_turn = false;
    while (!next_turn)
    {
        std::cout << "Wprowad« komend©: ";
        std::cin >> inp;

        switch (map.at(inp))
        {
        case 1: //{"lp",1}, 
            company.print_employees();
            break;
        case 2: //{"zinz",2},
            company.hire< Engineer >();
            break;
        case 3: //{"zmag",3},
            company.hire< Storeman >();
            break;
        case 4: //{"zmkt",4},
            company.hire< Marketer >();
            break;
        case 5: //{"zrob",5},
            company.hire< Worker >();
            break;
        case 6: //{"kred",6},
            company.get_loan();
            break;
        case 7: //{"kt",7},
            next_turn = true;
            break;
        case 8: //{"pomoc",8}};
            help();
            break;
        default:
            std::cout << "Niepoprawna komenda\n";
            break;
        }
    }
}

bool Game::get_status()
{
    return status;
}

void Game::check()
{
    company.pay_salary();
    company.pay_credits();
    company.get_profit();

    std::cout << "\nStan konta w nowym miesi¥cu: " << company.get_account_balance()<<std::endl;
    if (company.get_account_balance() < 0)
    {
        std::cout << "Przegraˆe˜!\n" << std::endl;
        status = 0;
    }
    else if (company.get_goodwill() > GOODWILL_WINNING_VALUE)
    {
        std::cout << "Wygraˆe˜!\n" << std::endl;
        status = 0;
    }
    else {
        std::cout << "Nast©pna tura\n" << std::endl;
    }
}
void Game::help()
{
    std::cout << "\nLista komend:\n"
                 "lp - wylistuj pracownik¢w\n"
                 "zinz - zatrudnij in¾yniera\n"
                 "zmag - zatrudnij magazyniera\n"
                 "zmkt - zatrudnij marketingowca\n"
                 "zrob - zatrudnij robotnika\n"
                 "kred - we« kredyt\n"
                 "kt - zakoäcz tur©\n"
                 "pomoc - instrukcja komend\n";
}

double Loan::pay_installment()
    {
    double result = debt_ / static_cast< double > (installment_left_);
    installment_left_--;
    debt_ -= result;
    
    return result;
}
