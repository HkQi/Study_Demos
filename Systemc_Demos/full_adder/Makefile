sc_obj = driver.o full_adder.o half_adder.o monitor.o full_adder_main.o
#cflags = -lsystemc -L/usr/local/lib-linux64 -lm
cflags = -lsystemc -lm

all: ${sc_obj}
	g++ ${sc_obj} ${cflags} -o test

full_adder_main.o: full_adder_main.cpp
driver.o: driver.cpp driver.h
full_adder.o: full_adder.cpp full_adder.h
half_adder.o: half_adder.cpp half_adder.h
monitor.o: monitor.cpp monitor.h

clean:
	rm -rf *.o test
