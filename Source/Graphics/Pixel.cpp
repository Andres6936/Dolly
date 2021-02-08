// Joan Andrés (@Andres6936) Github.

#include "Graphics/Pixel.hpp"

using namespace Dolly;

Pixel::Pixel(const std::uint32_t r, const std::uint32_t g, const std::uint32_t b) : Pixel(r, g, b,
		255)
{

}

Pixel::Pixel(const std::uint32_t r, const std::uint32_t g, const std::uint32_t b,
		const std::uint32_t a)
{
	value += r << 24;
	value += g << 16;
	value += b << 8;
	value += a << 0;
}

void Pixel::SetRed(uint32_t r) noexcept
{
	// Remember, the component red is
	// localize in the side left,
	// The schema is - R G B A -
	// In the parameter r the schema
	// is - 0 0 0 R -
	// Need move R to left (aka: - R 0 0 0 -)
	// Each position (of 4 possibles)
	// in the schema have a size of 8.
	// As we need move 3 position the total
	// of bits to move is of
	// 24 = 8 bits * 3 positions
	r <<= 24;
	// Clear the old value of component
	// in r for that we can store a new
	// value of component r.
	// The schema is actual is - G B A 0 -
	value <<= 8;
	// However, with the above operation
	// the schema is unordered, we have
	// order tha schema.
	// It will be like that again
	// as - 0 G B A -
	value >>= 8;
	// The operator "bitwise XOR (exclusive
	// OR)" allow interchange the values of
	// component r without affect the
	// another components ( G B and A).
	// See:
	// - 0 G B A - The schema of value
	// - R 0 0 0 - The schema of parameter r
	// Apply the operation xor the result is:
	// - R G B A -
	value ^= r;
}

void Pixel::SetGreen(uint32_t g) noexcept
{
	// Schema r is : - R 0 0 0 -
	std::uint32_t r = GetRed() << 24;
	// Schema value: - B A 0 0 -
	value <<= 16;
	// Schema value: - 0 0 B A -
	value >>= 16;
	// Schema parameter g is : - 0 G 0 0 -
	g <<= 16;

	// - 0 0 B A - Schema value
	// - 0 G 0 0 - Schema parameter g
	// Result of operation
	// - 0 G B A -
	value ^= g;

	// - 0 G B A - Schema value
	// - R G B A - Schema r
	// Result of operation
	// - R G B A -
	value ^= r;
}

void Pixel::SetBlue(uint32_t b) noexcept
{
	std::uint32_t a = GetAlpha();
	value >>= 16;
	value <<= 16;
	b <<= 8;
	value ^= b;
	value ^= a;
}

void Pixel::SetAlpha(uint32_t a) noexcept
{
	// The schema of parameter a is perfect
	// that is: - 0 0 0 A -
	// So that not is needed make operations
	// with the parameter

	// Clear the old value of alpha (aka: a)
	value >>= 8;
	// Sort the schema to - R G B 0 -
	value <<= 8;

	// The operator "bitwise XOR (exclusive
	// OR)" allow interchange the values of
	// component a without affect the
	// another components ( R G and B).
	// See:
	// - R G B 0 - The schema of value
	// - 0 0 0 A - The schema of parameter a
	// Apply the operation xor the result is:
	// - R G B A -
	value ^= a;
}

std::uint8_t Pixel::GetRed() const noexcept
{
	return static_cast<std::uint8_t>(value >> 24);
}

std::uint8_t Pixel::GetGreen() const noexcept
{
	return static_cast<std::uint8_t>(value >> 16);
}

std::uint8_t Pixel::GetBlue() const noexcept
{
	return static_cast<std::uint8_t>(value >> 8);
}

std::uint8_t Pixel::GetAlpha() const noexcept
{
	return static_cast<std::uint8_t>(value >> 0);
}
