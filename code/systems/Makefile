include Makefile.flags
#TODO Quizá sea ambicioso, pero esto sobreescribe las reglas de tests
#se podía intentar hacer algo para mantener eso vivo.
#MORE TODO
#OBJ :=
#include parser/Makefile
#OBJ += $(ALL_CODE_BUILD_OBJECTS)
#include lexer/Makefile
#OBJ += $(ALL_CODE_BUILD_OBJECTS)
#include command_executor/Makefile
#OBJ += $(ALL_CODE_BUILD_OBJECTS)
##TODO Yes aux stuff
#KILL_VICMARTI := $(OBJ)
#include database/Makefile
#OBJ += $(KILL_VICMARTI)

ALL_CODE_SOURCE_FOLDERS:=$(shell find -H parser/code -type d -mindepth 1)
#ALL_CODE_SOURCE_FOLDERS:=$(ALL_CODE_SOURCE_FOLDERS) $(shell find -H parser/code -type l -mindepth 1)
ALL_CODE_SOURCE_FILES:=$(foreach dir, $(ALL_CODE_SOURCE_FOLDERS), $(wildcard $(dir)/*.cpp))

ALL_CODE_SOURCE_FOLDERS:=$(shell find -H lexer/code -type d -mindepth 1)
#ALL_CODE_SOURCE_FOLDERS:=$(ALL_CODE_SOURCE_FOLDERS) $(shell find -H lexer/code -type l -mindepth 1)
ALL_CODE_SOURCE_FILES+=$(foreach dir, $(ALL_CODE_SOURCE_FOLDERS), $(wildcard $(dir)/*.cpp))

ALL_CODE_SOURCE_FOLDERS:=$(shell find -H command_executor/code -type d -mindepth 1)
#ALL_CODE_SOURCE_FOLDERS:=$(ALL_CODE_SOURCE_FOLDERS) $(shell find -H command_executor/code -type l -mindepth 1)
ALL_CODE_SOURCE_FILES+=$(foreach dir, $(ALL_CODE_SOURCE_FOLDERS), $(wildcard $(dir)/*.cpp))

ALL_CODE_SOURCE_FOLDERS:=$(shell find -H input_stream_orquestator/code -type d -mindepth 1)
#ALL_CODE_SOURCE_FOLDERS:=$(ALL_CODE_SOURCE_FOLDERS) $(shell find -H parser/code -type l -mindepth 1)
ALL_CODE_SOURCE_FILES+=$(foreach dir, $(ALL_CODE_SOURCE_FOLDERS), $(wildcard $(dir)/*.cpp))
#
# Source files and includes
SRC :=
BASE_DIR :=
#  Database
BASE_DIR := database/db
SRC += $(BASE_DIR)/ClientId.cpp
SRC += $(BASE_DIR)/ClientData.cpp
SRC += $(BASE_DIR)/Unregistered.cpp
SRC += $(BASE_DIR)/Key.cpp
SRC += $(BASE_DIR)/TextMask.cpp
SRC += $(BASE_DIR)/Client.cpp
SRC += $(BASE_DIR)/ChanId.cpp
SRC += $(BASE_DIR)/Chan.cpp
SRC += $(BASE_DIR)/IdManager.cpp
SRC += $(BASE_DIR)/Database.cpp
# Exceptions
BASE_DIR := database/db/exceptions
SRC += $(BASE_DIR)/InvalidId.cpp
SRC += $(BASE_DIR)/InvalidState.cpp
SRC += $(BASE_DIR)/RegisterNotFound.cpp
#  Strings
BASE_DIR := database/db/strings
SRC += $(BASE_DIR)/equalsNoCase.cpp
SRC += $(BASE_DIR)/toLower.cpp
SRC += $(BASE_DIR)/toUpper.cpp
#  End
BASE_DIR :=
#TODO
ALL_CODE_SOURCE_FILES += $(SRC)

SRC_DIR = sockets/src/
#TODO tamartin sources
SRC_FILES = com.cpp com_exceptions.cpp orchestator.cpp user.cpp \
			msg.cpp replies.cpp replies_generator.cpp aux_server.cpp \
			time_control.cpp log.cpp others.cpp internal_commands.cpp
ALL_CODE_SOURCE_FILES += $(addprefix $(SRC_DIR), $(SRC_FILES))

#TODO I AM DESPERATE, JUST APPEND
ALL_CODE_SOURCE_FILES += main_loop/CommandActionAssociator.cpp main_loop/main_loop.cpp

OBJ_DIR := obj
OBJ := $(ALL_CODE_SOURCE_FILES:%.cpp=$(OBJ_DIR)/%.o)

NAME := irc

CXX := g++ -std=c++98
CXXFLAGS := -Wall -Wextra -Werror # TODO -g3 -fsanitize=address  for sanitize compiling
CPPFLAGS := -MMD
LDFLAGS := # TODO -fsanitize=address for sanitize compiling

#Directories
#SRC_DIR := src
#OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)

#Full relpath of sources, objects and dependency files
#OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP := $(SRC:%.cpp=$(DEP_DIR)/%.d)
#SRC := $(addprefix $(SRC_DIR)/, $(SRC))


# Rules
all: $(NAME)

print:
	@echo "The thing: \n" $(ALL_CODE_SOURCE_FILES)
#	@echo "Sources: \n" $(SRC)
	@echo "Objects: \n" $(OBJ)
#	@echo "Dependecies: \n" $(DEP)

#TODO en este makefile no se compila
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
#	@mkdir -p $(@D)
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

#TODO Not here
NORMAL_COMPILER:=$(COMPILER_COMMAND) $(COMPILER_FLAGS)

$(OBJ_DIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(NORMAL_COMPILER) -c -o $@ $<

$(NAME): $(OBJ) #$(addprefix tom/,$(TOMOBJ))
	@echo "Frankenstein powered by Javgonza, Vicmarti & Tomartin in 42Madrid"
	@echo #TODO usar $@ y $loqusea para los objs
	$(COMPILER_COMMAND) $(LINKER_FLAGS) $(OBJ) -o $(NAME)

bonus: all

# clean rule
clean:
#	@make -C ./src/tests tests_clean
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re

# default
.DEFAULT_GOAL := all
