#ifndef DOLLY_DRAWABLE_HPP
#define DOLLY_DRAWABLE_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <Dolly/Core.hpp>

namespace Dolly
{
	class Drawable : public Core
	{

	protected:

		/**
		 *  X Window System is a protocol driven
		 *  by Windows. All object that can be
		 *  drawable must have a instance Window.
		 */
		Window window;

	public:

		Drawable();

		Drawable(const Drawable& parent);

		virtual ~Drawable();

	};
}


#endif //DOLLY_DRAWABLE_HPP
