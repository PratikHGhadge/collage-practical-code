#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int _data)
    {
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Bst
{
public:
    void incertNode(Node *root)
    {
        int tempData;
        cout << "Enter data for incert :";
        cin >> tempData;
        Node *temp = root;
        while (temp != NULL)
        {
            if (tempData < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node(tempData);
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node(tempData);
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void search(Node *root)
    {
        int key;
        cout << "Enter Key for search : ";
        cin >> key;
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Key is present " << endl;
                return;
            }
            else if (key > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        cout << "key is not Present " << endl;
    }

    void max(Node *root)
    {
        Node *temp = root;
        if (temp->right == NULL)
        {
            cout << "Max = " << temp->data;
            return;
        }
        max(temp->right);
    }

    void min(Node *root)
    {
        Node *temp = root;
        if (temp->left == NULL)
        {
            cout << "Min = " << temp->data;
            return;
        }
        min(temp->left);
    }

    int height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return left + right + 1;
    }

    void mirror(Node *root)
    {
        Node *temp;
        if (root != NULL)
        {
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            mirror(root->left);
            mirror(root->right);
        }
    }

    void Delete(Node *root){
        int key;
        cout<<"Enter key to delete :";
        cin>>key;
    }
};
int main()
{
    int ch, ans;
    Bst obj = Bst();
    int data;
    cout << "Enter a data for root Node :";
    cin >> data;
    Node *root = new Node(data);
    cout << "********************************* BST ************************" << endl;
    do
    {
        cout << "1 incert Node " << endl;
        cout << "2 Inorder " << endl;
        cout << "3 Preorder " << endl;
        cout << "4 PostOrder " << endl;
        cout << "5 Search Key " << endl;
        cout << "6 Max" << endl;
        cout << "7 Min " << endl;
        cout << "8 height " << endl;
        cout << "9 mirror " << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            obj.incertNode(root);
            break;
        }
        case 2:
        {
            obj.inorder(root);
            break;
        }
        case 3:
        {
            obj.preorder(root);
            break;
        }
        case 4:
        {
            obj.postorder(root);
            break;
        }
        case 5:
        {
            obj.search(root);
            break;
        }
        case 6:
        {
            obj.max(root);
            break;
        }
        case 7:
        {
            obj.min(root);
            break;
        }
        case 8:
        {
            int h = obj.height(root);
            cout<<" Height = "<<h<<endl;
            break;
        }
        case 9:
        {
            obj.mirror(root);
            break;
        }
        case 10:
        {
            obj.Delete(root);
            break;
        }
        }
        cout << endl
             << "Do you want to continue :";
        cin >> ans;
    } while (ans == 1);
}