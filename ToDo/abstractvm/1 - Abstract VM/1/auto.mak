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
$(DIROBJ)/$(DIROBJ)/AVM.o: src/AVM.cpp src/AVM.hpp src/AVMException.hpp src/Program.class.hpp \
  src/IOperand.class.hpp src/Stack.class.hpp \
  src/OperandFactory.class.hpp src/Lexer.hpp src/Operand.template.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/AVMException.o: src/AVMException.cpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
