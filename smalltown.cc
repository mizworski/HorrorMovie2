#include "smalltown.h"
#include "citizen.h"
#include "monster.h"
#include <vector>

typedef int Time;


class SmallTown{
public:
    class Builder;

private:
    Time t0; // czas startowy
    Time t1; // czas maksymalny
    GroupOfMOnsters groupOfMonsters = NULL;
    std::vector<Citizen> citizens; // should be a vector

public:
    SmallTown(Time t0, Time t1, GroupOfMOnsters groupOfMonsters, std::vector<Citizen> citizens ) :
            t0(t0), t1(t1), groupOfMonsters(groupOfMonsters), citizens(citizens) {}

};


class SmallTown::Builder{
private:
    // variables needed for construction of object of Product class
    Time t0; // czas startowy
    Time t1; // czas maksymalny
    std::vector<Citizen> citizens; // should be a vector
    GroupOfMOnsters groupOfMonsters;

public:
    SmallTown::Builder monster(GroupOfMOnsters groupOfMonsters) { this->groupOfMonsters = groupOfMonsters; return *this; }
    SmallTown::Builder startTime(const Time f ){ this->t0 = f; return *this; }
    SmallTown::Builder maxTime(const Time c ){ this->t1 = c; return *this; }
    SmallTown::Builder citizen(const Citizen c ){ this->citizens.push_back(c); return *this; }

    SmallTown build(){
        return SmallTown( this->t0, this->t1, groupOfMonsters,this->citizens );
    }
};