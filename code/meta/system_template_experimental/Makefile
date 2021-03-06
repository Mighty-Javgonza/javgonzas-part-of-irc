include Makefile.conf

CODE_SOURCE_FOLDER=$(CODE_FOLDER)/$(SOURCE_FOLDER_NAME)
CODE_BUILD_FOLDER=$(CODE_FOLDER)/$(BUILD_FOLDER_NAME)
TESTS_SOURCE_FOLDER=$(TESTS_FOLDER)/$(SOURCE_FOLDER_NAME)
TESTS_BUILD_FOLDER=$(TESTS_FOLDER)/$(BUILD_FOLDER_NAME)

ALL_CODE_SOURCE_FOLDERS=$(shell find $(CODE_SOURCE_FOLDER) -type d -mindepth 1)
ALL_CODE_SOURCE_FILES=$(foreach dir, $(ALL_CODE_SOURCE_FOLDERS), $(wildcard $(dir)/*.cpp))
ALL_CODE_BUILD_FOLDERS=$(subst $(SOURCE_FOLDER_NAME),$(BUILD_FOLDER_NAME),$(ALL_CODE_SOURCE_FOLDERS))
ALL_CODE_BUILD_OBJECTS=$(subst $(SOURCE_FOLDER_NAME),$(BUILD_FOLDER_NAME),$(ALL_CODE_SOURCE_FILES:.cpp=.o))
ALL_CODE_TESTABLE_OBJECTS=$(ALL_CODE_BUILD_OBJECTS:.o=$(TESTABLE_OBJECT_SUFFIX).o)
ALL_CODE_BUILD_DEPENDENCIES=$(subst $(SOURCE_FOLDER_NAME),$(BUILD_FOLDER_NAME),$(ALL_CODE_SOURCE_FILES:.cpp=.d))

ALL_TESTS_SOURCE_FOLDERS=$(shell find $(TESTS_SOURCE_FOLDER) -type d -mindepth 1)
ALL_TESTS_SOURCE_FILES=$(foreach dir, $(ALL_TESTS_SOURCE_FOLDERS), $(wildcard $(dir)/*.cpp))
ALL_TESTS_BUILD_FOLDERS=$(subst $(SOURCE_FOLDER_NAME),$(BUILD_FOLDER_NAME),$(ALL_TESTS_SOURCE_FOLDERS))
ALL_TESTS_BUILD_EXECUTABLES=$(subst $(SOURCE_FOLDER_NAME),$(BUILD_FOLDER_NAME),$(ALL_TESTS_SOURCE_FILES:.cpp=$(TESTS_SUFFIX)))
ALL_TESTS_BUILD_DEPENDENCIES=$(subst $(SOURCE_FOLDER_NAME),$(BUILD_FOLDER_NAME),$(ALL_TESTS_SOURCE_FILES:.cpp=.d))

NORMAL_COMPILER=$(COMPILER_COMMAND) $(COMPILER_FLAGS)
TESTABLE_OBJECT_COMPILER=$(NORMAL_COMPILER) -D 'private=public' -D 'protected=public'
DEPENCIES_COMPILER= $(COMPILER_COMMAND) -MM

$(CODE_BUILD_FOLDER)%$(TESTABLE_OBJECT_SUFFIX).o:$(CODE_SOURCE_FOLDER)%.cpp
	$(TESTABLE_OBJECT_COMPILER) -c -o $@ $<

$(CODE_BUILD_FOLDER)%.o:$(CODE_SOURCE_FOLDER)%.cpp
	$(NORMAL_COMPILER) -c -o $@ $<

$(TESTS_BUILD_FOLDER)%$(TESTS_SUFFIX):$(TESTS_SOURCE_FOLDER)%.cpp
	$(TESTABLE_OBJECT_COMPILER) -o $@ $< $(ALL_CODE_BUILD_OBJECTS)

$(CODE_BUILD_FOLDER)%.d:$(CODE_SOURCE_FOLDER)%.cpp
	$(DEPENCIES_COMPILER) -MT $(CODE_BUILD_FOLDER)$*.o -o $@ $<

$(TESTS_BUILD_FOLDER)%.d:$(TESTS_SOURCE_FOLDER)%.cpp
	$(DEPENCIES_COMPILER) -MT $(TESTS_BUILD_FOLDER)$*.o -o $@ $<

tests/build/hola/zz_temp_test.o: tests/source/hola/zz_temp_test.cpp \
  tests/source/hola/../../../code/source/asdf/hola.hpp

all:
	echo $(ALL_TESTS_SOURCE_FILES)
	echo $(ALL_TESTS_BUILD_DEPENDENCIES)
	echo $(ALL_TESTS_BUILD_EXECUTABLES)

build_dirs: code_build_dirs tests_build_dirs

code_build_dirs:
	mkdir -p $(ALL_CODE_BUILD_FOLDERS)

tests_build_dirs:
	mkdir -p $(ALL_TESTS_BUILD_FOLDERS)

code_build_dependencies: $(ALL_CODE_BUILD_DEPENDENCIES)

tests_build_dependencies: $(ALL_TESTS_BUILD_DEPENDENCIES)

.PHONY: code_build_dirs tests_build_dirs build_dirs tests code_build_dependencies tests_build_dependencies
