#include <iostream>
#include "TutorialConfig.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello world!" << std::endl;

    if (argc < 2) {
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                    << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    return 0;
}