
SOURCEDIR := ./build/src
SOURCES   := $(shell find $(SOURCEDIR) -name '*.cpp')

update:
	git pull origin main
	git submodule update --init --recursive
	git submodule foreach git pull origin main
clean:
	-[ -e build/src ] && rm -rf build/src
	-[ -e build/out ] && rm -f build/out
	-[ -e out ] && rm -f out
compile:
	g++ -o build/out -I./build/src $(SOURCES) -DVIRTUAL
	mv build/out .
build:
	make -B clean

	mkdir -p build
	
	cp -r src build/
	cp -r vpico/vpico build/src

	make -B compile
run:
	make -B build
	./out