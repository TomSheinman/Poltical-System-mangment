#pragma once
#include "Democrat.h"

class SocialDemocrat : public Democrat
{
public:
    /**
     * Constructor - creates a Social Democrat using the base class constructor
     * @param firstName - the politician first name
     * @param lastName - the politician last name
     * @param id - the politician id
     * @param power - represents the politician strength in the primaries to come
     */
    SocialDemocrat(string firstName, string lastName, string id, int power):
            Democrat(std::move(firstName), std::move(lastName), std::move(id), power){};


    /**
     * Copy Constructor creates a SocialDemocrat based on another SocialDemocrat
     * @param cPol - the SocialDemocrat we copy from
     */
    SocialDemocrat(SocialDemocrat & sdPol): Democrat(sdPol) {};


    /// default destructor
    ~SocialDemocrat() override =default;


    /**
     * This function compares two Social democrats based on their power in the primaries, do determine who can be a chairman of their party
     * because a social cant be a chairman and this function is used to determine the leader will return false in every case
     * @param other social Democrat we compare to
     */
    bool operator>(Politician * other)const override;


    /// returns the SocialDemocrat power in the primaries - twice its usual power
    int getPower()const override;


    /// prints the SocialDemocrat based on its variables
    void printPolitician()const override;
};

