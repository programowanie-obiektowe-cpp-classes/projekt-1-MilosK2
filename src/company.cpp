#include "company.hpp"
#include <variant>
#include "RandomNameGenerator.hpp"
#include <iostream>
#include "game.hpp"
#include "workers.hpp"
#include <numeric>
#include <ranges>

Company::Company()
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
       std::visit(VisitEmployees{}, e);
    }
}
void Company::get_loan()
{
    double amount      = 0;
    int    installment = 0;
    std::cout << "Wprowad« kwot© kredytu: ";
    std::cin >> amount;
    std::cout << std::endl << "Wprowad« liczb© rat: ";
    std::cin >> installment;
    std::cout << std::endl;

     double debt_sum =
        std::reduce(loans.begin(), loans.end(), 0, [](double acc, const Loan& obj) { return acc + obj.debt_; });

    if (installment > MAX_INSTALLMENT)
       std::cout << "Maksymalna liczba rat to 12" << std::endl;
    else if (debt_sum + amount > LOAN_LIMIT_COEFFICIENT* get_goodwill())
       std::cout << "Nie wolno przekroczyæ limitu zad³u¿enia" << std::endl;
    else
        loans.emplace_back(Loan(amount, installment));
}

void Company::pay_salary()
{
    for (auto& e : employees) {
       if (std::holds_alternative< Engineer >(e))
           account_balance -= Engineer::salary;
       else if (std::holds_alternative< Marketer >(e))
           account_balance -= Marketer::salary;
       else if (std::holds_alternative< Storeman >(e))
           account_balance -= Storeman::salary;
       else if (std::holds_alternative< Worker >(e))
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
       account_balance -= (it)->pay_installment();
       if ((it)->installment_left_ == 0)
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
    int    count   = 0;

    auto last3 = history | std::views::drop(std::max(0, static_cast< int >(history.size()) - 3));
    int  sum   = std::accumulate(last3.begin(), last3.end(), 0);

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