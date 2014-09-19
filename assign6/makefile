#
# PROGRAM:    assign6
# PROGRAMMER: Taylor Douthitt
# LOGON ID:   z1579803
# DATE DUE:   3/29/11
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign6: assign6.o MyString.o 
	g++ $(CCFLAGS) -o assign6 assign6.o MyString.o
   
   
# Rules to compile source code files to object code
assign6.o: assign6.cpp MyString.h
	g++ $(CCFLAGS) -c assign6.cpp
      
MyString.o: MyString.cpp MyString.h
	g++ $(CCFLAGS) -c MyString.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
            
            
