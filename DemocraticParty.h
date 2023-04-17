#pragma once
#include "Party.h"
#include "Democrat.h"
#include "Republican.h"


class DemocraticParty : public Party
{
public:

    /**
     * Constructor - uses the Party constructor to create a new democratic party
     * @param name - the name of the party
     */
    explicit DemocraticParty(string name): Party(std::move(name)) {};


    /**
     * Copy constructor - uses the copy constructor of the party to create a new democratic party from an existing one
     * @param cDParty - the party to copy from
     */
    DemocraticParty(DemocraticParty &cDParty) : Party(cDParty) {};


    /// Destructor - default, no need to clear a vector of pointers
    ~DemocraticParty() override = default;

    /**
    * This Function receives a new Democrat and adds him to the party, hes now the newest member of the party
    * @param newMem - the new Democrat to add
    * @return true
    */
    bool addPolitician(Democrat & newDem) override;

    /** Overloading
     * will return false as a republican cant be in a democratic party
     * @param newMem a republican politician that tries to join the party
     * @return false
     */
    bool addPolitician(Republican & newRep) override;

    /** Prints the party - first will print the party details and the its members one by one
     *
     */
    void printParty()const override;

};

