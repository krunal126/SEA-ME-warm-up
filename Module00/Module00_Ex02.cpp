#include <iostream>
#include <cctype>
#include <string>

// Class for converting strings to different cases
class StringConverter
{
public:
    // Function to convert the string to uppercase
    std::string toUpperCase(const std::string &str)
    {
        std::string result;

        for (size_t i = 0; i < str.length(); i++)
        {
            result += std::toupper(str[i]);
        }
        return result;
    }

    // Function to convert the string to lowercase
    std::string toLowerCase(const std::string &str)
    {
        std::string result;

        for (size_t i = 0; i < str.length(); i++)
        {
            result += std::tolower(str[i]);
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 3)
    {
        std::cout << "Usage: program_name {command} {string}" << std::endl;
        return 1; // Exit the program with an error status
    }

    StringConverter stringConverter;

    // Get the command-line arguments
    std::string command = argv[1];
    std::string inputString = argv[2];

    std::string outputString;

    // Perform the specified command on the input string
    if (command == "up")
    {
        outputString = stringConverter.toUpperCase(inputString);
    }
    else if (command == "down")
    {
        outputString = stringConverter.toLowerCase(inputString);
    }
    else
    {
        std::cout << "Invalid command. Available commands: up, down" << std::endl;
        return 1; // Exit the program with an error status
    }

    // Print the result
    std::cout << "Output: " << outputString << std::endl;

    return 0; // Exit the program with success status
}
