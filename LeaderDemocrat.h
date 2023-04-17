#pragma once
#include "Democrat.h"

class LeaderDemocrat : public Democrat
{
public:
  /**
    * Constructor - creates a LeaderDemocrat using the base class constructor
    * @param firstName - the politician first name
    * @param lastName - the politician last name
    * @param id - the politician id
    * @param power - represents the politician strength in the primaries to come
    */
    LeaderDemocrat(string firstName, string lastName, string id, int power):
            Democrat(std::move(firstName), std::move(lastName), std::move(id), power){};


    /**
     * Copy Constructor creates a LeaderDemocrat based on another LeaderRepublican
     * @param cPol - the LeaderRepublican we copy from
     */
    LeaderDemocrat(LeaderDemocrat & sdPol): Democrat(sdPol) {};


    /// default destructor
    ~LeaderDemocrat() override =default;


    /**
     * This function compares two LeaderDemocrat based on their power in the primaries, and returns true if the
     * left leader is has more power than the right one, false otherwise
     * @param other to LeaderDemocrat we compare to
     */
    bool operator>(Politician * other)const override;


    /// returns the LeaderDemocrat power in the primaries
    int getPower()const override;


    /// prints the LeaderDemocrat based on its variables
    void printPolitician()const override;

};

