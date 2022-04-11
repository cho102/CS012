#include <iostream>
#include <string>

#include "Message.h"

using namespace std;

    Message::Message()
    {
        author = "";
        subject = "";
        body = "";
        id = 0;
    }
	
	Message::Message(const string & athr, const string & sbjct, const string & bdy, unsigned num)
    {
        author = athr;
        subject = sbjct;
        body = bdy;
        id = num;
    }

    Message::~Message() {}

    void Message::print(unsigned sp) const // New !! 
    {
        for (unsigned i = 0; i < 2 * sp; ++i)
        {
            cout << " ";
        }
        cout << "Message #" << id << ": " << subject << endl;
        for (unsigned i = 0; i < 2 * sp; ++i)
        {
            cout << " ";
        }
        istringstream inSS;
        string line;
        inSS.str(body);
        getline(inSS, line);
        cout << "from " << author << ": " << line << endl;
        
        while (getline(inSS, line))
        {
            for (unsigned i = 0; i < 2 * sp; ++i)
            {
                cout << " ";
            }
            cout << line << endl;
            
        }
        for (unsigned int i = 0; i < childList.size(); ++i)
        {
            cout << endl;
            childList.at(i)->print(1 + sp);
        }
        
    }
	
	const string & Message::getSubject() const
    {
        return subject;
    }
	
	unsigned Message::getID() const // New !! 
    {
        return id;
    }
	
	void Message::addChild(Message *m) // New !! 
    {
        this->childList.push_back(m);
    }