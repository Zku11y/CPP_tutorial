#include "Header.hpp"

bool PhoneBook::add_contact(){
    std::string input;

    for(int i = 0; i < 9; i++){
        if(i == 8 && !contacts[i].get_f_name().empty()){
            std::rotate(contacts.begin(), contacts.begin() + 1, contacts.end());
            if(!contacts[i].add_contact()) return false;
            break;
        }
        else if(contacts[i].get_f_name().empty()){
            if(!contacts[i].add_contact()) return false;
            break;
        }
    }
    return true;
}
void PhoneBook::list_contacts(){
    int index = -1;

    std::cout << "|     index|first_name| last_name| nick_name|" << std::endl;
    for(int i = 0; i < 9; i++){
        contacts[i].display_contact(i);
    }
    while(true){
        std::cout << "Enter Index of desired Contact :";
        std::cin >> index;
        if(index < 0 || index > 8)
            std::cout << "value : " << index << " Invalid, enter a valid value between 0 and 8" << std::endl;
        else{
            display_contact(contacts[index]);
            return;
        }
    }
}


void PhoneBook::display_contact(Contact contact){
    std::cout << "First Name : " << contact.get_f_name() << std::endl;
    std::cout << "Last Name : " << contact.get_l_name() << std::endl;
    std::cout << "NickName : " << contact.get_n_name() << std::endl;
    std::cout << "Phone Number : " << contact.get_number() << std::endl;
    std::cout << "Darkest Secret : " << contact.get_secret() << std::endl;
}