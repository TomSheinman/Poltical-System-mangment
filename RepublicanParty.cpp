#include "RepublicanParty.h"

bool RepublicanParty::addPolitician(Democrat & newDem)
{
    return false;
}

bool RepublicanParty::addPolitician(Republican & newRep)
{
    m_partyMembers.push_back(&newRep);
    newRep.setParty(this);
    return true;
}

void RepublicanParty::printParty()const
{
    cout << "Republican Party: ";
    Party::printParty();
}