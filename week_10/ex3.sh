touch _ex3.txt
printf "I am _ex3's brain, please, rescue mee!" > _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
printf "660 means 6 for user (read and write permissions(r+w)), 6 for group (r+w), 0 for others (no permission\n" >> ex3.txt
printf "775 means 7 for user (r+w+e (execute permission)), 7 for group (r+w+e), 5 for others (r+e)\n" >> ex3.txt
printf "777 means r+w+e for everyone\n" >> ex3.txt
