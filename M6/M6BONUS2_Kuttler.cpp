/* CSC 134
Kuttlerj6796
M6BONUS2 - PPM IMAGE
4/22/26
PROMPT: Hey Gemini, can you write a C++ script that creates a PPM image of Tung Tung Tung Sahur?
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

struct Color {
    int r, g, b;
};

int main() {
    const int width = 800;
    const int height = 600;

    std::ofstream outFile("sahur_scene.ppm");

    // PPM Header: P3 means ASCII color, then width, height, and max color value
    outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Color pixel = {0, 0, 0};

            // 1. Create a Dark Blue Gradient Background
            float gradient = (float)y / height;
            pixel.r = 10 * (1 - gradient);
            pixel.g = 10 * (1 - gradient);
            pixel.b = 40 * (1 - gradient) + 20;

            // 2. Draw a Crescent Moon (Two overlapping circles)
            // Main Moon Circle
            float centerX = 150.0f, centerY = 120.0f, radius = 60.0f;
            float dist = std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2));
            
            // "Cutter" Circle (to create the crescent shape)
            float cutX = 175.0f, cutY = 110.0f, cutRadius = 60.0f;
            float cutDist = std::sqrt(std::pow(x - cutX, 2) + std::pow(y - cutY, 2));

            if (dist < radius && cutDist > cutRadius) {
                pixel = {255, 240, 150}; // Warm Yellow
            }

            // 3. Add some "Stars" (Random-ish noise)
            if ((x * y + x) % 997 == 0 && pixel.r < 50) {
                pixel = {255, 255, 255};
            }

            // Write the pixel to the file
            outFile << pixel.r << " " << pixel.g << " " << pixel.b << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    std::cout << "Image generated: sahur_scene.ppm" << std::endl;

    return 0;
}