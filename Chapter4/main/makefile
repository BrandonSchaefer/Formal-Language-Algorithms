OBJS = $(MAIN).o alg4_1.o alg4_2.o alg4_3.o alg4_4_2.o alg4_4_4.o alg4_5.o alg4_6.o alg4_7.o alg4_8.o latexTable.o lib.o gramLib.o grammerIO.o
MAIN = main

all: clean compile

compile: $(OBJS)
	g++ $(OBJS) -o test 

$(MAIN).o:
	g++ -c $(MAIN).cpp
	
alg4_1.o:
	g++ -c ../alg4_1/alg4_1.cpp

alg4_2.o:
	g++ -c ../alg4_2/alg4_2.cpp

alg4_3.o:
	g++ -c ../alg4_3/alg4_3.cpp

alg4_4_2.o:
	g++ -c ../alg4_4/4_4_2/alg4_4_2.cpp

alg4_4_4.o:
	g++ -c ../alg4_4/4_4_4/alg4_4_4.cpp

alg4_5.o:
	g++ -c ../alg4_5/alg4_5.cpp

alg4_6.o:
	g++ -c ../alg4_6/alg4_6.cpp

alg4_7.o:
	g++ -c ../alg4_7/alg4_7.cpp

alg4_8.o:
	g++ -c ../alg4_8/alg4_8.cpp

latexTable.o:
	g++ -c ../alg4_6/latexTable.cpp

lib.o:
	g++ -c ../../Main/library/lib.cpp

gramLib.o:
	g++ -c ../library/gramLib.cpp

grammerIO.o:
	g++ -c ../library/grammerIO.cpp

remove:
	rm $(MAIN).o

clean:
	rm -rf *o compile
