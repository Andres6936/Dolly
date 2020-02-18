#ifndef DOLLY_FRAME_HPP
#define DOLLY_FRAME_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "Application.hpp"
#include "Core.hpp"

namespace Dolly
{
	class Frame : public Core
	{

	private:

		/**
		 * Frame window.
		 */
		Window window;

		/**
		 * The only instance of app in
		 * all execution of program.
		 */
		Application app = Application();

	public:

		explicit Frame();

		int Show();

	};
}


#endif //DOLLY_FRAME_HPP
