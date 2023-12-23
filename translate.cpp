#include <bits/stdc++.h>
using namespace std;
string decode(string &s, map<string, char> &m)
{
    stringstream ss(s);
    cout << s << endl;
    string sentence = "";
    string token;
    vector<string> tokens;
    while (getline(ss, token, ' '))
    {
        // check if the token is /
        if (token == "/")
            sentence += " ";
        else
            sentence += m[token];
    }
    return sentence;
}
string encode(string &s, map<char, string> &m)
{
    string sentence = "";
    for (char c : s)
    {
        if (!isupper(c))
            c = toupper(c);
        //add spaces
        if (c == ' ')
        {
            sentence += "/";
        }
        else sentence += m[c];
        sentence += " ";
    }
    sentence = sentence.substr(0, sentence.length() - 1);
    return sentence;
}
map<char, string> getCharStringMap()
{
    map<char, string> m;
    ifstream inp("letters.txt");
    if (!inp.is_open())
    {
        cerr << "error opening the file" << endl;
        exit(1);
    }
    string line;
    while (getline(inp, line))
    {
        stringstream ss(line);
        char alphabet;
        string morseCode;
        ss >> alphabet >> morseCode;
        m[alphabet] = morseCode;
    }
    inp.close();
    return m;
}
map<string, char> getStringCharMap()
{
    map<string, char> m;
    ifstream inp;
    inp.open("decode.txt");
    if (!inp.is_open())
    {
        cerr << "error" << endl;
        exit(1);
    }
    string line;
    while (getline(inp, line))
    {
        stringstream ss(line);
        char alphabet;
        string morseCode;
        ss >> morseCode >> alphabet;
        m[morseCode] = alphabet;
    }
    inp.close();
    return m;
}
void init()
{
    map<char, string> charString;
    charString = getCharStringMap();
    map<string, char> stringChar;
    stringChar = getStringCharMap();
    string s;
    getline(cin, s);

    string original = s;
    if (s.empty())
        cerr << "enter a valid string" << endl;
    // if (s[0] == '.' || s[0] == '-')
    // {
    //     string check = decode(s, stringChar);
    //     cout<<"decoded: "<<check<<endl;
    //     check = encode(check, charString);
    //     cout<<check<<"\n"<<original;
    //     if (original == check)
    //         cout << "abboo!" << endl;
    //     else
    //         cout << "wrong sucker!" << endl;
    // }
    // else
    // {
    //     for(char &c:s){
    //         if(!isupper(c))c=toupper(c);
    //     }
    //     original=s;
    //     string encoded = encode(s, charString);
    //     cout<<"encoded: "<<encoded<<endl;
    //     encoded = decode(encoded, stringChar);
    //     if (encoded == original)
    //         cout << "abboo!" << endl;
    //     else
    //         cout << "wrong sucker!" << endl;
    // }
    for (char &c : s)
    {
        if (!isupper(c))
            c = toupper(c);
    }
    s = (s[0] == '.' || s[0] == '-') ? decode(s, stringChar) : encode(s, charString);
    cout << s << endl;
}
int main()
{
    init();
    // run();

    return 0;
}