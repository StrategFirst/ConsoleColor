#include "consolecolor.hh"

namespace console {
	//color
	float color::math_mod(float a,float b) {
		if(a<0) { return math_mod(-a,b); }
		if(a<b) { return a; }
		return math_mod(a-b,b);
	}
	color::RGB color::HSL_to_RGB(color_component_t H, color_component_t S, color_component_t L) {
		//make it float, avoiding integer division problem
		float h = H;
		float s = S;
		float l = L;

		//scale down value to : H ∈ [0;360[ , S ∈ [0;1] , L ∈ [0,1], to simplify later operations
		while(h >= 360) { h-= 360; }
		while(h < 0) { h+=360; }
		s /= 100;
		l /= 100;

		//intermediate operations
		float C = (1 - abs( (2*l) - 1 ) ) * (s);
		float X = (C * (1 - abs( (math_mod(h / 60,2)) - 1)));
		float m = (l - C/2);
		float r,g,b;

		if( h < 60 ) { r=C;g=X;b=0; }
		else if( h < 120 ) { r=X;g=C;b=0; }
		else if( h < 180 ) { r=0;g=C;b=X; }
		else if( h < 240 ) { r=0;g=X;b=C; }
		else if( h < 300 ) { r=X;g=0;b=C; }
		else if( h < 360 ) { r=C;g=0;b=X; }

		//Final result
		return {
			static_cast<color_component_t>((r+m)*255),
			static_cast<color_component_t>((g+m)*255),
			static_cast<color_component_t>((b+m)*255)
		};
	}
	color::RGB color::HSV_to_RGB(color_component_t H, color_component_t S, color_component_t V) {
		//make it float, avoiding integer division problem
		float h = H;
		float s = S;
		float v = V;

		//scale down value to : H ∈ [0;360[ , S ∈ [0;1] , L ∈ [0,1], to simplify later operations
		while(h >= 360) { h-= 360; }
		while(h < 0) { h+=360; }
		s /= 100;
		v /= 100;

		//intermediate operations
		float C = v * s;
		float X = (C * (1 - abs( (math_mod(h / 60,2)) - 1)));
		float m = v - C;
		float r,g,b;

		if( h < 60 ) { r=C;g=X;b=0; }
		else if( h < 120 ) { r=X;g=C;b=0; }
		else if( h < 180 ) { r=0;g=C;b=X; }
		else if( h < 240 ) { r=0;g=X;b=C; }
		else if( h < 300 ) { r=X;g=0;b=C; }
		else if( h < 360 ) { r=C;g=0;b=X; }

		//Final result
		return {
			static_cast<color_component_t>((r+m)*255),
			static_cast<color_component_t>((g+m)*255),
			static_cast<color_component_t>((b+m)*255)
		};
	}

	color::color(color_component_t const r,color_component_t const g,color_component_t const b):_r(r),_g(g),_b(b) {
		if(	r>255 || g>255 || b>255 )	throw std::range_error("RGB value must be within the interval 0 to 255");
	}
	color::color(color_component_t const x,color_component_t const y,color_component_t const z,mode const m) {
		switch (m) {
			case mode::RGB:
			{
				if(	x>255 || y>255 || z>255 )
					throw std::range_error("RGB value must be within the interval 0 to 255");
				_r=x; _g=y; _b=z; break;
			}

			case mode::HSL:
			{
			  if( y>100 || z>100 )
			 		throw std::range_error("HSL value must be an angle followed by 2 pourcentage between 0 and 100");
				const RGB c = HSL_to_RGB(x,y,z);
				_r=c.r; _g=c.g; _b=c.b; break;
			}

			case mode::HSV:
			{
				if( y>100 || z>100 )
					throw std::range_error("HSV value must be an angle followed by 2 pourcentage between 0 and 100");
				const RGB c = HSV_to_RGB(x,y,z);
				_r=c.r; _g=c.g; _b=c.b; break;
			}
		}
	}

	std::ostream & operator<< (std::ostream & os,color c) {
		os << "\u001b[38;2;" << c.r() << ";"<< c.g() << ";" << c.b() << "m";
		return os;
	}


};
