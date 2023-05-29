"class_name is in the form <category><name>
"							ChannelTopic

fu! UpgradeMessageParserClassHeader(message_category, message_name)
"	r ! upfind -name 'MessageParser.hpp'
	normal gg
	exe '/# define'
	normal o
	put='# include \"../MessageParser.hpp\"'
	put=''
	put='# include \"../../ParsedMessage/'.a:message_category.'Messages/ParsedMessage'.a:message_category.a:message_name.'.hpp\"'

	exe '/class'

	normal $i: public MessageParser 

	exe '/\~'
	put=''
	put='	ParsedMessage'.a:message_category.a:message_name.'	*specific_message;'

	exe '/private'
	normal ddk
	put='protected:'
	put='	void	parse_specific_part();'
	put='	void	create_specific_message();'
endfunction

fu! UpgradeMessageParserClassSource(message_category, message_name)
	normal Go
	put='void	Message'.a:message_category.a:message_name.'Parser::parse_specific_part()'
	put='{'
	put=''
	put='}'
	put=''
	put='void	Message'.a:message_category.a:message_name.'Parser::create_specific_message()'
	put='{'
	put='	specific_message = new ParsedMessage'.a:message_category.a:message_name.'();'
	put='	in_progress_message = specific_message;'
	put='}'

endfunction

fu! UpgradeParsedMessageClass(message_category, message_name)
	normal gg
	exe '/# define'
	normal o
	put='# include \"../ParsedMessage.hpp\"'
	put=''
	put='# include \"../../MessageParser/MessageParameterCommonParser.hpp\"'

	exe '/class'

	normal $i: public ParsedMessage 
endfunction

fu! UpgradeParsedMessageTest(message_category, message_name)
	put='# include \"../tests.hpp\"'
	put=''
	put='int main()'
	put='{'
	put='	ParsedMessage'.a:message_category.a:message_name.'	result;'
	put='	ParsedMessage	msg;'
	put=''
	put='	msg = result;'
	put='}'
	
	normal ggdd

endfunction

fu! CreateMessageParserClass(message_category, message_name)
	call UnmapCPPMacros()
	call UpgradeMessageParserClassHeader(a:message_category, a:message_name)
	w
	exe 'e ./Message'.a:message_category.a:message_name.'Parser.cpp'
	call UpgradeMessageParserClassSource(a:message_category, a:message_name)
	w
	exe 'e ../../ParsedMessage/'.a:message_category.'Messages/ParsedMessage'.a:message_category.a:message_name.'.hpp'
	call UpgradeParsedMessageClass(a:message_category, a:message_name)
	w
	exe 'e ../../../../tests/source/ParsedMessage/ParsedMessage'.a:message_category.a:message_name.'_inherits_from_parsed_message.cpp'
	call UpgradeParsedMessageTest(a:message_category, a:message_name)
	w
	call MapCPPMacros()
endfunction
