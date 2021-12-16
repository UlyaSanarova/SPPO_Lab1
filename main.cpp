#include <iostream>
#include "buildingcompany.h"
#include "itcompany.h"
#include "consultingcompany.h"

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

    ConsultingCompany myCompany3;
    myCompany3.setEmployeesCount(10);
    myCompany3.setIncome(999999);
    myCompany3.setSquare(100);
    myCompany3.setOwners(QList<QString>() << "John" << "Carl" << "Tom");
    cout << "Tax for company '" << myCompany3.getName().toStdString() << "' = " << myCompany3.getTax() << endl;

    ConsultingCompany myCompany4("Consultation+");
    myCompany4.setEmployeesCount(100);
    myCompany4.setIncome(10000);
    myCompany4.setSquare(100);
    cout << "Tax for company '" << myCompany4.getName().toStdString() << "' = " << myCompany4.getTax() << endl;
    return 0;
}
