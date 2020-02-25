while [ 1 ]
		do
			./minishell < commands_tests.txt
			if [ $? != 0 ]; then
					echo "It crashed!"
					exit 1
			fi
			DIFF=$(diff test _real_test)
			if [ "$DIFF" != "" ]; then
				printf "\nThis is not the same\n"
				exit 1
			else
				printf "\n== No diff between files ==\n"
			fi
		done
