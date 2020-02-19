#include "Application.hpp"

#include <Levin/Log.h>

Dolly::Application::Application(int argc, char** argv)
{
	window = XCreateSimpleWindow(app.GetPointerDisplay(), app.GetWindowDisplay(),
			0, 0, width, height, 4, app.GetBlackPixel(), app.GetWhitePixel());

	// Fill the structure XSizeHints, that will be contented the information about
	// of size and position of window.
	sizeHint.x = 0;
	sizeHint.y = 0;
	sizeHint.width = (int)width;
	sizeHint.height = (int)height;
	sizeHint.flags = PPosition | PSize;

	XSetStandardProperties(app.GetPointerDisplay(), window, "Dolly", "Dolly",
			None, argv, argc, &sizeHint);

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

int Dolly::Application::MainLoop()
{
	// MainLoop is the first method called.
	// Is needed show the widgets to user.
	XFlush(app.GetPointerDisplay());

	XEvent event;

	bool running = true;

	while (running)
	{
		// Gets the next event of any type on any window.
		XNextEvent(app.GetPointerDisplay(), &event);

		switch (event.type)
		{
		case Expose:
			Levin::Info() << "Expose Event." << Levin::endl;
			break;
		case ConfigureNotify:
			Levin::Info() << "Configure Event." << Levin::endl;
			break;
		case ButtonPress:
			Levin::Info() << "Button Event." << Levin::endl;
			break;
		case KeyPress:
			Levin::Info() << "Key Event." << Levin::endl;
			break;
		case ClientMessage:
			// If the client close the main window.
			if (event.xclient.data.l[0] == wmDeleteMessage) running = false;
		default:
			Levin::Info() << "Default Event." << Levin::endl;
			break;
		}
	}

	return 0;
}