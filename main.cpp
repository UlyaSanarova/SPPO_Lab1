#include <iostream>
#include "buildingcompany.h"
#include "itcompany.h"
#include "consultingcompany.h"
#include "registry.h"

using namespace std;

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

void printAllTax()
{
    auto reg = Registry::getInstance();
    for (int i = 0; i < reg->getCount(); i++) {
        auto company = reg->get(i);
        cout << "Tax for company '" << company->getName().toStdString() << "' = " << company->getTax() << endl;
    }
}

int main()
{
    try {
        cout << "Filling registry..." << endl;
        fillRegistry();
        cout << "Calculating tax..." << endl;
        printAllTax();
        cout << "Success!!!" << endl;
    } catch (...) {
        Registry::destroy();
        return 1;
    }
    return 0;
}
