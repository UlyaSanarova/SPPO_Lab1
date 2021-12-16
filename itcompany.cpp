#include "itcompany.h"

ITCompany::ITCompany(const QString &name) : Company(name)
{
}

Company::Type ITCompany::getType() const
{
    return TypeIT;
}

double ITCompany::getTax() const
{
    return 0.25 * getIncome() * (getOwners().size() + getEmployeesCount());
}
