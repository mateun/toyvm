#include <SDL2/SDL.h>
#include <string>

SDL_Texture* loadImageIntoTexture(const std::string& imageName, SDL_Renderer* renderer) {
	SDL_Surface* surface = SDL_LoadBMP(imageName.c_str());
	if (!surface) { SDL_Log("E: loading image %s %s", imageName.c_str(), SDL_GetError());
									return nullptr;}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void fillRect(SDL_Rect& r, int size) { 
	r.x = 0;
	r.y = 0;
	r.w = size;
	r.h = size; 
}

int main(int argc, char** args) {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* surface;
	SDL_Texture* texture;

	if (SDL_Init(SDL_INIT_VIDEO)) { SDL_Log("Error SDL init%s", SDL_GetError()); exit(1);}

	SDL_Log("SDL initialized");
	
	if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer)) {
		SDL_Log("Error creating window %s", SDL_GetError());
		exit(1);
	}

	SDL_Texture* a_tex = loadImageIntoTexture("../images/courier.bmp", renderer);
	if (!a_tex) { SDL_Log("Error: tex loading %s", SDL_GetError()); exit(1); }

	int cursorX=0, cursorY=0;
	SDL_StartTextInput();
	while (1) {
		SDL_Event event;
		//SDL_PollEvent(&event);
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) break;
		if (event.type == SDL_TEXTINPUT) printf("textinput: %s\n", event.text.text);
		if (event.type == SDL_KEYUP) printf("keyup: %d\n", event.key.keysym.sym);
		if (event.type == SDL_TEXTEDITING) printf("textedit: %s\n", event.edit.text);

		SDL_SetRenderDrawColor(renderer, 0x20, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0xee, 0xea, 0xee, 0xFF);
		SDL_Rect r; fillRect(r, 256);
		SDL_RenderCopy(renderer, a_tex, NULL, &r);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	return 0;
}
