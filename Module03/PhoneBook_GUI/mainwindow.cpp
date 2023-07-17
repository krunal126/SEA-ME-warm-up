#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<string>
#include<vector>
#include <QDebug>
#include <QMessageBox>
#include <QRegExp>
#include <QListWidgetItem>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QListView>
#include <QDir> // Include the QDir class
#include<QObject>

#include "contact.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{

    ui->setupUi(this);

 //   void on_AddSubmitPushButton_clicked();
//    void on_SearchPushButton_2_clicked();
//    void on_RemoveMainPushButton_clicked();
//    void on_ReloadPushButton_clicked();
//    void on_ListPushButton_clicked();
}

//class Contact
//{
//private:
//    std::string name;        // Name of the contact
//    std::string phoneNumber; // Phone number of the contact
//    std::string email;    // Nickname of the contact
//    bool isBookmarked;       // Flag indicating if the contact is bookmarked or not

//public:
//    // Constructor
//    Contact(const std::string &name, const std::string &phoneNumber, const std::string &email)
//        : name(name), phoneNumber(phoneNumber), email(email), isBookmarked(false)
//    {
//    }

//    // Getter functions
//    std::string getName() const
//    {
//        return name;
//    }

//    std::string getPhoneNumber() const
//    {
//        return phoneNumber;
//    }

//    std::string getEmail() const
//    {
//        return email;
//    }

//    bool isContactBookmarked() const
//    {
//        return isBookmarked;
//    }

//    // Function to toggle the bookmark status of the contact
//    void toggleBookmark()
//    {
//        isBookmarked = !isBookmarked;
//    }
//};


/*class ContactList
{
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact &contact)
    {
         qDebug() << "function called ";
        contacts.push_back(contact);


    }

//    bool removeContactByName(const std::string &name)
//    {
//        auto it = std::remove_if(contacts.begin(), contacts.end(),
//                                 [name](const Contact &contact) {
//                                     return contact.getName() == name;
//                                 });

//        if (it != contacts.end())
//        {
//            contacts.erase(it, contacts.end());
//            return true;
//        }
//        return false;
//    }

//    std::vector<Contact> searchContactsByName(const std::string &name) const
//    {
//        std::vector<Contact> matchingContacts;
//        for (const auto &contact : contacts)
//        {
//            if (contact.getName() == name)
//            {
//                matchingContacts.push_back(contact);
//            }
//        }
//        return matchingContacts;
//    }

//    QStringListModel *getAllContactsModel() const
//    {
//        QStringList contactDetailsList;
//        for (const auto &contact : contacts)
//        {
//            QString contactDetails = "Name: " + QString::fromStdString(contact.getName()) + "\n";
//            contactDetails += "Phone Number: " + QString::fromStdString(contact.getPhoneNumber()) + "\n";
//            contactDetails += "Email: " + QString::fromStdString(contact.getEmail()) + "\n\n";
//            contactDetailsList << contactDetails;
//        }
//        return new QStringListModel(contactDetailsList);
//    }
};*/

std::vector<Contact> contacts;


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_SearchPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::on_RemovePushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_AddMainPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_SearchMainPushButton_clicked()
{
     ui->SearchNameLineEdit->clear();
    // Clear the model associated with the search list view
    ui->SearchListView->setModel(nullptr);
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_RemoveMainPushButton_clicked()
{
    QString removeName = ui->RemoveLineEdit->text();

    // Find and remove the contact with the given name from the contacts vector
    auto it = std::remove_if(contacts.begin(), contacts.end(),
                             [removeName](const Contact &contact) {
                                 return QString::fromStdString(contact.getName()) == removeName;
                             });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        QMessageBox::information(this, "Contact Removed", "Contact has been removed successfully!");
    } else {
        QMessageBox::warning(this, "Contact Not Found", "Contact with the given name not found in the phonebook.");
    }

    // Clear the input field after removing the contact
    ui->RemoveLineEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_AddSubmitPushButton_clicked()
{


    QString name = ui->AddNameLineEdit->text();
    QString phoneNumber = ui->AddNumberLineEdit->text();
    QString email = ui->AddEmailLineEdit->text();

    // Check if the phone number already exists
    for (const auto &contact : contacts)
    {
        if (contact.getPhoneNumber() == phoneNumber.toStdString())
        {

            QMessageBox::warning(this, "Phone number already exists,Contact not added", "Please enter a diffrent Phone number ");
            return;
        }
    }
    // Validate the email address using QRegExp
    QRegExp regex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    bool isValidEmail = regex.exactMatch(email);
    if (!isValidEmail)
    {
        QMessageBox::warning(this, "Invalid Email Address", "Please enter a valid email address.");
        return;
    }
    // Create a new Contact object and add it to the contacts vector
    Contact newContact(name.toStdString(), phoneNumber.toStdString(), email.toStdString());
   contacts.push_back(newContact);
//    ContactList c;
//    c.addContact(newContact);
    // Display a message box indicating the contact has been added
    QMessageBox::information(this, "Contact Added", "Contact has been added successfully!");


    // Reset the line edit widgets
    ui->AddNameLineEdit->clear();
    ui->AddNumberLineEdit->clear();
    ui->AddEmailLineEdit->clear();

    // Switch back to the main page
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_SearchPushButton_2_clicked()
{
    QString searchName = ui->SearchNameLineEdit->text();

    // Create a string list model
    QStringListModel *model = new QStringListModel(this);

    // Create a string list to hold the matched contact details
    QStringList matchedContacts;

    // Iterate through the contacts and find matching names
    for (const auto &contact : contacts)
    {
        if (QString::fromStdString(contact.getName()).contains(searchName, Qt::CaseInsensitive))
        {
            // Add the contact details to the string list
            QString contactDetails = "Name: " + QString::fromStdString(contact.getName()) + "\n";
            contactDetails += "Phone Number: " + QString::fromStdString(contact.getPhoneNumber()) + "\n";
            contactDetails += "Email: " + QString::fromStdString(contact.getEmail());

            matchedContacts << contactDetails;
        }
    }

    // Set the string list as the model data for the list view
    model->setStringList(matchedContacts);
    ui->SearchListView->setModel(model);


    // Clear the search results if no matches found
    if (matchedContacts.isEmpty())
    {
        ui->SearchListView->setModel(nullptr);
    }

}








void MainWindow::on_RemoveEnterPushButton_clicked()
{

}


void MainWindow::on_ListPushButton_clicked()
{
      ui->stackedWidget->setCurrentIndex(4);
    QStringList contactDetailsList;

    for (const auto &contact : contacts)
    {
        QString contactDetails = "Name: " + QString::fromStdString(contact.getName()) + "\n";
        contactDetails += "Phone Number: " + QString::fromStdString(contact.getPhoneNumber()) + "\n";
        contactDetails += "Email: " + QString::fromStdString(contact.getEmail()) + "\n\n";
        contactDetailsList << contactDetails;
    }

    if (contactDetailsList.isEmpty())
    {
        QMessageBox::information(this, "No Contacts", "No contacts added yet.");
    }
    else
    {
       ui->AllContactsListView->setModel(new QStringListModel(contactDetailsList, this));
    }
}


void MainWindow::on_SaveListPushButton_clicked()
{
    QString fileName = "C:/Users/kruna/Documents/SEAME_LAST/PhoneBook_GUI/Data_Store.txt"; // Fixed filename
    QDir dataDir; // Create a QDir instance
    QString filePath = dataDir.absoluteFilePath(fileName); // Get the absolute file path
    QFile file(filePath); // Use the absolute file path

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
       QTextStream out(&file);
       for (const auto &contact : contacts)
       {
            out << QString::fromStdString(contact.getName()) << "\n";
            out << QString::fromStdString(contact.getPhoneNumber()) << "\n";
            out << QString::fromStdString(contact.getEmail()) << "\n";
            out << "\n"; // Add an empty line between each contact
       }
       file.close();

       // Check for errors during writing
       if (file.error() == QFile::NoError)
       {
            qDebug() << "Contact list has been saved to the file:" << filePath;
            QMessageBox::information(this, "Contact List Saved", "Contact list has been saved to the file.");
       }
       else
       {
            qDebug() << "Error saving contact list to the file:" << file.errorString();
            QMessageBox::warning(this, "Error", "Unable to save contact list to the file.");
       }
    }
    else
    {
       qDebug() << "Error opening the file for writing:" << file.errorString();
       QMessageBox::warning(this, "Error", "Unable to save contact list to the file.");
    }
    ui->AllContactsListView->setModel(nullptr);
}





void MainWindow::on_ReloadListPushButton_clicked()
{
    QString fileName = "C:/Users/kruna/Documents/SEAME_LAST/PhoneBook_GUI/Data_Store.txt"; // Fixed filename
    QDir dataDir; // Create a QDir instance
    QString filePath = dataDir.absoluteFilePath(fileName); // Get the absolute file path
    QFile file(filePath); // Use the absolute file path

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       contacts.clear();
       QStringList contactDetailsList;

       QTextStream in(&file);
       while (!in.atEnd())
       {
            QString name = in.readLine();
            QString phoneNumber = in.readLine();
            QString email = in.readLine();
            in.readLine(); // Skip the empty line between contacts

            // Add the contact to the contacts vector
            contacts.emplace_back(name.toStdString(), phoneNumber.toStdString(), email.toStdString());

            // Add the contact details to the contactDetailsList
            QString contactDetails = "Name: " + name + "\n";
            contactDetails += "Phone Number: " + phoneNumber + "\n";
            contactDetails += "Email: " + email + "\n";
            contactDetailsList << contactDetails;
       }
       file.close();

       if (contactDetailsList.isEmpty())
       {
            QMessageBox::information(this, "No Contacts", "No contacts available. Please add contacts and save.");
       }
       else
       {
            ui->AllContactsListView->setModel(new QStringListModel(contactDetailsList, this));
            QMessageBox::information(this, "Contact List Reloaded", "Contact list has been reloaded from the file.");
       }
    }
    else
    {
       QMessageBox::warning(this, "Error", "Unable to load contact list from the file.");
    }
}


void MainWindow::on_ListMainPushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_RemoveMainPushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

