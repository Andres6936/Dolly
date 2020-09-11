#include "Application.hpp"

using namespace Dolly;

int main(int argc, char** argv)
{
	Application app(argc, argv);
	app.Resize(500, 500);
	app.MainLoop();
}
