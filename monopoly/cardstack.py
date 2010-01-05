#!/usr/bin/env python
import random

class CardStack(object):
    def __init__(self, card_data):
        self.deck = []
        self.used_cards = []
        for card in card_data:
            self.deck.append(Card(card))
        random.shuffle(self.deck)
    
    def pickup(self, player):
        card = self.deck.pop(0)
        if card.is_gojfc:
            player.gojfc.append(card)
        else:
            self.used_cards.append(card)
        #when we reach the end of the deck we will shuffle
        if len(self.deck) == 0:
            self.deck, self.used_cards = self.used_cards, self.deck
            random.shuffle(self.deck)
    
    def return_gojfc(self, player):
        self.used_cards.append(player.gojfc.pop())
        

class Card(object):
    def __init__(self, data):
        self.id = data[0]
        self.text = data[1]
        self.is_gojfc = data[2]
        