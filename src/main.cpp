// Kamil Breczko (280 990)

#include <iostream>
#include <sys/stat.h>
#include "Server.h"

#define MAX_PORT 65535
#define MIN_PORT 0

using namespace std;

void validInput(const char *port_s, const char *directory);

int main(int argc, char const *argv[]) {

    if (argc != 3) {
        cerr << "Incorrect input, two arguments were expected \n";
        return -1;
    }

    try {
        validInput(argv[1], argv[2]);

        uint16_t port = stoi(argv[1]);
        string directory = string(argv[2]);

        Server server(port, directory);
        server.run();
    } catch (const exception &e) {
        cerr << e.what();
        return -1;
    }

    return 0;
}

void validInput(const char *port_s, const char *directory) {
    int port = 0;
    struct stat buf{};
    stat(directory, &buf);

    try {
        port = stoi(port_s);
    } catch (const exception &e) {
        throw invalid_argument("Port must be positive number \n");
    }

    if (port < MIN_PORT || port > MAX_PORT)
        throw invalid_argument("Port must be between 0 and 65535 \n");

    if (!S_ISDIR(buf.st_mode))
        throw invalid_argument("Second argument is not directory \n");

}