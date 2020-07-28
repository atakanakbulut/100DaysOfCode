include depend.make

.PHONY: signal.bin

SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=%.o)
HDR = $(wildcard *.h)

CFLAGS = -g -Wall -Wextra $(USERDEFINES)
CXX = g++

all : makeall

makeall : $(DEPS) $(OBJ)
	echo "Building.."
	$(CXX)  $(OBJ) -o $(TARGET) $(CFLAGS) $(LPATH) $(SYSROOT)

.cpp.o:
	$(CXX) $(CFLAGS) $(IPATH) -c -o $*.o $<

clean :
	echo "Cleaning"
	rm -r dynamic/*.so
	rm -r *.o $(TARGET) *.a *.so *.bin
	cd dynamic && $(MAKE) clean

oneshotrelease : all
