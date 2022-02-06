#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <time.h>
using namespace std;

string passwordGenerator(int passlength);

int main()
{
    cout << "Enter Your Password Length" << endl;
    int passlength;
    cin >> passlength;

    while (passlength < 8){
        cout << "Enter a Number Bigger than '8'" << endl;
        cin >> passlength;
    }
    
    string pass = passwordGenerator(passlength);
    cout << "Your Password --->   " << pass << endl;

    system("pause"); // for keep the console until hit a key

    return 1;
}

string passwordGenerator(int passlength)
{
    char character = 'a';
    char charList[50];
    int numberList[9];
    char specialCharList[] = {'!', '#', '@', '$', '%', '^', '&', '*'};
    string password;
    int i = 0;
    int k = 0;
    srand(time(0));

    do
    {
        charList[i] = character;
        charList[i += 1] = toupper(character);
        character++;
        i++;
    } while (character <= 'z');

    while (k <= 9)
    {
        numberList[k] = k;
        k++;
    }

    for (int j = 1; j <= passlength; j++)
    {
        int rnd_r = rand() % 100;

        if (rnd_r <= 33)
        {
            // chars
            int char_r = rand() % 50;
            char p_char = charList[char_r];
            password += p_char;
        }
        else if (rnd_r <= 66 && rnd_r > 33)
        {
            // int 
            int int_r = rand() % 9;
            int p_int = numberList[int_r];
            stringstream ss;
            ss << p_int;
            string st_int_p;
            ss >> st_int_p;
            password += st_int_p;
        }
        else if (rnd_r > 66)
        {
            // Special chars
            int spc_r = rand() % 7;
            char p_spc = specialCharList[spc_r];
            password += p_spc;
        }
    }
    return password;
}
