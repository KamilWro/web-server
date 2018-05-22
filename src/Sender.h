// Kamil Breczko (280 990)

#ifndef WEB_SERVER_SENDER_H
#define WEB_SERVER_SENDER_H

#include <cstdint>
#include "Request.h"
#include "Sockwrap.h"

class Sender {
public:
    string constructResponse(Request request, string directory);

    void send(int conn_sockfd, string response);
};

#endif
