#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Fonts.h"
#include "j1Scene.h"
#include "Soldier.h"
#include "j1Player.h"
#include "j1DynamicObjects.h"
#include "j1FileSystem.h"
#include "j1Collision.h"
#include "j1Weapon.h"

j1Scene::j1Scene() : j1Module()
{
	name="scene";
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;
	ingame = false;
	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	Load_new_map(2);
	gamestate = INGAME;
	//App->audio->PlayMusic("audio/FIRE.ogg");
	//App->audio->VolumeMusic(100);
	App->audio->LoadFx("audio/flamethrower.wav");

	inventory = false;
	switch_map = 0;
	notrepeatmusic = true;


	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{



	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	BROFILER_CATEGORY("Update_Scene", Profiler::Color::DarkGreen)

		if (ingame == true)
		{


		}

		/*if (App->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN)
		{
			player->position.x -= 50;
			App->render->camera.x += 100;
		}
		if (App->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN)
		{
			player->position.x += 50;
			App->render->camera.x -= 100;
		}*/
		
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	//Draw a map
	App->map->Draw();

	if (App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
	{
		ret = false;
	}
	if (App->input->GetKey(SDL_SCANCODE_Z) == KEY_DOWN)
	{

	}


	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}


bool j1Scene::Load_new_map(int n)
{
	if (player == NULL)
	{
		player = App->entity_elements->CreatePlayer();
	}
	/*//SET WEAPONS WHEN MAP CHANGES
	if (weapon_equiped == BOMB)
	{
		player->bombmanager = App->entity_elements->CreateBombContainer();
		player->equiped_item = (Weapon*)player->bombmanager;
	}
	if (weapon_equiped == HOOKSHOT)
	{
		player->hook = App->entity_elements->CreateHookshot();
		player->equiped_item = (Weapon*)player->hook;
	}*/

	bool stop_rearch = false;

	pugi::xml_document	config_file;
	pugi::xml_node		config;
	config = LoadConfig(config_file);

	for (pugi::xml_node temp = config.child("maps").child("map"); stop_rearch == false; temp = temp.next_sibling())
	{
		if (temp.attribute("n").as_int(0) == n)
		{
			//player position
			player->position.x = temp.child("Link").attribute("pos_x").as_int(0);
			player->position.y = temp.child("Link").attribute("pos_y").as_int(0);



			//Enemies
			pugi::xml_node temp_enemy = temp.child("enemies").child("enemy");
			for (int i = 0; i < temp.child("enemies").attribute("num").as_int(0); i++)
			{
				enemy.push_back(App->entity_elements->CreateSoldier(temp_enemy.attribute("id").as_int(0), temp_enemy));
				temp_enemy = temp_enemy.next_sibling();
			}

			//map
			std::string name_map = temp.attribute("file").as_string("");
			App->map->Load(name_map.c_str(), n);

			//Camera position
			int scale = App->win->GetScale();
			player->camera_follow = temp.child("camera").attribute("follow").as_bool();
			if (player->camera_follow == true)
			{
				int h = App->win->GetHeight() / scale;
				int w = App->win->GetWidth() / scale;
				App->render->camera.x = -((player->position.x - (w / scale)) * scale);
				App->render->camera.y = -((player->position.y - (h / scale)) * scale);

				iPoint size_map = App->map->MapToWorld(App->map->data.width, App->map->data.height);
				if (-App->render->camera.x < 0)
				{
					App->render->camera.x = 0;
				}
				if (-App->render->camera.y < 0)
				{
					App->render->camera.y = 0;
				}
				if (((-App->render->camera.x / scale) + App->win->GetWidth() / scale) > size_map.x)
				{
					App->render->camera.x = (-size_map.x + App->win->GetWidth() / scale) * scale;
				}
				if (((-App->render->camera.y / scale) + App->win->GetHeight() / scale) > size_map.y)
				{
					App->render->camera.y = (-size_map.y + App->win->GetHeight() / scale) * scale;
				}
			}
			else
			{
				iPoint size_pos = App->map->MapToWorld(App->map->data.width, App->map->data.height);
				App->render->camera.x = (App->win->GetWidth() / scale - size_pos.x);
				App->render->camera.y = (App->win->GetHeight() / scale - size_pos.y);
			}
			stop_rearch = true;
		}
	}
	return true;
}

int j1Scene::IdMap()
{
	return id_map;

}


// ---------------------------------------------
pugi::xml_node j1Scene::LoadConfig(pugi::xml_document& config_file) const
{
	pugi::xml_node ret;

	char* buf;
	int size = App->fs->Load("Levels.xml", &buf);
	pugi::xml_parse_result result = config_file.load_buffer(buf, size);
	RELEASE(buf);

	if (result == NULL)
		LOG("Could not load map xml file config.xml. pugi error: %s", result.description());
	else
		ret = config_file.child("levels");

	return ret;
}