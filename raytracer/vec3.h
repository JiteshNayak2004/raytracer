// pragma once is used so that when we use this header in multiple places
// this header is defined only once and not multiple times


#pragma once

#include <cmath>
#include <iostream>

class vec3 {
	public:
	double coordinates[3];
	
	//default constructor 
	vec3 () : coordinates{0,0,0} {}

	//parameterized constructor 
	vec3(double x,double y,double z): coordinates{x,y,z} {}


	//accessor methods
	double x() const { return coordinates[0]; }
	double y() const { return coordinates[1]; }
	double z() const { return coordinates[2]; }

	//operator overloading 
	//allows you to perform operations on objects of this class
	

	//negation operator
	vec3 operator-() const { return vec3(-coordinates[0],-coordinates[1],-coordinates[2]);   }

	//indexing operator when object is const
	double operator[](int index) const { return coordinates[index]; }
	//indexing operator when object is non const
	double& operator[](int index) {return coordinates[index]; }


	// Compound assignment operators
	vec3& operator+=(const vec3& other) {
		coordinates[0] += other.coordinates[0];
		coordinates[1] += other.coordinates[1];
		coordinates[2] += other.coordinates[2];
		return *this;
	}

	vec3& operator*=(double scalar) {
		coordinates[0] *= scalar;
		coordinates[1] *= scalar;
		coordinates[2] *= scalar;
		return *this;
	}

	vec3& operator/=(double scalar) {
		return *this *= 1 / scalar;
	}
	// Length (magnitude) of the vector
	double length() const {
		return std::sqrt(lengthSquared());
	}

	// Squared length of the vector (more efficient for comparisons)
	double lengthSquared() const {
		return coordinates[0] * coordinates[0] + coordinates[1] * coordinates[1] + coordinates[2] * coordinates[2];
	}


};

// Aliases for geometric clarity
using point = vec3;
using color = vec3;

// Vector utility functions

// Output stream operator
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.coordinates[0] << ' ' << v.coordinates[1] << ' ' << v.coordinates[2];
}

// Vector addition
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.coordinates[0] + v.coordinates[0], u.coordinates[1] + v.coordinates[1], u.coordinates[2] + v.coordinates[2]);
}

// Vector subtraction
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.coordinates[0] - v.coordinates[0], u.coordinates[1] - v.coordinates[1], u.coordinates[2] - v.coordinates[2]);
}

// Component-wise multiplication
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.coordinates[0] * v.coordinates[0], u.coordinates[1] * v.coordinates[1], u.coordinates[2] * v.coordinates[2]);
}

// Scalar multiplication
inline vec3 operator*(double scalar, const vec3& v) {
    return vec3(scalar * v.coordinates[0], scalar * v.coordinates[1], scalar * v.coordinates[2]);
}

inline vec3 operator*(const vec3& v, double scalar) {
    return scalar * v;
}

// Scalar division
inline vec3 operator/(const vec3& v, double scalar) {
    return (1 / scalar) * v;
}

// Dot product of two vectors
inline double dot(const vec3& u, const vec3& v) {
    return u.coordinates[0] * v.coordinates[0]
         + u.coordinates[1] * v.coordinates[1]
         + u.coordinates[2] * v.coordinates[2];
}

// Cross product of two vectors
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(
        u.coordinates[1] * v.coordinates[2] - u.coordinates[2] * v.coordinates[1],
        u.coordinates[2] * v.coordinates[0] - u.coordinates[0] * v.coordinates[2],
        u.coordinates[0] * v.coordinates[1] - u.coordinates[1] * v.coordinates[0]
    );
}

// Unit vector (vector of length 1) in the same direction as v
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}




