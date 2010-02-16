#!/usr/bin/env python

from google.appengine.ext import db

class User(db.Model):
    name = db.StringProperty()
    password = db.StringProperty()
    email = db.EmailProperty()
    

class NewGame(db.Model):
    game_id = db.StringProperty()
    creator = db.ReferenceProperty(User)
    ip = db.StringProperty()
    status = db.StringProperty()
    locale = db.StringProperty()
    current_player_count = db.IntegerProperty()
    current_player_names = db.StringListProperty()
    max_players = db.IntegerProperty()
    min_players = db.IntegerProperty()
    

class SavedGame(db.Model):
    game_id = db.IntegerProperty()
    creator = db.UserProperty()
    data = db.BlobProperty()
    

