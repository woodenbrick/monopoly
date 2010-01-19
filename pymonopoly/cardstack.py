#!/usr/bin/env python
import random

class CardStack(object):
    def __init__(self, card_data, board):
        self.deck = []
        self.used_cards = []
        for card in card_data:
            self.deck.append(Card(card, board))
        random.shuffle(self.deck)
    
    def pickup(self, player):
        card = self.deck.pop(0)
        card.use(player)
        if not card.is_gojfc:
            self.used_cards.append(card)
        #when we reach the end of the deck we will shuffle
        if len(self.deck) == 0:
            self.deck, self.used_cards = self.used_cards, self.deck
            random.shuffle(self.deck)
    
    def return_gojfc(self, player):
        self.used_cards.append(player.gojfc.pop())
        

class Card(object):
    def __init__(self, data, board):
        self.id = data[0]
        self.text = data[1]
        self.is_gojfc = data[2]
        if data[3] == 0:
            self.street_repairs = False
            self.money = data[4]
        else:
            self.street_repairs = True
            self.house = data[3]
            self.hotel = data[4]
        if data[5] == False:
            self.players = board.players
        else:
            self.players = None
        if self.move_square != -1:
            self.move_square = board.get_square_by_id(self.id)
        else:
            self.move_square = None
            
    def use(self, player):
        """Use the card and returns the text attribute"""
        if self.street_repairs:
            houses_owned, hotels_owned = player.return_house_hotel_count()
            player.pay((houses_owned * self.house) + (hotels_owned * self.hotel))
        elif self.players is not None:
            #a payment to others/others to self
            for p in self.players:
                if p is not player:
                    #self.money is negative if player is making a payment
                    p.money -= self.money
                    player.money += self.money
        elif self.money != 0:
            #a payment/receipt to the bank
            player.money += self.money
        elif self.move_square is not None:
            #move around the board
            if self.move_square == 10:
                #player was sent to jail
                player.go_to_jail()
            else:
                square = player.get_square_by_id(self.move_square)
                player.board.move_counter(square=square)
        elif card.is_gojfc:
            player.gojfc.append(card)
        return self.text
        