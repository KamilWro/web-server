// Kamil Breczko (280 990)

#ifndef WEB_SERVER_RECEIVER_H
#define WEB_SERVER_RECEIVER_H

#include <netinet/ip.h>
#include <string>
#include "Sockwrap.h"
#include "Request.h"

using namespace std;

class Receiver {
    string extractHeader(string request, string key);

    string extractPath(string request);

    string extractMethod(string request);

public:
    Request receiveHTTP(int conn_sockfd);

    size_t find(string data, string pattern);
};


#endif
