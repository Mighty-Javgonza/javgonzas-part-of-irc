COMMAND=$1

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

COMMAND_C_FILES=$(find tests/source/commands -name "command_$COMMAND*")
COMMAND_C_FILES="$COMMAND_C_FILES tests/source/commands/zz_temp_test.cpp"

COMMAND_TEST_FILES=$(echo $COMMAND_C_FILES | sed 's/source/build/g' | sed 's/.cpp/.test/g')

rm $COMMAND_TEST_FILES

make test_objects

make $COMMAND_TEST_FILES

for f in $COMMAND_TEST_FILES; do
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
