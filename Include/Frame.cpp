#include "Frame.hpp"

Dolly::Frame::Frame()
{
	window = XCreateSimpleWindow(app.GetPointerDisplay(), app.GetWindowDisplay(),
			0, 0, width, height, 4, app.GetBlackPixel(), app.GetWhitePixel());

	// Is needed that the events will be selected before the window will be mapped.
	// This sequence is important, since otherwise the window will not receive the
	// first Expose event that occurs after a new window is mapped and it will not
	// know when to redraw the window.
	XSelectInput(app.GetPointerDisplay(), window,
			StructureNotifyMask | ExposureMask | ButtonPressMask | KeyPressMask);
	XMapWindow(app.GetPointerDisplay(), window);

	wmDeleteMessage = XInternAtom(app.GetPointerDisplay(), "WM_DELETE_WINDOW", false);
	XSetWMProtocols(app.GetPointerDisplay(), window, &wmDeleteMessage, 1);
}

int Dolly::Frame::Show()
{
	return app.MainLoop(wmDeleteMessage);
}
