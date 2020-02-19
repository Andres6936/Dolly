#include "Client.hpp"

#include <memory>
#include <iostream>
#include <Levin/Log.h>
#include <Levin/Logger.h>

Dolly::Client::Client()
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

Dolly::Client::~Client()
{
	XCloseDisplay(display);
}

Display* Dolly::Client::GetPointerDisplay() const
{
	return display;
}

Window Dolly::Client::GetWindowDisplay() const
{
	return XRootWindow(display, screenNumber);
}

unsigned long Dolly::Client::GetBlackPixel() const
{
	return BlackPixel(display, screenNumber);
}

unsigned long Dolly::Client::GetWhitePixel() const
{
	return WhitePixel(display, screenNumber);
}

int Dolly::Client::GetDisplayWidthInMillimeters() const
{
	return displayWidthInMillimeters;
}

int Dolly::Client::GetDisplayHeightInMillimeters() const
{
	return displayHeightInMillimeters;
}

int Dolly::Client::GetDisplayWidthInPixels() const
{
	return displayWidthInPixels;
}

int Dolly::Client::GetDisplayHeightInPixels() const
{
	return displayHeightInPixels;
}

void Dolly::Client::GetGeometryInformationAboutDisplay()
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