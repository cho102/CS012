#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
 
using namespace std;

class Message
{
    protected:
        string author;
        string subject;
        string body;
        unsigned id;
        vector<Message *> childList;
    
    public: 
        Message();
        Message(string author, string subject, string body, unsigned id);
};

Message::Message()
    {
        author = "";
        subject = "";
        body = "";
        id = 0;
    }

Message::Message(string a, string s, string b, unsigned i)
{
    author = a;
    subject = s;
    body = b;
    id = i;
}

class Reply : public Message {
    public:
        Reply(const string &, 
      const string &, 
      const string &, 
      unsigned);
};

 Reply::Reply(const string & ath, const string & sub, const string & bod, unsigned num)
    {
        string subj = "Re: " + sub;
        Message(ath, subj, bod, num);
    }
        

int main() {
    
//     ofstream outFS;
//     string fileName;
    
//     cout << "Input file name: " ;
//     cin >> fileName;
    
//     outFS.open(fileName);

//     if (!outFS.is_open()) {
//        cout << "Could not open file " << fileName << endl;
//        return 1;
//     }
    
//     int ie;
//     string subject;
//     string author;
//     string body;
//     char child;
//     string input;
//     string id;
//     stringstream convert;
    
    
//     //Output data to file
//     for (int i = 0; i < 2; ++i)
//     {
//         cout << "Enter id: ";
//         cin >> ie;
    
//         cin.ignore();

//         cout << "Enter subject: ";
//         getline(cin, subject);
  
//         cout << "Enter author: ";
//         cin >> author;

//         cin.ignore();
//         cout << "Enter body: ";
//         getline(cin, body);
//         convert.str("");
//         convert << ie;
//         id = "";
//         id = convert.str();
    
//         input += "<begin_topic>";
//         input += " \n:id: " + id;
//         input += " \n:subject: " + subject;
//         input += "\n:from: " + author;
//         input += "\n:body: " + body;
//         input += "\n<end> \n";
  
//         outFS << input;
//         input = "";
//     }

    
//     //converting int to string
//     cin >> ie;
//     convert << ie;
//     id = convert.str();
//     convert.str("");
   
//   outFS.close();

    int numMessages;
    vector<Message*> message_list;
    ifstream inFS;
    string file;
    string data;
    string header;
    string sub;
    string auth;
    string bodT;
    string bod;
    int id;
    string child;
    string childr;
    
    cout << "Input file name: " ;
    cin >> file;
    
    inFS.open(file);
    
    if (!inFS.is_open()) {
           cout << "Could not open file " << file << endl;
//            return false;
        }
        else
        {
            inFS >> numMessages;
            cout << "numMessage: " << numMessages << endl;
            for (int i = 0; i < numMessages; ++i)
            {
                bodT.clear();
                inFS >> header;
                if (header == "<begin_topic>")
                {
                    inFS >> data >> id;
                    cout << "id: " << id << endl;
                    inFS >> data;
                    getline(inFS, sub);
                    sub.erase(sub.begin());
                    cout << "sub: " << sub << endl;
                    inFS >> data >> auth;
                    cout << "auth: " << auth << endl;
                    inFS >> data;
                    if (data == ":children:")
                    {
                        childr.clear();
                        inFS >> child;
                        while (child != ":body:")
                        {
                            childr += child;
                            inFS >> child;
                        }
                        cout << "childr: " << childr << endl;
//                         inFS >> data;
                    }
                    getline(inFS, bod);
                    bod.erase(bod.begin());
                    while ( bod != "<end>")
                    {
                        bodT += bod + " ";
                        getline(inFS, bod);

                    }
                    cout << "bodT: " << bodT << endl << endl;
                }
                else if(header == "<begin_reply>")
                {
                    inFS >> data >> id;
                    cout << "id: " << id << endl;
                    inFS >> data;
                    getline(inFS, sub);
                    sub.erase(sub.begin());
                    cout << "sub: " << sub << endl;
                    inFS >> data >> auth;
                    cout << "auth: " << auth << endl;
                    inFS >> data;
                    if (data == ":children:")
                    {
                        childr.clear();
                        inFS >> child;
                        while (child != ":body:")
                        {
                            childr += child;
                            inFS >> child;
                        }
                        cout << "childr: " << childr;
//                         inFS >> data;
                    }
                    getline(inFS, bod);
                    bod.erase(bod.begin());
                    while ( bod != "<end>")
                    {
                        bodT += bod + " ";
                        getline(inFS, bod);

                    }
                    cout << "bodT: " << bodT << endl << endl;
                    Reply messIn = Reply(auth, sub, bodT, id);
                    message_list.push_back(&messIn);
                }
                
//                 Message messIn = Message(auth, sub, bodT, id);
//                 message_list.push_back(&messIn);
//                 bodT.clear();
            }

        }
    
    cout <<"message_list.size(): " << message_list.size() << endl;

        inFS.close();
//         return true;
    
    
    
    
    return 0;
}

