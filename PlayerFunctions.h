#ifndef PLAYERFUNCTIONS_H
#define PLAYERFUNCTIONS_H

#include "Players.h"
#include <iostream>
#include <string>

using namespace std;

void Players::setMoney(int money)
{
    playerMoney = money;
}

void Players::setSpace(int space)
{
    playerSpace = space;
}

void Players::setBankruptcy(bool bankruptcy)
{
    playerBankruptcy = bankruptcy;
}

int Players::getMoney()
{
    return playerMoney;
}

int Players::getSpace()
{
    return playerSpace;
}

bool Players::getBankruptcy()
{
    return playerBankruptcy;
}

#endif
