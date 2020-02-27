make -C ../ > /dev/null
./../minishell < commands_tests.txt > user_output 2> user_error
bash < commands_tests.txt > real_output 2> real_error
if [ $? != 0 ]; then
		echo "\033[0;31mBash crashed !\033[0;0m"
		exit 1
fi
DIFF=$(diff user_output real_output)
if [ "$DIFF" != "" ]; then
	printf "======= \033[0;31mThis is not the same\033[0;0m =======\n"
	printf "%s\n" "$DIFF"
	exit 1
else
	printf "======= \033[0;32mNo diff between files\033[0;0m =======\n"
fi
if [ "$1" == "-rm" ]; then
	rm -f user_output
	rm -f user_error
	rm -f real_error
	rm -f real_output
fi
