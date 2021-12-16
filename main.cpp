#include <iostream>
#include "buildingcompany.h"
#include "itcompany.h"

using namespace std;

int main()
{
    BuildingCompany myCompany;
    myCompany.setEmployeesCount(10);
    myCompany.addOwner("John");
    cout << "Tax for company '" << myCompany.getName().toStdString() << "' = " << myCompany.getTax() << endl;

    ITCompany myCompany2;
    myCompany2.setEmployeesCount(100);
    myCompany2.setIncome(10000);
    myCompany2.setOwners(QList<QString>() << "John" << "Carl");
    cout << "Tax for company '" << myCompany2.getName().toStdString() << "' = " << myCompany2.getTax() << endl;
    return 0;
}
