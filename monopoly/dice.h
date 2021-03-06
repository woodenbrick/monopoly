#ifndef DICE_H
#define DICE_H
#include <QString>

class Dice
{
private:
    int doublesRolled;
    int jailRolls;
    int die1;
    int die2;
public:
    QString rollString;
    QString rollStringDouble;
    QString getLastRollString();
    Dice();
    int roll(bool inJail=false);
    int getLastRoll();
    int getDie1();
    int getDie2();
    int getJailRolls();
    bool tooManyDoubles();
};
#endif // DICE_H
