#include "DemocraticParty.h"

bool DemocraticParty::addPolitician(Democrat & newDem)
{
    m_partyMembers.push_back(&newDem);
    newDem.setParty(this);
    return true;
}

bool DemocraticParty::addPolitician(Republican & newRep)
{
    return false;
}

void DemocraticParty::printParty()const
{
    cout << "Democrat Party: ";
    Party::printParty();
}

