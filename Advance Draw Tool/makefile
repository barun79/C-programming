# Your name 1000074079 Coding Assignment 4

SRC1 = AdvanceDrawTool.c
SRC2 = DrawTool.c
SRC3 = ListLib.c
SRC4 = FileLib.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
EXE = $(SRC1:.c=.e)

CFLAGS = -g

all: $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) -o $(EXE)

# Correctly compile the object files
$(OBJ1): $(SRC1)
	gcc -c $(CFLAGS) $(SRC1)

$(OBJ2): $(SRC2)
	gcc -c $(CFLAGS) $(SRC2)

$(OBJ3): $(SRC3)
	gcc -c $(CFLAGS) $(SRC3)

$(OBJ4): $(SRC4)
	gcc -c $(CFLAGS) $(SRC4)

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(EXE)
