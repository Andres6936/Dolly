#include "Dolly/Application.hpp"

using namespace Dolly;

int main(int argc, char** argv)
{
	Application app(argc, argv);

	app.SetTitleWindow("Application");
	app.ResizeAndCenter(500, 500);
	app.SetMinSize(300, 300);
	app.SetMaxSize(700, 700);

	for (std::size_t x = 0; x < 500; x += 1)
	{
		for (std::size_t y = 0; y < 500; y += 1)
		{
			app.DrawPixel(x, y, { 255, 0, 0 });
		}
	}

	while (app.IsRunning())
	{
		app.HandleEvents();
	}
}
