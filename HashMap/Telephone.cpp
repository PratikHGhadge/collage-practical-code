#include <iostream>
using namespace std;
class Telephone
{
public:
    string name;
    long long number;
    Telephone(string _name, long long _number)
    {
        this->name = _name;
        this->number = _number;
    }

    Telephone()
    {
        name = "";
        number = 0;
    }

    bool isEmpty()
    {
        return name == "" && number == 0;
    }
};

class database
{
protected:
    int hashing(long long num)
    {
        return num % size;
    }

public:
    int size = 10;
    Telephone *map = new Telephone[size];

    void add()
    {
        string _name;
        long long _num;
        cout << "Enter Name:";
        cin >> _name;
        cout << "Enter number :";
        cin >> _num;
        Telephone temp = Telephone(_name, _num);
        int index = hashing(_num);
        if (map[index].isEmpty())
        {
            map[index] = temp;
            cout << "RECORD ADDED SUCCESFULLY" << endl;
            return;
        }
        else
        {
            int temp1 = (index + 1) % size;
            while (temp1 != index)
            {
                if (map[temp1].isEmpty())
                {
                    map[temp1] = temp;
                    cout << "RECORD ADDED SUCCESFULLY" << endl;
                    return;
                }
                else
                {
                    temp1 = (temp1 + 1) % size;
                }
            }
        }
        cout << "MAP IS FULL" << endl;
    }

    void search()
    {
        long long _num;
        cout << "Enter Number for search :";
        cin >> _num;
        int index = hashing(_num);
        if (map[index].number == _num)
        {
            cout << "Number is present " << endl;
            cout << "Name = " << map[index].name;
            cout << "Number = " << map[index].number;
            return;
        }
        else
        {
            int temp = (index + 1) % size;
            while (temp != index)
            {
                if (map[temp].number == _num)
                {
                    cout << "Number is present " << endl;
                    cout << "Name = " << map[temp].name;
                    cout << "Number = " << map[temp].number;
                    return;
                }
                else{
                    temp = (temp+1)%size;
                }
            }
        }
        cout<<"Number is not Present "<<endl;
    }
};
int main()
{
    int ans, ch;
    database dbt = database();
    do
    {
        cout << " 1 Add Data " << endl;
        cout << " 2 Search Data " << endl;
        cout << "Enter your choice :";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            dbt.add();
            break;
        }
        case 2:
        {
            dbt.search();
            break;
        }
        }
        cout << "Do you want to continue :" << endl;
        cin >> ans;
    } while (ans == 1);
}