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

	maxDisplayWidth = DisplayWidth(display, screenNumber);

	maxDisplayHeight = DisplayHeight(display, screenNumber);

	appWindow = XCreateSimpleWindow(display, GetRootWindow(),
			0, 0, 300, 300, 4, GetBlackPixel(), GetWhitePixel());

	XMapWindow(display, appWindow);
}

Dolly::Application::~Application()
{
	XCloseDisplay(display);
}

int Dolly::Application::GetMaxWidthDisplay(int displayNum)
{
	return maxDisplayWidth;
}

int Dolly::Application::GetMaxHeightDisplay(int displayNum)
{
	return maxDisplayHeight;
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
