#include <display.h>
#include <SDL2/SDL.h>


bool SDL_initialized = false;

bool initializeSDL() {
	if (SDL_Init(SDL_INIT_VIDEO)) 
		return false;
	else
		return true;

}

static SDL_Window* window;
static SDL_Renderer* renderer;

WIN showWindow(int x, int y, int w, int h) {
	if (!SDL_initialized) 
		SDL_initialized = initializeSDL();

	if (!SDL_initialized) {
		printf("Could not initialize SDL\n"); 
		exit(1);
	}
	
	if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, &window, &renderer)) {
		SDL_Log("Error creating window %s", SDL_GetError());
		exit(1);
	}

	return WIN {window};	

}

DisplayEvent pollEvent(WIN win) {
	DisplayEvent evt;
	SDL_Event e;
	SDL_PollEvent(&e);
	if (e.type == SDL_QUIT) evt.type = e_quit;


	return evt;

}
