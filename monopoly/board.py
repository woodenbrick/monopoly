#!/usr/bin/env python

import pyglet
import sqlite3

class Board(object):
    
    def __init__(self, db):
        self.connection = sqlite3.Connection(db)
        self.cursor = self.connection.cursor()
        self.squares = []
        result = self.cursor.execute("""SELECT * FROM squares""").fetchall()
        for row in result:
            self.squares.append(Square(row))
        
        result = self.cursor.execute("""SELECT * FROM community_chest""").fetchall()
        self.community_chest = CardStack(result)
        result = self.cursor.execute("""SELECT * FROM chance""").fetchall()
        self.chance = CardStack(result)
        
    def get_set_by_id(self, id):
        """Returns all the Properties in a set"""
        return [square for square in self.squares if square.set == self.squares[id].set]
    
    def get_set_by_property(self, property):
        return [square for square in self.squares if square.set == property.set]
    
    def return_destination_square(self, player):
        new_square = player.current_square.id + player.last_roll
        try:
            return self.squares[new_square]
        except IndexError:
            #we have reached the end of the board
            return self.squares[new_square - len(self.squares)]