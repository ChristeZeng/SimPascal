all: SimPascal
 
clean:
		rm parser.cpp parser.hpp parser tokens.cpp
 
SimPascal.cpp: SimPascal.y
		bison -d -o $@ $^
 
SimPascal.h: SimPascal.cpp
 
tokens.cpp: SimPascal.l SimPascal.h
		lex -o $@ $^
 
parser: SimPascal.cpp main.cpp tokens.cpp
		g++ -o $@ `llvm-config --libs core jit native --cxxflags --ldflags` *.cpp