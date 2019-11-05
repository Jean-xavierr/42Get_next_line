WHITE="\e[97m"
GREEN="\e[92m"
RED="\e[91m"


printf "\n$WHITE==========================================\n"
printf "==============$GREEN GNL TESTS $WHITE=================\n"
printf "==========================================\n\n"

gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_next_line_tester.c -D BUFFER_SIZE=1
if [ "$?" = "0" ]
then
	printf "$GREEN Compilation done\n$WHITE"
	rm -f ouput_user/result1.txt
	./a.out >> ouput_user/result1.txt	
	diff correct_ouput/result1.txt ouput_user/result1.txt >> diff.txt
	if [ "$?" = "0" ]
	then
		printf " [TEST 1 | BUFFER_SIZE 1] $GREEN OK\n"
		rm diff.txt
	else
		printf " [TEST 1 | BUFFER_SIZE 1] $RED KO\n"
		printf " check diff.txt or correct_ouput/result1.txt and ouput_user/result1.txt\n\n"
	fi
else
	printf "$RED Compilation error\n"
fi
