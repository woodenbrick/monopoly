#!/usr/bin/env python

from google.appengine.ext import db

class NewGame(db.Model):
    game_id = db.IntegerProperty()
    creator = db.UserProperty()
    ip = db.StringProperty()
    locale = db.StringProperty()
    current_players = db.IntegerProperty()
    max_players = db.IntegerProperty()
    min_players = db.IntegerProperty()
    

class SavedGame(db.Model):
    game_id = db.IntegerProperty()
    creator = db.UserProperty()
    data = db.BlobProperty()
    

