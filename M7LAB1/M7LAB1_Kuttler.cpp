#include <bits/stdc++.h>
using namespace std;

struct Cell {
    bool visited = false;
    bool walls[4] = {true, true, true, true}; // N, E, S, W
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

class SinisterMaze {
    int width, height;
    vector<vector<Cell>> grid;
    mt19937 rng;

public:
    SinisterMaze(int w, int h) : width(w), height(h), grid(h, vector<Cell>(w)) {
        rng.seed(random_device{}());
    }

    bool inBounds(int x, int y) {
        return x >= 0 && y >= 0 && x < width && y < height;
    }

    void removeWall(int x, int y, int dir) {
        grid[y][x].walls[dir] = false;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        grid[ny][nx].walls[(dir + 2) % 4] = false;
    }

    void generate(int x = 0, int y = 0) {
        grid[y][x].visited = true;

        vector<int> dirs = {0, 1, 2, 3};

        // Bias direction: prefer continuing same direction (sinister long paths)
        shuffle(dirs.begin(), dirs.end(), rng);

        for (int dir : dirs) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (inBounds(nx, ny) && !grid[ny][nx].visited) {
                removeWall(x, y, dir);
                generate(nx, ny);

                // Occasionally create a "trap branch"
                if (uniform_int_distribution<>(0, 100)(rng) < 15) {
                    createTrap(nx, ny);
                }
            }
        }

        // Occasionally punch loops (makes maze deceptive)
        if (uniform_int_distribution<>(0, 100)(rng) < 20) {
            addLoop(x, y);
        }
    }

    void createTrap(int x, int y) {
        vector<int> dirs = {0, 1, 2, 3};
        shuffle(dirs.begin(), dirs.end(), rng);

        for (int dir : dirs) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (inBounds(nx, ny) && grid[ny][nx].visited && grid[y][x].walls[dir]) {
                removeWall(x, y, dir);
                return;
            }
        }
    }

    void addLoop(int x, int y) {
        vector<int> dirs = {0, 1, 2, 3};
        shuffle(dirs.begin(), dirs.end(), rng);

        for (int dir : dirs) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (inBounds(nx, ny) && grid[ny][nx].visited && grid[y][x].walls[dir]) {
                removeWall(x, y, dir);
                return;
            }
        }
    }

    void print() {
        // Top border
        for (int i = 0; i < width; i++) cout << " _";
        cout << "\n";

        for (int y = 0; y < height; y++) {
            cout << "|";
            for (int x = 0; x < width; x++) {
                cout << (grid[y][x].walls[2] ? "_" : " ");
                cout << (grid[y][x].walls[1] ? "|" : " ");
            }
            cout << "\n";
        }
    }
};

int main() {
    int w = 20, h = 10;
    SinisterMaze maze(w, h);

    maze.generate();
    maze.print();

    return 0;
}