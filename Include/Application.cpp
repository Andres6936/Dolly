#include "Application.hpp"

#include <memory>
#include <iostream>
#include <Levin/Log.h>
#include <Levin/Logger.h>

Dolly::Application::Application()
{
	Levin::LOGGER = std::make_unique <Levin::ColoredLogger>(std::wcout);

	// Pre-condition: The display has been initialized and connect to X server.
	// @see Documentation of member variable display.
	if (display == nullptr)
	{
		Levin::Error() << "Can't is possible connect to X server." << Levin::endl;
		// Terminate the program, Can't continue without the display and a
		// connection to X Server.
		std::terminate();
	}

	screenNumber = DefaultScreen(display);

	// Get dimensions of display in pixels.
	displayWidthInPixels = DisplayWidth(display, screenNumber);
	displayHeightInPixels = DisplayHeight(display, screenNumber);

	// Get dimensions of display in millimeters.
	displayWidthInMillimeters = DisplayWidthMM(display, screenNumber);
	displayHeightInMillimeters = DisplayHeightMM(display, screenNumber);

	GetGeometryInformationAboutDisplay();

	// Pre-condition: infoDisplay windows has been initialized.
	XMapWindow(display, infoDisplay);
}

Dolly::Application::~Application()
{
	XCloseDisplay(display);
}

Display* Dolly::Application::GetPointerDisplay() const
{
	return display;
}

Window Dolly::Application::GetWindowDisplay() const
{
	return XRootWindow(display, screenNumber);
}

unsigned long Dolly::Application::GetBlackPixel() const
{
	return BlackPixel(display, screenNumber);
}

unsigned long Dolly::Application::GetWhitePixel() const
{
	return WhitePixel(display, screenNumber);
}

int Dolly::Application::GetDisplayWidthInMillimeters() const
{
	return displayWidthInMillimeters;
}

int Dolly::Application::GetDisplayHeightInMillimeters() const
{
	return displayHeightInMillimeters;
}

int Dolly::Application::GetDisplayWidthInPixels() const
{
	return displayWidthInPixels;
}

int Dolly::Application::GetDisplayHeightInPixels() const
{
	return displayHeightInPixels;
}

void Dolly::Application::GetGeometryInformationAboutDisplay()
{
	// Note that the infoDisplay argument of XGetGeometry()
	// returns the infoDisplay window at the top of the
	// hierarchy of the window being queried

	if (not XGetGeometry(display, GetWindowDisplay(), &infoDisplay,
			&x, &y, &width, &height, &borderWidth, &depth))
	{
		Levin::Error() << "Can't get display window geometry." << Levin::endl;
		// Terminate the program, no is possible continue
		// without the information of infoDisplay window.
		std::terminate();
	}
}

int Dolly::Application::MainLoop(Atom& info)
{
	// MainLoop is the first method called.
	// Is needed show the widgets to user.
	XFlush(display);

	XEvent event;

	bool running = true;

	while (running)
	{
		// Gets the next event of any type on any window.
		XNextEvent(display, &event);

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
			if (event.xclient.data.l[0] == info) running = false;
		default:
			Levin::Info() << "Default Event." << Levin::endl;
			break;
		}
	}

	return 0;
}
