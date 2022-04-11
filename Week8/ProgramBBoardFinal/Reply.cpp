#include <iostream>
#include <string>

#include "Reply.h"

using namespace std;

    Reply::Reply()
    {}

    Reply::Reply(const string & ath, const string & sub, const string & bod, unsigned num) : Message(ath, sub, bod, num)
    {
//         string subj = "Re: " + sub;
        
    }

    bool  Reply::isReply() const
    {
       return true;
    }


    string  Reply::toFormattedString() const // New !! 
    {
        string formatted; 
        stringstream convert;
        string changedId;
        
        convert << id;
        changedId = convert.str();
        
        formatted += "<begin_reply>";
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
            }
            
        }
        
        formatted += "\n:body: " + body;
        formatted += "\n<end>\n";
        
        return formatted;
        
    }