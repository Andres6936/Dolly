#ifndef DOLLY_APPLICATION_HPP
#define DOLLY_APPLICATION_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "Client.hpp"
#include "Core.hpp"

namespace Dolly
{
	class Application : public Core
	{

	private:

		/**
		 * Needed for capture the window close event.
		 */
		Atom wmDeleteMessage;

		/**
		 * Application window.
		 */
		Window window;

		/**
		 * The only instance of app in
		 * all execution of program.
		 */
		Client app = Client();

	public:

		explicit Application();

		// Methods

		int MainLoop();
	};
}


#endif //DOLLY_APPLICATION_HPP
