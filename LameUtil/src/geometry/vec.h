#pragma once
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <utility>
//#define LAME_VEC_DISABLE_ANON_STRUCT 1

namespace lameutil
{
	template <size_t DIM, typename T>
	struct vec
	{
		vec()
		{
			for (size_t i = DIM; i--; m_data[i] = T());
		}
		vec(const std::initializer_list<T>& l)
		{
			assert(l.size() <= DIM);
			size_t j = 0;
			for (auto i = l.begin(); i != l.end(); m_data[j++] = *(i++));
			for (j; j < DIM; j++)
			{
				m_data[j] = T();
			}
		}
		T& operator[](const size_t i) { assert(i < DIM); return m_data[i]; }
		const T& operator[](const size_t i) const { assert(i < DIM); return m_data[i]; }

		double sqrnorm() const
		{
			T sum = T();
			for (size_t i = DIM; i--; sum += m_data[i] * m_data[i]);
			return sum;
		}
		double norm() const
		{
			return std::sqrt(sqrnorm());
		}
		inline vec<DIM, T>& normalize() { *this = (*this) * (1 / norm()); return *this; }
	private:
		T m_data[DIM];
	};

	typedef vec<2, double> Vec2d;
	typedef vec<2, float > Vec2f;
	typedef vec<2, int   > Vec2i;
	typedef vec<3, double> Vec3d;
	typedef vec<3, float > Vec3f;
	typedef vec<3, int   > Vec3i;
	typedef vec<4, double> Vec4d;
	typedef vec<4, float > Vec4f;
	typedef vec<4, int   > Vec4i;

	template <typename T>
	struct vec<2, T>
	{
		vec() : x(T()), y(T()) {}
		vec(T X, T Y) : x(X), y(Y) {}
		T& operator[](const size_t i) { assert(i < 2); return i <= 0 ? x : y; }
		const T& operator[](const size_t i) const { assert(i < 2); return i <= 0 ? x : y; }
		double norm() const { return std::sqrt(sqrnorm()); }
		inline double sqrnorm() const { return x * x + y * y; }
		inline vec<2, T>& normalize() { *this = (*this) * (1 / norm()); return *this;}

#if LAME_VEC_DISABLE_ANON_STRUCT
		T x, y;
#else
		union
		{
			struct { T x, y; };
			struct { T a, b; };
			struct { T s, t; };
		};
#endif
	};

	template <typename T>
	struct vec<3, T>
	{
		vec() : x(T()), y(T()), z(T()) {}
		vec(T X, T Y, T Z) : x(X), y(Y), z(Z) {}
		T& operator[](const size_t i) { assert(i < 3); return i <= 0 ? x : (1 == i ? y : z); }
		const T& operator[](const size_t i) const { assert(i < 3); return i <= 0 ? x : (1 == i ? y : z); }
		inline double norm() const {return std::sqrt(sqrnorm());}
		inline double sqrnorm() const { return x * x + y * y + z * z; }
		inline vec<3, T>& normalize() { *this = (*this) * (1 / norm()); return *this; }
#if LAME_VEC_DISABLE_ANON_STRUCT
		T x, y, z;
#else
		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T s, t, p; };
		};
#endif
	};

	template <typename T>
	struct vec<4, T>
	{
		vec() : x(T()), y(T()), z(T()), w(T()) {}
		vec(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}
		T& operator[](const size_t i) { assert(i < 4); return i <= 0 ? x : (1 == i ? y : (2 == i ? z : w)); }
		const T& operator[](const size_t i) const { assert(i < 4); return i <= 0 ? x : (1 == i ? y : (2 == i ? z : w)); }
		double norm() const { return std::sqrt(sqrnorm()); }
		inline double sqrnorm() const { return x * x + y * y + z * z + w*w; }
		inline vec<4, T>& normalize() { *this = (*this) * (1 / norm()); return *this; }
#if LAME_VEC_DISABLE_ANON_STRUCT
		T x, y, z, w;
#else
		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T s, t, p, q; };
		};
#endif
	};

	template<size_t DIM, typename T>
	T operator*(const vec<DIM, T>& lhs, const vec<DIM, T>& rhs)
	{
		T ret = T();
		for (size_t i = DIM; i--; ret += lhs[i] * rhs[i]);
		return ret;
	}

	template<size_t DIM, typename T>
	vec<DIM, T> operator+(vec<DIM, T> lhs, const vec<DIM, T>& rhs)
	{
		for (size_t i = DIM; i--; lhs[i] += rhs[i]);
		return lhs;
	}

	template<size_t DIM, typename T>
	vec<DIM, T>& operator+=(vec<DIM, T>& lhs, const vec<DIM, T>& rhs)
	{
		for (size_t i = DIM; i--; lhs[i] += rhs[i]);
		return lhs;
	}

	template<size_t DIM, typename T>
	vec<DIM, T> operator-(vec<DIM, T> lhs, const vec<DIM, T>& rhs)
	{
		for (size_t i = DIM; i--; lhs[i] -= rhs[i]);
		return lhs;
	}

	template<size_t DIM, typename T>
	vec<DIM, T>& operator-=(vec<DIM, T>& lhs, const vec<DIM, T>& rhs)
	{
		for (size_t i = DIM; i--; lhs[i] -= rhs[i]);
		return lhs;
	}

	template<size_t DIM, typename T, typename U>
	vec<DIM, T> operator*(const vec<DIM, T>& v, const U& scalar)
	{
		vec<DIM, T> ret;
		for (size_t i = DIM; i--; ret[i] = v[i] * (T)scalar);
		return ret;
	}

	template<size_t DIM, typename T, typename U>
	vec<DIM, T> operator*(const U& scalar, const vec<DIM, T>& v)
	{
		vec<DIM, T> ret;
		for (size_t i = DIM; i--; ret[i] = v[i] * (T)scalar);
		return ret;
	}

	template<size_t DIM, typename T, typename U>
	vec<DIM, T> operator*=(vec<DIM, T>& v, const U& scalar)
	{
		for (size_t i = DIM; i--; v[i] *= scalar);
		return v;
	}

	template<size_t DIM, typename T, typename U>
	vec<DIM, T> operator/(const vec<DIM, T>& v, const U& scalar)
	{
		vec<DIM, T> ret;
		for (size_t i = DIM; i--; ret[i] = v[i] / scalar);
		return ret;
	}

	template<size_t DIM, typename T, typename U>
	vec<DIM, T> operator/(const U& scalar, const vec<DIM, T>& v)
	{
		vec<DIM, T> ret;
		for (size_t i = DIM; i--; ret[i] = v[i] / scalar);
		return ret;
	}

	template<size_t DIM, typename T, typename U>
	vec<DIM, T> operator/=(vec<DIM, T>& v, const U& scalar)
	{
		for (size_t i = DIM; i--; v[i] /= scalar);
		return v;
	}

	template<size_t DIM, typename T>
	vec<DIM, T> operator-(const vec<DIM, T>& v)
	{
		return v * T(-1);
	}

	template <size_t DIM, typename T>
	bool operator==(const vec<DIM, T>& v, const vec<DIM, T>& u)
	{
	    bool ret = true;
	    for (size_t i = DIM; i--; ret &= (v[i] == u[i]));
	    return ret;
	}

	template <size_t DIM, typename T>
	bool operator!=(const vec<DIM, T>& v, const vec<DIM, T>& u)
	{
	    return !(v==u);
	}

	template <typename T> 
	vec<3, T> cross(const vec<3, T>& v1, const vec<3, T>& v2)
	{
		return vec<3, T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}

	template <size_t DIM, typename T>
	std::ostream& operator<<(std::ostream& out, const vec<DIM, T>& v)
	{
		for (unsigned int i = 0; i < DIM; i++) out << v[i] << " ";
		return out;
	}

	template<size_t DIM, typename T>
	double sqrdistance(const vec<DIM, T>& lhs, const vec<DIM, T>& rhs)
	{
		double sum = 0;
		for (size_t i = DIM; i--; sum += (double)(lhs[i] - rhs[i]) * (lhs[i] - rhs[i]));
		return sum;
	}

	template<size_t DIM, typename T>
	double distance(const vec<DIM, T>& lhs, const vec<DIM, T>& rhs)
	{
		return std::sqrt(sqrdistance(lhs, rhs));
	}

	//determinant for 3x3 matrices - TODO ADD TO MATRIX HEADER
	template <typename T>
	double determinant(const vec<3, T>& v1, const vec<3, T>& v2, const vec<3, T>& v3)
	{
		return (v1.x * (v2.y * v3.z - v2.z * v3.y) - v2.x * (v1.y * v3.z - v1.z * v3.y) + v3.x * (v1.y * v2.z - v1.z * v2.y));
	}
};