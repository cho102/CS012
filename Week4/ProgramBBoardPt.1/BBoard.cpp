#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "BBoard.h"
#include "User.h"
#include "Message.h"


BBoard::BBoard()
{
    title = "";
}


BBoard::BBoard(const string & name)
{
    title = name;
}

bool BBoard::loadUsers(const string & file)
{
    string name;
    string pass;
    User passIn;
    ifstream inFS;
    inFS.open(file);    
    
    if(!inFS.is_open())
    {
        inFS.close();
        return false;
    }
    else
    {
        while (inFS >> name)
        {
            if (name != "end")
            {
                inFS >> pass;
                passIn = User(name, pass);
                userList.push_back(passIn);
            }
        }
        inFS.close();
        return true;
    }
}


bool BBoard::login()
{
    bool found = true;
    bool failed = true;
    bool exists = false;
    string userFound;
    string name;
    string pass;
    
    cout << "Welcome to " << title << endl;
    
    while (failed == true)
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> name;
        cout << endl;

        if (name != "Q" && name != "q")
        {
            cout << "Enter your password: ";
            cin >> pass;
            cout << endl;
//             entered.username = name;
//             entered.password = pass;
            for (unsigned int i = 0; i < userList.size(); ++i)
            {
                if (userList.at(i).check(name, pass))
                {
                    exists = true; 
                    currentUser = userList.at(i);
                }
//                 if (currentUser.checentered ==  userList.at(i))
//                 {
//                     exists = true;
//                     currentUser = userList.at(i);
//                 }
            }
            if (exists)
            {
                cout << "Welcome back " << name << "!" << endl << endl;
                failed = false;
                found = true;
            }
            else
            {
                cout << "Invalid Username or Password!" << endl << endl;
                failed = true;
            }
        }
        else
        {
            cout << "Bye!" << endl;
            found = false;
            failed = false;
        }
    }
    
    
    return found;
}


void BBoard::run()
{
    char input;
    string sub;
    string bod;
    
    cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Message ('N' or 'n')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
    cin >> input;
    cout << endl;

    while (input != 'Q' && input != 'q')
    {
        if (input == 'D' || input == 'd')
        {
            if (messageList.empty())
            {
                cout << "Nothing to Display." << endl << endl;
            }
            else
            {
                cout << "---------------------------------------------------------" << endl;
                for (unsigned int i = 0; i < messageList.size(); ++i)
                {
                    cout << "Message #" << i + 1 << ": "; 
                    messageList.at(i).display();
                    cout << "---------------------------------------------------------" << endl;
                }
                cout << endl;
            }
        }
        else if (input == 'N' || input == 'n')
        {
            cin.ignore();
            cout << "Enter Subject: ";
            
            getline(cin, sub);
            cout << endl;
            cout << "Enter Body: ";
            
//             cin.ignore();
            getline(cin, bod);
            
            cout << endl;
            messageList.push_back(Message(currentUser.getUsername(), sub, bod));
            cout << "Message Recorded!" << endl << endl;
        }
        
        cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl;
        cout << "- Add New Message ('N' or 'n')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
        cin >> input;
        cout << endl;
    }
    cout << "Bye!" << endl;

}