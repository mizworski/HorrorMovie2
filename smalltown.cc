#include "smalltown.h"
#include <vector>
#include <functional>


SmallTown::SmallTown(Time t0, Time t1, GroupOfMonsters &groupOfMonsters,
                     std::vector<std::shared_ptr<Citizen>> &citizens) :
        actTime_(t0), maxTime_(t1), citizens_(citizens), monsters_(groupOfMonsters) {}

void SmallTown::tick(Time timeStep) {
    if (!gameHasEnded()) {
        if (isAttackingTime()) {
            AttackPower citizensAttackPower = 0;
            for (auto &citizen : citizens_) {
                auto pt = citizen.get();
                citizen.get()->fightAgainstMonsters(monsters_);
            }
            monsters_.takeDamage(citizensAttackPower);
        }

        actTime_ = (actTime_ + timeStep) % maxTime_;
    }
}

bool SmallTown::gameHasEnded() {
    return false;
}

bool SmallTown::isAttackingTime() {
    return true;
}

SmallTown::Builder SmallTown::Builder::monster(GroupOfMonsters const &groupOfMonsters) {
    this->groupOfMonsters = groupOfMonsters;
    return *this;
}

SmallTown::Builder SmallTown::Builder::startTime(const Time actTime) {
    this->t0 = actTime;
    return *this;
}

SmallTown::Builder SmallTown::Builder::maxTime(const Time maxTime) {
    this->t1 = maxTime;
    return *this;
}

SmallTown::Builder SmallTown::Builder::citizen(Citizen const &citizen) {
    this->tempCitizens_.push_back(std::make_shared<Citizen>(citizen));
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(this->t0, this->t1, this->groupOfMonsters, this->tempCitizens_);
}

SmallTown::Builder::Builder() : groupOfMonsters({}) {}
