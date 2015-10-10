OBJS = Main.o Controller.o Screen.o Projectile.o Enemy.o Player.o
FLAGS = -std=c++11 -O2 -pthread $(DEBUG) 
LINK_ONLY = -c
CC = g++
DEBUG = -g
NAME = GalagASCII
BIN_DIR = bin/

$(BIN_DIR)$(NAME): $(addprefix $(BIN_DIR), $(OBJS))
	g++ $(FLAGS) -o $@ $^

$(BIN_DIR) :
	mkdir $@

$(BIN_DIR)%.o: src/%.cpp | $(BIN_DIR)
	$(CC) $(LINK_ONLY) $(FLAGS) $< -o $@ -I src/

clean:
	rm -rf bin
