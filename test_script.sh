WHITE="\e[97m"
GREEN="\e[92m"
RED="\e[91m"


printf "\n$WHITE==========================================\n"
printf "==============$GREEN GNL TESTS $WHITE=================\n"
printf "==========================================\n\n"

function tester {
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line_tester.c -D BUFFER_SIZE=$1
if [ "$?" = "0" ]
then
	printf "$GREEN Compilation done\n$WHITE"
	rm -f ouput_user/result$2.txt
	./a.out >> ouput_user/result$2.txt	
	diff correct_ouput/result$2.txt ouput_user/result$2.txt >> diff.txt
	if [ "$?" = "0" ]
	then
		printf " [TEST $2 | BUFFER_SIZE $1] $GREEN OK\n"
		rm diff.txt
	else
		printf " [TEST $2 | BUFFER_SIZE $1] $RED KO\n"
		printf " check diff.txt or correct_ouput/result$2.txt and ouput_user/result$2.txt\n\n"
	fi
else
	printf "$RED Compilation error\n"
fi

}

n=0
for i in 1 2 5 10 12 15 20 25 50 100 125 250 1024
do
	n=$(($n + 1))
	tester "$i" "$n"
done
