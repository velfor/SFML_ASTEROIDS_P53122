#include <ctime>
#include "game.h"

using namespace sf;

int main()
{
	srand(time(nullptr));
	Game game;
	game.play();
	return 0;
}