#include <SDL2/SDL.h>

int main(int argc, char** args) {

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Error initializing SDL%s", SDL_GetError());
		exit(1);
	}

	SDL_Log("SDL initialized");
	
	if (SDL_CreateWindowAndRenderer(320, 200, SDL_WINDOW_SHOWN, &window, &renderer)) {
		SDL_Log("Error creating window %s", SDL_GetError());
		exit(1);
	}

	SDL_Event event;
	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) break;

		SDL_SetRenderDrawColor(renderer, 0x20, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0xee, 0xea, 0xee, 0xFF);
		for (int x = 0; x < 200; x++) {
			for (int y = 0; y < 150; y++) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	
	
	return 0;
}
