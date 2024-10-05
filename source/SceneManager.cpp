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

#include "../include/engine/SceneManager.h"

SceneManager::SceneManager()
{
    m_Scenes["defaultScene"] = new defaultScene();
    m_activeScene = m_Scenes["defaultScene"];
}

SceneManager::~SceneManager()
{
    // unLoad  all
    for (auto it = m_Scenes.begin(); it != m_Scenes.end();)
    {
        it->second->unLoad();
        ++it;
    }

    //Remove all
    m_Scenes.clear();
}

void SceneManager::addScene(Scene* scene, std::string name)
{
    auto search = m_Scenes.find(name);
    if (search != m_Scenes.end())
    {
        // Already there do nothing
    }
    else
    {
        // Not found, add Scene
        m_Scenes[name] = scene;
    }
}

void SceneManager::removeScene(std::string name)
{
    auto search = m_Scenes.find(name);
    if (search != m_Scenes.end())
    {
        // Found, unLoad and Remove
        search->second->unLoad();
        m_Scenes.erase(search);
    }
    else
    {
        // Not found, do nothing
    }
}

void SceneManager::setActive(std::string name)
{
    auto search = m_Scenes.find(name);
    if (search != m_Scenes.end())
    {
        // Found, set as active
        m_activeScene = search->second;

    }
    else
    {
        // Not found, do nothing
    }
}

void SceneManager::loadScene()
{
    if (!m_activeScene->isLoaded())
        m_activeScene->Load();
}

void SceneManager::unloadScene()
{
    if (m_activeScene->isLoaded())
        m_activeScene->unLoad();
}

void SceneManager::InputScene(void* event)
{
    m_activeScene->Input(event);
}

void SceneManager::UpdateScene(float* elapsedTime)
{
    m_activeScene->Update(elapsedTime);
}

void SceneManager::RenderScene(void* renderer)
{
    m_activeScene->Render(renderer);
}


// Default Scene
defaultScene::defaultScene()
{
    m_isLoaded = true;
}
defaultScene::~defaultScene()
{
    unLoad();
}

void defaultScene::Load()
{
    if (!m_isLoaded)
    {
        // Load stuff

        m_isLoaded = true;
    }
}

void defaultScene::Input(void* event)
{
    
}
void defaultScene::Update(float* elapsedTime)
{
    
}
void defaultScene::Render(void* renderer)
{

}

void defaultScene::unLoad()
{
    m_isLoaded = false;
}

bool defaultScene::isLoaded()
{
    return m_isLoaded;
}