# Specify flags and compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# List executable and source files
SOURCES = DAEMON.c mqttPub.c mqttSub.c tictactoe.c
EXECUTABLE = tic-tac-toe

# Specify any dependencies
LIBS = -lmqtt

# Build executable
all: $(SOURCES)
    $(CC) $(CFLAGS) $(SOURCES) $(LIBS) -o $(EXECUTABLE)

# Clean the build
clean:
    rm -f $(EXECUTABLE)

# Run the game
run: all
    ./$(EXECUTABLE)