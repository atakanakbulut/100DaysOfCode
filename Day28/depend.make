NAME = static.bin
TARGET = static.bin
override USERDEFINES += -std=c++17 $(USERLIBS)

USERLIBS = -Istatic -L. -lStaticLibrary
#CC = gcc
#CROSS_COMPILE =
