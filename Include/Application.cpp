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
	sizeHint.width = static_cast<int>(width);
	sizeHint.height = static_cast<int>(height);
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

	// Clients, usually those with multiple top-level windows, whose server connection
	// must survive the deletion of some of their top-level windows, should include the
	// atom WM_DELETE_WINDOW in the WM_PROTOCOLS property on each such window.

	// They will receive a ClientMessage event as described above whose data[0] field is
	// WM_DELETE_WINDOW.
	wmDeleteMessage = XInternAtom(app.GetPointerDisplay(), "WM_DELETE_WINDOW", false);
	XSetWMProtocols(app.GetPointerDisplay(), window, &wmDeleteMessage, 1);

	// X applications need to be careful in their use of colour, most colour
	// workstations use a colour map, that is part of the display hardware and
	// not part of the windows on the screen.
	// All the windows on the screen must share the same hardware colour map.
	colorMap = DefaultColormap(app.GetPointerDisplay(), DefaultScreen(app.GetPointerDisplay()));
}

Dolly::Application::~Application()
{
	XFreeGC(app.GetPointerDisplay(), graphicContext);
	XDestroyWindow(app.GetPointerDisplay(), window);
}

Dolly::Point2D<> Dolly::Application::GetCenteredPosition() const noexcept
{
	const std::int32_t x = static_cast<int>(app.GetDisplayWidthInPixels() - width) / 2;
	const std::int32_t y = static_cast<int>(app.GetDisplayHeightInPixels() - height) / 2;

	return { x, y };
}

int Dolly::Application::HandleEvents()
{
	XEvent event;

	// Gets the next event of any type on any window.
	XNextEvent(app.GetPointerDisplay(), &event);

	switch (event.type)
	{
	case Expose:
		Levin::Info() << "Expose Event." << Levin::endl;
		if (event.xexpose.count == 0)
		{
			// XDrawImageString(event.xexpose.display, event.xexpose.window, graphicContext, 50, 50, "Hello", 5);
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
		if (event.xclient.data.l[0] == wmDeleteMessage)
		{
			running = false;
		}
	default:
		Levin::Info() << "Default Event." << Levin::endl;
		break;
	}

	return 0;
}

void Dolly::Application::DrawString(std::string_view _string) noexcept
{
	XDrawImageString(app.GetPointerDisplay(), window, graphicContext, 50, 50,
			_string.data(), _string.size());
}

void Dolly::Application::Resize(const std::uint32_t _width, const std::uint32_t _height) noexcept
{
	// Redefine the width and height of window
	this->width = _width;
	this->height = _height;

	XResizeWindow(app.GetPointerDisplay(), window, width, height);
}

void Dolly::Application::ResizeAndCenter(const std::uint32_t _width,
		const std::uint32_t _height) noexcept
{
	this->width = _width;
	this->height = _height;

	// Get the centered position of root window
	const auto[x, y] = GetCenteredPosition();

	XMoveResizeWindow(app.GetPointerDisplay(), window, x, y, width, height);
}

void Dolly::Application::DrawPixel(const std::uint32_t x, const std::uint32_t y,
		const Pixel& color) noexcept
{
	// The pixel field is the colour map index for the colour and red, green,
	// and blue are the three components of the colour, these values range from
	// 0 to 65535, with 65535 giving the maximum amount of colour.
	XColor xColor;

	// The use of the magic number is get from follow
	// formulae: 255 (Max value for a pixel in Pixel class) * x (The magic
	// number) = 65535 (Max value for a pixel in X Server)
	xColor.red = color.GetRed() * 257;
	xColor.green = color.GetGreen() * 257;
	xColor.blue = color.GetBlue() * 257;

	// Before calling XAllocColor, the red, green and blue fields of color must
	// be set to the desired color.
	// The XAllocColor() function allocates a read-only colorMap entry
	// corresponding to the closest RGB value supported by the hardware.
	XAllocColor(app.GetPointerDisplay(), colorMap, &xColor);

	XSetForeground(app.GetPointerDisplay(), graphicContext, xColor.pixel);
	XDrawPoint(app.GetPointerDisplay(), window, graphicContext, x, y);
}

const Dolly::Client& Dolly::Application::GetClient()
{
	return app;
}

// Getters

bool Dolly::Application::IsRunning() const noexcept
{
	return running;
}

// Setters

void Dolly::Application::SetMinSize(const Dolly::Size& size) noexcept
{
	SetMinSize(size.w, size.h);
}

void Dolly::Application::SetMaxSize(const Dolly::Size& size) noexcept
{
	SetMaxSize(size.w, size.h);
}

void Dolly::Application::SetTitleWindow(std::string_view _title) const noexcept
{
	// The window name is a standard null-terminated text string
	// Many windows managers display the current window name in a
	// prominent place.
	XStoreName(app.GetPointerDisplay(), window, _title.data());
}

void Dolly::Application::SetMinSize(const std::uint32_t _width, const std::uint32_t _height) noexcept
{
	sizeHint.min_width = _width;
	sizeHint.min_height = _height;

	// The bitmask specifying which other fields contain valid information.
	// For this case, PMinSize is a valid information
	// For avoid deleted the other valid information, needed overwrite the
	// value of flags
	sizeHint.flags = sizeHint.flags | PMinSize;

	XSetNormalHints(app.GetPointerDisplay(), window, &sizeHint);
}

void Dolly::Application::SetMaxSize(const std::uint32_t _width, const std::uint32_t _height) noexcept
{
	sizeHint.max_width = _width;
	sizeHint.max_height = _height;

	// The bitmask specifying which other fields contain valid information.
	// For this case, PMaxSize is a valid information
	// For avoid deleted the other valid information, needed overwrite the
	// value of flags
	sizeHint.flags = sizeHint.flags | PMaxSize;

	XSetNormalHints(app.GetPointerDisplay(), window, &sizeHint);
}
