#ifndef HORRORMOVIE2_SMALLTOWN_H
#define HORRORMOVIE2_SMALLTOWN_H

#include "citizen.h"
#include "monster.h"

typedef int Time;

class Status {
public:
    Status(std::string monsterName, HealthPoints monsterHealth, int aliveCitizens);

    std::string getMonsterName() const;

    HealthPoints getMonsterHealth() const;

    int getAliveCitizens() const;

private:
    std::string monsterName_;
    HealthPoints monsterHealth_;
    int aliveCitizens_;
};

class Strategy {
public:
    virtual bool isAttackingTime(Time &time) = 0;
};

class MyStrategy : public Strategy {
public:
    bool isAttackingTime(Time &time) override {
        return  ((time % 3 == 0) || (time % 13 == 0)) && (time % 7 != 0);
    }
};

class Clock {
public:
    virtual void increaseTime(Time timeStamp) = 0;

    virtual bool isAttackingTime() = 0;
};

class MyClock : public Clock {
public:
    MyClock(Time startTime, Time endTime, std::shared_ptr<Strategy> strategy);

    void increaseTime(Time timeStep) override;

    bool isAttackingTime() override;

private:
    Time actTime_;
    Time endTime_;
    std::shared_ptr<Strategy> strategy_;
};

class SmallTown {
public:
    class Builder;

    SmallTown(Time t0, Time t1, std::shared_ptr<Monster> monster, std::vector<std::shared_ptr<Citizen>> &citizens,
              std::shared_ptr<Strategy> strategy);

    void tick(Time timeStep);

    Status getStatus() const;

private:
    bool gameHasEnded() const;

    int countCitizens() const;

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

    Builder strategy(std::shared_ptr<Strategy> strategy);

    SmallTown build();

private:
    // variables needed for construction of object of Product class
    Time t0_; // czas startowy
    Time t1_; // czas maksymalny
    std::vector<std::shared_ptr<Citizen>> tempCitizens_; // should be a vector
    std::shared_ptr<Monster> monster_;
    std::shared_ptr<Strategy> strategy_ = std::make_shared<MyStrategy>();
};

#endif //HORRORMOVIE2_SMALLTOWN_H
