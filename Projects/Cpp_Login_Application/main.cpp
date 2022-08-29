#include <iostream>
#include <fstream>
#include <string>


using namespace std; 

bool isLoggedIN()
{
    string username, password, un, pw;
 cout << "Enter username: "; cin >> username;
 cout << "Enter password: "; cin >> password;
    
    // reads the first two lines of the file and stores them in the un / pw variables
    ifstream read("c:\\data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);


    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false; 
    }
}


int main()
{
    int choice;

    cout << "1: Register \n2: Login\nYour Choice: "; cin >> choice;
    if (choice ==1)
    {
        string username, password;

        cout << "select a username: "; cin >> username;
        cout << "select a password: "; cin >> password;

        ofstream file;
        file.open("c:\\data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = isLoggedIN();

        if(!status)
        {
            cout << "False Login" << endl;
            system("PAUSE");
            return 0;
        }
        else{
            cout << "Successfully Logged in!" << endl;
            system("PAUSE");
            return 1; 
        }
    }
}