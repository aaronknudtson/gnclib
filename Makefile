.PHONY: all test clean compile gen mkbuild clean

all: compile

py: compile
	python orbit.py

test: compile
	cd build && ctest .

compile: gen
	cd build && cmake --build . --target all

gen: mkbuild
	# cd build && cmake .. 
	cd build && cmake .. 

mkbuild:
	mkdir -p build

clean:
	rm -rf build
