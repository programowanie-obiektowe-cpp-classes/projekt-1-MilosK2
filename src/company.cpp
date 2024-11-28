#include "company.hpp"
#include <variant>
#include "RandomNameGenerator.hpp"
#include <iostream>
#include "game.hpp"
#include "workers.hpp"

Company::Company() : Workers(0), Marketers(0), Engineers(0), Storemans(0), employees(0), loans(0), history(0)
{
    hire< Engineer >();
    hire< Marketer >();
    hire< Storeman >();
    hire< Worker >();
}
void Company::print_employees()
{
    for (auto& e : employees) 
    {
       std::visit(VisitEmployees{}, *e);
    }
}
void Company::get_credit()
{
    double amount      = 0;
    int    installment = 0;
    std::cout << "Wprowad« kwot© kredytu: ";
    std::cin >> amount;
    std::cout << std::endl << "Wprowad« liczb© rat: ";
    std::cin >> installment;
    std::cout << std::endl;

    loans.push_back(std::make_unique< Loan >(amount, installment));
}

void Company::pay_salary()
{
    for (auto& e : employees) {
       if (std::holds_alternative< Engineer >(*e))
           account_balance -= Engineer::salary;
       else if (std::holds_alternative< Marketer >(*e))
           account_balance -= Marketer::salary;
       else if (std::holds_alternative< Storeman >(*e))
           account_balance -= Storeman::salary;
       else if (std::holds_alternative< Worker >(*e))
           account_balance -= Worker::salary;
    }
}
void Company::get_profit()
{
    account_balance = account_balance + calculate_profit();
}
void Company::pay_credits()
{
    for (auto it = loans.begin(); it != loans.end();)
    {
       account_balance -= (*it)->pay_installment();
       if ((*it)->installment_left_ == 0)
           it = loans.erase(it);
       else
           ++it;
    }

}
double Company::get_account_balance()
{
    return account_balance;
}
double Company::get_goodwill()
{
    double sum = 0;
    int    count   = 0;
    for (auto iter = history.rbegin(); iter != history.rend() and iter != (history.rbegin() + 3); ++iter)
    {
       sum += *iter;
    }

    return sum;
}
double Company::calculate_profit()
{
    int warehouse_capacity = Storeman::CStr * Storemans;
    int demand             = Marketer::CMkt * Marketers;
    double price           = Engineer::CI * static_cast<double>(Engineers);
    produced_goods += Worker::CW * Workers < warehouse_capacity ? Worker::CW * Workers : warehouse_capacity;
    int selled_goods       = demand < produced_goods ? demand : produced_goods;
    double profit          = price * static_cast< double >(selled_goods);
    
    history.push_back(profit);

    return profit;
}