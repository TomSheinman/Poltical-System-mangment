#pragma once
#include "Party.h"
#include "Democrat.h"
#include "Republican.h"

class RepublicanParty : public Party
{
public:

    /**
     * Constructor - uses the Party constructor to create a new Republican party
     * @param name - the name of the party
     */
    explicit RepublicanParty(string name): Party(std::move(name)) {};


    /**
     * Copy constructor - uses the copy constructor of the party to create a new republican party from an existing one
     * @param cDParty - the party to copy from
     */
    RepublicanParty(RepublicanParty &cDParty): Party(cDParty) {};


    /// Destructor - default - no need to clear a vector of pointers
    ~RepublicanParty() override = default;


    /** Overloading
    * will return false as a Democrat cant be in a Republican party
    * @param newMem a Democrat politician that tries to join the party
    * @return false
    */
    bool addPolitician(Democrat & newDem) override;


    /**
    * This Function receives a new Republican and adds him to the party, hes now the newest member of the party
    * @param newMem - the new Republican to add
    */
    bool addPolitician(Republican & newRep) override;


    /// Prints the party - first will print the party details and then its members one by one by oldest to newest
    void printParty()const override;
};
