#include "card.h"
#include <algorithm>
#include "board.h"

Card::Card(int id, QString text, bool isGojfc, int streetRepairs, int money, bool playerTransfer, int square)
{
    this->id = id;
    this->text = text;
    this->isGojfc = isGojfc;
    this->streetRepairs = streetRepairs;
    this->money = money;
    this->playerTransfer = playerTransfer;
    this->square = square;

}


CardStack::CardStack(std::vector<Card>deck)
{
    this->deck = deck;

}

void CardStack::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
}

void CardStack::addToStack(Card card)
{
    this->deck.push_back(card);
}

void CardStack::addToDiscardPile(Card card)
{
    this->usedCards.push_back(card);
}


QString CardStack::pickup(Player *player, std::vector<Player> *otherPlayers)
{
    Card currentCard = deck.back();
    deck.pop_back();
    if(currentCard.streetRepairs != 0)
    {
        //street repairs
        int debt;
        debt = (player->returnHouseCount() * currentCard.streetRepairs) + (player->returnHotelCount() * currentCard.money);
        player->createDebt(debt);
    }
    else if(currentCard.playerTransfer)
    {
        //payment to others/others to self
        //negative money amounts indicate a payment, positive a receipt
        for(int i=0; i<otherPlayers->size(); i++)
        {
            if(currentCard.money < 0)
            {
                player->createDebt(std::abs(currentCard.money), otherPlayers->at(i));
            }
            else
            {
                otherPlayers->at(i).createDebt(*currentCard.money, &player);
            }
        }
    }
    else if(currentCard.money != 0)
    {
        //payment to the bank
        if (currentCard.money > 0)
        {
            player->receivePayment(currentCard.money);
        }
        else
        {
            player->createDebt(abs(currentCard.money));
        }
    }
    else if(currentCard.square >= 0)
    {
        //player has moved to a different square
        player->move(currentCard.square);
    }
    else if(currentCard.isGojfc)
    {
        //Get out of jail free card
        player->addGojfc(currentCard);
        //return early so we dont add card to discard pile
        return currentCard.text;
    }
    else
    {
        //special card, use the square attribute to figure out what to do.
        // -2 go to nearest railroad
        // -3 go to nearest utility
        // -4 go back 3 spaces
        if(currentCard.square == -2)
        {
            player->moveToNearestRailroad();
        }
        if(currentCard.square == -3)
        {
            player->moveToNearestUtility();
        }
        else
        {
            player->moveBack3Spaces();
        }
    }
    this->addToDiscardPile(currentCard);
    return currentCard.text;

}


void CardStack::useGojfc(Card &card)
{
    this->usedCards.push_back(card);
}


