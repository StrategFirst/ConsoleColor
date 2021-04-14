#include "consolecolor.hh"

int main() {
	std::cout << console::color(30,80,200) << "TEST" << std::endl << console::reset ;
	return EXIT_SUCCESS;
}
