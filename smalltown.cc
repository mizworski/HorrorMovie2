#include "smalltown.h"


SmallTown::SmallTown(Time t0, Time t1, GroupOfMonsters &groupOfMonsters,
                     std::vector<std::shared_ptr<Citizen>> &citizens) :
        actTime_(t0), maxTime_(t1), monsters_(groupOfMonsters), citizens_(citizens) {}

void SmallTown::tick(Time timeStep) {
    if (!gameHasEnded()) {
        if (isAttackingTime()) {
            for (auto &citizen : citizens_) {
                citizen->fightAgainstMonster(std::make_shared<GroupOfMonsters>(monsters_));
            }
        }

        actTime_ = (actTime_ + timeStep) % (maxTime_ + 1);
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

SmallTown::Builder SmallTown::Builder::citizen(std::shared_ptr<Citizen> citizen) {
    this->tempCitizens_.push_back(citizen);
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(this->t0, this->t1, this->groupOfMonsters, this->tempCitizens_);
}

SmallTown::Builder::Builder() : groupOfMonsters({}) {}
