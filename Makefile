build:
	gcc -Wall -Wextra -L ./game/src/lib game/main.c game/game.c -o game -I ./game/src/include -lmingw32 -lSDL2 -lSDL2Main -lSDL2_Image

run:
	game