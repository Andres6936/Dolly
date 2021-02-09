#include "Dolly/Drawable.hpp"
#include "Dolly/Client.hpp"
#include "Dolly/Application.hpp"

Dolly::Drawable::Drawable()
{
	// Get the instance of Client.
	Client app = Application::GetClient();

	window = XCreateSimpleWindow(app.GetPointerDisplay(),
			app.GetWindowDisplay(), x, y, width, height, borderWidth,
			app.GetBlackPixel(), app.GetWhitePixel());
}

Dolly::Drawable::Drawable(const Dolly::Drawable& parent)
{
	// Get the instance of Client.
	Client app = Application::GetClient();

	window = XCreateSimpleWindow(app.GetPointerDisplay(),
			parent.window, x, y, width, height, borderWidth,
			app.GetBlackPixel(), app.GetWhitePixel());
}

Dolly::Drawable::~Drawable()
{
	// Get the instance of Client.
	Client app = Application::GetClient();

	XDestroyWindow(app.GetPointerDisplay(), window);
}
