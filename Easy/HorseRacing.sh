# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
#
#read N
#for (( i=0; i<N; i++ )); do
#    read Pi[i]
#done
#
# Write an action using echo
# To debug: echo "Debug messages..." >&2
#sortedPi=($(for i in ${Pi[@]}; do echo $i; done | sort -n))
#lowbound=10000000
#
#for (( j=1; j<N; j++)); do
#    boundone=${sortedPi[j]}
#    boundtwo=${sortedPi[j-1]}
#    difference=$(( boundone-boundtwo ))
#    
#    if [ $difference -lt $lowbound ]; then
#        lowbound=$difference;
#    fi
#done
#
#echo $lowbound
#
#Updated...
#

read n
declare -a horses
declare -a sorted
lower=10000000; last=-1

for((i=0 ; i<n ; i++)); do
    read horse
    sorted[horse]=1
done

if [[ ${#sorted[@]} -ne n ]]; then lower=0;
else
    for i in ${!sorted[@]}; do
        if [[ $last -ne -1 && $(($i-$last)) -lt $lower ]]; then 
            lower=$(($i-$last)); fi
        last=$i
    done
fi
echo $lower
