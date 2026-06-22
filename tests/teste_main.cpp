#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Utils.hpp"
#include "Engine.hpp"

int main(int argc, char** argv) {
    Utils::modoTeste = true;
    Engine::modoTeste = true;
    
    doctest::Context context(argc, argv);
    return context.run();
}