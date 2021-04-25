#pragma once
#include <cmath>
/*
Template vector struct.
Operations: addition, subtraction, increment, decrement, multiplication with a scalar and division with a scalar, insertion.
Functions: dot product, square distance, distance, square norm, norm.
*/

namespace lameutil
{
	template<typename T>
	struct Vec4
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
		union
		{
			T w;
			T a;
		};

		Vec4() : x(0), y(0), z(0), w(0) {}
		Vec4(T x, T y = 0, T z = 0, T w = 0) : x(x), y(y), z(z), w(w) {}
		Vec4(const Vec4& aux) : x(aux.x), y(aux.y), z(aux.z), w(aux.w) {}

		Vec4 operator+(const T& in)
		{
			Vec4 aux = *this;
			aux.x += in;
			aux.y += in;
			aux.z += in;
			aux.w += in;

			return aux;
		}
		Vec4 operator+(const Vec4& in)
		{
			Vec4 aux = *this;
			aux.x += in.x;
			aux.y += in.y;
			aux.z += in.z;
			aux.w += in.w;

			return aux;
		}
		Vec4 operator-(const T& in)
		{
			Vec4 aux = *this;
			aux.x -= in;
			aux.y -= in;
			aux.z -= in;
			aux.w -= in;

			return aux;
		}
		Vec4 operator-(const Vec4& in)
		{
			Vec4 aux = *this;
			aux.x -= in.x;
			aux.y -= in.y;
			aux.z -= in.z;
			aux.w -= in.w;

			return aux;
		}


		Vec4& operator+=(const Vec4& in)
		{
			x += in.x;
			y += in.y;
			z += in.z;
			w += in.w;

			return *this;
		}
		Vec4& operator+=(const T& in)
		{
			x += in;
			y += in;
			z += in;
			w += in;

			return *this;
		}
		Vec4& operator-=(const Vec4& in)
		{
			x -= in.x;
			y -= in.y;
			z -= in.z;
			w -= in.w;

			return *this;
		}
		Vec4& operator-=(const T& in)
		{
			x -= in;
			y -= in;
			z -= in;
			w -= in;

			return *this;
		}
		Vec4 operator*(const T& in)
		{
			Vec4 aux = *this;
			aux.x *= in;
			aux.y *= in;
			aux.z *= in;
			aux.w *= in;

			return aux;
		}
		Vec4& operator*=(const T& in)
		{
			x *= in;
			y *= in;
			z *= in;
			w *= in;

			return *this;
		}
		Vec4& operator/(const T& in)
		{
			Vec4 aux = *this;
			aux.x /= in;
			aux.y /= in;
			aux.z /= in;
			aux.w /= in;

			return *this;
		}
		Vec4& operator/=(const T& in)
		{
			x /= in;
			y /= in;
			z /= in;
			w /= in;

			return *this;
		}

		template<typename TT>
		friend std::ostream& operator<<(std::ostream& os, const Vec4<TT>& in)
		{
			os << "x: " << in.x << ", y: " << in.y << ", z: " << in.z << ", w: " << in.w;
			return os;
		}
	};

	using Vec4i = Vec4<int>;
	using Vec4f = Vec4<float>;
	using Vec4d = Vec4<double>;

	template<typename T>
	inline T dot(const Vec4<T>& a, const Vec4<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	template<typename T>
	inline double sqrDistance(const Vec4<T>& a, const Vec4<T>& b)
	{
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) + (a.w - b.w) * (a.w - b.w);
	}
	template<typename T>
	inline double distance(const Vec4<T>& a, const Vec4<T>& b)
	{
		return sqrt(sqrDistance(a, b));
	}

	template<typename T>
	inline double sqrNorm(const Vec4<T>& a)
	{
		return (a.x * a.x) + (a.y * a.y) + (a.z + a.z) + (a.w + a.w);
	}
	template<typename T>
	inline double norm(const Vec4<T>& a)
	{
		return sqrt(sqrNorm(a));
	}
}