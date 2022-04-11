#include <iostream>
#include <string>
#include <sstream>
#include "Topic.h"

using namespace std;

    Topic::Topic()
    {}
	
	Topic::Topic(const string & a, const string & s, const string & b, unsigned i) :  Message(a, s, b, i)
    {}
	
	bool Topic::isReply() const
    {
        return false;
    }

	string Topic::toFormattedString() const // New !! 
    {
        string formatted; 
        stringstream convert;
        string changedId;
        
        convert << id;
        changedId = convert.str();
        
        formatted += "<begin_topic>";
        formatted += "\n:id: " + changedId;
        formatted += "\n:subject: " + subject;
        formatted += "\n:from: " + author;
        
        if (!childList.empty())
        {
            formatted += "\n:children:";
            for (unsigned int i = 0; i < childList.size(); ++i)
            {
                changedId = "";
                convert.str("");
                convert << childList.at(i)->getID();
                changedId = convert.str();
                formatted += " " + changedId;
//                 cout << "childList.at(i)->getID(): " << childList.at(i)->getID() << endl;
            }
            
        }
        
        formatted += "\n:body: " + body;
        formatted += "\n<end>\n";
   
        return formatted;
    }