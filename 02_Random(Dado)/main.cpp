#include <iostream>
#include <random>

int main() {
    // Crear una instancia de std::mt19937 y sembrarla con el tiempo actual
    std::mt19937 mt_rand(std::time(0));

    // Generar un número entre 1 y 6 (como lanzar un dado)
    std::uniform_int_distribution<int> dice_distribution(1, 6);
    int dice_roll = dice_distribution(mt_rand);
    std::cout << "Resultado del dado: " << dice_roll << std::endl;

    return 0;
}
