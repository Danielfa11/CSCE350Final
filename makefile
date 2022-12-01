#!/bin/sh
cc = g++

path = ..

flags = -std=c++17

flags += -Wall

flags += -I $(path)

link = $(cc) $(flags) -o #final build

compile = $(cc) $(flags) -c #for .o

Anderson_Daniel_QuickSort.o : Anderson_Daniel_QuickSort.cpp
	$(compile) $^

Anderson_Daniel_QuickSort : Anderson_Daniel_QuickSort.o
	$(link) $@ $^

InputFileGenerator.o : InputFileGenerator.cpp
	$(compile) $^

InputFileGenerator : InputFileGenerator.o
	$(link) $@ $^

clean : 
	$(RM) *.o 
	$(RM) inputs/*
	$(RM) InputFileGenerator
	$(RM) output/*
	$(RM) Anderson_Daniel_QuickSort

r = 0
b = inputs/input_
a = $(foreach wrd,$(b), $n)
n = 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 
m = 25 26 27 29 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 
k = 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74
test :
	$(foreach i,$(b),./Anderson_Daniel_QuickSort $(i) & $(SLEEP .1))


test2:
	$(foreach i,$(n),./Anderson_Daniel_QuickSort $(wildcard $(b)$(i)size_10.txt) & sleep .7;)
	$(foreach i,$(m),./Anderson_Daniel_QuickSort $(wildcard $(b)$(i)size_100.txt) & sleep .7;)
	$(foreach i,$(m),./Anderson_Daniel_QuickSort $(wildcard $(b)$(i)size_1000.txt) & sleep .7;)