read a
fact=1
num=2
while [ $num -le $a ]
do
	fact=$((fact*num))
	num=$((num+1))
done
echo $fact
            #prints factorial of the given number
