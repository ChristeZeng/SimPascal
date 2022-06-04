./test.sh 1.pas > info.log
chmod +x tester/quicksort/linux-amd64
./tester/quicksort/linux-amd64 ./a.out

./test.sh 2.pas > info.log
chmod +x tester/matrix-multiplication/linux-amd64
./tester/matrix-multiplication/linux-amd64 ./a.out

./test.sh 3.pas > info.log
chmod +x tester/auto-advisor/linux-amd64
./tester/auto-advisor/linux-amd64 ./a.out