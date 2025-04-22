#include <iostream>
using namespace std;

class Character {
public:
    string characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

    Character(string id, string n, int lvl, int hp, string wt = "") {
        characterID = id;
        name = n;
        level = lvl;
        healthPoints = hp;
        weaponType = wt;
    }

    virtual void attack() {
    }

    virtual void defend() {
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        if (weaponType != "") {
            cout << "Weapon Type: " << weaponType << endl;
        }
    }
};

class Warrior : public Character {
private:
    int armorStrength;
    int meleeDamage;
public:
    Warrior(string id, string n, int lvl, int hp, int armor, int damage, string wt)
        : Character(id, n, lvl, hp, wt) {
        armorStrength = armor;
        meleeDamage = damage;
    }

    void attack() {
        cout << "Warrior performs melee attack with damage: " << meleeDamage << endl;
    }

    void displayStats() {
        Character::displayStats();
        cout << "Armor Strength: " << armorStrength << endl;
        cout << "Melee Damage: " << meleeDamage << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;
    int spellPower;
public:
    Mage(string id, string n, int lvl, int hp, int mana, int spell, string wt)
        : Character(id, n, lvl, hp, wt) {
        manaPoints = mana;
        spellPower = spell;
    }

    void defend() {
        cout << "Mage uses magical barrier with power: " << spellPower << endl;
    }

    void displayStats() {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << endl;
        cout << "Spell Power: " << spellPower << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;
    double rangedAccuracy;
public:
    Archer(string id, string n, int lvl, int hp, int arrows, double accuracy, string wt)
        : Character(id, n, lvl, hp, wt) {
        arrowCount = arrows;
        rangedAccuracy = accuracy;
    }

    void attack() {
        cout << "Archer performs ranged attack with accuracy: " << rangedAccuracy << endl;
    }

    void displayStats() {
        Character::displayStats();
        cout << "Arrow Count: " << arrowCount << endl;
        cout << "Ranged Accuracy: " << rangedAccuracy << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    int agility;
public:
    Rogue(string id, string n, int lvl, int hp, int stealth, int agi, string wt)
        : Character(id, n, lvl, hp, wt) {
        stealthLevel = stealth;
        agility = agi;
    }

    void displayStats() {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    cout << "khubaib ur rehman \n24k-0748" << endl;

    Warrior w1("W101", "Ali", 10, 150, 80, 60, "Sword");
    Mage m1("M101", "Zain", 12, 100, 200, 90, "Staff");
    Archer a1("A101", "Mehmod", 11, 120, 30, 85.5, "Bow");
    Rogue r1("R101", "Khubaib", 9, 110, 70, 95, "Daggers");

    cout << "\n--- Warrior Stats ---" << endl;
    w1.attack();
    w1.displayStats();

    cout << "\n--- Mage Stats ---" << endl;
    m1.defend();
    m1.displayStats();

    cout << "\n--- Archer Stats ---" << endl;
    a1.attack();
    a1.displayStats();

    cout << "\n--- Rogue Stats ---" << endl;
    r1.displayStats();

    return 0;
}
