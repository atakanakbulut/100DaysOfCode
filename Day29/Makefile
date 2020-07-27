include depend.make

.PHONY: static.bin

SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=%.o)
HDR = $(wildcard *.h)

CFLAGS = -g -Wall -Wextra $(USERDEFINES)
CXX = g++

all : makeall

lib :
	cd dynamic && $(MAKE) makelib

makeall : $(DEPS) $(OBJ) lib
	echo "Building.."
	$(CXX)  $(OBJ) -o $(TARGET) $(CFLAGS) $(LPATH) $(SYSROOT)

.cpp.o:
	$(CXX) $(CFLAGS) $(IPATH) -c -o $*.o $<

clean :
	echo "Cleaning"
	rm -r dynamic/*.so
	rm -r *.o $(TARGET) *.a *.so
	cd dynamic && $(MAKE) clean

	

oneshotrelease : all
