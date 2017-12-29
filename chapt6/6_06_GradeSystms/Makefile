
#compilation flags
CXX := g++
CXXFLAGS := -g -Wall -O2 -std=c++11

#linking flags
LDFLAGS := -g -Wall -O2

#object files
OBJS := Student_info Analysis grade median main

#linking...
code: $(addprefix build/,$(addsuffix .o,$(OBJS)))
	@echo "Linking $@..."
	@$(CXX) $^ $(LDFLAGS) -o $@
	
#compilation...
build/%.o: %.cc build/%.d
	@echo "Compiling $<..."
	@$(CXX) $< $(CXXFLAGS) -c -o $@
	
#dependencies	
build/%.d: %.cc
	@echo "Generating dependencies for $<..."
	@$(CXX) $< -MM $(CXXFLAGS) -MT $(subst .d,.o,$@) -o $@

#cleaning....
clean:
	@echo "Cleaning dependencies..."
	@$(RM) build/*.o
	@echo "Cleaning object files..."
	@$(RM) build/*.d
	@echo "Cleaning executables..."
	@$(RM) ex_40

include $(wildcard build/*.d)

.PRECIOUS: build/%.d
