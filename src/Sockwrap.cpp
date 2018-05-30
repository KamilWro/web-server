// Kamil Breczko (280 990)

#include "Sockwrap.h"

int Socket(int family, int type, int protocol) {
    int n;
    if ((n = socket(family, type, protocol)) < 0)
        throw runtime_error(string("socket error: ") + strerror(errno));
    return n;
}

void Bind(int fd, const struct sockaddr_in *sa, socklen_t salen) {
    if (bind(fd, (struct sockaddr *) sa, salen) < 0)
        throw runtime_error(string("bind error: ") + strerror(errno));
}

int Accept(int fd, struct sockaddr_in *sa, socklen_t *salenptr) {
    int n;
    if ((n = accept(fd, (struct sockaddr *) sa, salenptr)) < 0)
        throw runtime_error(string("accept error: ") + strerror(errno));
    return n;
}

void Listen(int fd, int backlog) {
    if (listen(fd, backlog) < 0)
        throw runtime_error(string("listen error: ") + strerror(errno));
}

size_t Recv(int fd, char *ptr, size_t nbytes, int flags) {
    ssize_t n = recv(fd, ptr, nbytes, flags);
    if (n < 0)
        throw runtime_error(string("recv error: ") + strerror(errno));
    ptr[n] = 0;
    return n;
}

void Send(int fd, const char *ptr, int nbytes, int flags) {
    if (send(fd, ptr, nbytes, flags) < nbytes)
        throw runtime_error(string("send error: ") + strerror(errno));
}

void Close(int fd) {
    if (close(fd) < 0)
        throw runtime_error(string("close error: ") + strerror(errno));
}

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout) {
    int n;
    if ((n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
        throw runtime_error(string("select error: ") + strerror(errno));
    return n;
}