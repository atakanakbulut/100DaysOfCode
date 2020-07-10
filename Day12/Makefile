include depend.make

.PHONY: sharedptr

SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=%.o)
HDR = $(wildcard *.h)

CFLAGS = -g -Wall -Wextra $(USERDEFINES)
CXX = g++

all : makeall

makeall : $(DEPS) $(OBJ)
	echo "Building.."
	$(CXX) $(CFLAGS)$(LPATH) $(OBJ) $(SYSROOT)  -o $(TARGET) 

.cpp.o:
	$(CXX) $(CFLAGS) $(IPATH) -c -o $*.o $<

clean :
	echo "Cleaning"
	rm -r *.o $(TARGET)

oneshotrelease : all
