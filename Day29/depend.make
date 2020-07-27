NAME = dynamic.bin
TARGET = dynamic.bin
override USERDEFINES += -std=c++17 $(USERLIBS)

USERLIBS = -Idynamic -Ldynamic -lDynamicLibrary
#CC = gcc
#CROSS_COMPILE =
