#! bin/bash

make retests

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

for f in "$1"/*.test; do
	SHORT=$(basename $f)
	./"$f"
	if test $? -eq 0
	then
		echo -e " ${GREEN}$SHORT"
	else
		echo -e "${RED}$SHORT"
	fi
	echo -ne "${NC}"
done
