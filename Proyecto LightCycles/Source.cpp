/*#include<SDL.h>
#include "Clase.h"
//#include <SDL_image.h>



Clase* juego = nullptr;


int main(int argc, char* argv[])
{
	juego = new Clase();

	juego->componentes("Light Cycles", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 600, true);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 inicio;
	int Tiempo;



	//juego = new Clase();
	while (juego->run()) {

		inicio = SDL_GetTicks();
		juego->handle();
		juego->up();
		juego->renderizado();

		Tiempo = SDL_GetTicks() - inicio;


		if (frameDelay > Tiempo) {
			SDL_Delay(frameDelay - Tiempo);
		}



	}
	juego->clean();

	return 0;



}
*/

#include <iostream>
#include "Juego.h"

using namespace std;

int main(int argc, char* argv[])
{
	Juego game;
	game.Run();
	cout << "Game has terminated successfully, score: " << game.GetScore()
		<< ", size: " << game.GetSize() << endl;
	return 0;
}