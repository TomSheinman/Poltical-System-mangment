#pragma once
#include "Party.h"
#include <string>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

class Party;
class Politician
{
protected:
    const string m_firstName;
    const string m_lastName;
    const string m_id;
    Party * m_party;
    Politician * m_chairmen;
    const int m_power;

public:

    /**
     * Constructor - creates a politician based on the parameters received
     * @param firstName - the politician first name
     * @param lastName - the politician last name
     * @param id - the politician id
     * @param power - represents the politician strength in the primaries to come
     */
    Politician(string  firstName, string  lastName, string id, int power): m_firstName(std::move(firstName)), m_lastName(std::move(lastName)),
                                                                         m_id(std::move(id)), m_power(power), m_party(nullptr), m_chairmen(nullptr){};


    /**
     * Copy Constructor creates a politician based on another politician
     * @param cPol - the politician we copy from
     */
    Politician(Politician & cPol): m_firstName(cPol.m_firstName), m_lastName(cPol.m_lastName),
                                   m_id(cPol.m_id), m_power(cPol.m_power), m_party(cPol.m_party), m_chairmen(cPol.m_chairmen){};


    /**
     * default destructor - the derived class will implement this
     */
    virtual ~Politician() = default;

    /**
     * This function is called from the party class to notify the politician that a new chairmen has been appointed
     * after this function is over the chairmen variable will be updated accordingly
     */
    void update();


     /// This function compares two politicians - the derived class will implement this, more information there
    virtual bool operator>(Politician * other)const = 0;


    /**
     * This function compares two politicians by their id.
     * @param other - the politician we compare to.
     * @return true - if their id is equal, false otherwise.
     */
    bool operator==(const Politician & other)const;


    /**
    * Adds a politician to a party by calling the relevant party and politician types by using double dispatch
    * @param party a party we add to
    * @return true if adds is successful, false if otherwise - party and politician types aren't matching
    */
    virtual bool addToParty(Party & party) = 0;


    ///A getter function for the first name of the politician
    const string& getFirstName()const;


    ///A getter function for the id of the politician
    const string& getId()const;


    ///A getter for the party of the politician
    Party * getParty()const;


    /**
     * setter for the politician party and its chairman - the chairman of that new party
     * @param nParty - the new party for the politician
     */
    void setParty(Party * nParty);


    ///This function returns the power of the politician - will be implemented in derived classes
    virtual int getPower()const = 0;


    ///This function prints a politician - will be implemented in derived classes
    virtual void printPolitician()const = 0;

};



