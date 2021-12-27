NAME=avm

SHELL=/bin/sh

OS:=$(shell uname)
ifeq ($(OS), Linux)
  LIBBOOST:=$(HOME)/Documents/programmation/c++/boost_1_63_0
else
  LIBBOOST:=$(HOME)/.brew/Cellar/boost/1.63.0/include
endif

DIRSRC=src
DIRHEADS=src
DIROBJ=obj

#FILESSRC= Int8.cpp Int16.cpp Int32.cpp Float.cpp Double.cpp 
FILESSRC = Program.class.cpp main.cpp OperandFactory.class.cpp \
	Stack.class.cpp Lexer.cpp AVM.cpp AVMException.cpp
#FILESHEADS=Int8.hpp Int16.hpp Int32.hpp Float.hpp Double.hpp
FILESHEADS= Operand.template.hpp \
	IOperand.class.hpp Program.class.hpp Stack.class.hpp \
	OperandFactory.class.hpp Lexer.hpp AVM.hpp AVMException.hpp

HEADERS=$(addprefix $(DIRHEADS)/, $(FILESHEADS))
OBJS=$(addprefix $(DIROBJ)/, $(FILESSRC:.cpp=.o))
SRC=$(addprefix $(DIRSRC)/, $(FILESSRC))

CXX=g++ #clang++
CXXFLAGS=-ggdb -O0 -Wconversion -Wall -Wextra -Werror -std=gnu++11 # -isystem$(LIBBOOST)
#CXXFLAGS=-ggdb -O0 -Wall -Wextra -Werror -std=gnu++11 -isystem$(LIBBOOST)
#CXXFLAGS=-Wall -Wextra -Werror -std=gnu++11 -isystem$(LIBBOOST)
#CXXFLAGS=-Wall -Wextra -Werror -std=gnu++11

TITLE="====  $@ : $? =================" 

all: $(NAME)

auto.mak:Makefile $(SRC) $(HEADERS)
	@echo $(TITLE)
	@#$(CXX) $(CXXFLAGS) -MM $(SRC) > auto.mak
	printf "" > auto.tmp
	for s in $(SRC); do printf '$$(DIROBJ)/' >> auto.tmp \
	&& $(CXX) $(CXXFLAGS) -MM $$s  >> auto.tmp 	\
	&& echo '	@echo $$(TITLE)'  >> auto.tmp \
	&& echo '	@mkdir -p $$(DIROBJ)'  >> auto.tmp \
	&& echo '	$$(CXX) $$(CXXFLAGS) -o $$@ -c $$<'  >> auto.tmp \
	; done
	mv auto.tmp auto.mak
#include auto.mak

#$(DIROBJ)/%.o:$(DIRSRC)/%.cpp
#	@echo $(TITLE)
#	@mkdir -p $(DIROBJ)
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(DIROBJ)/Lexer.o: src/Lexer.cpp src/Lexer.hpp src/Program.class.hpp \
  src/IOperand.class.hpp src/AVMException.hpp src/Stack.class.hpp \
  src/AVM.hpp src/OperandFactory.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -isystem$(LIBBOOST) -o $@ -c $<

$(DIROBJ)/Program.class.o: src/Program.class.cpp src/Program.class.hpp \
  src/IOperand.class.hpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/main.o: src/main.cpp src/AVM.hpp src/AVMException.hpp \
  src/Program.class.hpp src/IOperand.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/OperandFactory.class.o: src/OperandFactory.class.cpp \
  src/OperandFactory.class.hpp src/IOperand.class.hpp \
  src/Operand.template.hpp src/AVMException.hpp src/AVM.hpp \
  src/Program.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Stack.class.o: src/Stack.class.cpp src/Stack.class.hpp \
  src/IOperand.class.hpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/AVM.o: src/AVM.cpp src/AVM.hpp src/AVMException.hpp src/Program.class.hpp \
  src/IOperand.class.hpp src/Stack.class.hpp \
  src/OperandFactory.class.hpp src/Lexer.hpp src/Operand.template.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/AVMException.o: src/AVMException.cpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME):$(OBJS)
	@echo $(TITLE)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(DIROBJ)

re:
	@make fclean
	@make $(NAME)

test: $(NAME)
	@echo $(TITLE)
	( ./$(NAME) -f tests/exemple.avm && echo "OK" ) || echo "KO"

test_all: $(NAME)
	@echo $(TITLE)
	for t in tests/*.avm ; do ( ./$(NAME) -f $$t && echo "OK" ) || echo "KO" ; done

test_print:$(NAME)
	cat tests/print.avm
	( ./$(NAME) -f tests/print.avm && echo "OK" ) || echo "KO"
test_add:$(NAME)
	cat tests/add.avm
	( ./$(NAME) -f tests/add.avm && echo "OK" ) || echo "KO"
test_sub:$(NAME)
	cat tests/sub.avm
	( ./$(NAME) -f tests/sub.avm && echo "OK" ) || echo "KO"
test_mul:$(NAME)
	cat tests/mul.avm
	( ./$(NAME) -f tests/mul.avm && echo "OK" ) || echo "KO"
test_div:$(NAME) 
	cat tests/div.avm
	( ./$(NAME) -f tests/div.avm && echo "OK" ) || echo "KO"
test_mod:$(NAME)
	cat tests/mod.avm
	( ./$(NAME) -f tests/mod.avm && echo "OK" ) || echo "KO"
test_assert:$(NAME)
	cat tests/assert.avm
	( ./$(NAME) -f tests/assert.avm && echo "OK" ) || echo "KO"

test1:$(NAME)
	cat tests/test1.avm
	( ./$(NAME) -f tests/test1.avm && echo "OK" ) || echo "KO"
test2:$(NAME)
	cat tests/test2.avm
	( ./$(NAME) -f tests/test2.avm && echo "OK" ) || echo "KO"
test3:$(NAME)
	cat tests/test3.avm
	( ./$(NAME) -f tests/test3.avm && echo "OK" ) || echo "KO"
test4:$(NAME)
	cat tests/test4.avm
	( ./$(NAME) -f tests/test4.avm && echo "OK" ) || echo "KO"
test5:$(NAME)
	cat tests/test5.avm
	( ./$(NAME) -f tests/test5.avm && echo "OK" ) || echo "KO"
test6:$(NAME)
	cat tests/test6.avm
	( ./$(NAME) -f tests/test6.avm && echo "OK" ) || echo "KO"
test7:$(NAME)
	cat tests/test7.avm
	( ./$(NAME) -f tests/test7.avm && echo "OK" ) || echo "KO"
test8:$(NAME)
	cat tests/test8.avm
	( ./$(NAME) -f tests/test8.avm && echo "OK" ) || echo "KO"

