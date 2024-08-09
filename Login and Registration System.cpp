#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser()
{
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Create or open a file named after the username
    ofstream userFile(username + ".txt");

    // Write the username and password to the file
    if (userFile.is_open())
    {
        userFile << username << endl;
        userFile << password << endl;
        userFile.close();
        cout << "Registration successful!" << endl;
    }
    else
    {
        cout << "Error: Could not open file for writing." << endl;
    }
}

// Function to login a user
bool loginUser()
{
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Open the file named after the username
    ifstream userFile(username + ".txt");

    // Read the stored username and password
    if (userFile.is_open())
    {
        getline(userFile, storedUsername);
        getline(userFile, storedPassword);
        userFile.close();

        // Check if the entered credentials match the stored credentials
        if (username == storedUsername && password == storedPassword)
        {
            cout << "Login successful!" << endl;
            return true;
        }
        else
        {
            cout << "Invalid username or password." << endl;
            return false;
        }
    }
    else
    {
        cout << "Error: User does not exist." << endl;
        return false;
    }
}

int main()
{
    int choice;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        registerUser();
    }
    else if (choice == 2)
    {
        loginUser();
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}