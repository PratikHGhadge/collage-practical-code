#include <iostream>
using namespace std;
class Node
{
public:
    string key;
    string value;
    Node *left;
    Node *right;

    Node()
    {
        key = "";
        value = "";
        left = NULL;
        right = NULL;
    }

    Node(string _key, string _value)
    {
        this->key = _key;
        this->value = _value;
        left = NULL;
        right = NULL;
    }

    Node(string _key, string _value, Node *_left, Node *_right)
    {
        this->key = _key;
        this->value = _value;
        left = _left;
        right = _right;
    }
};
class dict
{
public:
    void incert(Node *root)
    {
        string key, meaning;
        cout << "Enter key for Dictionary : ";
        cin >> key;
        cout << "Enter meaning : ";
        cin >> meaning;
        Node *temp = root;
        while (temp != NULL)
        {
            if (key > temp->value)
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node(key, meaning);
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node(key, meaning);
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
    }
    Node *Delete(Node *root, string key)
    {
        if (root == NULL)
            return root;

        if (key < root->value)
            root->left = Delete(root->left, key);
        else if (key > root->value)
            root->right = Delete(root->right, key);
        else
        {
            if (root->left == NULL and root->right == NULL)
                return NULL;
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            Node *temp = low_node(root->right);
            root->value = temp->value;
            root->right = Delete(root->right, temp->value);
        }
        return root;
    }
    Node *low_node(Node *root)
    {
        Node *temp = root;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    void update(Node *root, string _key, string _val)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->key == _key)
        {
            root->value = _val;
            return;
        }
        if (_key < root->value)
        {
            update(root->left, _key, _val);
        }
        else
        {
            update(root->right, _key, _val);
        }
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << " key = " << root->key << " value = " << root->value << endl;
        inorder(root->right);
    }
};
int main()
{

    int ans, ch;
    string key, meaning;
    cout << "Enter key for Dictionary : ";
    cin >> key;
    cout << "Enter meaning : ";
    cin >> meaning;
    Node *root = new Node(key, meaning);
    dict obj = dict();
    do
    {
        cout << "----------- Dictionary BST -------------" << endl;

        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Update" << endl;
        cout << "4. Inorder" << endl;

        cout << "Enter Your choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            obj.incert(root);
            cout << "Data is added succesfully! " << endl;
            break;
        }
        case 2:
        {
            string key;
            cout << "Enter Key :";
            cin >> key;
            obj.Delete(root, key);
            break;
        }
        case 3:
        {
            string key;
            string val;
            cout << "Enter Key :";
            cin >> key;
            cout << "Enter value :";
            cin >> val;
            obj.update(root, key, val);
            break;
        }
        case 4:
        {
            obj.inorder(root);
            break;
        }
        }
        cout << "Do You Want to continue :";
        cin >> ans;
    } while (ans == 1);
}