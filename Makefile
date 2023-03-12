test:
	cmake -S . -B build
	cmake --build build
	cp -r TestTaskFolder build
	cd build && ctest && cd ..

clean: 
	rm -r build

precomp:
	g++ -Wall -pedantic -g -O0 -std=c++11 -o RplTaskMainBuild RplTaskMainBuild.cpp PrecompTopSort.cpp

precomp_test:
	./RplTaskMainBuild TestTaskFolder/Task1.h TestTaskFolder/Task2.h TestTaskFolder/Task3.h TestTaskFolder/Task4.h

precomp_clean: PrecompTopSort.cpp PrecompTopSort.h
	rm -r RplTaskMainBuild.dSYM
	rm RplTaskMainBuild
	
