#include <array>
#include <iostream>
#include <numeric>
#include <algorithm>
// Bad approach , doesn't scale
//
// class Creature {
//     int strength, agility, intelligence;

//    public:
//     int get_strength() const { return strength; }
//     int get_agility() const { return agility; }
//     int get_intelligence() const { return intelligence; }
//     int set_strength(int value) { strength = value; }
//     int set_agility(int value) { agility = value; }
//     int set_intelligence(int value) { intelligence = value; }
//     int sum() { return strength + agility + intelligence; }
//     float avg() { return sum() / 3; }
//     int max() { return std::max(std::max(strength, agility), intelligence); }
// };

class Creature {
    enum Abilities { kStrenght, kAgility, kIntelligence, kCount };
    std::array<int, kCount> abilities;

   public:
    int getStrength() const { return abilities[kStrenght]; }
    int getAgility() const { return abilities[kAgility]; }
    int getIntelligence() const { return abilities[kIntelligence]; }
    void setStrength(int value) { abilities[kStrenght] = value; }
    void setAgility(int value) { abilities[kAgility] = value; }
    void setIntelligence(int value) { abilities[kIntelligence] = value; }
    int sum() { return std::accumulate(abilities.begin(), abilities.end(), 0); }
    float avg() { return sum() / kCount; }
    int max() { return *std::max_element(abilities.begin(), abilities.end()); }
};

int main(int argc, char** argv) {
    Creature orc;
    orc.setStrength(18);
    orc.setAgility(12);
    orc.setIntelligence(4);
    std::cout << "The orc has an average stat of " << orc.avg()
              << " and a max stat of " << orc.max() << std::endl;
}
