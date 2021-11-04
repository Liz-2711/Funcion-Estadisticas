#include "Clase.h"
#include <stdio.h>

SDL_Texture* PlayerTexture; 
SDL_Texture* PlayerTexture1;// the new SDL_Texture variable
SDL_Rect srcR, destR, Mov;

using namespace std;

Clase::Clase() {

}
Clase::~Clase() {

}

void Clase::componentes(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_SHOWN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SUBSISTEMAS... ok" << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) {
			cout << "VENTANA CREADA" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 60, 76, 142);
			cout << "Renderizando" << endl;
		}


		isrun = true;
	}
	else {
		isrun = false;
	}
	tmpsurface = IMG_Load("Src/Player.png");
	PlayerTexture = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	PlayerTexture1 = SDL_CreateTextureFromSurface(renderer, tmpsurface);
	SDL_FreeSurface(tmpsurface);
	if (tmpsurface == NULL) {
		cout << "No se encontro" << endl;
	}
}


void Clase::handle() {

	SDL_Event evento;
	SDL_PollEvent(&evento);
	switch (evento.type) {
	case SDL_QUIT:
		isrun = false;
		break;

	default:
		break;
	}


}
void Clase::up() {
	cnt++;
	cout << cnt << endl;
	destR.h = 18;
	destR.w = 18;
	
	destR.x = cnt;
	destR.y = (cnt);

	Mov.h = 18;
	Mov.w = 18;

	Mov.y = cnt;


}

void Clase::renderizado() {


	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, PlayerTexture, NULL, &destR);

	SDL_RenderCopy(renderer, PlayerTexture1, NULL, &Mov);

	SDL_RenderPresent(renderer);


}
void Clase::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	cout << "FIN" << endl;
}
