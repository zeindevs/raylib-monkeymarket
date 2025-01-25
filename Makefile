all: build run

run:
	@./build/monkeymarket

build:
	@cmake --build build

init:
	@cmake -B build
