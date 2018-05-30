// Kamil Breczko (280 990)

#include "Server.h"

Server::Server(uint16_t port, string directory) : directory(directory) {
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    Bind(sockfd, &server_address, sizeof(server_address));
    Listen(sockfd, QUEUE_SIZE);

    if (directory[directory.length() - 1] != '/')
        directory += '/';
}

void Server::run() {
    while (true) {
        makeConnection();
    }

}

void Server::makeConnection() const {
    try {
        Receiver receiver;
        Sender sender;
        int conn_sockfd = Accept(sockfd, NULL, NULL);

        fd_set descriptors;
        FD_ZERO (&descriptors);
        FD_SET (conn_sockfd, &descriptors);
        struct timeval tv{};

        while (true) {
            tv.tv_sec = 1;
            tv.tv_usec = 0;

            int ready = Select(conn_sockfd + 1, &descriptors, NULL, NULL, &tv);

            if (ready == 0)
                break;

            Request request("", "", "", "close");
            string filePath;

            try {
                request = receiver.receiveHTTP(conn_sockfd);
                filePath = createFilePath(request);
                cout << "Request {" << request.method << " " << filePath << ", connection: " << request.connection
                     << "}" << endl;
            } catch (const exception &e) {
                cerr << "Invalid data received. " << e.what() << endl;
            }

            try {
                string response = sender.constructResponse(request, filePath);
                sender.send(conn_sockfd, response);
            } catch (const exception &e) {
                cerr << "Message has not been sent. " << e.what() << endl;
            }

            if (request.connection == "close")
                break;
        }

        Close(conn_sockfd);
    } catch (const exception &e) {
        cerr << "There was a problem with the connection. " << e.what() << endl;
    }
}

string Server::createFilePath(Request request) const {
    string host = request.host;
    host = host.substr(0, host.find_last_of(':'));
    string filePath = directory + "/" + host + request.path;

    struct stat buf{};
    stat(filePath.c_str(), &buf);

    if (S_ISDIR(buf.st_mode) && filePath[filePath.length() - 1] != '/')
        filePath += '/';

    return filePath;
}

Server::~Server() {
    Close(sockfd);
}