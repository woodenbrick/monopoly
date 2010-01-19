#!/usr/bin/env python

class Square(object):
    
    def __init__(self, id, name, coords, set=None):
        """coords is a list of x1, x2, y1, y2 coordinates for this square"""
        self.id = id
        self.name = name
        self.coords = coords
        self.centre = [(coords[0] + coords[1]) / 2, (coords[2] + coords[3] / 2)]
        self.set = set
    
    def get_placement(self, player_list):
        """Gets the centre of this square, where we will place the token.
        if this area is already taken we will adjust the tokens and return a
        new placement"""
        adjustments = []
        space_taken = 0
        for player in player_list:
            if player.current_square == self:
                #add to adjustment list
                adjustments.append(player)
                space_taken += player.counter.width
        #if len(adjustments) == 0:
        #XXX currently just always places counter in centre
        return self.centre

            
            
        
    
    
class Property(Square):
    
    def __init__(self, id, name, coords, price, set, rent_list):
        """rent_list is [base_rent, 1 house, 2 houses etc.]
        for railroads/utilities it will just be the base rent"""
        Square.__init__(self, id, name, coords, set)
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
    
    def __init__(self, id, name, coords, price, set, rent_list, house_cost):
        Property.__init__(self, id, name, coords, price, set, rent_list)
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
    
    def __init__(self, id, name, coords, price, set):
        Property.__init__(self, id, name, coords, price, set)
        
    def return_rent(self, payer):
        if self.owner.properties_in_set_owned(self) == 1:
            return payer.last_roll * 4
        else:
            return payer.last_roll * 10
        
class Railroad(Property):
    
    def __init__(self, id, name, coords, price, set):
        Property.__init__(self, id, name, coords, price, set)
        
    def return_rent(self):
        multipler = [1, 2, 4, 8]
        return 25 * multipler[self.owner.properties_in_set_owned(self) + 1]
        
    
    