#pragma once

#include "Header.hpp"

class Contact
{
private:
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string number;
    std::string secret;
public:
    void set_f_name(std::string str){f_name = str;}
    void set_l_name(std::string str){l_name = str;}
    void set_n_name(std::string str){n_name = str;}
    void set_number(std::string str){number = str;}
    void set_secret(std::string str){secret = str;}
    std::string get_f_name(){return f_name;}
    std::string get_l_name(){return l_name;}
    std::string get_n_name(){return n_name;}
    std::string get_number(){return number;}
    std::string get_secret(){return secret;}
    bool add_contact();
    void display_contact(int i);
};