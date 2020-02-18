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

		Window window;

		Application& parent;

	public:

		explicit Frame(Application& _parent);

	};
}


#endif //DOLLY_FRAME_HPP
