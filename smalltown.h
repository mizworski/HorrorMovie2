#ifndef HORRORMOVIE2_SMALLTOWN_H
#define HORRORMOVIE2_SMALLTOWN_H

#include "citizen.h"
#include "monster.h"

typedef int Time;

class SmallTown {
public:
    class Builder;

    SmallTown(Time t0, Time t1, GroupOfMOnsters groupOfMonsters, std::vector<Citizen> citizens);

private:
    Time t0; // czas startowy
    Time t1; // czas maksymalny
    GroupOfMOnsters groupOfMonsters;

    std::vector<Citizen> citizens; // should be a vector
};

class SmallTown::Builder {
public:
    Builder monster(GroupOfMOnsters groupOfMonsters);

    Builder startTime(const Time f);

    Builder maxTime(const Time c);

    Builder citizen(const Citizen c);

    SmallTown build();

private:
    // variables needed for construction of object of Product class
    Time t0; // czas startowy
    Time t1; // czas maksymalny
    std::vector<Citizen> citizens; // should be a vector
    GroupOfMOnsters groupOfMonsters;
};

#endif //HORRORMOVIE2_SMALLTOWN_H
