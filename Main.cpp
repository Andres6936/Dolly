#include "Dolly/Application.hpp"

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
		app.DrawPixel(5, 5, { 255, 0, 0 });
		app.DrawPixel(5, 6, { 0, 255, 0 });
		app.DrawPixel(5, 7, { 0, 0, 255 });
		app.DrawString("Hello, World!");
		app.HandleEvents();
	}
}
