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
		 * The graphic context.
		 */
		GC graphicContext;

		/**
		 * Needed for capture the window close event.
		 */
		Atom wmDeleteMessage;

		/**
		 * Application window.
		 */
		Window window;

		/**
		 * Use for inform other windows running about
		 * of this window.
		 */
		XSizeHints sizeHint;

		/**
		 * The only instance of app in
		 * all execution of program.
		 */
		Client app = Client();

	public:

		Application(int argc, char** argv);

		virtual ~Application();

		// Methods

		int MainLoop();
	};
}


#endif //DOLLY_APPLICATION_HPP
