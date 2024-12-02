OS=$(shell uname)
CC = gcc

# Flags
MAIN_FLAGS = -std=c11
DEBUG_FLAGS = -Wall -Wextra -Werror
VALG_FLAGS = -g
POSIX_FLAG = -D_POSIX_C_SOURCE=201706L
COVLAGS =-fprofile-arcs -ftest-coverage
CHLIB = -lcheck
MATHLIB = -lm
NCURLIB = -lncurses
LIBFLAGS= 
ifeq ($(OS), Linux)
	LIBFLAGS += -lsubunit
endif
CLANG_FLAGS = --style=Google

# Checkers
VALG_FILE = RESULT_VALGRIND.txt
CPPCHECK_FILE = RESULT_CPPCHECK.txt
VALG = valgrind --tool=memcheck  --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(VALG_FILE) ./
CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem  --force --checkers-report=$(CPPCHECK_FILE) 
CLANG = clang-format

# main info
PROJECT_NAME=TeTris
VERSION =1.0

# directories 
SRC_DIR= ../src
CL_DIR = ../materials/linters/.clang-format
BUILD_DIR = ../build
OBJ_DIR = $(BUILD_DIR)/service_files
COV_DIR = $(BUILD_DIR)/coverage
GAME_DIR = $(BUILD_DIR)/Game
DOC_DIR = ../documentation
DIST_DIR = ../distribution
TETRIS_DIR = brick_game/tetris
GUI_DIR = gui/cli
TEST_DIR = tests


# tetris files 
SRC_FILES_TETRIS = $(shell find $(TETRIS_DIR)  -type  f -name '*.c')
HEAD_FILES_TETRIS = $(shell find $(TETRIS_DIR)  -type f -name '*.h')
OBJ_FILES_TETRIS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES_TETRIS:.c=.o)))

# test files
TEST_SRC_FILES_TETRIS = $(shell find $(TEST_DIR) -type f -name '*.c')
TEST_OBJ_FILES_TETRIS = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC_FILES_TETRIS:.c=.o)))
TEST_EXEC = $(addprefix $(BUILD_DIR)/, $(notdir $(TEST_SRC_FILES_TETRIS:.c=)))
TEST_COV_OBJ_FILES_TETRIS = $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC_FILES_TETRIS:.c=.cov.o)))
TEST_COV_EXEC = $(addprefix $(BUILD_DIR)/, $(notdir $(TEST_SRC_FILES_TETRIS:.c=_cov)))

# GUI files 
GUI_SRC_FILES = $(shell find $(GUI_DIR)  -type  f -name '*.c')
GUI_HEAD_FILES = $(shell find $(GUI_DIR) -type  f -name '*.h')
GUI_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(GUI_SRC_FILES:.c=.o)))
GUI_EXEC = $(addprefix $(GAME_DIR)/, $(GAME_EXE))


# lib files		(unique for a project)
MAIN_HEADER=tetris.h
LIB_NAME=$(MAIN_HEADER:.h=.a)
LIB_COV_NAME=$(MAIN_HEADER:.h=.cov.a)

# Game files
DATA_FILE=$(BUILD_DIR)/high_score.txt
GAME_EXE=PlayTerm

# extra files
DOXYFILE = ../documentation/Doxyfile
DOXYFILE_2 = ../documentation/Doxyfile_full

# target specific variables
$(LIB_NAME): MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG) #$(VALG_FLAGS)
$(TEST_EXEC): MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG) #$(VALG_FLAGS)
$(LIB_COV_NAME): MAIN_FLAGS:=  $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG) $(COVLAGS)
$(TEST_COV_EXEC): MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG) $(COVLAGS)
$(GUI_EXEC):  MAIN_FLAGS:= $(MAIN_FLAGS) $(DEBUG_FLAGS) $(POSIX_FLAG)
$(TEST_EXEC): LIBFLAGS:=  $(CHLIB) $(MATHLIB) $(LIBFLAGS)
$(TEST_COV_EXEC): LIBFLAGS:= $(CHLIB) $(MATHLIB) $(LIBFLAGS) 
$(GUI_EXEC):  LIBFLAGS:= $(NCURLIB) $(LIBFLAGS) 

# targets
all: $(LIB_NAME)

# library
.PHONY: $(LIB_NAME)

$(LIB_NAME): clear_o $(OBJ_DIR) $(OBJ_FILES_TETRIS)
	ar rcs $@ $(OBJ_FILES_TETRIS)            

$(LIB_COV_NAME): clear_o $(OBJ_DIR) $(OBJ_FILES_TETRIS)
	ar rcs $@ $(OBJ_FILES_TETRIS)            

# tests
.PHONY: test

$(TEST_EXEC): clear_o $(OBJ_DIR) $(DATA_FILE) $(LIB_NAME) $(TEST_OBJ_FILES_TETRIS)
	$(CC) $(MAIN_FLAGS) $(TEST_OBJ_FILES_TETRIS) -o $@ $(LIB_NAME) $(LIBFLAGS)
	@rm -f $(LIB_NAME)
	@make -s clear_o

test: $(TEST_EXEC)
	@cd $(BUILD_DIR) && ./$(TEST_EXEC)

$(TEST_COV_EXEC): clear_o  $(OBJ_DIR) $(DATA_FILE) $(LIB_COV_NAME) $(TEST_OBJ_FILES_TETRIS)
	$(CC) $(MAIN_FLAGS) $(TEST_OBJ_FILES_TETRIS) -o $@ $(LIB_COV_NAME) $(LIBFLAGS)
	@rm -f $(LIB_COV_NAME)

test_cov: $(TEST_COV_EXEC)
	@cd $(BUILD_DIR) && ./$(TEST_COV_EXEC)


# game
.PHONY: install play uninstall

install: clean_data $(GAME_DIR) $(DATA_FILE) $(GUI_EXEC)
	@mv $(DATA_FILE) $(GAME_DIR)/$(notdir $(DATA_FILE))
	@rm -f $(LIB_NAME)

play:
	@cd $(GAME_DIR) && ./$(GAME_EXE)

uninstall: 
	rm -fr $(GAME_DIR)

uninstall_f:
	rm -fr $(BUILD_DIR)


# GUI
$(GUI_EXEC):clear_o $(GAME_DIR) $(LIB_NAME) $(GUI_OBJ_FILES)
	$(CC) $(MAIN_FLAGS) $(GUI_OBJ_FILES) -o $(GUI_EXEC)  $(LIB_NAME) $(LIBFLAGS)
	@make -s clear_o


# object files
$(OBJ_DIR)/%.o: */*/%.c
	@$(CC) $(MAIN_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: */%.c
	@$(CC) $(MAIN_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: */*/*/%.c
	@$(CC) $(MAIN_FLAGS) -c $< -o $@


# coverage & report
.PHONY:  gcov_report

coverage: test_cov
	gcov -b --object-directory=$(OBJ_DIR) $(SRC_FILES_TETRIS)  

gcov_report: $(COV_DIR) coverage
	@gcovr  --object-directory $(OBJ_DIR)  -r . --html --html-details --output=$(COV_DIR)/    
	@make -s clear_gc
	@make -s clear_o


#checkers 
clang_all:
	@cp $(CL_DIR) .$(CLANG)
	$(CLANG) -i $(HEAD_FILES_TETRIS) $(SRC_FILES_TETRIS) $(TEST_SRC_FILES_TETRIS) $(GUI_SRC_FILES) $(GUI_HEAD_FILES)
	@rm -f .$(CLANG)

clang_check:
	$(CLANG) -n $(CLANG_FLAGS) $(HEAD_FILES_TETRIS) $(SRC_FILES_TETRIS) $(TEST_SRC_FILES_TETRIS) $(GUI_SRC_FILES) $(GUI_HEAD_FILES)

valgrind_me: $(TEST_EXEC)
	cd $(BUILD_DIR) && $(VALG)$(TEST_EXEC)


cpp_check:
	$(CPPCHECK) $(HEAD_FILES_TETRIS) $(SRC_FILES_TETRIS) $(TEST_SRC_FILES_TETRIS) $(GUI_SRC_FILES) $(GUI_HEAD_FILES)
	mv $(CPPCHECK_FILE) $(BUILD_DIR)/$(CPPCHECK_FILE)


# documentation
.PHONY: dvi 

dvi:
	@doxygen $(DOXYFILE) 
	@echo "project documentation can be found in $(DOC_DIR)"

dvi_full:
	@doxygen $(DOXYFILE_2) 
	@echo "project documentation can be found in $(DOC_DIR)"

# archive creation
.PHONY: dist

dist: $(DIST_DIR) $(TETRIS_DIR) $(GUI_DIR) $(DOC_DIR)
	tar -czf $(DIST_DIR)/$(PROJECT_NAME)-$(VERSION).tar.gz $(TETRIS_DIR) $(GUI_DIR) $(DOC_DIR) Makefile

dist_all: $(DIST_DIR) $(TEST_DIR) $(TETRIS_DIR) $(GUI_DIR)
	tar -czf $(DIST_DIR)/$(PROJECT_NAME)-$(VERSION)-f.tar.gz $(TEST_DIR) $(TETRIS_DIR) $(GUI_DIR) $(DOC_DIR) Makefile


# service
.PHONY: clean

$(OBJ_DIR) $(BUILD_DIR) $(COV_DIR) $(GAME_DIR) $(DOC_DIR) $(DIST_DIR):
	@mkdir -p $@

$(DATA_FILE): 
	@touch $@

clean_data:
	@rm -f $(DATA_FILE)

clear_o: 
	@rm -fr $(OBJ_DIR)

clear_gc:
	@rm -fr $(OBJ_DIR)/*.gc*	
	@rm -fr *.gc*

clear_cov:
	@rm -fr $(COV_DIR)

clear_doc:
	rm -fr $(DOC_DIR)/html $(DOC_DIR)/html_full

clear_dist:
	rm -fr $(DIST_DIR)

clear: clear_cov clear_gc clear_o clean_data clear_doc clear_dist
	rm -fr $(BUILD_DIR) $(LIB_NAME) $(LIB_COV_NAME) 

clean: clear

rebuild_test: clear test

rebuild_test_cov: clear test_cov

rebuild_report: clear gcov_report

.PHONY: all 