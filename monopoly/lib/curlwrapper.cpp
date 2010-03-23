#include <string>
#include <iostream>
#include "curlwrapper.h"
using namespace std;

// Write any errors in here
static char errorBuffer[CURL_ERROR_SIZE];

// This is the writer call back function used by curl
static int writer(char *data, size_t size, size_t nmemb,
                  std::string *buffer)
{
  // What we will return
  int result = 0;

  // Is there anything in the buffer?
  if (buffer != NULL)
  {
    // Append the data to the buffer
    buffer->append(data, size * nmemb);

    // How much did we write?
    result = size * nmemb;
  }

  return result;
}


string urlRetrieve(char* url)
{
    cout << "Retrieving " << url << endl;
    // Our curl objects
    CURL *curl;
    CURLcode result;

    // Create our curl handle
    curl = curl_easy_init();

    if (curl)
    {
      // Now set up all of the curl options
      curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_HEADER, 0);
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

      // Attempt to retrieve the remote page
      result = curl_easy_perform(curl);

      // Always cleanup
      curl_easy_cleanup(curl);

      // Did we succeed?
      if (result != CURLE_OK)
      {
        cout << "Error: [" << result << "] - " << errorBuffer;

      }
    }
    return buffer;
}


namespace curlwrapper
{
    string urlRetrieve(string* url);
}
