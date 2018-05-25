// Kamil Breczko (280 990)

#include "ResponseBuilder.h"

uint32_t ResponseBuilder::createCode(Request request, string filePath) {
    if (request.method != "GET")
        return 501;

    if (request.path.find("../") != string::npos)
        return 403;

    if (isDirectory(filePath) && isRegular(filePath + "index.html"))
        return 301;

    if (isRegular(filePath))
        return 200;

    return 404;
}

string ResponseBuilder::buildBody(uint32_t code, string filePath) {
    if (code == 301)
        filePath += "index.html";
    if (code == 200 || code == 301) {
        ifstream file(filePath, ios::binary);
        ostringstream ostrm;
        ostrm << file.rdbuf();
        return string(ostrm.str());
    }
    if (code == 404)
        return "<b>404</b> Sorry, file not found :(";
    if (code == 403)
        return "<b>Forbidden</b>";
    if (code == 501)
        return "<b>Not Implemented</b>";

    throw runtime_error("Unknown response code \n");
}

string ResponseBuilder::buildHeader(uint32_t code, string filePath, string body) {
    string header = "HTTP/1.1 " + to_string(code) + ' ' + createMessage(code) + "\r\n";
    header += "Content-Type: " + createContentType(code, filePath) + "\r\n";
    header += "Content-Length: " + to_string(body.length()) + "\r\n";
    return header;
}

string ResponseBuilder::createMessage(uint32_t code) {
    switch (code) {
        case 200:
            return "OK";
        case 301:
            return "Moved Permanently";
        case 403:
            return "Forbidden";
        case 404:
            return "Not Found";
        case 501:
            return "Not Implemented";
    }

    throw runtime_error("Unknown response code \n");
}

string ResponseBuilder::createContentType(uint32_t code, string filePath) {
    string extension = filePath.substr(filePath.find_last_of('.') + 1);

    if (code != 200)
        return "text/html";
    if (extension == "txt")
        return "text/plain";
    if (extension == "html")
        return "text/html";
    if (extension == "css")
        return "text/css";
    if (extension == "jpg")
        return "image/jpeg";
    if (extension == "jpeg")
        return "image/jpeg";
    if (extension == "png")
        return "image/png";
    if (extension == "pdf")
        return "application/pdf";

    return "application/octet-stream";
}

bool ResponseBuilder::isDirectory(string filePath) {
    struct stat buf{};
    stat(filePath.c_str(), &buf);
    return S_ISDIR(buf.st_mode);
}

bool ResponseBuilder::isRegular(string filePath) {
    struct stat buf{};
    stat(filePath.c_str(), &buf);
    return S_ISREG(buf.st_mode);
}