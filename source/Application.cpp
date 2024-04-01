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