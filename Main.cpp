#include "Application.hpp"
#include "Frame.hpp"

using namespace Dolly;

int main()
{
	Application app;
	Frame frame(app);
	app.MainLoop();
}
