#include <iostream>
#include "buildingcompany.h"
#include "itcompany.h"
#include "consultingcompany.h"
#include "registry.h"

using namespace std;

void printCompanyType(Company::Type type)
{
    switch (type) {
    case Company::TypeBuilding:
        printf("Building");
        break;
    case Company::TypeIT:
        printf("IT");
        break;
    case Company::TypeConsulting:
        printf("Consulting");
        break;
    default:
        printf("<unknown>");
        break;
    }
}

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
    printCompanyType(company.getType());
    printf("\n");
    printf("        Tax: %.4f\n", company.getTax());
}

void fillRegistry()
{
    auto reg = Registry::getInstance();

    shared_ptr<Company> company = make_shared<BuildingCompany>();
    company->setEmployeesCount(10);
    company->addOwner("John");
    company->setSquare(100);
    reg->add(company);

    company = make_shared<BuildingCompany>("BuildPro");
    company->setEmployeesCount(100);
    company->setIncome(10000);
    company->addOwner("Carl");
    reg->add(company);

    company = make_shared<ITCompany>();
    company->setEmployeesCount(100);
    company->setIncome(10000);
    company->setOwners(QList<QString>() << "John" << "Carl");
    reg->add(company);

    reg->add(shared_ptr<Company>());

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

void printByType(Company::Type type)
{
    auto reg = Registry::getInstance();
    for (int i = 0; i < reg->getCount(); i++) {
        auto company = reg->get(i);
        if (company->getType() == type) {
            printCompany(*company);
            printf("\n");
        }
    }
}

void printByOwner(const QString &owner) {
    auto reg = Registry::getInstance();
    for (int i = 0; i < reg->getCount(); i++) {
        auto company = reg->get(i);
        if (company->getOwners().contains(owner)) {
            printCompany(*company);
            printf("\n");
        }
    }
}

void printAverageIncomeSquareEmployees()
{
    map<Company::Type, double> incomes, squares;
    map<Company::Type, int> employeesCounts, companiesCounts;

    auto reg = Registry::getInstance();
    for (int i = 0; i < reg->getCount(); i++) {
        auto company = reg->get(i);
        auto type = company->getType();
        incomes[type] += company->getIncome();
        squares[type] += company->getSquare();
        employeesCounts[type] += company->getEmployeesCount();
        companiesCounts[type]++;
    }

    auto companyTypes = QList<Company::Type>() << Company::TypeBuilding << Company::TypeIT << Company::TypeConsulting;
    for (const auto &type : companyTypes) {
        int count = companiesCounts[type];
        if (count != 0) {
            double in = incomes[type] / count;
            double sq = squares[type] / count;
            double employeesCount = double(employeesCounts[type]) / count;
            printf("Company type: ");
            printCompanyType(type);
            printf("\n");
            printf("     Avg. Income: %.4f\n", in);
            printf("     Avg. Square: %.4f\n", sq);
            printf("  Avg. Employees: %.4f\n", employeesCount);
            printf("\n");
        }
    }
}

int main()
{
    try {
        fillRegistry();

        printf("All companies {\n\n");
        printAll();
        printf("} // All companies\n\n");

        printf("IT Companies {\n\n");
        printByType(Company::TypeIT);
        printf("} // IT Companies \n\n");

        printf("Consulting Companies {\n\n");
        printByType(Company::TypeConsulting);
        printf("} // Consulting Companies\n\n");

        printf("Carl's Companies {\n\n");
        printByOwner("Carl");
        printf("} // Carl's Companies\n\n");

        printf("Tom's Companies {\n\n");
        printByOwner("Tom");
        printf("} // Tom's Companies\n\n");

        printf("Robert's Companies {\n\n");
        printByOwner("Robert");
        printf("} // Robert's Companies\n\n");

        printf("Statistics {\n\n");
        printAverageIncomeSquareEmployees();
        printf("} // Statistics\n\n");
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
