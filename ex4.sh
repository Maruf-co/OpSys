mkdir tmp
cd tmp
touch file1.txt
printf "I am file1 and I don't like file2" > file1.txt
touch file2.txt
printf "I am file2 and I know that file1 doesn't like me" > file2.txt
ln file1.txt link1.txt
cd ..
gcc ex4.c -o  ex4
./ex4 > ex4.txt
