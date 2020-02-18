#ifndef DOLLY_APPLICATION_HPP
#define DOLLY_APPLICATION_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

namespace Dolly
{
	class Application
	{

	private:

		int screenNumber = 0;

		int maxDisplayWidth = 0;

		int maxDisplayHeigth = 0;

		Window appWindow;

		Display* display = XOpenDisplay(nullptr);

	public:

		Application();

		virtual ~Application();

		// Methods

		void Show();

		// Getters

		int GetMaxWidthDisplay(int displayNum);

		int GetMaxHeigthDisplay(int displayNum);

		[[nodiscard]] unsigned long GetBlackPixel() const;

		[[nodiscard]] unsigned long GetWhitePixel() const;

		[[nodiscard]] Window GetRootWindow() const;

		[[nodiscard]] Display* GetPointerDisplay() const;

	};
}

#endif //DOLLY_APPLICATION_HPP
