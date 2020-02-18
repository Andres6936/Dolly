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
		 * Coordinate in x of root window.
		 */
		int x = 0;

		/**
		 * Coordinate in y of root window.
		 */
		int y = 0;

		unsigned int depth = 0;

		/**
		 * Width of root window in pixels.
		 *
		 * @note Is same that width in pixels of display.
		 */
		unsigned int width = 0;

		/**
		 * Height of root window in pixels.
		 *
		 * @note Is same that height in pixels of display.
		 */
		unsigned int height = 0;

		unsigned int borderWidth = 0;

		/**
		 * Id of screen used for X server.
		 */
		int screenNumber = 0;

		/**
		 * Width of display in pixels.
		 *
		 * @note Is same that width.
		 */
		int displayWidthInPixels = 0;

		/**
		 * Height of display in pixels.
		 *
		 * @note Is same that height.
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
		 * Root window of display.
		 */
		Window root;

		/**
		 * Structure needed for connect to X Server.
		 *
		 * @post The display will be initialized and
		 *  connect to X server.
		 */
		Display* display = XOpenDisplay(nullptr);

		/**
		 * @post The root window will be initialized.
		 */
		void GetGeometryInformationAboutRootWindow();

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
