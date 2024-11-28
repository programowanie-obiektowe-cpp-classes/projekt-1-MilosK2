#ifndef COMPANY_H
#define COMPANY_H

#include <memory>
#include "workers.hpp"
#include <variant>
#include <vector>
#include <list>

class Company
{
public:
    Company();
    ~Company()            = default;
    using EmployeeVariant = std::variant<Engineer, Storeman, Marketer, Worker>;

    void print_employees();
    void get_credit();

    template<typename employee_t>
    void hire();

    void pay_salary();

    void get_profit();
    void pay_credits();

    double get_account_balance();
    double get_goodwill();

private:
    double calculate_profit();
    double account_balance = INIT_ACCOUNT_BALANCE;
    int    produced_goods=0;
    int Workers;
    int Engineers;
    int Marketers;
    int Storemans;

    std::vector< double >                                                              history;
    std::list<std::unique_ptr< class Loan >>                                           loans;
    std::vector<std::unique_ptr< std::variant< Engineer, Storeman, Marketer, Worker > >> employees;
    
};

template < typename employee_t >
void Company::hire()
{
    if constexpr (std::is_same_v< employee_t, Engineer >)
        Engineers++;
    else if constexpr (std::is_same_v< employee_t, Marketer >)
        Marketers++;
    else if constexpr (std::is_same_v< employee_t, Storeman >)
        Storemans++;
    else if constexpr (std::is_same_v< employee_t, Worker >)
        Workers++;

    employees.push_back(std::make_unique< EmployeeVariant >(employee_t(getRandomName())));
}

#endif // !COMPANY_H