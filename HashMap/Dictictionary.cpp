#include <iostream>
using namespace std;
class Dictionary
{
public:
    string word;
    string meaning;
    Dictionary(string _word, string _meaning)
    {
        this->word = _word;
        this->meaning = _meaning;
    }
    Dictionary()
    {
        word = "#";
        meaning = "#";
    }

    bool isEmpty()
    {
        return word == "#" && meaning == "#";
    }
};

class Database
{
protected:
    int hashing(string word)
    {
        int lastchar = word[word.size() - 1] - '0';
        return lastchar % size;
    }
    int size = 10;
    Dictionary *map = new Dictionary[size];

public:
    void add()
    {
        string _word, _meaning;
        cout << "enter word to add ";
        cin >> _word;
        cout << "Enter meaning of word ";
        cin >> _meaning;
        Dictionary ne = Dictionary(_word, _meaning);
        int index = hashing(_word);
        if (map[index].isEmpty())
        {
            map[index] = ne;
            cout << "word added successfully! " << endl;
            return;
        }
        else
        {
            int temp = (index + 1) % size;
            if (map[temp].isEmpty())
            {
                map[temp] = ne;
                cout << "word added successfully! " << endl;
                return;
            }
            else
            {
                temp = (temp + 1) % size;
            }
        }
        cout << "Map is full " << endl;
    }

    void search()
    {
        string _word;
        cout << "enter word to search ";
        cin >> _word;
        int index = hashing(_word);
        if (map[index].word == _word)
        {
            cout << "Word is Present " << endl;
            cout << "Word = " << map[index].word << " Meaning = " << map[index].meaning << endl;
            return;
        }
        else
        {
            int temp = (index + 1) % size;
            if (map[temp].word == _word)
            {
                cout << "Word is Present " << endl;
                cout << "Word = " << map[temp].word << " Meaning = " << map[temp].meaning << endl;
                return;
            }
            else
            {
                temp = (temp + 1) % size;
            }
        }
        cout << "Word is not Present " << endl;
    }

    void Delete()
    {
        string _word;
        cout << "enter word to delete ";
        cin >> _word;
        int index = hashing(_word);
        if (map[index].word == _word)
        {
            map[index] = Dictionary();
            return;
        }
        else
        {
            int temp = (index + 1) % size;
            if (map[temp].word == _word)
            {
                map[temp] = Dictionary();
                return;
            }
            else
            {
                temp = (temp + 1) % size;
            }
        }
        cout << "Word is not Present " << endl;
    }
};
int main()
{
    int ans, ch;
    Database obj = Database();
    do
    {
        cout << "1 Add a word " << endl;
        cout << "2 delete a word " << endl;
        cout << "3 search a word " << endl;
        cout << "Enter Your choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            obj.add();
            break;
        }
        case 2:
        {
            obj.Delete();
            break;
        }
        case 3:
        {
            obj.search();
            break;
        }
        }
        cout << "Do you want to continue :";
        cin >> ans;
    } while (ans == 1);

    return 0;
}