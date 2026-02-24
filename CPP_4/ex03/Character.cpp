#include "Character.hpp"

Character::Character(std::string name): name(name), sk_floor_i(0){

    for(int i = 0; i < 4; i++)
        inv[i] = 0;

    for(int i = 0; i < 100; i++)
        sk_floor[i] = 0;
}

Character::Character(Character const &other): name(other.name), sk_floor_i(other.sk_floor_i){

    for(int i = 0; i < 4; i++){
        if(other.inv[i])
            inv[i] = other.inv[i]->clone();
        else
            inv[i] = 0;
    }

    for(int i = 0; i < 100; i++){
        if(other.sk_floor[i])
            sk_floor[i] = other.sk_floor[i]->clone();
        else
            sk_floor[i] = 0;
    }


}

Character &Character::operator=(Character const &other){

    if(this != &other){

        this->sk_floor_i = other.sk_floor_i;
        this->name = other.name;

        for(int i = 0; i < 4; i++){
            if(inv[i])
                delete(inv[i]);

            if(other.inv[i])
                inv[i] = other.inv[i]->clone();
            else
                inv[i] = 0;
        }

        for(int i = 0; i < 100; i++){
            if(sk_floor[i])
                delete(sk_floor[i]);
            if(other.sk_floor[i])
                sk_floor[i] = other.sk_floor[i]->clone();
            else
                sk_floor[i] = 0;
        }

    }

    return (*this);
}

Character::~Character(){
    for(int i = 0; i < 4; i++){
        if(inv[i])
            delete inv[i];
    }

    for(int i = 0; i < 100; i++){
        if(sk_floor[i])
            delete sk_floor[i];
    }
}

std::string const &Character::getName() const{
    return name;
}

void Character::equip(AMateria *m){
    if(m){
        for(int i = 0; i < 4; i++){
            if(!inv[i]){
                inv[i] = m;
                return;
            }
        }
    }
}

void Character::unequip(int idx){
    if(idx < 0 || idx > 3 || !inv[idx] || sk_floor_i + 1 == 100)
        return;
    
    sk_floor[sk_floor_i] = inv[idx];
    inv[idx] = 0;
    sk_floor_i++;
}

void Character::use(int idx, ICharacter &target){
    if(idx < 0 || idx > 3 || !inv[idx])
        return;
    inv[idx]->use(target);
}