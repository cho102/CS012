#include <iostream>
using namespace std;

#include "User.h"


User::User()
{
    username = "";
    password = "";
}

User::User(const string& uname, const string& pass)
{
    username = uname;
    password = pass;
}


string User::getUsername() const
{
    return username;
}


bool User::check(const string &uname, const string &pass) const
{
    if ((uname == "") && (pass == ""))
    {
        return false;
    }
    else if ((username == uname) && (password == pass))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool User::setPassword(const string &oldpass, const string &newpass)
{
    bool changed = false;
    
    if (username == "")
    {
        return false;
    }
    
    if (oldpass == password)
    {
        password = newpass;
        changed = true;
    }
    
    
    return changed;
}