if [ ! -f f.txt ]; then
	echo "1" > "f.txt"
fi

while [ $(tail -1 f.txt) -lt 100 ]; 
do
	if ln "f.txt" "f.lock"
	then
		n=$(cat "f.txt" | tail -n 1)
		echo "$((n+1))" >> f.txt
		rm "f.lock"
	fi
done
