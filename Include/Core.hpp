#ifndef DOLLY_CORE_HPP
#define DOLLY_CORE_HPP


namespace Dolly
{
	class Core
	{

	protected:

		/**
		 * Coordinate in x of window.
		 */
		int x = 0;

		/**
		 * Coordinate in y of window.
		 */
		int y = 0;

		unsigned int depth = 0;

		/**
		 * Width of window in pixels.
		 */
		unsigned int width = 300;

		/**
		 * Height of window in pixels.
		 */
		unsigned int height = 300;

		unsigned int borderWidth = 0;

	public:

		// Getters

		[[nodiscard]] int GetX() const;

		[[nodiscard]] int GetY() const;

		[[nodiscard]] unsigned int GetWidth() const;

		[[nodiscard]] unsigned int GetHeight() const;

		// Setters

		void SetX(int _x);

		void SetY(int _y);

		void SetWidth(unsigned int _width);

		void SetHeight(unsigned int _height);

	};
}


#endif //DOLLY_CORE_HPP
