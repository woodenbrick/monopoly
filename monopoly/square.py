#!/usr/bin/env python

class Square(object):
    
    def __init__(self, id, name, set=None):
        self.id = id
        self.name = name
        self.set = set
    
    
class Property(Square):
    
    def __init__(self, id, name, price, set, rent_list):
        """rent_list is [base_rent, 1 house, 2 houses etc.]
        for railroads/utilities it will just be the base rent"""
        Square.__init__(self, id, name, set)
        self.owner = None
        self.purchase_price = price
        self.is_mortgaged = False
        self.rent_list = rent_list
    
    def purchase(self, player):
        self.owner = player
        self.owner.money -= self.purchase_price
    
    def mortgage(self):
        self.is_mortgaged = True
        self.owner.money += self.purchase_price / 2
    
    def unmortgage(self):
        """Returns True if the property was unmortgaged successfully"""
        payment = (self.purchase_price / 2) + (self.purchase_price * 0.1)
        if self.owner.money >= payment:
            self.is_mortgaged = False
            self.owner.money -= payment
            return True
        return False
        
    
    def get_set(self):
        """Return a list of all properties in this set"""
        pass

class Street(Property):
    
    def __init__(self, id, name, price, set, rent_list, house_cost):
        Property.__init__(self, id, name, price, set, rent_list)
        self.house_cost = house_cost
        self.houses = 0
    
    def buy_houses(self, amount):
        self.houses += amount
        self.owner.money -= self.house_cost * amount
    
    def sell_houses(self, amount):
        self.houses += amount
        self.owner.money -= self.house_cost / 2 * amount
        
    def return_rent(self):
        if not self.owner.has_set(self):
            return self.rent_list[0]
        elif self.houses == 0:
            return self.rent_list[0] * 2
        else:
            return self.rent_list[self.houses]


class Utility(Property):
    
    def __init__(self, id, name, price, set):
        Property.__init__(self, id, name, price, set)
        
    def return_rent(self, payer):
        if self.owner.properties_in_set_owned(self) == 1:
            return payer.last_roll * 4
        else:
            return payer.last_roll * 10
        
class Railroad(Property):
    
    def __init__(self, id, name, price, set):
        Property.__init__(self, id, name, price, set)
        
    def return_rent(self):
        multipler = [1, 2, 4, 8]
        return 25 * multipler[self.owner.properties_in_set_owned(self) + 1]
        
    
    