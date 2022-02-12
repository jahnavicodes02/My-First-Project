#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool IsLoggedIn(){

    string username,password,un,pw;

    cout<<"Enter the username: \n";
    cin>>username;
    cout<<"Enter the password: \n";
    cin>>password;

    ifstream read("C:\\Users\\Lenovo\\OneDrive\\Desktop\\code\\Login_System\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int choice;

    cout<<"1.Register \n2.Login \nYour choice: \n";
    cin>>choice;

    if(choice == 1){

        string username, password;

        cout<<"Select a username: \n";
        cin>>username;
        cout<<"Select a password: \n";
        cin>>password;

        ofstream file;
        file.open("C:\\Users\\Lenovo\\OneDrive\\Desktop\\code\\Login_System\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }

    else if(choice == 2){

        bool status=IsLoggedIn();

        if(!status){
            cout<<"False Login";
            system("Pause");
            return 0; 
        }

        else{
            cout<<"Successfully Logged In!"<<endl;
            system("Pause");
            return 1;
        }
    }
}