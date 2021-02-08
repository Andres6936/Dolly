#include "Application.hpp"

using namespace Dolly;

int main(int argc, char** argv)
{
	Application app(argc, argv);

	app.SetTitleWindow("Application");
	app.ResizeAndCenter(500, 500);
	app.SetMinSize(300, 300);
	app.SetMaxSize(700, 700);

	while (app.IsRunning())
	{
		app.DrawPixel(5, 5);
		app.DrawPixel(5, 6);
		app.DrawPixel(5, 7);
		app.DrawString("Hello, World!");
		app.HandleEvents();
	}
}
