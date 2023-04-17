#include "PoliticalSys.h"
#include <algorithm>


///------------------------------------------helper methods-------------------------------------///

void PoliticalSys::createPol(const string& fName, const string& lName, const string& id, int power, char paType, char pType)
{
    Politician * nPol;
    if(paType == 'D')
    {
        if (pType == 'S')
            nPol = new SocialDemocrat(fName, lName, id, power);
        else
            nPol = new LeaderDemocrat(fName, lName, id, power);
    }
    else
    {
        if (pType == 'S')
            nPol = new SocialRepublican(fName, lName, id, power);
        else
            nPol = new LeaderRepublican(fName, lName, id, power);
    }
    m_Politicians.push_back(nPol);
    ///Find a suitable party
    for(Party * party : m_Parties)
        partyIsSuitable(nPol, party);
}


void PoliticalSys::createParty(const string& pName, char pType)
{
    Party * nParty;
    if(pType == 'D')
        nParty = new DemocraticParty(pName);
    else
        nParty = new RepublicanParty(pName);
    m_Parties.push_back(nParty);
    m_partiesBySize.insert(nParty);
    ///Here we check for any politicians in the system if he can be added to the new party using the helper function
        for(Politician * politician : m_Politicians)
            partyIsSuitable(politician, nParty);
}


void PoliticalSys::checkInput(const vector<string> &inputs, const string &inputType) {
    ///Check that adding to politician input was correct
    if(inputType == "polAdd")
    {
        ///Check valid id
        for(char c : inputs[0])
            if(!isdigit(c))
                throw InvalidData();
        /// check that id is not in the system
        for(Politician * pol : m_Politicians)
            if(pol->getId() == inputs[0])
                throw InvalidData();
        if(inputs[0].length() == 1 && inputs[0][0] == '0') /// Id is 0
            throw InvalidData();
        ///Check valid Power
        for(char ch : inputs[1])
            if(!isdigit(ch))
                    throw InvalidData();
        ///Check valid party type
        if(inputs[2].length() != 1 || (inputs[2][0] != 'D' && inputs[2][0] != 'R'))
            throw InvalidData();
        ///Check valid politician type
        if(inputs[3].length() != 1 || (inputs[3][0] != 'S' && inputs[3][0] != 'L'))
            throw InvalidData();
    }
    ///Check that adding a party input was correct
    if(inputType == "partyAdd")
    {
        ///checks that party name is not in the system
        for(Party * party : m_Parties)
            if(party->getName() == inputs[0])
                throw InvalidData();
        ///Check valid party type
        if(inputs[1].length() != 1 || (inputs[1][0] != 'D' && inputs[1][0] != 'R'))
            throw InvalidData();
    }
    ///Check that removing a politician input was correct
    if(inputType == "remPol")
    {
        ///Check valid id
        for(char c : inputs[0])
            if(!isdigit(c))
                throw InvalidId();
    }
}



void PoliticalSys::partyIsSuitable(Politician * polToAdd, Party * partyToCheck)
{
    /// check if the conditions for moving to a new party are true
    if(polToAdd->getParty() == nullptr || partyToCheck->getNumMembers() < polToAdd->getParty()->getNumMembers())
    {
        /**To keep the set order we have to first delete the party then update it if needed and then add again
         * in this case we first remove the partyToCheck from the set, then try to add the politician and then return it
           same goes for his previous party, if he has one*/
        m_partiesBySize.erase(m_partiesBySize.find(partyToCheck));
        if(polToAdd->getParty() != nullptr)
        {
            Party * prevParty = polToAdd->getParty();
            if(polToAdd->addToParty(*partyToCheck)) /// if pol was added to the party(pol type is the same as party)
            {
                m_partiesBySize.erase(m_partiesBySize.find(prevParty));
                prevParty->removePolitician(*polToAdd);
                m_partiesBySize.insert(prevParty);
            }
        }
        else
            polToAdd->addToParty(*partyToCheck);
        m_partiesBySize.insert(partyToCheck);
    }
}


///------------------------------------------methods-------------------------------------///


PoliticalSys::PoliticalSys(const char* filePath)
{
    /// will use this to split each line to the politician/party arguments
    stringstream tokenizer;
    string currLine;
    ifstream fileRead(filePath);
    ///Politician arguments
    string firstName, lastName, id, partyName;
    int power;
    char partyType, polType;
    ///Skips "Politicians" and then read politicians
    getline(fileRead, currLine);
    while(getline(fileRead, currLine))
    {
        if(currLine.rfind("Parties", 0) == 0)
            break;
        else
        {
            tokenizer << currLine;
            tokenizer >> firstName >> lastName >> id >> power >> partyType >> polType;
            createPol(firstName, lastName, id, power, partyType, polType);
        }
    }
    ///Reading parties
    while(getline(fileRead, currLine))
    {
        tokenizer << currLine;
        tokenizer >> partyName >> partyType;
        createParty(partyName, partyType);
    }
}


PoliticalSys::~PoliticalSys()
{
    ///Delete Politician
    for(Politician * politician : m_Politicians)
        delete(politician);
    ///Delete parties
    for(Party * party : m_Parties)
        delete(party);
}


void PoliticalSys::addPolitician()
{
    string firstName, lastName, id, power, partyType, polType;
    cout << "---Create Politician---" << endl;
    while (true)
    {
        try {
            cout << "First name:" << endl;
            cin >> firstName;
            cout << "Last name:" << endl;
            cin >> lastName;
            cout << "ID:" << endl;
            cin >> id;
            cout << "Power:" << endl;
            cin >> power;
            cout << "Republican or Democratic person" << endl;
            cin >> partyType;
            cout << "Leader or Social" << endl;
            cin >> polType;
            const vector<string> v{id, power, partyType, polType};
            checkInput(v, "polAdd");
            break;
        }
        catch (InputError &e)
        {
            e.Handle();
        }
    }
    createPol(firstName, lastName, id, stoi(power), partyType[0], polType[0]);
}


void PoliticalSys::addParty()
{
    string partyName, partyType;
    cout << "---Create Party---" << endl;
    while(true)
    {
        try
        {
            cout << "Name:" << endl;
            cin >> partyName;
            cout << "Republican or Democratic party" << endl;
            cin >> partyType;
            vector<string> v{partyName, partyType};
            checkInput(v, "partyAdd");
            break;
        }
        catch (InputError &e)
        {
            e.Handle();
        }
    }
    createParty(partyName, partyType[0]);
}


void PoliticalSys::removePolitician()
{
    if(m_Politicians.empty())
        return;
    string id;
    Politician * currPol; /// Saves the politician to delete
    cout << "---Remove Politician---" << endl;
    while (true)
    {
        try
        {
            cout << "Enter the ID:" << endl;
            cin >> id;
            vector<string> v{id};
            checkInput(v, "remPol");
            bool deleted = false;
            /// We check that id is in the system and find to politician if it is
            for(int i = 0; i < m_Politicians.size(); i++)
            {
                currPol = m_Politicians[i];
                if(currPol->getId() == id)
                {
                    m_Politicians.erase(m_Politicians.begin() + i);
                    deleted = true;
                    break;
                }
            }
            if(deleted)
                break;
            throw InvalidId(); /// No Politician has the id that was input
        }
        catch (InputError &e)
        {
            e.Handle();
        }
    }
    Party * tParty = currPol->getParty();
    if(tParty != nullptr) /// update the set by deleting updating and inserting because we change a party in the set
    {
        m_partiesBySize.erase(m_partiesBySize.find(tParty));
        tParty->removePolitician(*currPol);
        m_partiesBySize.insert(tParty);
    }
    delete currPol;
}


void PoliticalSys::removeParty()
{
    if(m_Parties.empty())
        return;
    string partyName;
    Party *partyToDel; /// saves the party to delete
    cout << "---Remove Party---" << endl;
    while (true)
    {
        try
        {
            cout << "Enter party name:" << endl;
            cin >> partyName;
            bool deleted = false;
            /// We check if a party in the system has that name
            for(int i = 0; i < m_Parties.size(); i++)
            {
                partyToDel = m_Parties[i];
                if (partyToDel->getName() == partyName)
                {
                    m_Parties.erase(m_Parties.begin() + i);
                    m_partiesBySize.erase(m_partiesBySize.find(partyToDel));
                    deleted = true;
                    break;
                }
            }
            if (deleted)
                break;
            throw InvalidName(); /// No Party has the id that was input
        }
        catch (InputError &e)
        {
            e.Handle();
        }
    }
    vector<Politician *> delPartyMem = partyToDel->getMembers();
    delete partyToDel;
    for (Politician *polToMove : delPartyMem)
    {
        polToMove->setParty(nullptr); /// first we set the party to nullptr
        for (Party *currParty: m_Parties) /// find the suiting party of the same kind
            partyIsSuitable(polToMove, currParty);
    }
}


void PoliticalSys::printPoliticians()const
{
    if(m_Politicians.empty())
        return;
    cout << "----Politicians----" << endl;
    for (Politician * politician : m_Politicians)
        politician->printPolitician();
}


void PoliticalSys::printParties()const
{
    if(m_Parties.empty())
        return;
    cout << "----Parties----" << endl;
    for (Party * party : m_Parties)
        party->printParty();
}


void PoliticalSys::BiggestParty()const
{
    if(m_partiesBySize.empty())
        return;
    Party * biggestParty = *m_partiesBySize.begin();
    cout << "----Biggest Party----" << endl;
    cout << "[" << biggestParty->getName() << "," << biggestParty->getNumMembers() << "]" << endl;
}


void PoliticalSys::elections()const
{
    if(m_Politicians.empty() || m_Parties.empty())
        return;
    vector<Party *> mergeVector;
    cout << "----Primaries----" << endl;
    /// Run primaries for every party
    for(Party * party : m_Parties)
        party->primaries();
    cout << "----Elections----" << endl;
    /// Print the election results and find the maximum party based on the elections
    Party * maxParty = m_Parties[0];
    for(Party * currParty : m_Parties)
    {
        cout << "Party: " << currParty->getName() << ",Power: " << currParty->partyPower() << endl;
        if (*currParty > *maxParty)
            maxParty = currParty;
    }
    cout << "----Elections Results----" << endl;
    cout << maxParty->getName() << " party won the elections and ";
    if(maxParty->getChairman() == nullptr)
        cout << "None";
    else
        cout << maxParty->getChairman()->getFirstName();
    cout << " is the prime minister" << endl;
}
