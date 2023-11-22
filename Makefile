#Gaspard Gentil

main.exe : main.o
	g++ -g main.o -omain.exe

clean :
	-rm *.o *~

veryclean : clean 
	-rm *.exe

