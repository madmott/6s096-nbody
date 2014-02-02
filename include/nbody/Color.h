#ifndef _NBODY_COLOR_H
#define _NBODY_COLOR_H


#include <cstdlib>

namespace nbody{
    
	//Color class will RGBA values in floats ranging from 0.0 to 1.0
	class Color {
		//RGBA values for the color
		float _r, _g, _b, _a;
        
	public:
		//Generate random floats for default constructor
		Color() : _r{ static_cast <float> (rand()) / static_cast <float> (RAND_MAX) }, _g{ static_cast <float> (rand()) / static_cast <float> (RAND_MAX) }, _b{ static_cast <float> (rand()) / static_cast <float> (RAND_MAX) }, _a{} {}
		Color(float r_, float g_, float b_, float a_) : _r{ r_ }, _g{ g_ }, _b{ b_ }, _a{ a_ } {}
        
		//Getters and setters
		inline float r() const { return _r; };
		inline float& r() { return _r; };
		inline float g() const { return _g; };
		inline float& g() { return _g; };
		inline float b() const { return _b; };
		inline float& b() { return _b; };
		inline float a() const { return _a; };
		inline float& a() { return _a; };
	};
    
} //namespace nbody

#endif //_NBODY_COLOR_H