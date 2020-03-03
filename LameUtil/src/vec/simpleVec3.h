#pragma once
#include <cmath>
/*
Template vector struct.
Operations: addition, subtraction, increment, decrement, multiplication with a scalar and division with a scalar.
Functions: static square distance, static distance.
*/

namespace lameutil
{
	template<typename T>
	struct Vec3
	{
		union
		{
			T x;
			T r;
		};
		union
		{
			T y;
			T g;
		};
		union
		{
			T z;
			T b;
		};

		Vec3() : x(0), y(0), z(0) {}
		Vec3(T x, T y = 0, T z = 0) : x(x), y(y), z(z) {}
		Vec3(const Vec3& aux) : x(aux.x), y(aux.y), z(aux.z) {}

		Vec3 operator+(const T& in)
		{
			Vec3 aux = *this;
			aux.x += in;
			aux.y += in;
			aux.z += in;

			return aux;
		}
		Vec3 operator+(const Vec3& in)
		{
			Vec3 aux = *this;
			aux.x += in.x;
			aux.y += in.y;
			aux.z += in.z;

			return aux;
		}
		Vec3 operator-(const T& in)
		{
			Vec3 aux = *this;
			aux.x -= in;
			aux.y -= in;
			aux.z -= in;

			return aux;
		}
		Vec3 operator-(const Vec3& in)
		{
			Vec3 aux = *this;
			aux.x -= in.x;
			aux.y -= in.y;
			aux.z -= in.z;

			return aux;
		}

		Vec3& operator+=(const Vec3& in)
		{
			x += in.x;
			y += in.y;
			z += in.z;

			return *this;
		}
		Vec3& operator+=(const T& in)
		{
			x += in;
			y += in;
			z += in;

			return *this;
		}
		Vec3& operator++()
		{
			x++;
			y++;
			z++;

			return *this;
		}
		Vec3 operator++(int)
		{
			Vec3 aux = *this;
			x++;
			y++;
			z++;

			return aux;
		}
		Vec3& operator-=(const Vec3& in)
		{
			x -= in.x;
			y -= in.y;
			z -= in.z;

			return *this;
		}
		Vec3& operator-=(const T& in)
		{
			x -= in;
			y -= in;
			z -= in;

			return *this;
		}
		Vec3& operator--()
		{
			x--;
			y--;
			z--;

			return *this;
		}
		Vec3 operator--(int)
		{
			Vec3 aux = *this;
			x--;
			y--;
			z--;

			return aux;
		}

		Vec3 operator*(const T& in)
		{
			Vec3 aux = *this;
			aux.x *= in;
			aux.y *= in;
			aux.z *= in;

			return aux;
		}
		Vec3& operator*=(const T& in)
		{
			x *= in;
			y *= in;
			z *= in;

			return *this;
		}
		Vec3 operator/(const T& in)
		{
			Vec3 aux = *this;
			aux.x /= in;
			aux.y /= in;
			aux.z /= in;

			return aux;
		}
		Vec3& operator/=(const T& in)
		{
			x /= in;
			y /= in;
			z /= in;

			return *this;
		}

		static inline double sqrDistance(const Vec3& a, const Vec3& b)
		{
			return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z);
		}
		static inline double distance(const Vec3& a, const Vec3& b)
		{
			return sqrt(sqrDistance(a, b));
		}

		static inline double sqrNorm(const Vec3& a)
		{
			return (a.x*a.x) + (a.y*a.y) + (a.z+a.z);
		}
		static inline double norm(const Vec3& a)
		{
			return sqrt(sqrNorm(a));
		}
	};

	using Vec3i = Vec3<int>;
	using Vec3f = Vec3<float>;
	using Vec3d = Vec3<double>;
}