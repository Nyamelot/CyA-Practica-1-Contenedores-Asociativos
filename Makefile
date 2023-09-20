NAME=p01-
DIRPATH=$(shell realpath .)
DIRNAME=$(shell basename $(DIRPATH))

cmake:
	cmake -S . -B build

build: cmake
	cd build; make

clean:
	rm -rf build

tar:
	cd ..; tar cvfz $(DIRNAME)/p01-PortilloGarcia-JoseAngel.tar.gz --exclude-from=./$(DIRNAME)/.gitignore $(DIRNAME)