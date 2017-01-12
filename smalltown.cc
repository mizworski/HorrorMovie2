#include <iostream>
#include "smalltown.h"


SmallTown::SmallTown(Time t0, Time t1, std::shared_ptr<Monster> monster,
                     std::vector<std::shared_ptr<Citizen>> &citizens,
                     std::shared_ptr<Strategy> strategy) :
        clock_(t0, t1,strategy), monster_(monster), citizens_(citizens) {}

void SmallTown::tick(Time timeStep) {
    if (!gameHasEnded()) {
        if (clock_.isAttackingTime()) {
            for (auto &citizen : citizens_) {
                citizen->fightAgainstMonster(monster_);
            }
        }
        clock_.increaseTime(timeStep);
    }
}

Status SmallTown::getStatus() const {
    return Status(this->monster_->getMonsterName(), this->monster_->getHealth(), countCitizens());
}

bool SmallTown::gameHasEnded() const {
    HealthPoints monstersHealth = monster_->getHealth();
    HealthPoints citizensHealth = 0;

    for (auto &citizen : citizens_) {
        citizensHealth += citizen->getHealth();
    }

    if (citizensHealth == 0 && monstersHealth == 0) {
        std::cout << "DRAW" << std::endl;
        return true;
    } else if (citizensHealth == 0) {
        std::cout << "MONSTER WON" << std::endl;
        return true;
    } else if (monstersHealth == 0) {
        std::cout << "CITIZENS WON" << std::endl;
        return true;
    } else {
        return false;
    }
}

int SmallTown::countCitizens() const {
    int citizensAlive = 0;

    for (auto &citizen : citizens_) {
        if (citizen->getHealth() > 0) {
            ++citizensAlive;
        }
    }

    return citizensAlive;
}

SmallTown::Builder SmallTown::Builder::monster(std::shared_ptr<Monster> monster) {
    this->monster_ = monster;
    return *this;
}

SmallTown::Builder SmallTown::Builder::strategy(std::shared_ptr<Strategy> strategy) {
    this->strategy_ = strategy;
    return *this;
}

SmallTown::Builder SmallTown::Builder::startTime(const Time actTime) {
    this->t0_ = actTime;
    return *this;
}

SmallTown::Builder SmallTown::Builder::maxTime(const Time maxTime) {
    this->t1_ = maxTime;
    return *this;
}

SmallTown::Builder SmallTown::Builder::citizen(std::shared_ptr<Citizen> citizen) {
    this->tempCitizens_.push_back(citizen);
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(this->t0_, this->t1_, this->monster_, this->tempCitizens_,this->strategy_);
}

SmallTown::Builder::Builder() {}

Status::Status(std::string monsterName,
               HealthPoints monsterHealth,
               int aliveCitizens) : monsterName_(monsterName),
                                    monsterHealth_(monsterHealth),
                                    aliveCitizens_(aliveCitizens) {}

std::string Status::getMonsterName() const {
    return monsterName_;
}

HealthPoints Status::getMonsterHealth() const {
    return monsterHealth_;
}

int Status::getAliveCitizens() const {
    return aliveCitizens_;
}

MyClock::MyClock(Time startTime, Time endTime,std::shared_ptr<Strategy> strategy) : actTime_(startTime), endTime_(endTime),strategy_(strategy) {}

void MyClock::increaseTime(Time timeStep) {
    actTime_ = (actTime_ + timeStep) % (endTime_ + 1);
}

bool MyClock::isAttackingTime() {
    return this->strategy_.get()->isAttackingTime(actTime_);
}
