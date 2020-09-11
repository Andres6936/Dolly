#include "Application.hpp"

using namespace Dolly;

int main(int argc, char** argv)
{
	Application app(argc, argv);

	app.SetTitleWindow("Application");
	app.ResizeAndCenter(500, 500);
	app.SetMinSize(300, 300);
	app.MainLoop();
}
