#ifndef __MODULERENDER_H__
#define __MODULERENDER_H__

//#include "Globals.h"
#include "Module.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate(float deltaTime);
	update_status Update(const float deltaTime);
	update_status PostUpdate(float deltaTime);
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed = 1.0f, bool moveX = false, bool moveY = false, int scaledW = -1, int scaledH = -1);
	bool Print(unsigned int idFont, const char* text, int x, int y, float speed = 1.0f, bool center=true);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);
	bool DrawPoly(Color c, short x1, short y1, short w1, short x2, short y2, short w);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
};

#endif // __MODULERENDER_H__