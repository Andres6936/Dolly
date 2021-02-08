// Joan Andrés (@Andres6936) Github.

#ifndef DOLLY_SIZE_HPP
#define DOLLY_SIZE_HPP

namespace Dolly
{

	class Size
	{

	public:

		/**
		 * Width
		 */
		int w = 0;

		/**
		 * Height
		 */
		int h = 0;

		Size() = default;

		/**
		 * @param _w Width
		 * @param _h Height
		 */
		Size(int _w, int _h) noexcept
		{
			w = _w;
			h = _h;
		}

		bool operator<(const Size& _rhs) const
		{
			if (w < _rhs.w) return true;

			if (_rhs.w < w) return false;

			return h < _rhs.h;
		}

		bool operator>(const Size& _rhs) const
		{
			return _rhs < *this;
		}

		bool operator<=(const Size& _rhs) const
		{
			return !(_rhs < *this);
		}

		bool operator>=(const Size& _rhs) const
		{
			return !(*this < _rhs);
		}
	};

}

#endif //DOLLY_SIZE_HPP
