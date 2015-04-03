i=300;
j=1;
k=1;
while [ $j -le 5 ]
do
	k=1;
	echo $i;
	while [ $k -le 5 ]
	do
		touch inp;
		echo $i >>inp;
		time ./a.out < inp >out;
		rm inp out 
		let k=k+1;
	done
	echo "-------------------------------";
	let i=i*4;
	let j=j+1;
done	
