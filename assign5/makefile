#
# PROGRAM:    assign5
# PROGRAMMER: Taylor Douthitt
# LOGON ID:   z1579803
# DATE DUE:   3/22/11
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign5: assign5.o MyString.o 
	g++ $(CCFLAGS) -o assign5 assign5.o MyString.o
   
   
# Rules to compile source code files to object code
assign5.o: assign5.cpp MyString.h
	g++ $(CCFLAGS) -c assign5.cpp
      
MyString.o: MyString.cpp MyString.h
	g++ $(CCFLAGS) -c MyString.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5
            
            
