#ifndef BUILDINGCOMPANY_H
#define BUILDINGCOMPANY_H

#include "company.h"

// Класс "Строительное предприятие"
class BuildingCompany : public Company
{
public:
    BuildingCompany(const QString &name = "BuildingCompany");

    Type getType() const override;

    double getTax() const override;
};

#endif // BUILDINGCOMPANY_H
