#include "Header.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;
    std::cout << "Welcome to the PhoneBook! :D" << std::endl;
    while(true) {
        std::cout << "Enter action (ADD / SEARCH / EXIT) : ";
        // std::cin >> input;
        if(!std::getline(std::cin, input)) return(std::cout << "EOF detected!\n", 1);
        if(input.compare("ADD") != 0 && input.compare("SEARCH") != 0 && input.compare("EXIT") != 0){
            std::cout << "its not a valid input :(" << std::endl;
            continue;
        } else
            std::cout << "its a valid input! :D" << std::endl;
        // std::cin.ignore();
        if(input.compare("ADD") == 0){
            if(!phonebook.add_contact()) return(std::cout << "EOF detected!\n", 1);
        }
        else if(input.compare("SEARCH") == 0){
            phonebook.list_contacts();
        }
        else
            return (std::cout << "exiting phonebook..." << std::endl, 0);
    }
    return 0;
}
