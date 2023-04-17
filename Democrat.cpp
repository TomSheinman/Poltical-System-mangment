#include "Democrat.h"

bool Democrat::addToParty(Party & party)
{
    return party.addPolitician(*this);
}