#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <cstdlib> 
#include <utility>

using namespace std;
string alphaString = " AaBbCcDdEeFfGgHhIiJjKkLlmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789!':@[$%^*.,';(#}_-&{+)=]|?";
int length = alphaString.size();

void decrypt(vector <int> key, string s)
{
    vector <char> alphaVec;
    vector <int> pos_of_letters;
    vector <char> decryption;

    for (int i = 0; i < length; i++)
    {
        alphaVec.push_back(alphaString[i]);
    }

    
    

    for (int j = 0; j < (int) alphaVec.size(); j++)
    {
        for (int k = 0; k < (int) s.size(); k++)
        {
            size_t pos = alphaString.find(s[k]);
            //cout << pos << " ";
            pos_of_letters.push_back(pos);
        }
        break;
    }

    for (int i = 0; i < (int) s.size(); i++)
    {
        int together = pos_of_letters[i] - key[i];
        if(together < 0) together = 88 - (key[i] - (pos_of_letters[i] + 1)) ;
        //cout << alphaVec[together];
        decryption.push_back(alphaVec[together]);
    }
    string decrypted(decryption.begin(), decryption.end());
    
    
    cout << "DECRPYTED: " << decrypted << endl << endl;
}

void encrypt(string message)
{
    
    vector <int> publicKey;
    vector <int> pos_of_letters;
    vector <char> encryption;
    vector <string> encryptKey;
    vector <char> alphaVec;
   

    for (int i = 0; i < length; i++)
    {
        alphaVec.push_back(alphaString[i]);
    }

    srand(time(0));

    //Creates a public key
    for (int i = 0; i < (int) message.size() ; i++)
    {
        int rando = rand() % 10;
        publicKey.push_back(rando);
    }
   
    
    //Finds the positions of the characted of the message
    for (int j = 0; j < (int) alphaVec.size(); j++)
    {
        for (int k = 0; k < (int) message.size(); k++)
        {
            size_t pos = alphaString.find(message[k]);
            //cout << pos << " ";
            pos_of_letters.push_back(pos);
        }
        break;
    }

    //Creates encryption    
    for (int i = 0; i < (int) message.size(); i++)
    {
        int together = pos_of_letters[i] + publicKey[i];
        if(together > 88) together = publicKey[i] - (89 - pos_of_letters[i]) ;
        //cout << alphaVec[together];
        encryption.push_back(alphaVec[together]);
    }
    string encrypted(encryption.begin(), encryption.end());
    
    
    cout << endl << "ENCRYPTION: " << encrypted << endl;

    cout << "KEY: " ;
    for (int i = 0; i < (int) publicKey.size(); i++)
    {
        cout << publicKey[i];
        // encryptKey.push_back(key[i]);
    }

    

    //decrypt(key, encrypted);
    
    

}

int main()
{

    while(true){

        for (int i = 0; i < 5; i++)
        {
           cout << endl;
        }
        

        cout << "C++ Encryption" << endl << endl;
        cout << "0. Quit" << endl;
        cout << "1. Encrypt " << endl;
        cout << "2. Decrypt " << endl;
        cout << "> ";
        string option;
        getline(cin, option);

        if (option.compare("0") == 0) {
            break;
        } else if(option.compare("1") == 0){
            string message;
            cout << "Enter message: ";
            // cin >> message;
            // cin.ignore();
            getline(cin,message);
            encrypt(message);
        } else if(option.compare("2") == 0){
            string encryption;
            string key;
            vector <int> keyVec;

            cout << "Enter encryption: ";
            cin >> encryption;
            cout << "Enter key: ";
            cin >> key;
            cin.ignore();
            cout << endl;

            for (int i = 0; i < (int) key.size(); i++)
            {
                int n = key[i] - '0';
                keyVec.push_back(n);
            }

            decrypt(keyVec, encryption);
            
        }
    
    }

    return 0;
}