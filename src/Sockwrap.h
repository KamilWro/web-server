// Kamil Breczko (280 990)

#ifndef WEB_SERVER_SOCKWRAP_H
#define WEB_SERVER_SOCKWRAP_H

#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <unistd.h>
#include <stdexcept>

using namespace std;

int Socket(int family, int type, int protocol);

void Bind(int fd, const struct sockaddr_in *sa, socklen_t salen);

int Accept(int fd, struct sockaddr_in *sa, socklen_t *salenptr);

void Listen(int fd, int backlog);

size_t Recv(int fd, char *ptr, size_t nbytes, int flags);

void Send(int fd, const char *ptr, int nbytes, int flags);

void Close(int fd);

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

#endif