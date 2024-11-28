#ifndef WORKERS_H
#define WORKERS_H

#include <string>
#include "RandomNameGenerator.hpp"
#include "config.hpp"

class Engineer
{public:
    Engineer() : name_(getRandomName()), faculty_(getRandomFaculty()) {
    }
    void print() const;
    const static double CI;
    const static int    salary = ENGINNER_SALARY;

private:
    std::string faculty_;
    std::string name_;
};

class Storeman
{
public:
    Storeman() : name_(getRandomName()), forklift_(getRandomForklift()) {}
    void             print() const;
    const static int CStr   = STOREMAN_EFFICIENCY;
    const static int salary = STOREMAN_SALARY;

private:
    bool forklift_;
    std::string name_;
};
class Marketer
{
public:
    Marketer() : name_(getRandomName()), follows_(getRandomFollows()) {}
    void             print() const;
    const static int CMkt   = MARKETER_EFFICIENCY;
    const static int salary = MARKETER_SALARY;

private:
    int follows_;
    std::string name_;
};
class Worker
{
public:
    Worker() : name_(getRandomName()), shoe_(getRandomShoe()) {}
    void             print() const;
    const static int CW     = WORKER_EFFICIENCY;
    const static int salary = WORKER_SALARY;

private:
    double shoe_;
    std::string name_;
};
struct VisitEmployees
{
    void operator()(Engineer& Eng) { Eng.print(); }
    void operator()(Storeman& Str) { Str.print(); }
    void operator()(Marketer& Mrk) { Mrk.print(); }
    void operator()(Worker& Wrk) { Wrk.print(); }
};


#endif // !WORKERS_H