# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compare.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 16:54:53 by mbueno-g          #+#    #+#              #
#    Updated: 2022/01/28 12:35:58 by albzamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
RESET="\033[0m"

#ECHO TESTS

read -p "Enter your ECHO command: " var

touch test1 test2

echo "$var" | ../minishell > test1
echo "$var" | /bin/bash > test2

test1="test1"
test2="test2"

if (cmp -s "$test1" "$test2") ; then
	printf $BOLDGREEN"\nAll good! %s$RESET\n\n" "✓"
else
	printf $BOLDRED"\nError! %s$RESET\n" "✗"
	echo
	printf $BOLDRED"Your output : \n%.20s\n$(cat -e test1)\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
	echo
fi

printf $BOLDGREEN"Expected output : \n%.20s\n$(cat -e test2)\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"


rm -f test1 test2