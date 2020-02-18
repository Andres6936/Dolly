#include "Frame.hpp"

Dolly::Frame::Frame(Application& _parent) : parent(_parent)
{
	window = XCreateSimpleWindow(parent.GetPointerDisplay(), parent.GetRootWindow(),
			0, 0, width, height, 4, parent.GetBlackPixel(), parent.GetWhitePixel());

	XMapWindow(parent.GetPointerDisplay(), window);
}
