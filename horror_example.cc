//
//  horror_example.cc
//  horror-movie-2
//
//  Created by Patrycja Wegrzynowicz on 12/10/16.
//  Copyright (c) 2016 Patrycja Wegrzynowicz. All rights reserved.
//

#include "citizen.h"
#include "smalltown.h"

int main() {


    auto groupOfMonsters = createGroupOfMonsters({
        createMummy(90, 1),
        createZombie(20, 1),
        createVampire(30, 1)
    });
    auto smallTown = SmallTown::Builder()
        .monster(groupOfMonsters)
        .startTime(3)
        .maxTime(27)
        .citizen(createSheriff(100, 35, 20))
        .citizen(createAdult(100, 21))
        .citizen(createTeenager(50, 14))
        .build();

    smallTown.tick(18);
    smallTown.tick(3);


    auto status_ = smallTown.getStatus();
    assert(status_.getMonsterName() == "GroupOfMonsters");
    assert(status_.getMonsterHealth() == 80);
    assert(status_.getAliveCitizens() == 3);


    return 0;
}
