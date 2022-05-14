#include <iostream>

using namespace std;

//Задание №1.

string encrypt(string text, int key)
{
    string result = "";
    for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+key-65)%26 +65);
        else
            result += char(int(text[i]+key-97)%26 +97);
    }
    return result;
}

string decrypt(string encryptedtext, int key)
{
	string result="";
	for(int i=0;i<encryptedtext.length();i++)
	{
		if(isupper(encryptedtext[i]))
			result += char(int(encryptedtext[i]+key-65)%26 +65);
        else
            result += char(int(encryptedtext[i]+key-97)%26 +97);
	}
	return result;
}

int main()
{
    string text;
    int key;
    cout << "Enter the text: " << endl;
    cin >> text;
    cout << "Enter the key: " << endl;
    cin >> key;
    cout << "The cipher: " << encrypt(text, key);
    cout << "\n";

    string encryptedtext = encrypt(text, key);
	cout << "The cipher: " << encryptedtext << endl;
	cout << "The key: " << key << endl;
	key = key%26;
	cout << "The initial text: " << decrypt(encryptedtext, 26-key);
	cout << "\n";

    return 0;
}



int main()
{
    char word[50];
    char array[100][100];
    int n,m;
    int count = 0;

    cout<<"Enter the word: ";
    cin >> word;
    cout<<"Number of rows: ";
    cin >> n;
    cout<<"Number of columns: ";
    cin >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            array[i][j]=word[count];
            count++;
        }
    }

    cout<<"Encrypted word: ";
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n; i++)
        {
                cout << array[i][j];
        }
    }
    cout << endl;
}



