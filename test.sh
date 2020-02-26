while [ 1 ]
		do
			./minishell < commands_tests.txt
			if [ $? != 0 ]; then
					echo "It crashed!"
					exit 1
			fi
<<<<<<< HEAD
=======
			DIFF=$(diff test _real_test)
			if [ "$DIFF" != "" ]; then
				printf "\nThis is not the same\n"
				exit 1
			else
				printf "\n== No diff between files ==\n"
			fi
>>>>>>> fc196d398b6c627c28d0fdefd5d9231ec4b489a7
		done
