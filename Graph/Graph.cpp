#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int _data)
	{
		this->data = _data;
		this->next = NULL;
	}
};
class Graph
{
	int ne, nv, r, c;
	int matrix[10][10];
	int edge[10][2];
	Node *head[10];

public:
	void Adj_Matrix()
	{
		cout << "Enter Number of vertices and Edges : ";
		cin >> nv >> ne;
		for (int i = 0; i < nv; i++)
		{
			for (int j = 0; j < nv; j++)
			{
				matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < ne; i++)
		{
			cout << "Enter Start vertex and end vertex of edge : ";
			cin >> edge[i][0] >> edge[i][1];
		}
		for (int i = 0; i < ne; i++)
		{
			r = edge[i][0];
			c = edge[i][1];
			matrix[r][c] = 1;
		}
		cout << "ADJ_Matrix is :" << endl;
		for (int i = 0; i < nv; i++)
		{
			for (int j = 0; j < nv; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Adj_List()
	{
		Node *temp, *n, *print;
		for (int i = 0; i < nv; i++)
		{
			head[i] = new Node(i);
			head[i]->next = NULL;
		}
		for (int i = 0; i < ne; i++)
		{
			r = edge[i][0];
			c = edge[i][1];
			n = new Node(c);
			temp = head[r];
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
		cout << "*************Adj_List is****************" << endl;
		for (int i = 0; i < nv; i++)
		{
			print = head[i];
			while (print != NULL)
			{
				cout << print->data << " --> ";
				print = print->next;
			}
			cout << endl;
		}
	}
};
int main()
{
	int ch, ans;
	Graph obj = Graph();
	cout << "*****************Graph******************" << endl;
	do
	{
		cout << "1 Adj_Matrix" << endl;
		cout << "2 Adj_List" << endl;
		cout << "Enter Your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			obj.Adj_Matrix();
			break;
		}
		case 2:
		{
			obj.Adj_List();
			break;
		}
		}
		cout << "Do you want to continue : ";
		cin >> ans;
	} while (ans == 1);
	return 0;
}