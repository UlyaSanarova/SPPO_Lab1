#include <iostream>
#include "buildingcompany.h"

using namespace std;

int main()
{
    BuildingCompany myCompany;
    myCompany.setEmployeesCount(10);
    myCompany.addOwner("John");
    cout << "Tax for company '" << myCompany.getName().toStdString() << "' = " << myCompany.getTax() << endl;
    return 0;
}
