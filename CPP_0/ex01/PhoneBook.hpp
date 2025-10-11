#pragma once

#include "Header.hpp"
#include <iostream>
#include <array>

class PhoneBook
{
private:
    std::array<Contact, 9> contacts;

public:
    bool add_contact();
    void list_contacts();
    void display_contact(Contact contact);
};
