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

class Clock {
public:
    virtual void increaseTime(Time timeStamp) = 0;

    virtual bool isAttackingTime() = 0;
};

class MyClock : public Clock {
public:
    MyClock(Time startTime, Time endTime);

    void increaseTime(Time timeStep) override;

    bool isAttackingTime() override;

private:
    Time actTime_;
    Time endTime_;
};

class SmallTown {
public:
    class Builder;

    SmallTown(Time t0, Time t1, std::shared_ptr<Monster> monster, std::vector<std::shared_ptr<Citizen>> &citizens);

    void tick(Time timeStep);

    Status getStatus() const;

private:
    bool gameHasEnded();

    Status status_;
    MyClock clock_;

    std::shared_ptr<Monster> monster_;

    std::vector<std::shared_ptr<Citizen>> citizens_;
};

class SmallTown::Builder {
public:
    Builder();

    Builder monster(std::shared_ptr<Monster> monster);

    Builder startTime(const Time actTime);

    Builder maxTime(const Time c);

    Builder citizen(std::shared_ptr<Citizen> citizen);

    SmallTown build();

private:
    // variables needed for construction of object of Product class
    Time t0_; // czas startowy
    Time t1_; // czas maksymalny
    std::vector<std::shared_ptr<Citizen>> tempCitizens_; // should be a vector
    std::shared_ptr<Monster> monster_;
};

#endif //HORRORMOVIE2_SMALLTOWN_H
