# executable names, for our own makefile we only use EXE no rule for TEST (yet atleast)
EXE = ppmimg

EXE_OBJS = main.o ppm.o rgb.o

# all flags used and compiler name and stuff
CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libstdc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libstdc++ -lc++abi -lm

.PHONY: all clean

# rule for only "make"
all: $(EXE)

# this file is made when we type only make, its name will be "ppmimg"
# the object files used in the copilation of this executable are in the EXE_OBJS macro
# so update it if you want to change which files will be used for testing
# this rule links all object files to make the executable
$(EXE) : $(EXE_OBJS)
	$(LD) $(EXE_OBJS) $(LDFLAGS) -o $(EXE)

# rules for the object files start here
# add new rules according to test and files being used
# this is not linking so for example if we want graph.o, we will have graph.h and graph.cpp and structures.h in the rule
# also keep in mind the order of files is very important
# compiler starts compiliing files from right to left, so header files come on the right and cpp on the left
# for example i want to make graph.o, so i will order the files like this:
# graph.cpp graph.h structures.h
# we need structures.h for struct definitions used in graph class
# we need graph.h for all declarations in graph.cpp hence the order

main.o: main.cpp ppm.o
	$(CXX) $(CXXFLAGS) main.cpp

ppm.o: ppm.cpp ppm.h rgb.o
	$(CXX) $(CXXFLAGS) ppm.cpp ppm.h

rgb.o: rgb.cpp rgb.h
	$(CXX) $(CXXFLAGS) rgb.cpp rgb.h

# this is the generic clean rule works no matter how many rules you add above
# deletes all .o files or executables
# if in the future we add and .png file and use our own makefile, we will have to update this
clean :
	-rm -f *.o *.gch *.ppm $(EXE)
