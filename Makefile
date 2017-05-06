# Makefile

# Source files
SOURCES = UI.cpp Directory.cpp FileControlBlock.cpp FileSystem.cpp diskprocess.cpp Main.cpp

# Objects that result from compilation
OBJECTS = diskprocess.o UI.o Directory.o FileControlBlock.o FileSystem.o

# Include files
DEFS = diskprocess.h UI.h Directory.h FileControlBlock.h FileSystem.h

# Flags
CPPFLAGS = -g

# Libraries
LIBFLAGS = -lm

CISC3595_team10_atos-fs: $(DEFS) $(SOURCES) 
	g++ $(CPPFAGS) $(SOURCES) -o CISC3595_team10_atos-fs $(LIBFLAGS)
