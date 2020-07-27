CXX = g++

makelib :
	$(CXX) -fPIC -shared DynamicLibrary.cpp -o libDynamicLibrary.so
	cp libDynamicLibrary.so ../
make clean :
	rm -r *.so
