#ifndef DOLLY_CLIENT_HPP
#define DOLLY_CLIENT_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <string_view>

#include <Dolly/Core.hpp>

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
		int widthPixels = 0;

		/**
		 * Height of display in pixels.
		 *
		 * @note Is same that height.
		 */
		int heightPixels = 0;

		/**
		 * Width of display in millimeters.
		 */
		int widthMillimeters = 0;

		/**
		 * Height of display in millimeters.
		 */
		int heightMillimeters = 0;

		/**
		 * Major version of X Window Protocol
		 * used on the connection.
		 */
		int majorVersion = 0;

		/**
		 * Minor revision of X Window Protocol
		 * used on the connection.
		 */
		int minorRevision = 0;

		/**
		 * Vendor release number of workstation
		 * server used on the connection.
		 */
		int release = 0;

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
		 * Display name of specified connection.
		 *
		 * @note Information useful for error reporting.
		 */
		std::string_view displayName;

		/**
		 * Identity the vendor of the connected workstation.
		 */
		std::string_view vendorName;

		/**
		 * @post The infoDisplay window will be initialized.
		 */
		void GetGeometryInformationAboutDisplay();

	public:

		Client() noexcept;

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
