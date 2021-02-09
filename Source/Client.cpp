#include "Dolly/Client.hpp"

#include <memory>
#include <iostream>
#include <Levin/Log.h>
#include <Levin/Logger.h>

Dolly::Client::Client() noexcept
{
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
	widthPixels = DisplayWidth(display, screenNumber);
	heightPixels = DisplayHeight(display, screenNumber);

	// Get dimensions of display in millimeters.
	widthMillimeters = DisplayWidthMM(display, screenNumber);
	heightMillimeters = DisplayHeightMM(display, screenNumber);

	GetGeometryInformationAboutDisplay();

	displayName = DisplayString(display);

	majorVersion = ProtocolVersion(display);
	minorRevision = ProtocolRevision(display);

	release = VendorRelease(display);

	vendorName = ServerVendor(display);

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
	return widthMillimeters;
}

int Dolly::Client::GetDisplayHeightInMillimeters() const
{
	return heightMillimeters;
}

int Dolly::Client::GetDisplayWidthInPixels() const
{
	return widthPixels;
}

int Dolly::Client::GetDisplayHeightInPixels() const
{
	return heightPixels;
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