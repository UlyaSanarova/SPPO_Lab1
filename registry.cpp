#include "registry.h"

Registry::Registry()
{
}

Registry::~Registry ()
{
}

Registry *Registry::getInstance()
{
    if (m_instance == nullptr)
        m_instance = new Registry();
    return m_instance;
}

void Registry::destroy()
{
    delete m_instance;
    m_instance = nullptr;
}

void Registry::add(const std::shared_ptr<Company> &company)
{
    if (!company)
        return;
    for (const auto &c : m_companies) {
        if (c == company)
            return;
    }
    m_companies += company;
}

void Registry::remove(const std::shared_ptr<Company> &company)
{
    m_companies.removeAll(company);
}

int Registry::getCount() const
{
    return m_companies.size();
}

std::shared_ptr<Company> Registry::get(int index) const
{
    if (index < 0 || index >= m_companies.size())
        return std::shared_ptr<Company>();
    return m_companies.at(index);
}

Registry *Registry::m_instance = nullptr;
