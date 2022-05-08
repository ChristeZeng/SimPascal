NAME = SimPascal

LLVM_CONFIG = /usr/bin/llvm-config

CXXFLAGS = `$(LLVM_CONFIG) --cppflags` -std=c++14
LDFLAGS = `$(LLVM_CONFIG) --ldflags`
LIBS = `$(LLVM_CONFIG) --libs --system-libs`

OBJS = parser.o tokenizer.o  main.o

all : $(NAME)

parser.cpp: ${NAME}.y
	bison -d -o parser.cpp ${NAME}.y

parser.hpp: parser.cpp

tokenizer.cpp: ${NAME}.l
	flex -o tokenizer.cpp ${NAME}.l

%.o: %.cpp AST/AST.h AST/Node.h AST/Program.h AST/Stmt.h AST/Type.h AST/Const.h generator/CodeGenerator.h generator/CodeGenerator.cpp generator/genConstType.cpp generator/genExp.cpp generator/genFunc.cpp generator/genProgram.cpp generator/genStmt.cpp
	g++ -c $(CXXFLAGS) -g -o $@ $< 

$(NAME): $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

.PHONY: clean
clean:
	-rm -f *.o
	-rm -f parser.hpp parser.cpp tokenizer.cpp SimPascal