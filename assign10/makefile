#
# PROGRAM:    assign10
# PROGRAMMER: Taylor Douthitt
# LOGON ID:   z1579803
# DATE DUE:   5/3/11
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign10: assign10.o Shape.o Circle.o Rectangle.o Triangle.o
	g++ $(CCFLAGS) -o assign10 assign10.o Shape.o Circle.o Rectangle.o Triangle.o
   
   
# Rules to compile source code files to object code
assign10.o: assign10.cpp Shape.h Circle.h Rectangle.h Triangle.h
	g++ $(CCFLAGS) -c assign10.cpp
      
Shape.o: Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp
	
Circle.o: Circle.cpp Circle.h
	g++ $(CCFLAGS) -c Circle.cpp
	
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ $(CCFLAGS) -c Rectangle.cpp
	
Triangle.o: Triangle.cpp Triangle.h
	g++ $(CCFLAGS) -c Triangle.cpp
	       
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign10