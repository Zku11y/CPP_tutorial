#include "Header.hpp"

bool Contact::add_contact()
{
    std::string input;
        std::cout << "Enter First Name : \n";
        if(!std::getline(std::cin, input)) return false;

        set_f_name(input);

        std::cout << "Enter Last Name : \n";
        if(!std::getline(std::cin, input)) return false;

        set_l_name(input);

        std::cout << "Enter NickName : \n";
        if(!std::getline(std::cin, input)) return false;

        set_n_name(input);

        std::cout << "Enter Phone Number : \n";
        if(!std::getline(std::cin, input)) return false;

        set_number(input);

        std::cout << "Enter Your Darkest Secret (Don't worry it's safe with me 😈): \n";
        if(!std::getline(std::cin, input)) return false;

        set_secret(input);

        return true;
}

void ft_print_col(std::string str)
{
    int size = 10 - str.size();
    if(size < 0){
        while(str.size() > 9)
            str.pop_back();
        std::cout << "|";
        std::cout << str << ".";
        return;
    }
    std::cout << "|";
    for(int j = 0; j < std::abs(size); j++)
        std::cout << " ";
    std::cout << str;
}

void Contact::display_contact(int i)
{
    // std::cout << "name : " << get_f_name() << std::endl;
    // std::cout << "last name : " << get_l_name() << std::endl;
    // std::cout << "AKA : " << get_n_name() << std::endl;
    // std::cout << "Phone Number : " << get_number() << std::endl;
    // std::cout << "Darkest Secret : " << get_secret() << std::endl;
    std::cout << "|     " << i << "    ";
    ft_print_col(f_name);
    ft_print_col(l_name);
    ft_print_col(n_name);
    std::cout << "|" << std::endl;
}