test:
	cmake -S . -B build
	cmake --build build
	cd build && ctest && cd ..

clean: 
	rm -r build

precomp:
	g++ -Wall -pedantic -g -O0 -std=c++11 -o Precomp PrecompTopSort.cpp

precomp_clean: PrecompTopSort.cpp PrecompTopSort.h
	rm -r Precomp.dSYM
	rm Precomp
	
