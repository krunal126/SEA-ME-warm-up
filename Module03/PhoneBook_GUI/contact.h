#ifndef CONTACT_H
#define CONTACT_H
#include<string>

class Contact
{

private:
    std::string name;        // Name of the contact
    std::string phoneNumber; // Phone number of the contact
    std::string email;    // Nickname of the contact
    bool isBookmarked;       // Flag indicating if the contact is bookmarked or not

public:
    // Constructor
    Contact(const std::string &name, const std::string &phoneNumber, const std::string &email)
        : name(name), phoneNumber(phoneNumber), email(email), isBookmarked(false)
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

    std::string getEmail() const
    {
        return email;
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

#endif // CONTACT_H
