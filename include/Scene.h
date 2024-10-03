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
#include "../include/Scene.h"

class Scene
{
public:
	virtual void Load() = 0;

	virtual void Input(void* event) = 0;
	virtual void Update(float* elapsedTime) = 0;
	virtual void Render(void* renderer) = 0;

	virtual void unLoad() = 0;

	virtual bool isLoaded() = 0;
};