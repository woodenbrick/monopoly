#!/usr/bin/env python

import pyglet
import sqlite3


from square import Square
from cardstack import CardStack
from player import Player

class Board(object):
    
    def __init__(self, db, players):
        self.connection = sqlite3.Connection(db)
        self.cursor = self.connection.cursor()
        self.squares = []
        result = self.cursor.execute("""SELECT * FROM squares""").fetchall()
        for row in result:
            self.squares.append(Square(row))
        
        result = self.cursor.execute("""SELECT * FROM community_chest""").fetchall()
        self.community_chest = CardStack(result, self)
        result = self.cursor.execute("""SELECT * FROM chance""").fetchall()
        self.chance = CardStack(result, self)
        
        #these attributes should go somewhere else
        self.currency = "$"
        self.starting_money = 1500
        self.players = Player(self, "")
    
    def get_square_by_id(self, id):
        return [square for square in self.squares if square.id == id][0]
    
    def get_set_by_id(self, id):
        """Returns all the Properties in a set"""
        return [square for square in self.squares if square.set == self.squares[id].set]
    
    def get_set_by_property(self, property):
        return [square for square in self.squares if square.set == property.set]
    
    def move_counter(self, player, square=None):
        """Move player according to their last roll, or to a particular square if given"""
        if square is None:
            new_square = player.current_square.id + player.last_roll
            try:
                square = self.squares[new_square]
            except IndexError:
                #we have reached the end of the board
                square = self.squares[new_square - len(self.squares)]
        #XXX Move the counter to the appropriate square
        