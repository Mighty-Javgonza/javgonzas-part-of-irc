MESSAGE_CATEGORY=$1
MESSAGE_NAME=$2
DIR=$(dirname $PWD/$0)

source ~/Desktop/proyectos/irc/code/meta/scripts/create_irc_class.sh

cd "$DIR"'/../code/source/MessageParser/'"$MESSAGE_CATEGORY"'Messages'
irc_class 'Message'"$MESSAGE_CATEGORY$MESSAGE_NAME"'Parser'

cd "$DIR"'/../code/source/ParsedMessage/'"$MESSAGE_CATEGORY"'Messages'
irc_class 'ParsedMessage'"$MESSAGE_CATEGORY$MESSAGE_NAME"

touch "$DIR"'/../tests/source/ParsedMessage/ParsedMessage'"$MESSAGE_CATEGORY$MESSAGE_NAME"'_inherits_from_parsed_message.cpp'

vim "$DIR"'/../code/source/MessageParser/'"$MESSAGE_CATEGORY"'Messages/Message'"$MESSAGE_CATEGORY$MESSAGE_NAME"'Parser.hpp' -c ":cd %:p:h" -c "source $DIR/create_message_parser_class.vim" -c "call CreateMessageParserClass('$MESSAGE_CATEGORY', '$MESSAGE_NAME')"
