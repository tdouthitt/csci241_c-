#
# PROGRAM:    assign7
# PROGRAMMER: Taylor Douthitt
# LOGON ID:   z1579803
# DATE DUE:   4/12/11
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign7: assign7.o Stack.o 
	g++ $(CCFLAGS) -o assign7 assign7.o Stack.o
   
   
# Rules to compile source code files to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp
      
Stack.o: Stack.cpp Stack.h
	g++ $(CCFLAGS) -c Stack.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7