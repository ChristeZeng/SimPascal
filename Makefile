NAME = SimPascal

LLVM_CONFIG = /usr/bin/llvm-config

CXXFLAGS = `$(LLVM_CONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVM_CONFIG) --ldflags`
LIBS = `$(LLVM_CONFIG) --libs --system-libs`

OBJS = parser.o tokenizer.o AST.o  main.o

all : $(NAME)

parser.cpp: ${NAME}.y
	bison -d -o parser.cpp ${NAME}.y

parser.hpp: parser.cpp

tokenizer.cpp: ${NAME}.l
	flex -o tokenizer.cpp ${NAME}.l

%.o: %.cpp AST/AST.h
	g++ -c $(CXXFLAGS) -g -o $@ $< 

$(NAME): $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

.PHONY: clean
clean:
	-rm -f *.o
	-rm -f parser.hpp parser.cpp tokenizer.cpp SimPascal