#ifndef HORRORMOVIE2_CITIZEN_H
#define HORRORMOVIE2_CITIZEN_H

#include "helper.h"
#include "monster.h"

class Citizen : public virtual Living {
public:
    Citizen(HealthPoints healthPoints, Age age) : healthPoints_(healthPoints),  age_(age) {}

    HealthPoints getHealth() const override;

    Age getAge() const;

    void takeDamage(AttackPower damage) override;

    virtual void fightAgainstMonster(std::shared_ptr<Monster> monster);

private:
    HealthPoints healthPoints_;
    const Age age_;
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age);
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age);
};

class Sheriff : public Citizen, public virtual Attacking {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attackPower);

    AttackPower getAttackPower() const override ;

    void fightAgainstMonster(std::shared_ptr<Monster> monster) override;

private:
    void isAttackPowerValid(AttackPower attackPower) const;

    const AttackPower attackPower_;
};

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age);

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age);

std::shared_ptr<Sheriff> createSheriff(HealthPoints health, Age age, AttackPower attackPower);

#endif //HORRORMOVIE2_CITIZEN_H
