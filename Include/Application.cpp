#include "Application.hpp"

#include <Levin/Log.h>

Dolly::Application::Application(int argc, char** argv)
{
	// Represented the centered position of root window.
	const auto[_x, _y] = GetCenteredPosition();

	window = XCreateSimpleWindow(app.GetPointerDisplay(), app.GetWindowDisplay(),
			_x, _y, width, height, 4, app.GetBlackPixel(), app.GetWhitePixel());

	// Fill the structure XSizeHints, that will be contented the information about
	// of size and position of window.
	sizeHint.width = (int)width;
	sizeHint.height = (int)height;
	sizeHint.x = _x;
	sizeHint.y = _y;
	sizeHint.flags = PPosition | PSize;

	XSetStandardProperties(app.GetPointerDisplay(), window, "Dolly", "Dolly",
			None, argv, argc, &sizeHint);

	graphicContext = XCreateGC(app.GetPointerDisplay(), window, 0, nullptr);
	XSetBackground(app.GetPointerDisplay(), graphicContext, app.GetBlackPixel());
	XSetForeground(app.GetPointerDisplay(), graphicContext, app.GetWhitePixel());

	// Is needed that the events will be selected before the window will be mapped.
	// This sequence is important, since otherwise the window will not receive the
	// first Expose event that occurs after a new window is mapped and it will not
	// know when to redraw the window.
	XSelectInput(app.GetPointerDisplay(), window,
			StructureNotifyMask | ExposureMask | ButtonPressMask | KeyPressMask);
	// This request to Display that show this window in top of any other window
	// that may already be showing.
	XMapRaised(app.GetPointerDisplay(), window);

	wmDeleteMessage = XInternAtom(app.GetPointerDisplay(), "WM_DELETE_WINDOW", false);
	XSetWMProtocols(app.GetPointerDisplay(), window, &wmDeleteMessage, 1);
}

Dolly::Point2D<> Dolly::Application::GetCenteredPosition() const noexcept
{
	const std::int32_t x = static_cast<int>(app.GetDisplayWidthInPixels() - width) / 2;
	const std::int32_t y = static_cast<int>(app.GetDisplayHeightInPixels() - height) / 2;

	return { x, y };
}

int Dolly::Application::MainLoop()
{
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
			if (event.xexpose.count == 0)
			{
				XDrawImageString(event.xexpose.display, event.xexpose.window, graphicContext,
						50, 50, "Hello", 5);
			}
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

void Dolly::Application::Resize(const std::uint32_t _width, const std::uint32_t _height) noexcept
{
	// Redefine the width and height of window
	this->width = _width;
	this->height = _height;

	XResizeWindow(app.GetPointerDisplay(), window, width, height);
}

void Dolly::Application::ResizeAndCenter(const std::uint32_t _width, const std::uint32_t _height) noexcept
{
	this->width = _width;
	this->height = _height;

	// Get the centered position of root window
	const auto[x, y] = GetCenteredPosition();

	XMoveResizeWindow(app.GetPointerDisplay(), window, x, y, width, height);
}

Dolly::Application::~Application()
{
	XFreeGC(app.GetPointerDisplay(), graphicContext);
	XDestroyWindow(app.GetPointerDisplay(), window);
}

const Dolly::Client& Dolly::Application::GetClient()
{
	return app;
}
