all: compile run

run:
	@./build/monkeymarket

compile:
	@cmake --build build

init:
	@cmake -B build
