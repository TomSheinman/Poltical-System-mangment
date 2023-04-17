#include "SocialRepublican.h"

bool SocialRepublican::operator>(Politician *other)const
{
    return false;
}

int SocialRepublican::getPower() const
{
    return 2 * m_power;
}

void SocialRepublican::printPolitician() const
{
    cout << "Republican Person:" << m_firstName << " " << m_lastName << ", Id:" << m_id << ", Power:" << m_power << ", Type:" << "S" << ", Chairman: ";
    if (m_chairmen == nullptr)
        cout << "None" << endl;
    else
        cout << m_chairmen->getFirstName() << endl;
}
