#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "j1EntityElementsScene.h"

enum GameState { INGAME, INMENU, TIMETOPLAY, GAMEOVER };

struct SDL_Texture;

class Player;
class Item;
class Soldier;
class DynamicObjects;
enum WeaponType;



class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	//Load Maps
	bool Load_new_map(int n);

	int IdMap();

private:
	SDL_Texture* debug_tex;
	pugi::xml_node LoadConfig(pugi::xml_document& config_file) const;

public:

	GameState gamestate;

	//Combat or not
	bool combat = false;
	Player* player = nullptr;
	std::list<Soldier*> enemy;
	std::list<Item*> items;
	std::list<DynamicObjects*> dynobjects;

	pugi::xml_node		config;

	iPoint newPosition;

	bool ingame = false;
	bool switch_menu = false;
	bool inventory = false;
	int switch_map = 0;
	int id_map = 0;



	bool notrepeatmusic;

	bool fade = false;
	bool now_switch = false;
	WeaponType weapon_equiped;
};

#endif // __j1SCENE_H__