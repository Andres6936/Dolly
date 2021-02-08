// Joan Andrés (@Andres6936) Github.

#ifndef DOLLY_COLOR_HPP
#define DOLLY_COLOR_HPP

#include <cstdint>

namespace Dolly
{

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

		void SetRed(const uint32_t r) noexcept;

		void SetGreen(const uint32_t g) noexcept;

		void SetBlue(const uint32_t b) noexcept;

		void SetAlpha(const uint32_t a) noexcept;

		// Getters

		std::uint8_t GetRed() const noexcept;

		std::uint8_t GetGreen() const noexcept;

		std::uint8_t GetBlue() const noexcept;

		std::uint8_t GetAlpha() const noexcept;

	};

}

#endif //DOLLY_COLOR_HPP
