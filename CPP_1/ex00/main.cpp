#include "Zombie.hpp"

int main(){
    Zombie* z = newZombie("bruuuuh");
    z->announce();
    randomChump("bruuuuuh but random");
    delete(z);
}
