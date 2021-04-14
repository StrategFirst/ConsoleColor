#include "consolecolor.hh"

namespace console {

	//color
	color::color(color_component_t r,color_component_t g,color_component_t b):_r(r),_g(g),_b(b) {
		if(	r>255 || g>255 || b>255 )	throw std::range_error("RGB value must be within the interval 0 to 255");
	}

	std::ostream & operator<< (std::ostream & os,color c) {
		os << "\u001b[38;2;" << c.r() << ";"<< c.g() << ";" << c.b() << "m";
		return os;
	}


};
