#include "Politician.h"

bool Politician::operator==(const Politician & other)const
{
    return this->m_id == other.m_id;
}

void Politician::update()
{
    m_chairmen = m_party->getChairman();
}

const string& Politician::getFirstName() const
{
    return m_firstName;
}

const string& Politician::getId()const
{
    return m_id;
}

Party * Politician::getParty()const
{
    return m_party;
}

void Politician::setParty(Party * nParty)
{
    m_party = nParty;
    ///Have no party
    if(nParty == nullptr)
        m_chairmen = nullptr;
    else
        m_chairmen = nParty->getChairman();
}