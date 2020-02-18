#include "Application.hpp"

#include <memory>
#include <iostream>
#include <Levin/Log.h>
#include <Levin/Logger.h>

Dolly::Application::Application()
{
	Levin::LOGGER = std::make_unique<Levin::ColoredLogger>(std::wcout);

	if (display == nullptr)
	{
		Levin::Error() << "Not is possible connect to X server." << Levin::endl;
		// Terminate the program, is not possible continue with the display.
		std::terminate();
	}

	screenNumber = DefaultScreen(display);

	// Get dimensions of display in pixels.
	displayWidthInPixels = DisplayWidth(display, screenNumber);
	displayHeightInPixels = DisplayHeight(display, screenNumber);

	// Get dimensions of display in millimeters.
	displayWidthInMillimeters = DisplayWidthMM(display, screenNumber);
	displayHeightInMillimeters = DisplayHeightMM(display, screenNumber);

	appWindow = XCreateSimpleWindow(display, GetRootWindow(),
			0, 0, 300, 300, 4, GetBlackPixel(), GetWhitePixel());

	XMapWindow(display, appWindow);
}

Dolly::Application::~Application()
{
	XCloseDisplay(display);
}

int Dolly::Application::GetWidthDisplayInPixels(int displayNum) const
{
	return displayWidthInPixels;
}

int Dolly::Application::GetHeightDisplayInPixels(int displayNum) const
{
	return displayHeightInPixels;
}

Display* Dolly::Application::GetPointerDisplay() const
{
	return display;
}

Window Dolly::Application::GetRootWindow() const
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

void Dolly::Application::Show()
{
	XFlush(display);
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
