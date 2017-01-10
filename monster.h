#ifndef HORRORMOVIE2_MONSTER_H
#define HORRORMOVIE2_MONSTER_H

#include <vector>
#include <string>
#include "helper.h"

class Monster : public virtual Living, public virtual Attacking {
public:
    virtual const std::string getMonsterName() const = 0;
};

class SingleMonster : public virtual Monster {
public:
    SingleMonster(HealthPoints health, AttackPower attackPower, std::string monsterName);

    HealthPoints getHealth() const override;

    void takeDamage(AttackPower damage) override;

    AttackPower getAttackPower() const override;

    const std::string getMonsterName() const override;

private:
    HealthPoints healthPoints_;
    const AttackPower attackPower_;
    std::string monsterName_;

    void isAttackPowerValid(AttackPower attackPower) const;
};

class Zombie : public SingleMonster {
public :
    Zombie(HealthPoints health, AttackPower attackPower);
};

class Vampire : public SingleMonster {
public :
    Vampire(HealthPoints health, AttackPower attackPower);
};

class Mummy : public SingleMonster {
public :
    Mummy(HealthPoints health, AttackPower attackPower);
};

class GroupOfMonsters : public Monster {
public:
    GroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters);

    GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters);

    HealthPoints getHealth() const override;

    void takeDamage(AttackPower damage) override;

    AttackPower getAttackPower() const override;

    const std::string getMonsterName() const override;

private:
    std::vector<std::shared_ptr<Monster>> monsters_;
    std::string monsterName_;
};

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower);

GroupOfMonsters createGroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters);

#endif //HORRORMOVIE2_MONSTER_H
