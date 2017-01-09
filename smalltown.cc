#include "smalltown.h"
#include <vector>


SmallTown::SmallTown(Time t0, Time t1, GroupOfMOnsters groupOfMonsters, std::vector<Citizen> citizens) :
        t0(t0), t1(t1), groupOfMonsters(groupOfMonsters), citizens(citizens) {}

SmallTown::Builder SmallTown::Builder::monster(GroupOfMOnsters groupOfMonsters) {
    this->groupOfMonsters = groupOfMonsters;
    return *this;
}

SmallTown::Builder SmallTown::Builder::startTime(const Time f) {
    this->t0 = f;
    return *this;
}

SmallTown::Builder SmallTown::Builder::maxTime(const Time c) {
    this->t1 = c;
    return *this;
}

SmallTown::Builder SmallTown::Builder::citizen(const Citizen c) {
    this->citizens.push_back(c);
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(this->t0, this->t1, this->groupOfMonsters, this->citizens);
}