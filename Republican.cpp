#include "Republican.h"

bool Republican::addToParty(Party &party)
{
    return party.addPolitician(*this);
}
