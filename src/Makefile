# Kamil Breczko (280 990)

CXXFLAGS = -std=c++11 -Wall -Wextra

CXX = g++

main : main.o Server.o Sockwrap.o Sender.o Receiver.o ResponseBuilder.o
	$(CXX) $(CXXFLAGS) -o server main.o Server.o Sockwrap.o Sender.o Receiver.o ResponseBuilder.o

main.o : main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o  main.o

Server.o : Server.cpp Server.h Request.h
	$(CXX) -c $(CXXFLAGS) Server.cpp -o Server.o

Sockwrap.o : Sockwrap.cpp Sockwrap.h
	$(CXX) -c $(CXXFLAGS) Sockwrap.cpp -o  Sockwrap.o

Sender.o : Sender.cpp Sender.h Request.h
	$(CXX) -c $(CXXFLAGS) Sender.cpp -o  Sender.o

Receiver.o : Receiver.cpp Receiver.h Request.h
	$(CXX) -c $(CXXFLAGS) Receiver.cpp -o  Receiver.o

ResponseBuilder.o : ResponseBuilder.cpp ResponseBuilder.h Request.h
	$(CXX) -c $(CXXFLAGS) ResponseBuilder.cpp -o  ResponseBuilder.o

clean:
	rm -rf *.o

distclean:
	rm -rf *.o router .*.swp