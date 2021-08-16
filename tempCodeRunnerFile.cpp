#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
using namespace std;

//This is a class which contains the functions for Encryption/
class Encryption
{
public:
    //The xor Cipher Function
    void xorcipher(char input[], char key)
    {
        fstream encfile;
        encfile.open("encrypted.txt", ios::out);
        int len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            input[i] = input[i] ^ key;
            encfile << input[i];
        }
    }

    //Caeser Cipher Function
    void caeser_cipher_enc(char input[], int key)
    {
        fstream encfile;
        encfile.open("encrypted.txt", ios::out);
        char store[200];
        for (int i = 0; i < strlen(input); i++)
        {
            store[i] = (int)input[i] + key;
        }
        for (int i = 0; i < strlen(input); i++)
        {
            encfile << (char)store[i];
        }
    }

    void vigenere_cipher(char str[], string key)
    {
        fstream encfile;
        encfile.open("encrypted.txt", ios::out);
        string encrypted_data;

        for (int i = 0; i < strlen(str); i++)
        {
            char r = (str[i] + key[i]) % 26;
            r += 'A';

            encrypted_data.push_back(r);
        }
        for (int j = 0; j < encrypted_data.size(); j++)
        {
            encfile << encrypted_data[j];
        }
    }

    void image_cipher(string s, int key)
    {
        char c;
        ifstream takefile;
        ofstream showfile;
        takefile.open(s.c_str(), ios::binary);
        s = "edited";
        showfile.open(s.c_str(), ios::binary);

        while (!takefile.eof())
        {
            takefile >> noskipws >> c;
            int temp = (c + key);
            showfile << (char)temp;
        }
        takefile.close();
        showfile.close();
    }
};

//This is a class which contains the functions of Decryption algorithms/
class Decryption
{
public:
    //The xor Cipher Function
    void xorcipher(char input[], char key)
    {
        fstream encfile;
        encfile.open("decrypted.txt", ios::out);
        int len = strlen(input);
        for (int i = 0; i < len; i++)
        {
            input[i] = input[i] ^ key;
            encfile << input[i];
        }
    }

    //The Caeser Cipher Function
    void caeser_cipher_dec(char input[], int key)
    {
        fstream encfile;
        encfile.open("decrypted.txt", ios::out);
        char store[200];
        for (int i = 0; i < strlen(input); i++)
        {
            store[i] = (int)input[i] - key;
        }
        for (int i = 0; i < strlen(input); i++)
        {
            encfile << (char)store[i];
        }
    }

    void vigenere_cipher(char enc_data[], string key)
    {
        fstream encfile;
        encfile.open("decrypted.txt", ios::out);
        string dec_data;
        for (int i = 0; i < strlen(enc_data); i++)
        {
            char x = (enc_data[i] - key[i] + 26) % 26;

            x += 'A';
            dec_data.push_back(x);
        }
        for (int i = 0; i < dec_data.size(); i++)
        {
            encfile << dec_data[i];
        }
    }

    void image_cipher(string s, int key)
    {
        char c;
        ifstream takefile;
        ofstream showfile;
        takefile.open(s.c_str(), ios::binary);
        s = "same";
        showfile.open(s.c_str(), ios::binary);

        while (!takefile.eof())
        {
            takefile >> noskipws >> c;
            int temp = (c - key);
            showfile << (char)temp;
        }
        takefile.close();
        showfile.close();
    }
};

string getkey(string str, string key)
{
    int x = str.size();

    for (int i = 0;; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

// Main Function Starts here....
int main()
{

    Encryption enc;
    Decryption dec;
    string name;

    cout << "Choose the option: \n";
    cout << "1.Text Encryption: \n";
    cout << "2.Binary File Encryption: \n";
    int ch3;
    cin >> ch3;
    if (ch3 == 1)
    {
        cout << "Enter the name of file(with extension): " << endl;
        cin >> name;

        char ch;
        char input[300];

        fstream myfile;
        myfile.open(name, ios::in);

        //Storing the texts from file to an array.
        int i = 0;
        while (!myfile.eof())
        {
            myfile.get(ch);
            input[i] = ch;
            i++;
        }
        // Ciphers Menu
        cout << "Select The Cipher\n";
        cout << "1.XOR Cipher(Encryption)\n";
        cout << "2.XOR Cipher(Decryption)\n";
        cout << "3.Caeser Cipher (Encryption)\n";
        cout << "4.Caeser Cipher (Decryption)\n";
        cout << "5.Vigenre Cipher (Encryption)\n";
        cout << "6.Vigenre Cipher(Decryption)\n";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            char key1;
            cout << "Enter the Key:" << endl;
            cin >> key1;
            enc.xorcipher(input, key1);
        }

        else if (choice == 2)
        {
            char key2;
            cout << "Enter the Key:" << endl;
            cin >> key2;
            dec.xorcipher(input, key2);
        }

        else if (choice == 3)
        {
            int key3;
            cout << "Enter the Key:" << endl;
            cin >> key3;
            enc.caeser_cipher_enc(input, key3);
        }
        else if (choice == 4)
        {
            int key4;
            cout << "Enter the Key:" << endl;
            cin >> key4;
            dec.caeser_cipher_dec(input, key4);
        }
        else if (choice == 5)
        {
            string key5;
            cout << "Enter the Key:" << endl;
            cin >> key5;
            string modified_key = getkey(input, key5);
            enc.vigenere_cipher(input, modified_key);
        }
        else if (choice == 6)
        {
            string key6;
            cout << "Enter the Key:" << endl;
            cin >> key6;
            string modified_key = getkey(input, key6);
            dec.vigenere_cipher(input, modified_key);
        }
    }

    else if (ch3 == 2)
    {
        string nm;
        int ch1;
        int key8;
        cout << "1.Encryption\n";
        cout << "2.Decryption\n";
        cin >> ch1;
        cout << "Enter the name of file\n";
        cin >> nm;
        cout << "Enter the key\n";
        cin >> key8;
        if (ch1 == 1)
        {
            enc.image_cipher(nm, key8);
        }
        else if (ch1 == 2)
        {
            dec.image_cipher(nm, key8);
        }
    }

    return 0;
}

