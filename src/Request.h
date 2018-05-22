// Kamil Breczko (280 990)

#ifndef WEB_SERVER_REQUEST_H
#define WEB_SERVER_REQUEST_H

#include <string>

using namespace std;

typedef struct request {
    string method;
    string host;
    string connection;
    string path;

    request(string method, string host, string connection, string path)
            : method(method), host(host), connection(connection), path(path) {}
} Request;

#endif //WEB_SERVER_REQUEST_H
