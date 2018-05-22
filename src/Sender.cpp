// Kamil Breczko (280 990)

#include "Sender.h"
#include "ResponseBuilder.h"

string Sender::constructResponse(Request request, string filePath) {
    ResponseBuilder responseBuilder;
    uint32_t code = responseBuilder.createCode(request, filePath);
    string body = responseBuilder.buildBody(code, filePath);
    string header = responseBuilder.buildHeader(code, filePath, body);
    return header + "\r\n" + body;
}

void Sender::send(int conn_sockfd, string response) {
    Send(conn_sockfd, response.c_str(), response.length(), 0);
}