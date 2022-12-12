.PHONY: all test clean compile gen mkbuild clean

all: compile

test: compile
	cd build && ctest .

compile: gen
	cd build && cmake --build . --target all

gen: mkbuild
	# cd build && cmake .. 
	cd build && cmake .. -DPYTHON_EXECUTABLE=/opt/homebrew/anaconda3/bin/python

mkbuild:
	mkdir -p build

clean:
	rm -rf build
