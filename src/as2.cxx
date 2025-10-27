#include "../include/as2.hpp"
#include <iostream>
#include <sstream>

namespace homework {
Knight::Knight(const std::string name): Entity(name) {}
void Knight::attack() const {
    std::cout << name << " swings a " << _weapon << std::endl;
}
std::unique_ptr<Entity> Knight::clone() const {
        return std::make_unique<Knight>(*this);
}
void Knight::setWeapon(const std::string weapon) {
    _weapon = weapon;
}
Sorcerer::Sorcerer(const std::string name): Entity(name) {}
void Sorcerer::attack() const {
    std::cout << name << " casts a " << _ability << std::endl;
}
std::unique_ptr<Entity> Sorcerer::clone() const {
        return std::make_unique<Sorcerer>(*this);
}
void Sorcerer::setAbility(const std::string ability) {
    _ability = ability;
}
} // namespace homework

int main(){
    homework::Sorcerer sorcerer("Jinx");
    sorcerer.setAbility("fireball");
    std::ostringstream oss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    sorcerer.attack();
    std::cout.rdbuf(oldCoutStreamBuf);
    std::cout << oss.str() << std::endl;
    auto sorcClone = sorcerer.clone();
    std::cout << sorcClone->getName() << std::endl;
    return 0;
}
