#ifndef DOLLY_APPLICATION_HPP
#define DOLLY_APPLICATION_HPP

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "Client.hpp"
#include "Core.hpp"

#include <cstdint>
#include <string_view>

#include <Geometry/Point2D.hpp>

namespace Dolly
{
	class Application : public Core
	{

	private:

		/**
		 * The graphic context.
		 */
		GC graphicContext;

		/**
		 * Needed for capture the window close event.
		 */
		Atom wmDeleteMessage;

		/**
		 * Application window.
		 */
		Window window;

		/**
		 * Use for inform other windows running about
		 * of this window.
		 */
		XSizeHints sizeHint;

		/**
		 * The only instance of app in
		 * all execution of program.
		 */
		static inline Client app = Client();

		Point2D<> GetCenteredPosition() const noexcept;

	public:

		Application(int argc, char** argv);

		virtual ~Application();

		// Methods

		int MainLoop();

		void Resize(const std::uint32_t _width, const std::uint32_t _height) noexcept;

		void ResizeAndCenter(const std::uint32_t _width, const std::uint32_t _height) noexcept;

		// Static Methods

		/**
		 * @return Get the only instance with
		 * information of X Server.
		 */
		static const Client& GetClient();

		// Setters

		/**
		 * @param _title Text string that describe the name of window.
		 */
		void SetTitleWindow(std::string_view _title) const noexcept;
	};
}


#endif //DOLLY_APPLICATION_HPP
