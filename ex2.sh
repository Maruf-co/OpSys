mkdir week01
cd week01
touch file.txt
printf "Hi, I am file and I like pancakes" > file.txt
cd ..
mkdir week10
cd week10
link ~/week_10/week01/file.txt _ex2.txt
ls -i _ex2.txt > ex2.txt
find ~/week_10/week01/file.txt -inum 40781 >> ex2.txt
find ~/week_10/week01/file.txt -inum 40781 -exec rm {} \; >> ex2.txt
