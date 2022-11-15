

function irc_class {
	CLASS_NAME=$1
	PWD=$(pwd)

	source ~/Desktop/custools/bonsai_scripts/bonsai.sh

	SOURCE_DIR=$(echo $PWD | sed 's+source/.*+source+')
	INCLUDE=$(echo $PWD | sed 's+.*source/++')"/$1.hpp"

	vim $SOURCE_DIR/all_headers.hpp -c "call AddIncludeToHeader('$INCLUDE')" -c "wq"

	bonsai cpp_class $CLASS_NAME
}
