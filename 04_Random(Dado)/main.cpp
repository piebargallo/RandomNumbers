#include <iostream>
#include <random>

int main() {
    // Crear una instancia de std::mt19937 y sembrarla con el tiempo actual
    std::mt19937 mt_rand(std::time(0));

    // Crear una distribución uniforme de enteros en el rango [1, 6] (como lanzar un dado)
    std::uniform_int_distribution<int> dice_distribution(1, 6);

    // Generar y mostrar varios resultados de lanzamiento de dados
    for (int i = 0; i < 5; ++i) {
        int dice_roll = dice_distribution(mt_rand);
        std::cout << "Resultado del dado: " << dice_roll << std::endl;
    }

    return 0;
}
