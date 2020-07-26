include depend.make

.PHONY: static.bin

SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=%.o)
HDR = $(wildcard *.h)

CFLAGS = -g -Wall -Wextra $(USERDEFINES)
CXX = g++

all : makeall

lib :
	$(CXX) -c static/StaticLibrary.cpp -o static/StaticLibrary.o
	ar rcs libStaticLibrary.a static/StaticLibrary.o
	ar t libStaticLibrary.a	

static : lib
	echo "Building static lib"
	$(CXX) $(SRC) -o $(TARGET) $(CFLAGS) $(LPATH) $(SYSROOT)

makeall : $(DEPS) $(OBJ)
	echo "Building.."
	$(CXX) $(CFLAGS)$(LPATH) $(OBJ) $(SYSROOT)  -o $(TARGET) 

.cpp.o:
	$(CXX) $(CFLAGS) $(IPATH) -c -o $*.o $<

clean :
	echo "Cleaning"
	rm -r static/*.o
	rm -r *.o $(TARGET) *.a

	

oneshotrelease : all
