#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <math.h>
using namespace std;


class Node
{
public:
	int data;
	Node *left;
	Node *right;
};


size_t _size_tree = 0;


Node* consTreeUtil(vector<int>& pre, vector<int>::iterator& it, vector<int>::iterator key, int min, int max)
{
	if (it == pre.end())
		return NULL;

	Node* root = NULL;

	if (*key > min && *key < max)
	{
		Node* temp = new Node;
		temp->data = *key;
		temp->left = temp->right = NULL;
		root = temp;
		_size_tree++;
		it++;

		if (it != pre.end())
		{
			root->left = consTreeUtil(pre, it, it, min, *key);
			root->right = consTreeUtil(pre, it, it, *key, max);
		}
	}
	return root;
}

Node *consTree(vector<int>& pre)
{
	vector<int>::iterator it = pre.begin();
	return consTreeUtil(pre, it, it, INT_MIN, INT_MAX);
}

int main()
{
	ifstream fin("date.in");
	string str;
	vector<int> elem;
	std::getline(fin, str);
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;

	while ((pos = str.find(delimiter)) != std::string::npos)
	{
		token = str.substr(0, pos);
		if (token != "null")
			elem.push_back(atoi(token.c_str()));
		str.erase(0, pos + delimiter.length());
	}

	Node *root = consTree(elem);

	if (_size_tree == elem.size())
		cout << "Este arbore binar de cautare" << endl;
	else cout << "Nu este arbore binar de cautare" << endl;


	int ch;
	cin>>ch;
	return 0;
}
