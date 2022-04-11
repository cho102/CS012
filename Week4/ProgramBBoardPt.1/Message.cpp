#include <iostream>
using namespace std;

#include "BBoard.h"
#include "User.h"
#include "Message.h"

Message::Message()
{
    author = "";
    subject = "";
    body = "";
}

Message::Message(const string &athr, const string &sbjct, const string &bdy)
{
    author = athr;
    subject = sbjct;
    body = bdy;
}


void Message::display() const
{
    cout << subject << endl << "from " << author << ": " << body << endl;
}