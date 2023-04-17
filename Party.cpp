#include "Party.h"


void Party::notifyMembers()const
{
    for(Politician * currPol : m_partyMembers)
        currPol->update();
}

const string& Party::getName()const
{
    return m_name;
}


int Party::getNumMembers()const
{
    return (int)m_partyMembers.size();
}

Politician * Party::getChairman()const
{
    return this->m_chairman;
}


vector<Politician *> Party::getMembers()const
{
    return m_partyMembers;
}


void Party::removePolitician(Politician & memToRem)
{
    /// finds the politician in the vector inorder to delete it
    for(auto iter = m_partyMembers.begin(); iter != m_partyMembers.end(); iter++)
    {
        if (**iter == memToRem)
        {
            if (m_chairman != nullptr && memToRem == *m_chairman)
            {
                m_chairman = nullptr;
                notifyMembers();
            }
            m_partyMembers.erase(iter);
            break;
        }
    }
}


void Party::primaries()
{
    Politician * currLeader = nullptr;
    ///Find the leader
    for(Politician * curr_pol : m_partyMembers)
        if(*curr_pol > currLeader)
            currLeader = curr_pol;
    ///Notify the members on the leader identity
    m_chairman = currLeader;
    notifyMembers();
    if(m_chairman == nullptr)
        cout << "None";
    else
        cout << m_chairman->getFirstName();
    cout << " is the chairman of " << m_name << endl;
}


bool Party::operator>(Party & other)const
{
    return this->partyPower()>other.partyPower();
}


int Party::partyPower()const
{
    int totalPower = 0;
    for(Politician * m_partyMember : m_partyMembers)
        totalPower += m_partyMember->getPower();
    return totalPower;
}


void Party::printParty() const
{
    cout << m_name << ", " << "chairman:";
    if(m_chairman == nullptr)
        cout << "None";
    else
        cout << m_chairman->getFirstName();
    cout << ", Size:";
    cout << m_partyMembers.size() << endl;
    for(Politician * m_partyMember : m_partyMembers)
    {
        cout << '\t';
        m_partyMember->printPolitician();
    }
}

