CC = gcc 
AR = ar

FLAGS = -Wall -g

ALLc = Main.c StrList.c



StrList: Main.o
	$(CC) $(FLAGS) -o Main main.o

Main.o: main.c StrList.c StrList.h
	$(CC) $(FLAGS) -c $(ALLC)



clean:
	rm -f *.o *.out



