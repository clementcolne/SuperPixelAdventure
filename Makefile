SRC=superPixelAdventure.c game.c mapBuilder.c menu.c isEmpty.c keyboardEvent.c tileset.c picture.c atlas.c display.c button.c buttonCollision.c booleans.c createSDL.c variables.c tables.c createText.c createAudio.c menuMove.c error.c
BIN=SuperPixelAdventure

$(BIN): $(SRC) game.h mapBuilder.h constants.h menu.h isEmpty.h keyboardEvent.h tileset.h picture.h atlas.h display.h button.h buttonCollision.h booleans.h createSDL.h variables.h tables.h createText.h createAudio.h menuMove.h error.h
	gcc -Wall -g -std=c99 $(SRC) `sdl-config --cflags --libs` -lSDL_ttf -lSDL_mixer -L./usr/lib -I./usr/include -lm -o $(BIN)

clean:
	rm -f $(BIN)
