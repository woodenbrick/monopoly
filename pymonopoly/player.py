#!/usr/bin/env python
import pyglet
import random

from square import Street

class Player(object):
    
    def __init__(self, board, image_path):
        self.board = board
        self.current_square = self.board.squares[0]
        self.properties = []
        self.money = self.board.starting_money
        self.gojfc = []
        self.last_roll = 0
        self.doubles_rolled = 0
        self.in_jail = False
        self.jail_rolls = 0
        self.sets = []
        self.pending_house_purchases = []
        self.counter = pyglet.image.Sprite(pyglet.resource.image(image_path),
                                           *self.current_square.centre)
        
    def roll(self):
        die1 = random.choice([1, 2, 3, 4, 5, 6])
        die2 = random.choice([1, 2, 3, 4, 5, 6])
        if die1 == die2:
            self.doubles_rolled += 1
            if self.in_jail:
                self.in_jail = False
            if self.doubles_rolled == 3:
                self.in_jail = True
        else:
            self.doubles_rolled = 0
            if self.in_jail:
                self.jail_rolls += 1
                if self.jail_rolls == 3:
                    self.pay(50)
        self.last_roll = die1 + die2
        if self.in_jail:
            #XXX move to jail square
            pass
        else:
            self.board.move_counter(self)
    
    def pay(self, amount, player=None):
        """Return True if money was paid"""
        if self.money < amount:
            return False
        if player is not None:
            #payment to a player
            player.money += amount
        self.money -= amount
        return True
    
    def make_offer(self, cash=0, properties=[], gojfc=[], cash_player2=0,
                   properties_player2=[], gojfc_player2=[], other_player=None):
        """If other_player is set to None then the offer is made to all players
        but all player2 properties will be ignored apart from cash"""
        pass
    
    def go_to_jail(self):
        self.in_jail = True
        #XXX send token to jail square
    
    def has_set(self, property):
        set = self.board.get_set_by_property(property)
        for prop in set:
            if prop.owner != self:
                return False
        return True
    
    def purchase_property(self, property, player=None, amount=None):
        """Returns True if the property was purchased successfully"""
        if player is None and self.money < property.price:
            return False
        if player is not None and self.money < amount:
            return False
        property.owner = self
        if player is not None:
            player.money += amount
            self.money -= amount
        else:
            self.money -= property.price
        return True
    
    def return_house_hotel_count(self):
        """A tuple containing house/hotel count for this player"""
        houses = 0
        hotels = 0
        for prop in self.sets:
            if isinstance(prop, Street):
                if prop.houses == 5:
                    hotels += 1
                else:
                    houses += prop.houses
        return (houses, hotels)