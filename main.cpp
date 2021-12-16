#include <iostream>
#include "buildingcompany.h"
#include "itcompany.h"
#include "consultingcompany.h"
#include "registry.h"

using namespace std;

void printCompany(const Company &company)
{
    printf("Company '%s'\n", company.getName().toStdString().data());
    auto owners = company.getOwners();
    if (!owners.empty()) {
        printf("     Owners: ");
        for (int i = 0; i < owners.size(); i++) {
            if (i > 0) {
                if(i == owners.size() - 1)
                    printf(" and ");
                else
                    printf(", ");
            }
            printf("'%s'", owners.at(i).toStdString().data());
        }
        printf("\n");
    }
    printf("     Income: %.2f\n", company.getIncome());
    printf("     Square: %.4f\n", company.getSquare());
    printf("  Employess: %d\n", company.getEmployeesCount());
    printf("       Type: ");
    switch (company.getType()) {
    case Company::TypeBuilding:
        printf("Building\n");
        break;
    case Company::TypeIT:
        printf("IT\n");
        break;
    case Company::TypeConsulting:
        printf("Consulting\n");
        break;
    default:
        printf("<unknown>\n");
        break;
    }
    printf("        Tax: %.4f\n", company.getTax());
}

void fillRegistry()
{
    auto reg = Registry::getInstance();

    shared_ptr<Company> company = make_shared<BuildingCompany>();
    company->setEmployeesCount(10);
    company->addOwner("John");
    reg->add(company);

    company = make_shared<ITCompany>();
    company->setEmployeesCount(100);
    company->setIncome(10000);
    company->setOwners(QList<QString>() << "John" << "Carl");
    reg->add(company);

    company = make_shared<ConsultingCompany>();
    company->setEmployeesCount(10);
    company->setIncome(999999);
    company->setSquare(100);
    company->setOwners(QList<QString>() << "John" << "Carl" << "Tom");
    reg->add(company);

    company = make_shared<ConsultingCompany>("Consultation+");
    company->setEmployeesCount(100);
    company->setIncome(10000);
    company->setSquare(100);
    reg->add(company);
}

void printAll()
{
    auto reg = Registry::getInstance();
    for (int i = 0; i < reg->getCount(); i++) {
        auto company = reg->get(i);
        printCompany(*company);
        printf("\n");
    }
}

int main()
{
    try {
        fillRegistry();
        printAll();
    } catch (const std::exception &err) {
        printf("error: %s\n", err.what());
        Registry::destroy();
        return 1;
    } catch (...) {
        printf("unknown error\n");
        Registry::destroy();
        return 1;
    }
    return 0;
}
