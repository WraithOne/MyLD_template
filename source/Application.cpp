////////////////////////////////////////////
//
//	MyLDe - My Ludum Dare engine
//
//	@WraithOne
//
//	My little game engine for Ludum Dare
//	and other Game Jams
//
//	Application.cpp
//	Created: 29.10.2016
//	Edited:	29.10.2016
//
////////////////////////////////////////////

#include "../include/Application.h"

namespace MyLDe
{
	Appliction::Appliction()
	{
		m_isRunning = false;
	}
	void Appliction::Run()
	{
		m_isRunning = true;

		while (m_isRunning)
		{
			Update();

			Draw();
		}
	}
	void Appliction::Exit()
	{
		m_isRunning = false;
	}
}