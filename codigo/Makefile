PROYECTO=Universo
DESTDIR=/usr/local/bin
CFLAGS=-Wall 
LFLAGS=-lX11
CCpp=g++
CC=gcc

all: $(PROYECTO)

gfx.o: gfx.c
	$(CC) -c $< $(CFLAGS) 

Coor.o: Coor.cpp
	$(CCpp) -c $< $(CFLAGS)

Line.o: Line.cpp
	$(CCpp) -c $< $(CFLAGS)

Face.o: Face.cpp
	$(CCpp) -c $< $(CFLAGS)

Universo.o: Canvas.cpp
	$(CCpp) -c $< $(CFLAGS)

principal.o: principal.cpp
	$(CCpp) -c $< $(CFLAGS)

$(PROYECTO) : gfx.o Coor.o Line.o Face.o Canvas.o principal.o
	$(CCpp) $^ -o $@ $(LFLAGS) 

.PHONY: clean

install: all
	if [ ! -d $(DESDIR) ] ; then \
		sudo mkdir $(DESDIR); \
	fi; \
	sudo cp $(PROYECTO) $(DESDIR)
unistall:
	rm $(DESDIR)/$(PROYECO)
clean:
	rm -f *.o $(PROYECTO)
	


