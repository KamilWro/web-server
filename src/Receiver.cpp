// Kamil Breczko (280 990)

#include "Receiver.h"

Request Receiver::receiveHTTP(int conn_sockfd) {
    Request request("", "", "", "");
    char buffer[IP_MAXPACKET + 1];
    ssize_t size = Recv(conn_sockfd, buffer, IP_MAXPACKET, 0);
    string data = string(buffer, size);

    request.method = extractMethod(data);
    request.path = extractPath(data);
    request.connection = extractHeader(data, "Connection");
    request.host = extractHeader(data, "Host");

    return request;
}

string Receiver::extractMethod(string request) {
    return request.substr(0, request.find(' '));
}

string Receiver::extractPath(string request) {
    request = request.substr(request.find(' ') + 1);
    return request.substr(0, request.find(' '));
}

string Receiver::extractHeader(string request, string key) {
    request = request.substr(request.find(key + ": ") + key.length() + 2);
    return request.substr(0, request.find('\r'));

}
