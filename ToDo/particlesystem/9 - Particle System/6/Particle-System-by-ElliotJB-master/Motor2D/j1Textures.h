#ifndef __j1TEXTURES_H__
#define __j1TEXTURES_H__

#include "j1Module.h"
#include <list>
#include "p2Defs.h"

struct SDL_Texture;
struct SDL_Surface;

struct Size_texture
{
	/*Size_texture(SDL_Texture* tex, int x, int y)
	{
		texture = tex;
		width = x;
		height = y;
	}*/
	SDL_Texture* texture;
	int width;
	int height;
};

class j1Textures : public j1Module
{
public:

	j1Textures();

	// Destructor
	virtual ~j1Textures();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called before quitting
	bool CleanUp();

	// Load Texture
	SDL_Texture* const	Load(const char* path);
	bool				UnLoad(SDL_Texture* texture);
	SDL_Texture* const	LoadSurface(SDL_Surface* surface);
	void				GetSize(const SDL_Texture* texture, uint& width, uint& height) const;
	int					GetWidth(const SDL_Texture* texture);
	int					GetHeight(const SDL_Texture* texture);

public:

	std::list<SDL_Texture*> textures;
	std::list<Size_texture> size_textures;

};


#endif // __j1TEXTURES_H__