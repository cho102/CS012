#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "BBoard.h"
#include "Message.h"
#include "Reply.h"
#include "Topic.h"
#include "User.h"


using namespace std;

    BBoard::BBoard()
    {
        title = "";
        vector<User> user_list;
        current_user = nullptr;
        vector<Message *> message_list;
    }


	BBoard::BBoard(const string & name)
    {
        title = name;
        vector<User> user_list;
        current_user = nullptr;
        vector<Message *> message_list;
    }


	BBoard::~BBoard()
    {
        for (unsigned int i = 0; i < message_list.size(); ++i)
        {
            delete message_list.at(i);
        }
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
                    user_list.push_back(passIn);
                }
            }
            inFS.close();
            return true;
        }
    }


	bool BBoard::loadMessages(const string &file)
    {
        int numMessages;
        string data;
        string header;
        string sub;
        string auth;
        string bodT;
        string bod;
        int id;
        ifstream inFS;
        string childr;
        vector <string> childrenID;
            
        inFS.open(file);

        if (!inFS.is_open()) {
           cout << "Could not open file " << file << endl;
           return false;
        }
        else
        {
            inFS >> numMessages;
            for (int i = 0; i < numMessages; ++i)
            {
                childr.clear();
                bodT.clear();
                inFS >> header;
                if (header == "<begin_topic>")
                {
                    inFS >> data >> id;
                    inFS >> data;
                    getline(inFS, sub);
                    sub.erase(sub.begin());
                    inFS >> data >> auth;
                    inFS >> data;
                    if (data == ":children:")
                    {
                        childr.clear();
                        getline(inFS, childr);
                        childrenID.push_back(childr);
                        inFS >> data;
                    }
                    else
                    {
                        childrenID.push_back("");
                    }
                    getline(inFS, bod);
                    bod.erase(bod.begin());
                    bodT += bod;
                    getline(inFS, bod);
                    while ( bod != "<end>")
                    {
                        bodT += "\n" + bod;
                        getline(inFS, bod);

                    }
                    Topic* topIn = new Topic(auth, sub, bodT, id);
                    message_list.push_back(topIn);
                }
                else if(header == "<begin_reply>")
                {
                    inFS >> data >> id;
//                     cout << "id: " << id << endl;
                    inFS >> data;
                    getline(inFS, sub);
                    sub.erase(sub.begin());
                    inFS >> data >> auth;
//                     cout << "auth: " << auth << endl;
                    inFS >> data;
                    if (data == ":children:")
                    {
                        childr.clear();
                        getline(inFS, childr);
                        childrenID.push_back(childr);
                        inFS >> data;
                    }
                    else
                    {
                        childrenID.push_back("");
                    }
                    getline(inFS, bod);
//                     cout << "bod: " << bod << endl; 
                    bod.erase(bod.begin());
                    bodT += bod;
                    getline(inFS, bod);
                    while ( bod != "<end>")
                    {
//                         cout << "bod: " << endl; 
                        bodT += "\n" + bod;
//                         cout << "bodT: " << endl; 
                        getline(inFS, bod);

                    }
//                     cout << "bodT: " << bodT << endl << endl;
                    Reply* repIn = new Reply(auth, sub, bodT, id);
                    message_list.push_back(repIn);
                }

                
            }
            istringstream inSS;
            int child;
            for (unsigned int i = 0; i < childrenID.size(); ++i)
            {
                if (childrenID.at(i) != "")
                {      
//                     cout << "Children is here!" << endl;
                    inSS.str(childrenID.at(i));
                    while (inSS >> child)
                    {
//                         cout << "child: " << child << endl;
                        message_list.at(i)->addChild(message_list.at(child-1));
                    }
                }
                inSS.clear();
            }
            
//             cout << "message_list.size(): " << message_list.size() << endl;

        }

        inFS.close();
        return true;
        
    }


	bool BBoard::saveMessages(const string & file)
    {
        ofstream outFS;
        outFS.open(file);
        if (!outFS.is_open())
        {
            return false;
        }
        outFS << message_list.size();
        outFS << "\n";
        for (unsigned int i = 0; i < message_list.size(); ++i)
        {
            outFS << message_list.at(i)->toFormattedString();         
        }
        outFS.close();
        return true;
    }


	void BBoard::login()
    {
//         bool found = true;
        bool failed = true;
        bool exists = false;
        string userFound;
        string name;
        string pass;

        cout << "Welcome to " << title << endl;

        while ((current_user == nullptr) && (failed == true))
        {
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> name;
//             cout << endl;

            if (name != "Q" && name != "q")
            {
                cout << "Enter your password: ";
                cin >> pass;
                
                for (unsigned int i = 0; i < user_list.size(); ++i)
                {
                    if (user_list.at(i).check(name, pass))
                    {
                        exists = true; 
                        current_user = &user_list.at(i);
                    }
                }
                if (exists)
                {
                    cout << endl;
                    cout << "Welcome back " << name << "!" << endl << endl;
                    failed = false;
//                     found = true;
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
//                 found = false;
                failed = false;
//                 current_user = nullptr;
            }
        }



//         return found;
    }


	void BBoard::run()
    {
        char input;
        string sub;
        string bod;
        if (current_user == nullptr)
        {
//             cout << "null" << endl;
            return;
        }

        cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl;
        cout << "- Add New Topic ('N' or 'n')" << endl;
        cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
        cin >> input;
//         cout << endl;

        while (input != 'Q' && input != 'q')
        {
            if (input == 'D' || input == 'd')
            {
                cout << endl;
                if (message_list.empty())
                {
                    cout << "Nothing to Display." << endl << endl;
                }
                else
                {
                    cout << "---------------------------------------------------------" << endl;
                    for (unsigned int i = 0; i < message_list.size(); ++i)
                    {
                        if (!message_list.at(i)->isReply())
                        {
                            message_list.at(i)->print(0);
                            cout << "---------------------------------------------------------" << endl;
                        }
                    }
                    cout << endl;
                }
            }
            
            
            
            
            

            else if (input == 'N' || input == 'n')
            {
                string bodT;
                cin.ignore();
                cout << "Enter Subject: ";

                getline(cin, sub);
                cout << "Enter Body: ";
                getline(cin, bod);
                if (bod != "")
                {
                    bodT += bod;
                    getline(cin, bod);
                }
                while (bod != "")
                {
                    bodT += "\n" + bod;
                    getline(cin, bod);
                }
                Topic * recorded = new Topic(current_user->getUsername(), sub, bodT, message_list.size() + 1);

                cout << endl;
                message_list.push_back(recorded);
//                 cout << "Message Recorded!" << endl << endl;
            }
            
            
            
            
            
            
            else if (input == 'R' || input == 'r')
            {
                int num;
                string bodT;
                cout << "Enter Message ID (-1 for Menu): ";
                cin >> num;
                while (num != -1)
                {
//                     unsigned numC = num;
                    while (!(((unsigned) num < message_list.size() + 1) && (num > 0)))
                    {
                        cout << "Invalid Message ID!!" << endl << endl;
                        cout << "Enter Message ID (-1 for Menu): ";
                        cin >> num;
//                         unsigned numC = num;
                    }
                    cin.ignore();
                    cout << "Enter Body: ";
                    getline(cin, bod);
                    while (bod != "")
                    {
                        bodT += bod + "\n";
                        getline(cin, bod);
                    }
                    Reply * recorded = new Reply(current_user->getUsername(), "Re: " + message_list.at(num - 1)->getSubject(), bodT, message_list.size() + 1);
                    message_list.push_back(recorded);
                    message_list.at(num - 1)->addChild(message_list.at(message_list.size()-1));
                    num = -1;

                
                }
                
                
            }
            
    

            cout << "Menu" << endl << "- Display Messages ('D' or 'd')" << endl;
            cout << "- Add New Topic ('N' or 'n')" << endl;
            cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
            cout << "- Quit ('Q' or 'q')" << endl << "Choose an action: ";
            cin >> input;
//             cout << endl;
        }
        cout << "Bye!" << endl;
        
    }