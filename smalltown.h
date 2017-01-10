#ifndef HORRORMOVIE2_SMALLTOWN_H
#define HORRORMOVIE2_SMALLTOWN_H

#include "citizen.h"
#include "monster.h"

typedef int Time;

class Status {
public:
    std::string getMonsterName() const;

    HealthPoints getMonsterHealth() const;

    int getAliveCitizens() const;

    void updateStatus();

private:
};

class SmallTown {
public:
    class Builder;

    SmallTown(Time t0, Time t1, GroupOfMonsters &groupOfMonsters, std::vector<std::shared_ptr<Citizen>> &citizens);

    void tick(Time timeStep);

    Status getStatus() const;

private:
    bool gameHasEnded();

    bool isAttackingTime();

    Status status_;

    Time actTime_; // czas startowy
    Time maxTime_; // czas maksymalny
    GroupOfMonsters monsters_;

    std::vector<std::shared_ptr<Citizen>> citizens_;
};

class SmallTown::Builder {
public:
    Builder();

    Builder monster(GroupOfMonsters const &groupOfMonsters);

    Builder startTime(const Time actTime);

    Builder maxTime(const Time c);

    Builder citizen(std::shared_ptr<Citizen> citizen);

    SmallTown build();

private:
    // variables needed for construction of object of Product class
    Time t0; // czas startowy
    Time t1; // czas maksymalny
    std::vector<std::shared_ptr<Citizen>> tempCitizens_; // should be a vector
    GroupOfMonsters groupOfMonsters;
};

#endif //HORRORMOVIE2_SMALLTOWN_H
