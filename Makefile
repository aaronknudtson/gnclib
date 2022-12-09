.PHONY: all test clean compile gen mkbuild clean

all: compile

run: compile
	cd build && ./app/app

test: compile
	cd build && ctest .

gen: mkbuild
	cd build && cmake ..

mkbuild:
	mkdir -p build

clean:
	rm -rf build
