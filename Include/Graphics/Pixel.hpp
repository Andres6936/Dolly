// Joan Andrés (@Andres6936) Github.

#ifndef DOLLY_COLOR_HPP
#define DOLLY_COLOR_HPP

#include <cstdint>

namespace Dolly
{

	/**
	 * Each color is formed by mixing three basic colors: red, green and blue,
	 * using the RGB (Red-Green-Blue) system to specify colors. When identifying
	 * a particular color (e.g., deep white), it is defined as the sum of the
	 * three basic colors and the proportion of the mixture of these colors.
	 * This proportion is specified using one byte (range 0 to 255), so that
	 * the most intense pure white (mixture of all colors) would be the color
	 * (255,255,255), while black (absence of color) would be (0,0,0).
	 */
	class Pixel
	{

	private:

		/**
		 * The order of stored is:
		 * Red Green Blue Alpha
		 * each component have 8 bits
		 * in total 32 bits.
		 */
		std::uint32_t value = 0;

	public:

		Pixel(const std::uint32_t r, const std::uint32_t g, const std::uint32_t b);

		Pixel(const std::uint32_t r, const std::uint32_t g, const std::uint32_t b,
				const std::uint32_t a);

		// Setters

		void SetRed(uint32_t r) noexcept;

		void SetGreen(uint32_t g) noexcept;

		void SetBlue(uint32_t b) noexcept;

		void SetAlpha(uint32_t a) noexcept;

		// Getters

		std::uint8_t GetRed() const noexcept;

		std::uint8_t GetGreen() const noexcept;

		std::uint8_t GetBlue() const noexcept;

		std::uint8_t GetAlpha() const noexcept;

	};

}

#endif //DOLLY_COLOR_HPP
