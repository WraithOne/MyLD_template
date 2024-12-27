////////////////////////////////////////////
//
//	MyLDe - My Ludum Dare engine
//
//	@WraithOne
//
//	My little game engine for Ludum Dare
//	and other Game Jams
//
////////////////////////////////////////////

#pragma once
#include "3rdParty.h"
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void addScene(Scene* scene, std::string name);
	void removeScene(std::string name);
	void setActive(std::string name);
	std::string getActive();
	void loadScene();
	void unloadScene();

	void InputScene(void* event);
	void UpdateScene(float* elapsedTime);
	void RenderScene(void* renderer);

private:
	std::unordered_map<std::string, Scene*> m_Scenes;
	Scene* m_activeScene;
};

class defaultScene : public Scene
{
public:
	defaultScene();
	~defaultScene();

	void Load();

	void Input(void* event);
	void Update(float* elapsedTime);
	void Render(void* renderer);

	void unLoad();

	bool isLoaded();
private:
	bool m_isLoaded;
};