// Kamil Breczko (280 990)

#ifndef WEB_SERVER_REQUEST_H
#define WEB_SERVER_REQUEST_H

#include <string>
#include <utility>

using namespace std;

typedef struct request {
    string method;
    string host;
    string path;
    string connection;

    request(string method, string host, string path, string connection)
            : method(move(method)), host(move(host)), path(move(path)), connection(move(connection)) {}
} Request;

#endif
