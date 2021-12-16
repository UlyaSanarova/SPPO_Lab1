#ifndef CONSULTINGCOMPANY_H
#define CONSULTINGCOMPANY_H

#include "company.h"

// Класс "Консалтинговое предприятие"
class ConsultingCompany : public Company
{
public:
    ConsultingCompany(const QString &name = "ConsultingCompany");

    Type getType() const override;

    double getTax() const override;
};

#endif // CONSULTINGCOMPANY_H
