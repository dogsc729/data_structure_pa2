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
        string temp = numeinput;
        
        fout << input << " "
             << setw(3) << setfill('0') << i
             << " " << numeinput << endl;
    }
    return 0;
}