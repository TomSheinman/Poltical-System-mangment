all: Ass5

Ass5: main.o DemocraticParty.o LeaderDemocrat.o LeaderRepublican.o PoliticalSys.o Politician.o Democrat.o Republican.o RepublicanParty.o SocialRepublican.o SocialDemocrat.o Party.o 
	g++ main.o DemocraticParty.o LeaderDemocrat.o LeaderRepublican.o PoliticalSys.o Politician.o Democrat.o Republican.o RepublicanParty.o SocialRepublican.o SocialDemocrat.o Party.o -o Ass5

main.o : main.cpp PoliticalSys.h
	g++ -c main.cpp
	
DemocraticParty.o: DemocraticParty.cpp DemocraticParty.h Party.h Democrat.h Republican.h
	g++ -c DemocraticParty.cpp

LeaderDemocrat.o : LeaderDemocrat.cpp LeaderDemocrat.h Democrat.h
	g++ -c LeaderDemocrat.cpp

LeaderRepublican.o: LeaderRepublican.cpp LeaderRepublican.h Republican.h
	g++ -c LeaderRepublican.cpp

Party.o : Party.cpp Party.h Politician.h
	g++ -c Party.cpp

PoliticalSys.o : PoliticalSys.cpp PoliticalSys.h DemocraticParty.h RepublicanParty.h LeaderDemocrat.h LeaderRepublican.h SocialDemocrat.h SocialRepublican.h Party.h InputExceptions.h
	g++ -c PoliticalSys.cpp

Politician.o : Politician.cpp Politician.h Party.h
	g++ -c Politician.cpp

Democrat.o : Democrat.cpp Democrat.h Politician.h 
	g++ -c Democrat.cpp
	
Republican.o : Republican.cpp Republican.h Politician.h 
	g++ -c Republican.cpp
		
RepublicanParty.o : RepublicanParty.cpp RepublicanParty.h Democrat.h Republican.h
	g++ -c RepublicanParty.cpp

SocialRepublican.o : SocialRepublican.cpp SocialRepublican.h Republican.h
	g++ -c SocialRepublican.cpp
	
SocialDemocrat.o : SocialDemocrat.cpp SocialDemocrat.h Democrat.h
	g++ -c SocialDemocrat.cpp

clean : 
	@echo 'cleaning'
	rm –f *.o

