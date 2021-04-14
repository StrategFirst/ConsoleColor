#include <iostream>

namespace console {
	enum class mode { RGB , HSL , HSV };
	class color {
		private:
			using color_component_t = unsigned int;
		private: //class fields
			color_component_t _r,_g,_b;

		public: //constructors
			color(color_component_t r,color_component_t g,color_component_t b);
			~color() = default;
			color(const color & origin) = default;

		public: //operators
			friend std::ostream & operator<< (std::ostream & os,color c);

		public: //getters
			color_component_t r() { return _r; }
			color_component_t g() { return _g; }
			color_component_t b() { return _b; }

	};

	const std::string reset = "\033[0m";

};
