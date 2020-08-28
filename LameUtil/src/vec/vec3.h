#pragma once
#include <cmath>
/*
Template vector struct.
Operations: addition, subtraction, increment, decrement, multiplication with a scalar and division with a scalar, insertion.
Functions: dot product, cross product, square distance, distance, square norm, norm.
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


		template<typename TT>
		friend std::ostream& operator<<(std::ostream& os, const Vec3<TT>& in)
		{
			os << "x: " << in.x << ", y: " << in.y << ", z: " << in.z;
			return os;
		}
	};

	using Vec3i = Vec3<int>;
	using Vec3f = Vec3<float>;
	using Vec3d = Vec3<double>;

	template<typename T>
	inline T dot(const Vec3<T>& a, const Vec3<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	template<typename T>
	inline Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b)
	{

		return {
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	template<typename T>
	inline double sqrDistance(const Vec3<T>& a, const Vec3<T>& b)
	{
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
	}
	template<typename T>
	inline double distance(const Vec3<T>& a, const Vec3<T>& b)
	{
		return sqrt(sqrDistance(a, b));
	}

	template<typename T>
	inline double sqrNorm(const Vec3<T>& a)
	{
		return (a.x * a.x) + (a.y * a.y) + (a.z + a.z);
	}
	template<typename T>
	inline double norm(const Vec3<T>& a)
	{
		return sqrt(sqrNorm(a));
	}
}