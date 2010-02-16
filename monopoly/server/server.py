#!/usr/bin/env python
import time
from google.appengine.ext.webapp import RequestHandler, WSGIApplication
from google.appengine.ext.webapp.util import run_wsgi_app
from google.appengine.api import users
from google.appengine.ext.webapp.template import render 
import models

class NewUser(RequestHandler):
    def post(self):
        user = models.User(name=self.request.get("name"),
                    password=self.request.get("password"),
                    email=self.request.get("email"))
        user.put()
        
class CreateGame(RequestHandler):
    def post(self):
        creator = models.User.all().filter("name =", self.request.get("name")).get()
        #game id based on creator/time
        game_id = creator.name + "_" + str(round(time.time()))
        min_players = int(self.request.get("min"))
        max_players = int(self.request.get("max"))
        locale = self.request.get("locale")
        game = models.NewGame(game_id=game_id, creator=creator, ip=self.request.remote_addr,
                              locale=locale, current_player_count=1, current_player_names=[creator.name],
                       status="available", min_players=min_players, max_players=max_players)
        game.put()
        
class ListGames(RequestHandler):
    def get(self):
        games = models.NewGame.all().filter("status =", "available").fetch(100)
        self.response.headers['Content-type'] = "text/xml"
        self.response.out.write(render("templates/gamelist.xml", {"games" : games}))
        
    
class JoinGame(RequestHandler):
    def post(self):
        game = models.NewGame.all().filter("game_id =", self.request.get("game_id")).get()
        user = self.request.get("name")
        game.current_player_names.append(user)
        game.current_player_count += 1
        game.put()
        
class LeaveGame(RequestHandler):
    def post(self):
        game = models.NewGame.all().filter("game_id =", self.request.get("game_id")).get()
        user = self.request.get("name")
        game.current_player_names.remove(user)
    
class SaveGame(RequestHandler):
    def post(self):
        pass
    
class LoadGame(RequestHandler):
    def get(self):
        pass
    

app = WSGIApplication(
    [("/game/create", CreateGame),
    ("/game/list", ListGames),
    ("/game/leave", LeaveGame),
    ("/game/join", JoinGame),
    ("/user/create", NewUser)
    ],
    debug=True
    
)
run_wsgi_app(app)