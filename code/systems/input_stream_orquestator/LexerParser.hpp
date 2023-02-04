#ifndef LEXERPARSER_HPP
# define LEXERPARSER_HPP

//Clase principal que llama al Lexer y luego al Parser.
class LexerParserConnector;
# include "code/source/LexerParserConnector/LexerParserConnector.hpp"

//El resultado de usar parse_string de la clase LexerParserConnector es
// una de las clases que se pueden ver aquí: (o NULL)
# include "AllParsedMessages.hpp"

//Algunos ParsedMessage usan algún parámetro custom de entre estos:
typedef struct s_channel_parameter channel_parameter;
typedef struct s_msgto_parameter msgto_parameter;
typedef struct s_target_parameter target_parameter;
typedef struct s_msgtarget_parameter msgtarget_parameter;
typedef struct s_channel_list_parameter channel_list_parameter;
typedef struct s_user_list_parameter user_list_parameter;
typedef struct s_key_list_parameter key_list_parameter;
typedef struct s_mask_list_parameter mask_list_parameter;
typedef struct s_nickname_list_parameter nickname_list_parameter;
#include "code/source/MessageParser/MessageParameterCommonParser.hpp"

#endif
