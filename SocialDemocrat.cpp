#include "SocialDemocrat.h"

bool SocialDemocrat::operator>(Politician *other)const
{
    return false;
}

int SocialDemocrat::getPower() const
{
    return 2 * m_power;
}

void SocialDemocrat::printPolitician() const
{
    cout << "Democratic Person:" << m_firstName << " " << m_lastName << ", Id:" << m_id << ", Power:" << m_power << ", Type:" << "S" << ", Chairman: ";
    if (m_chairmen == nullptr)
        cout << "None" << endl;
    else
        cout << m_chairmen->getFirstName() << endl;
}
