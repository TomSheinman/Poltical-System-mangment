#pragma once
#include "DemocraticParty.h"
#include "RepublicanParty.h"
#include "LeaderDemocrat.h"
#include "LeaderRepublican.h"
#include "SocialDemocrat.h"
#include "SocialRepublican.h"
#include <set>
#include <fstream>
#include <sstream>
#include "InputExceptions.h"

/// A functor we'll use to compare party sizes based on 1 - number of politicians in the party 2 - the party name
class partyComp
{
public:
    bool operator() (const Party * lParty, const Party * rParty) const
    {
        if (lParty->getNumMembers() == rParty->getNumMembers())
            return lParty->getName() > rParty->getName();
        return lParty->getNumMembers() > rParty->getNumMembers();
    }
};


class PoliticalSys
{
    vector<Politician *> m_Politicians; ///Vector that stores all the Politicians in the system
    vector<Party *> m_Parties; ///Vector that stores all the Parties in the system
    set<Party *, partyComp> m_partiesBySize; ///Stores the Parties ordered by their size


    /**
     * Helper function that adds a new politician to a party based on these conditions :
     * 1- they belong to the same kind of party (democrat/republican) - well check it by trying to add the politician to the party
     * will check this condition after the 2nd condition
     * 2- if they dont have a party or their current party has more members than the one we want to add to
     * if he answer these conditions we change the politician party to the suitable party
     * @param polToAdd - the politician we want to add to a party
     * @param partyToCheck - the party we want to check if the politician is suitable to be added to
     */
    void partyIsSuitable(Politician * polToAdd, Party * partyToCheck);


    /**
     * Helper function for creating a new politician, receives all the parameters needed to create that politician
     * and adds him to the politicians vector and finds him a suitable party using the findSuitableParty function
     * @param fName - the first name of the politician
     * @param lName - the last name of the politician
     * @param id - the politician id
     * @param power - the politician power
     * @param paType - the party type of the politician (democrat/republican)
     * @param pType - the politician type (social/leader)
     */
    void createPol(const string& fName, const string& lName, const string& id, int power, char paType, char pType);


    /**
     * Helper function for creating a new party, receives all the parameters needed to create that party
     * @param pName - the new party name
     * @param pType - the new party type (democrat/politician)
     */
    void createParty(const string& pName, char pType);


    /**
     * Helper function for input checking, will receive an vector of strings that was received from the user
     * and the function it was send from (via string) and will check if its legal, if not will throw an exception
     * @param inputStr - a vector of string from the user of inputs to check
     * @param inputType - the function it was send from like - "addPol", "addParty", "remPol".
     */
    void checkInput(const vector<string>& inputs, const string& inputType);


public:
    ///Default Constructor
    PoliticalSys()= default;


    /**
     * Constructor the receives a filePath that stores parties and politicians and initializes the system accordingly
     * @param filePath - the path to the file from which we read and create the system
     */
    explicit PoliticalSys(const char* filePath);


    /**
     * Destructor - cleans everything in the database - all the politicians and the parties, no need to
     * clean the containers as they hold pointers and clear themselves
     */
    ~PoliticalSys();


    /**
     * This function adds a politician to the system according to user input received in the function
     * (first name, last name and so on) if one of the parameters received is invalid the user will have to input them again
     */
    void addPolitician();


    /**
     * This function adds a party to the system according to user input received in the function
     * if one of the parameters received is invalid the user will have to input them again
     */
    void addParty();


    /**
     * This Functions removes a Politician from a party in the system based on input received from the user
     * if one of the parameters received is invalid the user will have to input them again
     * if there are no politicians in the system the function will do nothing
     */
    void removePolitician();


    /**
     * This Functions removes a Party from the system based on input received from the user
     * if one of the parameters received is invalid the user will have to input them again
     * if there are no parties in the system the function will do nothing
     * the politicians from that party move by order of insertion, they find the smallest
     * party that belongs to the same political party as they are
     */
    void removeParty();


    /**
     * This function runs in there phases -
         * First phase - every party in the system runs a primaries meaning finds the strongest leader from that party.
         * after that each party prints the result of the primaries.
         * Second phase - every party calculates it total power and prints itself and its power
         * Third phase - the result of the election are printed - the strongest party and its leader
     * if there are no parties or politicians in the system nothing will happen
     */
    void elections()const;


    /**
     * This function prints all the politicians in the system by their time of entrance (vector order)
     */
    void printPoliticians()const;


    /**
     * This function prints the parties in the system by their time of entrance (vector order)
     */
     void printParties()const;


     /**
      * This function finds and prints the biggest party in the system (by the amount of politicians in the party)
      * if there is a tie the tiebreak will be decided by comparing there names
      * will find the biggest party in O(1) using the set first element
      */
     void BiggestParty()const;

};
