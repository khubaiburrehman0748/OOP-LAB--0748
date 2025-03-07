#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Level {
public:
    string name;
    int difficulty;

    Level(string name, int difficulty) {
        this->name = name;
        this->difficulty = difficulty;
    }
};

class VideoGame {
public:
    string title;
    string genre;
    vector<Level*> levels;

    VideoGame(string title, string genre) {
        this->title = title;
        this->genre = genre;
    }

    void addLevel(Level* level) {
        levels.push_back(level);
    }

    void display() {
        cout << "Game: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Levels:" << endl;
        for (int i = 0; i < levels.size(); i++) {
            cout << " - " << levels[i]->name << " (Difficulty: " << levels[i]->difficulty << ")" << endl;
        }
        cout << "-------------------------" << endl;
    }

    ~VideoGame() {
        for (int i = 0; i < levels.size(); i++) {
            delete levels[i];
        }
    }
};

int main() {
    VideoGame game("Quest Game", "RPG");
    game.addLevel(new Level("Forest", 3));
    game.addLevel(new Level("Cave", 5));
    game.addLevel(new Level("Castle", 7));

    game.display();

    return 0;
}