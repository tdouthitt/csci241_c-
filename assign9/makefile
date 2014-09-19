#
# PROGRAM:    assign9
# PROGRAMMER: Taylor Douthitt
# LOGON ID:   z1579803
# DATE DUE:   4/26/11
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign9: assign9.o  
	g++ $(CCFLAGS) -o assign9 assign9.o 
   
   
# Rules to compile source code files to object code
assign9.o: assign9.cpp quicksort.h
	g++ $(CCFLAGS) -c assign9.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9