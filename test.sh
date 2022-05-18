./SimPascal < pascal/$1 2> 1.ll
llc -filetype=obj 1.ll
clang 1.o