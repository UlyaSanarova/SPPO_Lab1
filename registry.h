#ifndef REGISTRY_H
#define REGISTRY_H

#include "company.h"
#include <QList>
#include <memory>

class Registry
{
    Registry();
    ~Registry();

public:
    static Registry *getInstance();

    static void destroy();

    void add(const std::shared_ptr<Company> &company);

    void remove(const std::shared_ptr<Company> &company);

    int getCount() const;

    std::shared_ptr<Company> get(int index) const;

private:
    QList<std::shared_ptr<Company>> m_companies;

    static Registry *m_instance;
};

#endif // REGISTRY_H
