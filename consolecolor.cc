#include "consolecolor.hh"

namespace console {

	//color
	color::color(int r,int g, int b):_r(r),_g(g),_b(b) {}
	std::ostream & operator<< (std::ostream & os,color c) {
		os << "\u001b[38;2;" << c.r() << ";"<< c.g() << ";" << c.b() << "m";
		return os;
	}


};
