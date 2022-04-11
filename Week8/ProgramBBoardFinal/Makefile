a.out : main.o Message.o User.o BBoard.o Reply.o Topic.o
	g++ main.o -o a.out
    
main.o : main.cpp
	g++ -Wall -c main.cpp Message.h User.h BBoard.h Reply.h Topic.h
    
Message.o : Message.h Message.cpp
	g++ -Wall -c Message.cpp
    
User.o : User.h User.cpp
	g++ -Wall -c User.cpp
    
BBoard.o : BBoard.h BBoard.cpp Message.h Message.cpp
	g++ -Wall -c BBoard.cpp
    
Reply.o : Reply.cpp Reply.h
	g++ -Wall -c Reply.cpp
    
Topic.o : Topic.cpp Topic.h
	g++ -Wall -c Topic.cpp
    
clean :
	rm *.o a.out