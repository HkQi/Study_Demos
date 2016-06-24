sc_obj = driver.o decoder.o monitor.o decoder_main.o
#cflags = -lsystemc -L/usr/local/lib-linux64 -lm
cflags = -lsystemc -lm

all: ${sc_obj}
	g++ ${sc_obj} ${cflags} -o test

decoder_main.o: decoder_main.cpp
driver.o: driver.cpp driver.h
decoder.o: decoder.cpp decoder.h
monitor.o: monitor.cpp monitor.h

clean:
	rm -rf *.o test
