#ifndef DOLLY_CLIENT_HPP
#define DOLLY_CLIENT_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "Core.hpp"

namespace Dolly
{
	class Client : public Core
	{

	private:

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
		 * Information of characteristics display.
		 *
		 * @note Is needed called the method
		 *  GetGeometryInformationAboutDisplay for
		 *  initialized correctly this variable.
		 */
		Window infoDisplay;

		/**
		 * Structure needed for connect to X Server.
		 *
		 * @post The display will be initialized and
		 *  connect to X server.
		 */
		Display* display = XOpenDisplay(nullptr);

		/**
		 * @post The infoDisplay window will be initialized.
		 */
		void GetGeometryInformationAboutDisplay();

	public:

		Client();

		virtual ~Client();

		// Methods

		// Getters

		[[nodiscard]] int GetDisplayWidthInPixels() const;

		[[nodiscard]] int GetDisplayHeightInPixels() const;

		[[nodiscard]] int GetDisplayWidthInMillimeters() const;

		[[nodiscard]] int GetDisplayHeightInMillimeters() const;

		[[nodiscard]] unsigned long GetBlackPixel() const;

		[[nodiscard]] unsigned long GetWhitePixel() const;

		[[nodiscard]] Window GetWindowDisplay() const;

		[[nodiscard]] Display* GetPointerDisplay() const;

	};
}

#endif //DOLLY_CLIENT_HPP
