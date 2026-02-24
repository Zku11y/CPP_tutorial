#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for(int i = 0; i < 4; i++){
        inv[i] = 0;
    }
}

MateriaSource::MateriaSource(MateriaSource const &other){

        for(int i = 0; i < 4; i++){
            if(other.inv[i]){
                inv[i] = other.inv[i]->clone();
            }
            else
                inv[i] = 0;
        }
        
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other){
    if(this != &other){

        for(int i = 0; i < 4; i++){
            if(inv[i])
                delete inv[i];
            if(other.inv[i]){
                inv[i] = other.inv[i]->clone();
            }
            else
                inv[i] = 0;
        }

    }

    return *this;
}

MateriaSource::~MateriaSource(){
    for(int i = 0; i < 4; i++){
        if(inv[i])
            delete(inv[i]);
    }
}

void MateriaSource::learnMateria(AMateria* tmp){
    if(!tmp)
        return;
    for(int i = 0; i < 4; i++){
        if(!inv[i]){
            inv[i] = tmp;
            return;
        }
    }
    delete(tmp);
}

AMateria *MateriaSource::createMateria(std::string const &type){
    for(int i = 0; i < 4; i++){
        if(inv[i] && type == inv[i]->getType()){
            return(inv[i]->clone());
        }
    }
    return 0;
}