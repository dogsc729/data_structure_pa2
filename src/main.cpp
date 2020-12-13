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
    fstream fin("./inputs/password.txt"), fout;
    fout.open("./outputs/dictionary.txt", ios::out);
    string password;
    vector<string> passwordset;
    /*while (fin >> password)
    {
        passwordset.push_back(password);
        fout << password << endl;
    }*/
    cout << "please enter a password!" << endl;
    string input;
    string numeinput;
    cin >> input;
    //transform the password to numeric value
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
        long left = stol(temp.substr(0,8));
        long right = stol(temp.substr(8));
        fout << input << " "
             << setw(3) << setfill('0') << i
             << " " << Hashfunction(left,right) << endl;
    }
    return 0;
}