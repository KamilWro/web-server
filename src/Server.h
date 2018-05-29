// Kamil Breczko (280 990)

#ifndef WEB_SERVER_SERVER_H
#define WEB_SERVER_SERVER_H

#include <cstdint>
#include <string>
#include "Request.h"
#include <stdexcept>
#include "Sockwrap.h"
#include "Receiver.h"
#include "Sender.h"
#include <netinet/ip.h>
#include <iostream>
#include <sys/stat.h>

#define QUEUE_SIZE 64

using namespace std;

class Server {
    string directory;
    int sockfd;

    string createFilePath(request request) const;

public:
    Server(uint16_t port, string directory);

    ~Server();

    void run();

    void tryConnect() const;
};


#endif
