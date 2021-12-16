#include "company.h"

Company::Company(const QString &name, const QList<QString> &owners, double income, double square, int employeesCount) :
    m_name(name),
    m_owners(owners),
    m_income(income),
    m_square(square),
    m_employeesCount(employeesCount)
{
}

Company::~Company() {}

void Company::setName(const QString &name)
{
    m_name = name;
}

void Company::setOwners(const QList<QString> &owners)
{
    m_owners = owners;
}

void Company::setIncome(double income)
{
    m_income = income;
}

void Company::setSquare(double square)
{
    m_square = square;
}

void Company::setEmployeesCount(int count)
{
    m_employeesCount = count;
}

const QString &Company::getName() const
{
    return m_name;
}

const QList<QString> &Company::getOwners() const
{
    return m_owners;
}

double Company::getIncome() const
{
    return m_income;
}

double Company::getSquare() const
{
    return m_square;
}

int Company::getEmployeesCount() const
{
    return m_employeesCount;
}

void Company::addOwner(const QString &name)
{
    m_owners += name;
}
