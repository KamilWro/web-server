// Kamil Breczko (280 990)

#ifndef WEB_SERVER_RESPONSEBUILDER_H
#define WEB_SERVER_RESPONSEBUILDER_H

#include <cstdint>
#include "Request.h"
#include <stdexcept>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include "Sockwrap.h"
#include <cstdint>
#include <string>

using namespace std;

class ResponseBuilder {
    string createContentType(uint32_t code, string filePath);

    string createMessage(uint32_t code);

    bool isDirectory(string filePath);

    bool isRegular(string filePath);

public:

    string buildBody(uint32_t code, string filePath);

    string buildHeader(uint32_t code, string filePath, string body);

    uint32_t createCode(Request request, string filePath);
};

#endif
