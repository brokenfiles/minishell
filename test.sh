while [ 1 ]
		do
			./minishell < commands_tests.txt
			if [ $? != 0 ]; then
					echo "It crashed!"
					exit 1
			fi
		done
