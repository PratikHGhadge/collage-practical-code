#include <iostream>
using namespace std;
class node
{
public:
    int data, lb, rb;
    node *right, *left;
};
class TBT
{
public:
    void create(node *head);
    void inorder(node *head);
};
void TBT::create(node *head)
{
    node *root, *ne, *temp;
    char ans, ans1;
    root = new node;
    cout << "enter a root dta\t:";
    cin >> root->data;
    root->left = head;
    root->right = head;
    root->lb = 0;
    root->rb = 0;
    head->left = root;
    head->lb = 1;
    do
    {
        ne = new node;
        cout << "enter a new data\t:";
        cin >> ne->data;
        ne->left = ne->right = NULL;
        ne->lb = 0;
        ne->rb = 0;
        temp = root;

        while (1)
        {
            cout << "enter left or right of\t:" << temp->data << "\t:";
            cin >> ans;
            if (ans == 'l')
            {
                if (temp->lb == 0)
                {
                    ne->left = temp->right;
                    ne->right = temp;
                    temp->left = ne;
                    temp->lb = 1;
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->rb == 0)
                {
                    ne->right = temp->right;
                    ne->left = temp;
                    temp->right = ne;
                    temp->rb = 1;
                    break;
                }
                else
                    temp = temp->right;
            }
        }
        cout << "do u want to perform other operation\t:";
        cin >> ans1;
    } while (ans1 == 'y');
}
void TBT::inorder(node *head)
{
    node *temp;
    temp = head->left;
    while (temp != head)

    {
        while (temp->lb == 1)
        {
            temp = temp->left;
        }
        cout << " " << temp->data << " ";
        while (temp->rb == 0)
        {
            temp = temp->right;
            if (temp == head)
            {
                break;
            }
            cout << " " << temp->data << " ";
        }
        temp = temp->right;
    }
}
int main()
{
    TBT t;
    int ch;
    node *head;
    while (1)
    {
        cout << "\n 1)creat 2)inorder \n";
        cout << "\nenter your choice\t:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            head = new node;
            head->lb = 0;
            head->rb = 1;
            head->left = head;
            head->right = head;
            t.create(head);
            break;

        case 2:
            t.inorder(head);
            break;
        }
    }
    return 0;
}