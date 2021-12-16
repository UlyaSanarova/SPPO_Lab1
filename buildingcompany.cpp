#include "buildingcompany.h"

BuildingCompany::BuildingCompany(const QString &name) : Company(name)
{
}

Company::Type BuildingCompany::getType() const
{
    return TypeBuilding;
}

double BuildingCompany::getTax() const
{
    return 1.5 * (getOwners().size() + getEmployeesCount());
}
