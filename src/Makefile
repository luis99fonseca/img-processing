CC=gcc
CFLAGS=-I.
DEPS = structs.h 
MAIN = main.o structs.o
P1 = p1.o structs.o
P2 = p2.o structs.o
P3 = p3.o structs.o
P4 = p4.o structs.o
P5 = p5.o structs.o
P6 = p6.o structs.o
P7 = p7.o structs.o
P8 = p8.o structs.o
P9 = p9.o structs.o
P10 = p10.o structs.o
P11 = p11.o structs.o

LIBS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(MAIN)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p1: $(P1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p2: $(P2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p3: $(P3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p4: $(P4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p5: $(P5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p6: $(P6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p7: $(P7)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p8: $(P8)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p9: $(P9)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p10: $(P10)
	 $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

p11: $(P11)
	 $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o main 
