OBJS = alg4_4_4.o lib.o grammerIO.o
MAIN = alg4_4_4

all: remove compile

new: compile

compile: $(OBJS)
	g++ $(OBJS) -o test 

$(MAIN).o:
	g++ -c $(MAIN).cpp
	
lib.o:
	g++ -c /home/schbra02/web/library/lib.cpp

grammerIO.o:
	g++ -c /home/schbra02/web/library/grammerIO.cpp

remove:
	rm $(MAIN).o

clean:
	rm -rf *o compile
