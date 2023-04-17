#pragma once
#include "Politician.h"

class Party;
class Republican : public Politician
{
public:
    /**
    * Constructor - creates a Republican using the base class constructor
    * @param firstName - the politician first name
    * @param lastName - the politician last name
    * @param id - the politician id
    * @param power - represents the politician strength in the primaries to come
    */
    Republican(string firstName, string lastName, string id, int power):
            Politician(std::move(firstName), std::move(lastName), std::move(id), power){};


    /**
     * Copy Constructor creates a Republican based on another Republican
     * @param cPol - the SocialDemocrat we copy from
     */
    Republican(Republican & sdPol): Politician(sdPol) {};


    /**
    * Adds a politician to a party by calling the addParty function on the relevant party class
    * @param party a party we add to
    * @return true if adds is successful, false if otherwise - party and politician types aren't matching
    */
    bool addToParty(Party & party) override;


    /// default destructor
    ~Republican() override =default;

};
