#pragma once
#include <string>
#include "Politician.h"
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class Politician;
class Democrat;
class Republican;
class Party
{
protected:
    const string m_name;
    Politician * m_chairman{};
    vector<Politician *> m_partyMembers{};

    /// helper function that notify all the members of the party on the party new leader
    void notifyMembers()const;

public:
    /**
     * constructor - creates a new party
     * @param name - the new party name
     */
    explicit Party(string name) : m_name(std::move(name)), m_chairman(nullptr){};


    /**
     * Copy constructor - creates a new party using another party instance
     * @param cParty
     */
    Party(const Party &cParty): m_name(cParty.m_name), m_chairman(cParty.m_chairman), m_partyMembers(cParty.m_partyMembers){};


    /// Destructor - will set the party of the members to nullptr, no need to delete a vector of pointers
    virtual ~Party() = default;


    /// A getter for the name of the party
    const string& getName ()const;


    /// This function returns the number of members in the party
    int getNumMembers()const;


    /// A getter for The chairmen of the party, if there is no chairmen will return a null pointer
    Politician * getChairman()const;


    /// A getter for The members of the party, returns a vector of all the politicians in the party
    vector<Politician *> getMembers()const;


    /**
     * This Function receives a new Democrat and adds him to the party, each party kind will implement this differently
     * as a republican party cant add a democrat
     * @param newMem - the new politician to add
     */
    virtual bool addPolitician(Democrat &newDem) = 0;


    /** OverLoading
    * This Function receives a new Republican and adds him to the party, each party kind will implement this differently
    * as a Democrat party cant add a Republican
    * @param newMem - the new politician to add
    * @return true if added, false otherwise
    */
    virtual bool addPolitician(Republican &newRep) = 0;


    /**
     * This Function receives a party member and removes him from the party
     * @param memToRem - the member to remove
     * @return true if added, false otherwise
     */
    void removePolitician(Politician & memToRem);


    /**
     * This function finds the politician who is a leader with the highest power and selects him as the party chairmen
     * if there isn't a leader in the party there will be no chairmen.
     * if there are two leaders with the highest power the oldest member will be the chairmen
     */
    void primaries();


    /**
     * This function accumulates the party members powers and return it
     * @return the party total power
     */
    int partyPower()const;


    /**
     * receives two Party and compares their strengths during primaries and returns the result
     * @param other - the party we compare two
     * @return true if the left party is bigger than the right party, false otherwise
     */
     bool operator > (Party & other)const;


    /**
     * This function prints the party and its members by their order - oldest to newer member - its a virtual function
     * as each party (democratic / republican) prints differently
     */
    virtual void printParty()const = 0;

};


