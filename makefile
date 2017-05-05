# Makefile

# Source files
SOURCES = UI.cpp Directory.cpp FileControlBlock.cpp FileSystem.cpp diskprocess.cpp

# Objects that result from compilation
OBJECTS = diskprocess.o UI.o Directory.o FileControlBlock.o FileSystem.o

# Include files
DEFS = diskprocess.h UI.h Directory.h FileControlBlock.h FileSystem.h

# Flags
CPPFLAGS = -g

# Libraries
LIBFLAGS = -lm

demo: $(SOURCES) $(DEFS)
	g++ $(CPPFAGS) $(SOURCES) -o demo $(LIBFLAGS)
