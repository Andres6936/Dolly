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

		/**
		 * Id of screen used for X server.
		 */
		int screenNumber = 0;

		/**
		 * Width of display in pixels.
		 */
		int displayWidthInPixels = 0;

		/**
		 * Height of display in pixels.
		 */
		int displayHeightInPixels = 0;

		/**
		 * Width of display in millimeters.
		 */
		int displayWidthInMillimeters = 0;

		/**
		 * Height of display in millimeters.
		 */
		int displayHeightInMillimeters = 0;

		/**
		 * Initial window that is show when a
		 * instance of this class is created.
		 */
		Window appWindow;

		/**
		 * Structure needed for connect to X Server.
		 */
		Display* display = XOpenDisplay(nullptr);

	public:

		Application();

		virtual ~Application();

		// Methods

		void Show();

		// Getters

		[[nodiscard]] int GetDisplayWidthInPixels() const;

		[[nodiscard]] int GetDisplayHeightInPixels() const;

		[[nodiscard]] int GetDisplayWidthInMillimeters() const;

		[[nodiscard]] int GetDisplayHeightInMillimeters() const;

		[[nodiscard]] unsigned long GetBlackPixel() const;

		[[nodiscard]] unsigned long GetWhitePixel() const;

		[[nodiscard]] Window GetRootWindow() const;

		[[nodiscard]] Display* GetPointerDisplay() const;

	};
}

#endif //DOLLY_APPLICATION_HPP
