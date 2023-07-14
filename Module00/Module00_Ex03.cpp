#include <iostream>
#include <string>
#include <vector>

class Contact
{
private:
    std::string name;        // Name of the contact
    std::string phoneNumber; // Phone number of the contact
    std::string nickname;    // Nickname of the contact
    bool isBookmarked;       // Flag indicating if the contact is bookmarked or not

public:
    // Constructor
    Contact(const std::string &name, const std::string &phoneNumber, const std::string &nickname)
        : name(name), phoneNumber(phoneNumber), nickname(nickname), isBookmarked(false)
    {
    }

    // Getter functions
    std::string getName() const
    {
        return name;
    }

    std::string getPhoneNumber() const
    {
        return phoneNumber;
    }

    std::string getNickname() const
    {
        return nickname;
    }

    bool isContactBookmarked() const
    {
        return isBookmarked;
    }

    // Function to toggle the bookmark status of the contact
    void toggleBookmark()
    {
        isBookmarked = !isBookmarked;
    }
};

class Phonebook
{
private:
    std::vector<Contact> contacts; // Vector to store contacts

public:
    // Function to add a new contact
    void addContact()
    {
        std::string name, phoneNumber, nickname;

        std::cout << "Enter contact details:" << std::endl;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Phone Number: ";
        std::cin >> phoneNumber;

        // Check if the phone number already exists
        for (const auto &contact : contacts)
        {
            if (contact.getPhoneNumber() == phoneNumber)
            {
                std::cout << "Phone number already exists. Contact not added." << std::endl;
                return;
            }
        }

        std::cout << "Nickname: ";
        std::cin >> nickname;

        // Create a new contact and add it to the vector
        Contact newContact(name, phoneNumber, nickname);
        contacts.push_back(newContact);
        std::cout << "Contact added successfully!" << std::endl;
    }

    // Function to search and display all contacts
    void searchContacts()
    {
        std::cout << "Contacts in Phonebook:" << std::endl;
        for (size_t i = 0; i < contacts.size(); ++i)
        {
            std::cout << "[" << i << "] " << contacts[i].getName() << std::endl;
        }
    }

    // Function to display the details of a specific contact
    void displayContactDetails(int index)
    {
        if (index < contacts.size())
        {
            std::cout << "Contact Details:" << std::endl;
            std::cout << "Name: " << contacts[index].getName() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }

    // Function to toggle the bookmark and remove the bookmark status of a specific contact
    void toggleBookmark(int index)
    {
        if (index < contacts.size())
        {
            Contact &contact = contacts[index];
            bool isBookmarked = contact.isContactBookmarked();

            if (isBookmarked)
            {
                contact.toggleBookmark();
                std::cout << "Bookmark removed." << std::endl;
            }
            else
            {
                contact.toggleBookmark();
                std::cout << "Contact bookmarked." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }

    // Function to list all bookmarked contacts
    void listBookmarkedContacts()
    {
        std::cout << "Bookmarked Contacts:" << std::endl;
        for (size_t i = 0; i < contacts.size(); ++i)
        {
            if (contacts[i].isContactBookmarked())
            {
                std::cout << "Name: " << contacts[i].getName() << std::endl;
                std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
                std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
                std::cout << std::endl;
            }
        }
    }

    // Function to remove a specific contact
    void removeContact(int index)
    {
        if (index < contacts.size())
        {
            contacts.erase(contacts.begin() + index); // erase the appropriate index element
            std::cout << "Contact removed successfully!" << std::endl;
        }
        else
        {
            std::cout << "Invalid index." << std::endl;
        }
    }
};

int main()
{
    Phonebook phonebook;

    while (true)
    {
        std::string command;
        std::cout << "(ADD, SEARCH, BOOKMARK, LIST, REMOVE, EXIT):" << std::endl;
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContacts();
            int index;
            std::cout << "Enter index to display contact details: ";
            std::cin >> index;
            phonebook.displayContactDetails(index);
        }
        else if (command == "BOOKMARK")
        {
            int index;
            std::cout << "Enter index to toggle contact bookmark or Remove bookmark status: ";
            std::cin >> index;
            phonebook.toggleBookmark(index);
        }
        else if (command == "REMOVE")
        {
            int index;
            std::cout << "Enter Index No. to remove contact: ";
            std::cin >> index;
            phonebook.removeContact(index);
        }
        else if (command == "LIST")
        {
            phonebook.listBookmarkedContacts();
        }
        else if (command == "EXIT")
        {
            break; // Terminate the program
        }
        else
        {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
