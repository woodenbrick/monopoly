#include "card.h"
#include <algorithm>
#include "board.h"
#include <iostream>

Card::Card(int id, QString text, bool isGojfc, int streetRepairs,
           int money, bool playerTransfer, int squareId)
{
    this->id = id;
    this->text = text;
    this->isGojfc = isGojfc;
    this->streetRepairs = streetRepairs;
    this->money = money;
    this->playerTransfer = playerTransfer;
    this->squareId = squareId;
}

void Card::printCard()
{
    std::cout << "id: " << id << "\n" << text.toStdString() << "\nGOJFC: " << isGojfc << "\nStreet repairs: "
            << streetRepairs << "\nMoney:" << money << "\nPlayer Transfer: " << playerTransfer <<
            "\nSquare Id: " << squareId << std::endl;

}

void Card::setDestinationSquare(Square* destination)
{
    square = destination;
}

CardStack::CardStack()
{

}

void CardStack::shuffle()
{
    std::random_shuffle(deck.begin(), deck.end());
    for(iter=deck.begin(); iter != deck.end(); iter++)
    {
        (*iter)->printCard();
    }
}

void CardStack::addToStack(Card *card)
{
    this->deck.push_back(card);
}

void CardStack::addToDiscardPile(Card *card)
{
    this->usedCards.push_back(card);
}


QString CardStack::pickup(Player *player)
{
    Card* currentCard = deck.back();
    deck.pop_back();
    if(currentCard->streetRepairs != 0)
    {
        //street repairs
        int debt;
        debt = (player->returnHouseCount() * currentCard->streetRepairs) + (player->returnHotelCount() * currentCard->money);
        player->createDebt(debt);
    }
    else if(currentCard->playerTransfer)
    {
        //payment to others/others to self
        //negative money amounts indicate a payment, positive a receipt
        for(std::vector<Player*>::iterator iter=player->otherPlayers->begin();
        iter != player->otherPlayers->end(); iter++)
        {
            if(currentCard->money < 0)
            {
                player->createDebt(std::abs(currentCard->money), *iter);
            }
            else
            {
                (*iter)->createDebt(currentCard->money, player);
            }
        }
    }
    else if(currentCard->money != 0)
    {
        //payment to the bank
        if (currentCard->money > 0)
        {
            player->receivePayment(currentCard->money);
        }
        else
        {
            player->createDebt(abs(currentCard->money));
        }
    }
    else if(currentCard->squareId >= 0)
    {
        //player has moved to a different square
        player->move(currentCard->square);
    }
    else if(currentCard->isGojfc)
    {
        //Get out of jail free card
        player->acquireGojfc(currentCard);
        //return early so we dont add card to discard pile
        return currentCard->text;
    }
    else
    {
        //special card, use the square attribute to figure out what to do.
        // -2 go to nearest railroad
        // -3 go to nearest utility
        // -4 go back 3 spaces
        if(currentCard->squareId == -2)
        {
            player->moveToNearestRailroad();
        }
        if(currentCard->squareId == -3)
        {
            player->moveToNearestUtility();
        }
        else
        {
            player->moveBack3Spaces();
        }
    }
    this->addToDiscardPile(currentCard);
    return currentCard->text;

}


void CardStack::useGojfc(Card *card)
{
    this->usedCards.push_back(card);
}


