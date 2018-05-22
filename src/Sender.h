// Kamil Breczko (280 990)

#ifndef WEB_SERVER_SENDER_H
#define WEB_SERVER_SENDER_H

#include <cstdint>
#include "Request.h"
#include <stdexcept>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include "Sockwrap.h"

class Sender {
    uint32_t createCode(Request request, string filePath);

    string buildHeader(uint32_t code, string filePath, string body);

    string buildBody(uint32_t code, string filePath);

    string createContentType(uint32_t code, string filePath);

    string createMessage(uint32_t code);

public:
    string constructResponse(Request request, string directory);

    void send(int conn_sockfd, string packet);
};

#endif
