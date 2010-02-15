#include <time.h>
#include <stdlib.h>
#include "dice.h"

Dice::Dice()
{
    srand(time(NULL));
    doublesRolled = 0;
    jailRolls = 0;
    rollStringDouble = " rolled a double %1";
    rollString = " rolled a %1 and a %2";
}

bool Dice::roll(bool inJail=false)
{
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    if(inJail)
    {
        if(die1 == die2)
        {
            doublesRolled++;
            jailRolls = 0;
        }
        else jailRolls++;
    }
    else if(die1 == die2)
    {
        doublesRolled++;
    }
    else
    {
        doublesRolled = 0;
    }
    return die1 + die2;
}

int Dice::getLastRoll()
{
    return die1 + die2;
}

QString& Dice::getLastRollString()
{
    if(die1 == die2)
    {
        return rollStringDouble.arg(die1);
    }
    return rollString.arg(die1).arg(die2);
}

int Dice::getDie1()
{
    return die1;
}


int Dice::getDie2()
{
    return die2;
}

int Dice::getJailRolls()
{
    return jailRolls;
}

bool tooManyDoubles()
{
    if(doublesRolled == 3)
    {
        return true;
    }
    return false;
}
