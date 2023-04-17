#include "LeaderDemocrat.h"

bool LeaderDemocrat::operator>(Politician *other)const
{
    if(other == nullptr)
        return true;
    return this->m_power > other->getPower();
}

int LeaderDemocrat::getPower() const
{
    return m_power;
}

void LeaderDemocrat::printPolitician() const
{
    cout << "Democratic Person:" << m_firstName << " " << m_lastName << ", Id:" << m_id << ", Power:" << m_power << ", Type:" << "L" << ", Chairman: ";
    if (m_chairmen == nullptr)
        cout << "None" << endl;
    else
        cout << m_chairmen->getFirstName() << endl;
}
