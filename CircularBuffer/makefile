PROG = ring

all: main.o circularBuffer.o
	$(CC) $^ -o $(PROG)

run: all
	./$(PROG)


clean:
	rm $(PROG) -f
