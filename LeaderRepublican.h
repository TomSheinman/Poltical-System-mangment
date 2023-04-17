#pragma once
#include "Republican.h"

class LeaderRepublican : public Republican
{
public:
   /**
    * Constructor - creates a LeaderRepublican using the base class constructor
    * @param firstName - the politician first name
    * @param lastName - the politician last name
    * @param id - the politician id
    * @param power - represents the politician strength in the primaries to come
    */
    LeaderRepublican(string firstName, string lastName, string id, int power):
            Republican(std::move(firstName), std::move(lastName), std::move(id), power){};


    /**
     * Copy Constructor creates a LeaderRepublican based on another LeaderRepublican
     * @param cPol - the LeaderRepublican we copy from
     */
    LeaderRepublican(LeaderRepublican & sdPol): Republican(sdPol){};


    /// destructor
    ~LeaderRepublican() override =default;


    /**
     * This function compares two LeaderRepublican based on their power in the primaries, and returns true if the
     * left leader is has more power than the right one, false otherwise
     * @param other to LeaderRepublican we compare to
     */
    bool operator>(Politician * other)const override;


    /// returns the LeaderRepublican power in the primaries
    int getPower()const override;


    /// prints the LeaderRepublican based on its variables
    void printPolitician()const override;
};

