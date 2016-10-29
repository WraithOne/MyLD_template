////////////////////////////////////////////
//
//	MyLDe - My Ludum Dare engine
//
//	@WraithOne
//
//	My little game engine for Ludum Dare
//	and other Game Jams
//
//	Application.h
//	Created: 29.10.2016
//	Edited:	29.10.2016
//
////////////////////////////////////////////

#ifndef APLLICATION_H_
#define APLLICATION_H_

namespace MyLDe
{
	class Appliction
	{
	public:
		Appliction();

		void Run();

		virtual void Update() = 0;
		virtual void Draw() = 0;

		void Exit();

	private:
		bool m_isRunning;
	};
}

#endif // !APLLICATION_H_