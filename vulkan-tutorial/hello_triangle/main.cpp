#include "Renderer.h"

int main() {
    Earth newearth;

	try {
		newearth.run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
