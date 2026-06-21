#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Utils.hpp"

int main(int argc, char** argv) {
    Utils::modoTeste = true;
    
    doctest::Context context(argc, argv);
    return context.run();
}