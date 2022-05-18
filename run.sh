make clean
make -j8 2>error.log
./SimPascal < pascal/$1 2> 1.ll