#pragma once
#include <cmath>
#include <iostream>
/*
Template vector struct.
Operations: addition, subtraction, increment, decrement, multiplication with a scalar and division with a scalar, insertion.
Functions: dot product, square distance, distance, square norm, norm.
*/

namespace lameutil
{
	template<typename T>
	struct Vec2
	{
		union
		{
			T x;
			T a;
		};
		union
		{
			T y;
			T b;
		};

		Vec2() : x(0), y(0) {}
		Vec2(T x, T y = 0) : x(x), y(y) {}
		Vec2(const Vec2& aux) : x(aux.x), y(aux.y) {}

		Vec2 operator+(const T& in)
		{
			Vec2 aux = *this;
			aux.x += in;
			aux.y += in;

			return aux;
		}
		Vec2 operator+(const Vec2& in)
		{
			Vec2 aux = *this;
			aux.x += in.x;
			aux.y += in.y;

			return aux;
		}
		Vec2 operator-(const T& in)
		{
			Vec2 aux = *this;
			aux.x -= in;
			aux.y -= in;

			return aux;
		}
		Vec2 operator-(const Vec2& in)
		{
			Vec2 aux = *this;
			aux.x -= in.x;
			aux.y -= in.y;

			return aux;
		}

		Vec2& operator+=(const Vec2& in)
		{
			x += in.x;
			y += in.y;

			return *this;
		}
		Vec2& operator+=(const T& in)
		{
			x += in;
			y += in;

			return *this;
		}
		Vec2& operator-=(const Vec2& in)
		{
			x -= in.x;
			y -= in.y;

			return *this;
		}
		Vec2& operator-=(const T& in)
		{
			x -= in;
			y -= in;

			return *this;
		}

		Vec2 operator*(const T& in)
		{
			Vec2 aux = *this;
			aux.x *= in;
			aux.y *= in;

			return aux;
		}
		Vec2& operator*=(const T& in)
		{
			x *= in;
			y *= in;

			return *this;
		}
		Vec2 operator/(const T& in)
		{
			Vec2 aux = *this;
			aux.x /= in;
			aux.y /= in;

			return aux;
		}
		Vec2& operator/=(const T& in)
		{
			x /= in;
			y /= in;

			return *this;
		}

		template<typename TT>
		friend std::ostream& operator<<(std::ostream& os, const Vec2<TT>& in)
		{
			os << "x: " << in.x << ", y: " << in.y;
			return os;
		}
	};

	using Vec2i = Vec2<int>;
	using Vec2f = Vec2<float>;
	using Vec2d = Vec2<double>;

	template<typename T>
	inline T dot(const Vec2<T>& a, const Vec2<T>& b)
	{
		return a.x * b.x + a.y * b.y;
	}

	template<typename T>
	inline double sqrDistance(const Vec2<T>& a, const Vec2<T>& b)
	{
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	template<typename T>
	inline double distance(const Vec2<T>& a, const Vec2<T>& b)
	{
		return sqrt(sqrDistance(a, b));
	}

	template<typename T>
	inline double sqrNorm(const Vec2<T>& a)
	{
		return (a.x * a.x) + (a.y * a.y);
	}
	template<typename T>
	inline double norm(const Vec2<T>& a)
	{
		return sqrt(sqrNorm(a));
	}
}