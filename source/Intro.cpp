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

#include "../include/intro.h"

Intro::Intro()
{
    // Init variables HERE
    m_isLoaded = false;
}

Intro::~Intro()
{
    // unLoad if not happend
    unLoad();
}

void Intro::Load()
{
    // Load assets HERE
    if (!m_isLoaded)
    {
        m_isLoaded = true;
    }

}

void Intro::Input(void* event)
{
    
}

void Intro::Update(float* elapsedTime)
{

}
void Intro::Render(void* renderer)
{

}

void Intro::unLoad()
{
    // Safe unLoad assets HERE
    m_isLoaded = false;
}

bool Intro::isLoaded()
{
    return m_isLoaded;
}
