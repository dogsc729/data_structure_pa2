# CC and CFLAGS are varilables
CC = g++
CFLAGS = -s
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O2

# optimized version 
bin/pswdhash1 : src/main.cpp
	$(CC) -std=c++11 $^ -o $@
			
bin/pswdhash2 : src/results_pa2.cpp
	$(CC) -std=c++11 $^ -o $@

# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*

