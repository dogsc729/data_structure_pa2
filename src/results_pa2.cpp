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
struct saltpassword
{
    string password;
    string salt;
    string hash_value;
};
vector<saltpassword> dictionary;
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
    fout.close();
    fstream fin2("./inputs/list_pa2.txt"), fout2;
    fout2.open("./outputs/results_pa2.txt", ios::out);
    string target_hashvalue;
    while (fin2 >> target_hashvalue)
    {
        int i;
        for (i = 0; i < hash_value.size(); i++)
        {
            if (target_hashvalue == hash_value[i])
            {
                fout2 << std::right << target_hashvalue << " " << passwordset[i] << " " << setw(3) << setfill('0') << (i % 1000) << " " << i+1 << endl;
                break;
            }
        }
        if (i == 100000)
        {
            fout2 << std::right << setw(8) << target_hashvalue << " "
                  << "******"
                  << " " << setw(3) << setfill('0') << "***"
                  << " "
                  << "100000" << endl;
        }
    }
    fout2.close();
    return 0;
}