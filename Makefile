OBJS = main.o Controller.o Screen.o Projectile.o Enemy.o Player.o
CPPFLAGS = -std=c++11 -O2 -pthread
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
NAME = GalagASCII
CPPFILES = src/Enemy.cpp src/Player.cpp src/Projectile.cpp src/Controller.cpp src/Screen.cpp src/Main.cpp
BIN_DIR = bin/

$(BIN_DIR)$(NAME): $(addprefix $(BIN_DIR), $(OBJS))
	g++ $(LFLAGS) $(CPPFLAGS) -o $@ $^

$(BIN_DIR) :
	mkdir $@

bin/main.o : src/main.cpp | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -Isrc/

bin/Controller.o : $(addprefix src/, Controller.cpp Controller.h Projectile.h Enemy.h Player.h Screen.h) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -Isrc/
	
bin/Projectile.o : $(addprefix src/, Projectile.cpp Projectile.h) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -Isrc/
	
bin/Enemy.o  : $(addprefix src/, Enemy.cpp Enemy.h) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -Isrc/
	
bin/Player.o : $(addprefix src/, Player.cpp Player.h) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -Isrc/

bin/Screen.o : $(addprefix src/, Screen.cpp Screen.h) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ -Isrc/

clean:
	rm -rf bin