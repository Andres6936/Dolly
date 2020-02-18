#include "Frame.hpp"

Dolly::Frame::Frame()
{
	window = XCreateSimpleWindow(app.GetPointerDisplay(), app.GetRootWindow(),
			0, 0, width, height, 4, app.GetBlackPixel(), app.GetWhitePixel());

	XMapWindow(app.GetPointerDisplay(), window);
}

int Dolly::Frame::Show()
{
	XSelectInput(app.GetPointerDisplay(), window,
			StructureNotifyMask | ExposureMask | ButtonPressMask | KeyPressMask);

	return app.MainLoop();
}
