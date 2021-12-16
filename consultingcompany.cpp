#include "consultingcompany.h"

ConsultingCompany::ConsultingCompany(const QString &name) : Company(name)
{
}

Company::Type ConsultingCompany::getType() const
{
    return TypeConsulting;
}

double ConsultingCompany::getTax() const
{
    auto ownersCount = getOwners().size();
    if (ownersCount == 0)
        return 0;
    return getSquare() * getIncome() / ownersCount;
}
