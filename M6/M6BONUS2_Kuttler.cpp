/* 
CSC 134
Kuttlerj6796
M6BONUS2 - Image Generation (Tung Tung Tung Sahur)
4/22/26
PROMPT: Hey Gemini, can you write a C++ script that creates a PPM image of Tung Tung Tung Sahur?
PROMPT: that looks good, but why did you skip the big tung tung tung?
*/

#include <iostream>
#include <fstream>
#include <cmath>

struct Color {
    int r, g, b;
};

int main() {
    const int width = 800;
    const int height = 600;

    std::ofstream outFile("tung_tung_sahur.ppm");
    outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // 1. Background Gradient (Midnight Blue)
            float grad = (float)y / height;
            Color pixel = { (int)(15 * (1-grad)), (int)(15 * (1-grad)), (int)(40 * (1-grad) + 10) };

            // 2. The Moon (Crescent)
            float mDist = std::sqrt(std::pow(x - 120, 2) + std::pow(y - 100, 2));
            float cDist = std::sqrt(std::pow(x - 140, 2) + std::pow(y - 90, 2));
            if (mDist < 50 && cDist > 50) pixel = {255, 230, 150};

            // 3. The Kentongan (Wooden Slit Drum)
            // Main Body (Rectangle-ish)
            if (x > 350 && x < 450 && y > 250 && y < 500) {
                pixel = {101, 67, 33}; // Dark Wood Brown
                
                // The Slit (The hollow part that makes the sound)
                if (x > 390 && x < 410 && y > 300 && y < 450) {
                    pixel = {20, 10, 0}; // Deep Shadow
                }
                // Wood Grain/Highlight
                if (x > 355 && x < 365) pixel = {130, 90, 50}; 
            }

            // 4. The "Tung Tung Tung" Sound Waves
            // We'll draw three concentric arcs to represent sound
            for (int i = 1; i <= 3; ++i) {
                float ringRadius = 100.0f + (i * 40);
                float sDist = std::sqrt(std::pow(x - 400, 2) + std::pow(y - 375, 2));
                // Only draw arcs on the right side to show direction
                if (std::abs(sDist - ringRadius) < 3 && x > 460 && y > 250 && y < 500) {
                    pixel = {200, 200, 200}; // Light Grey/White waves
                }
            }

            // 5. Ground (Dark Silhouette)
            if (y > 500) {
                pixel = {5, 5, 10};
            }

            outFile << pixel.r << " " << pixel.g << " " << pixel.b << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    std::cout << "Image generated: tung_tung_sahur.ppm" << std::endl;
    return 0;
}