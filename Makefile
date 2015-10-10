CPPFLAGS=-std=c++11 -O2 -pthread
CPPFILES=src/Enemy.cpp src/Player.cpp src/Projectile.cpp src/Controller.cpp src/Screen.cpp src/Main.cpp

GalagASCII: $(CPPFILES)
	g++ $(CPPFLAGS) -o $@ $^
