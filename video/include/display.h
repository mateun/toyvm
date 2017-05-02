
class SDL_Window;

enum EventType {
	e_quit,
	e_keydown,
	e_keyup,
	e_mousedown,
	e_mouseup

};

struct DisplayEvent {
	EventType type;
	void* data;
};

struct WIN {
	SDL_Window* window;

};

WIN showWindow(int x, int y, int w, int h);

DisplayEvent pollEvent(WIN win);
