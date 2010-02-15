#!/usr/bin/env python
import time
from google.appengine.ext.webapp import RequestHandler
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.api import users
from google.appengine.ext.webapp.template import render
import models

class CreateGame(RequestHandler):
    def post(self):
        creator = users.User(self.request.get("email"))
        ip = self.request.remote_addr
        #game id based on creator/time
        game_id = email.nickname() + "_" + round(time.time())
        min_players = self.request.get("min")
        max_players = self.request.get("max")
        game = models.NewGame(game_id=game_id, creator=creator, ip=ip, current_players=1,
                       min_players=min_players, max_players=max_players)
        game.put()
        
class ListGames(RequestHandler):
    def get(self):
        pass
    
class JoinGame(RequestHandler):
    def post(self):
        pass
    
class LeaveGame(RequestHandler):
    def post(self):
        pass
    
class SaveGame(RequestHandler):
    def post(self):
        pass
    
class LoadGame(RequestHandler):
    def get(self):
        pass