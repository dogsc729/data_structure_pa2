#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <new>
#include <ctime>
#include <map>
#include <iomanip>

using namespace std;

long Hashfunction(long left, long right)
{
    long hashvalue;
    hashvalue = ((243 * left) + right) % 85767489;
    return hashvalue;
}
int main()
{
    cout << "please enter the name of the passwordfile!" << endl;
    string input;
    cin >> input;
    fstream fin("./inputs/password.txt"), fout;
    fout.open("./outputs/Dictionary.txt", ios::out);
    string password;
    //read password.txt and output dictionary.txt
    vector<string> passwordset;
    vector<string> salt;
    vector<string> hash_value;
    while (fin >> password)
    {
        string numepassword;
        //transform the password to numeric value
        for (int i = 0; i < password.size(); i++)
        {
            numepassword = numepassword + to_string(int(password[i]));
        }
        for (int i = 0; i < 1000; i++)
        {
            passwordset.push_back(password);
            string temp;
            if (i < 10)
            {
                temp = "00" + to_string(i) + numepassword;
                salt.push_back(temp);
            }
            else if (i < 100)
            {
                temp = "0" + to_string(i) + numepassword;
                salt.push_back(temp);
            }
            else
            {
                temp = to_string(i) + numepassword;
                salt.push_back(temp);
            }
            long left = stol(temp.substr(0, 8));
            long right = stol(temp.substr(8));
            long hashvalue = Hashfunction(left, right);
            hash_value.push_back(to_string(hashvalue));
            fout << password << " "
                 << setw(3) << setfill('0') << i
                 << " " << hashvalue << endl;
        }
    }
    cout << "please enter a hash value" << endl;
    string target_hashvalue;
    cin >> target_hashvalue;
    while (target_hashvalue != "STOP")
    {
        int i;
        for (i = 0; i < hash_value.size(); i++)
        {
            if (target_hashvalue == hash_value[i])
            {
                cout << "the password is recovered!" << endl;
                cout << "the password is " << passwordset[i] << endl;
                cout << "the number of entries has been searched:" << i + 1 << endl;
                break;
            }
        }
        if (i == 100000)
        {
            cout << "the password is not found!" << endl;
            cout << "the number of entries has been searched:100000" << endl;
        }
        cout << "please enter a hash value" << endl;
        cin >> target_hashvalue;
    }
    /*//transform the password to numeric value
    for (int i = 0; i < input.size(); i++)
    {
        numeinput = numeinput + to_string(int(input[i]));
    }
    for (int i = 0; i < 1000; i++)
    {
        string temp;
        if (i < 10)
        {
            temp = "00" + to_string(i) + numeinput;
        }
        else if (i < 100)
        {
            temp = "0" + to_string(i) + numeinput;
        }
        else
        {
            temp = to_string(i) + numeinput;
        }
        long left = stol(temp.substr(0, 8));
        long right = stol(temp.substr(8));
        fout << input << " "
             << setw(3) << setfill('0') << i
             << " " << Hashfunction(left, right) << endl;
    }*/
    return 0;
}