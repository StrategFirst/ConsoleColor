#include <iostream>

namespace console {
	class color {
		private:
			int _r,_g,_b;

		public:
			color(int r,int g, int b);
			friend std::ostream & operator<< (std::ostream & os,color c);

		public:
			int r() { return _r; }
			int g() { return _g; }
			int b() { return _b; }

	};

	const std::string reset = "\033[0m";

};
