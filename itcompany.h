#ifndef ITCOMPANY_H
#define ITCOMPANY_H

#include "company.h"

// Класс "IT предприятие"
class ITCompany : public Company
{
public:
    ITCompany(const QString &name = "ITCompany");

    Type getType() const override;

    double getTax() const override;
};

#endif // ITCOMPANY_H
