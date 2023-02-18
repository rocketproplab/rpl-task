test:
	cmake -S . -B build
	cmake --build build
	cd build && ctest && cd ..

clean: 
	rm -r build
