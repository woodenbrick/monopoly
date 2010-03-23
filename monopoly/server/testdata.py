#!/usr/bin/env python
import sys
import urllib2
from urllib import urlencode
if sys.argv[1] == "local":
    url = "http://localhost:8080/"
else:
    url = "http://monopolyserver.appspot.com/"
def run_test(mapping, values={}):
    print "Running", mapping, "with values:", values
    request = urllib2.urlopen(url + mapping, urlencode(values))
    raw_input(">")
    return request

run_test("user/create", {"name" : "wode", "password" : "qwerty",
                        "email" : "wodemoneke@gmail.com"})
run_test("user/create", {"name" : "bory", "password" : "qwerty",
                        "email" : "wodemoneke@gmail.com"})
run_test("user/connect", {"name" :"wode"})
run_test("user/connect", {"name" : "bory"})
print run_test("game/create", {"name" : "wode", "locale" : "UK", "min" : 3,
                               "max" : 8}).read()
#run_test("game/join", {"game_id" :  "wode_1266506858.0", "name" : "bory"}))
run_test("user/disconnect", {"name" : "bory"})
