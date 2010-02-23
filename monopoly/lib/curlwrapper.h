#ifndef CURLWRAPPER_H
#define CURLWRAPPER_H

#include <string>
#include <iostream>
#include "curl/curl.h"

using namespace std;

// Write any errors in here

// Write all expected data in here
static string buffer;

// This is the writer call back function used by curl
static int writer(char *data, size_t size, size_t nmemb,
                  std::string *buffer);
string urlRetrieve(char* url);

#endif // CURLWRAPPER_H
