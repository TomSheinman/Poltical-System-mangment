#pragma once
#include "Republican.h"

class SocialRepublican : public Republican
{
public:
    /**
     * Constructor - creates a SocialRepublican using the base class constructor
     * @param firstName - the politician first name
     * @param lastName - the politician last name
     * @param id - the politician id
     * @param power - represents the politician strength in the primaries to come
     */
    SocialRepublican(string firstName, string lastName, string id, int power):
            Republican(std::move(firstName), std::move(lastName), std::move(id), power){};


    /**
     * Copy Constructor creates a SocialRepublican based on another SocialRepublican
     * @param cPol - the SocialRepublican we copy from
     */
    SocialRepublican(SocialRepublican & sdPol): Republican(sdPol) {};


    /// default destructor
    ~SocialRepublican() override =default;


    /**
     * This function compares two social republican based on their power in the primaries, do determine who can be a chairman of their party
     * because a social cant be a chairman and this function is used to determine the leader will return false in every case
     * @param other to social republican we compare to
     */
    bool operator>(Politician * other)const override;


    /// returns the SocialRepublican power in the primaries - twice its usual power
    int getPower()const override;


    /// prints the SocialRepublican based on its variables
    void printPolitician()const override;
};