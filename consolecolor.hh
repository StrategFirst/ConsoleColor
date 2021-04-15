#include <iostream> // std::ostream
#include <math.h> // abs

namespace console {
	enum class mode { RGB , HSL , HSV };
	class color {
		private: //custom types
			using color_component_t = unsigned int;
			struct RGB {
				color_component_t r;
				color_component_t g;
				color_component_t b;
			};
		private: //conversion methods
			RGB HSL_to_RGB(color_component_t H,color_component_t S,color_component_t L);

		private: //class fields
			color_component_t _r,_g,_b;

		public: //constructors
			color(color_component_t const r,color_component_t const g,color_component_t const b);
			color(color_component_t const x,color_component_t const y,color_component_t const z,mode const m);
			~color() = default;
			color(const color & origin) = default;

		public: //operators
			friend std::ostream & operator<< (std::ostream & os,color c);

		public: //getters
			color_component_t r() const { return _r; }
			color_component_t g() const { return _g; }
			color_component_t b() const { return _b; }

	};

	const std::string reset = "\033[0m";

};
