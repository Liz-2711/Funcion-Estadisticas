#pragma once

#ifndef CLASE_H
#define CLASE_H
#include "SDL.h"
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>


class Clase
{

public:
	Clase();
	~Clase();

	void componentes(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handle();
	void up();
	void renderizado();
	void clean();
	bool run() { return isrun; }

private:
	int cnt = 0;
	bool isrun;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* tmpsurface;
};
#endif
