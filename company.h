#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QList>

// Класс "Предприятие"
class Company
{
public:
    Company(const QString &name = "", const QList<QString> &owners = QList<QString>(), double income = 0, double square = 0, int employeesCount = 0);

    virtual ~Company();

    void setName(const QString &name);
    void setOwners(const QList<QString> &owners);
    void setIncome(double income);
    void setSquare(double square);
    void setEmployeesCount(int count);

    const QString &getName() const;
    const QList<QString> &getOwners() const;
    double getIncome() const;
    double getSquare() const;
    int getEmployeesCount() const;

    enum Type
    {
        TypeBuilding
    };
    virtual Type getType() const = 0;

    virtual double getTax() const = 0;

    void addOwner(const QString &name);

private:
    QString m_name;
    QList<QString> m_owners;
    double m_income;
    double m_square;
    int m_employeesCount;
};

#endif // COMPANY_H
