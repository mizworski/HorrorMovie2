#include <iostream>
#include "smalltown.h"


SmallTown::SmallTown(Time t0, Time t1, std::shared_ptr<Monster> monster,
                     std::vector<std::shared_ptr<Citizen>> &citizens) :
        clock_(t0, t1), monster_(monster), citizens_(citizens) {}

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

bool SmallTown::gameHasEnded() {
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

Status SmallTown::getStatus() const {
    return status_;
}

SmallTown::Builder SmallTown::Builder::monster(std::shared_ptr<Monster> monster) {
    this->monster_ = monster;
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
    return SmallTown(this->t0_, this->t1_, this->monster_, this->tempCitizens_);
}

SmallTown::Builder::Builder() {}

void Status::updateStatus() {

}

std::string Status::getMonsterName() const {
    return "";
}

HealthPoints Status::getMonsterHealth() const {
    return 0;
}

int Status::getAliveCitizens() const {
    return 0;
}

MyClock::MyClock(Time startTime, Time endTime) : actTime_(startTime), endTime_(endTime) {}

void MyClock::increaseTime(Time timeStep) {
    actTime_ = (actTime_ + timeStep) % (endTime_ + 1);
}

bool MyClock::isAttackingTime() {
    return (actTime_ % 3 == 0 || actTime_% 13 == 0) && actTime_% 7 != 0;
}
