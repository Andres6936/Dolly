#ifndef DOLLY_FRAME_HPP
#define DOLLY_FRAME_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

namespace Dolly
{
	class Frame
	{

	private:

		inline static int WIDTH_DEFAULT = 300;

		inline static int HEIGTH_DEFAULT = 300;

		Window window;

	public:

		Frame();

		Frame(short width, short heigth);

	};
}


#endif //DOLLY_FRAME_HPP
