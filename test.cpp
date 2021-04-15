#include "consolecolor.hh"
#include <iostream>

int main() {
	std::cout << "\u0010 " << "Color testing : " << std::endl;
	std::cout << console::color(255,0,0) << "This must be red!" << console::reset << std::endl;
	std::cout << console::color(0,255,0) << "This must be green!" << console::reset << std::endl;
	std::cout << console::color(0,0,255) << "This must be blue!" << console::reset << std::endl;
	std::cout << console::color(0,255,255) << "This must be cyan!" << console::reset << std::endl;
	std::cout << console::color(255,0,255) << "This must be purple!" << console::reset << std::endl;
	std::cout << console::color(255,255,0) << "This must be yellow!" << console::reset << std::endl;
	std::cout << console::color(255,255,255) << "This must be white!" << console::reset << std::endl;
	std::cout << console::color(75,75,75) << "This must be a dark gray!" << console::reset << std::endl;
	std::cout << std::endl;

	std::cout << "\u0010 " << "Security testing : " << std::endl;
	try {
		std::cout << console::color(42,666,69) << " /!\\ " << "This text shouldn't be displayed ! " << console::reset << std::endl;
	} catch( std::range_error & e ) {
		std::cout << console::color(42,255,69) << " [V] " << "Test passed " << console::reset << std::endl;
	}
	try {
		std::cout << console::color(128,100,580,console::mode::HSL) << " /!\\ " << "This text shouldn't be displayed ! " << console::reset << std::endl;
	} catch( std::range_error & e ) {
		std::cout << console::color(128,100,58,console::mode::HSL) << " [V] " << "Test passed " << console::reset << std::endl;
	}
	try {
		std::cout << console::color(128,984,100,console::mode::HSV) << " /!\\ " << "This text shouldn't be displayed ! " << console::reset << std::endl;
	} catch( std::range_error & e ) {
		std::cout << console::color(128,84,100,console::mode::HSV) << " [V] " << "Test passed " << console::reset << std::endl;
	}
	std::cout << std::endl;


	return EXIT_SUCCESS;
}
