#Gaspard Gentil

main.exe : obj/main.o
	g++ -Wall -g -o bin/main.exe obj/main.o

main.o : main.cpp
	g++ -Wall -o obj/main.o main.cpp

clean :
	-rm obj/*

veryclean : clean 
	-rm bin/* *~

