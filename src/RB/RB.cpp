#pragma once

#include <iostream> 
#include "Node.h"
#include <fstream>
#include <windows.h>

#include "NormalList.h"
void SetColor(int text, int background)
{
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, (WORD)((background << 4) | text));
}

using namespace std;

template<typename T1, typename T2>
class Map {

	Node<T1, T2>* root;

	void leftRotate(Node<T1, T2>* x) {
		Node<T1, T2>* nParent = x->right;
		if (x == root)
			root = nParent;
		x->moveDown(nParent);
		x->right = nParent->left;
		if (nParent->left != NULL)
			nParent->left->parent = x;
		nParent->left = x;

	}

	void rightRotate(Node<T1, T2>* x) {

		Node<T1, T2>* nParent = x->left;
		if (x == root)
			root = nParent;

		x->moveDown(nParent);
		x->left = nParent->right;
		if (nParent->right != NULL)
			nParent->right->parent = x;
		nParent->right = x;

	}

	void swapColors(Node<T1, T2>* x1, Node<T1, T2>* x2) {

		COLOR temp;

		temp = x1->color;

		x1->color = x2->color;

		x2->color = temp;

	}


	void swapkeyues(Node<T1, T2>* u, Node<T1, T2>* v) {

		int temp;

		temp = u->key;

		u->key = v->key;

		v->key = temp;

	}


	void fixRedRed(Node<T1, T2>* newElement) {


		if (newElement == root) {

			newElement->color = BLACK;

			return;

		}

		Node<T1, T2>* parent = newElement->parent, * grandparent = parent->parent,

			* uncle = newElement->uncle();



		if (parent->color != 1) {

			if (uncle != NULL && uncle->color == 0) {


				parent->color = BLACK;

				uncle->color = BLACK;

				grandparent->color = RED;

				fixRedRed(grandparent);

			}
			else {

				// Else perform LR, LL, RL, RR 

				if (parent->isOnLeft()) {

					if (newElement->isOnLeft()) {

						// for left right 

						swapColors(parent, grandparent);

					}
					else {

						leftRotate(parent);

						swapColors(newElement, grandparent);

					}

					// for left left and left right 

					rightRotate(grandparent);

				}
				else {

					if (newElement->isOnLeft()) {

						// for right left 

						rightRotate(parent);

						swapColors(newElement, grandparent);

					}
					else {

						swapColors(parent, grandparent);

					}



					// for right right and right left 

					leftRotate(grandparent);

				}

			}

		}

	}


	Node<T1, T2>* successor(Node<T1, T2>* x) {

		Node<T1, T2>* temp = x;



		while (temp->left != NULL)

			temp = temp->left;



		return temp;

	}



	Node<T1, T2>* BSTreplace(Node<T1, T2>* x) {
		if (x->left != NULL && x->right != NULL)
			return successor(x->right);
		if (x->left == NULL && x->right == NULL)
			return NULL;

		if (x->left != NULL)
			return x->left;
		else
			return x->right;

	}



	void deleteNode(Node<T1, T2>* v) {

		Node<T1, T2>* u = BSTreplace(v);



		// True when u and v are both 1 

		bool uv1 = ((u == NULL || u->color == 1) && (v->color == 1));

		Node<T1, T2>* parent = v->parent;



		if (u == NULL) {

			// u is NULL therefore v is leaf 

			if (v == root) {

				// v is root, making root null 

				root = NULL;

			}
			else {

				if (uv1) {

					// u and v both black 

					// v is leaf, fix double black at v 

					fixDoubleBlack(v);

				}
				else {

					// u or v is 0 

					if (v->sibling() != NULL)

						// sibling is not null, make it 0" 

						v->sibling()->color = RED;

				}



				// delete v from the tree 

				if (v->isOnLeft()) {

					parent->left = NULL;

				}
				else {

					parent->right = NULL;

				}

			}

			delete v;

			return;

		}



		if (v->left == NULL || v->right == NULL) {

			// v has 1 child 

			if (v == root) {

				// v is root, assign the keyue of u to v, and delete u 

				v->key = u->key;

				v->left = v->right = NULL;

				delete u;

			}
			else {

				// Detach v from tree and move u up 

				if (v->isOnLeft()) {

					parent->left = u;

				}
				else {

					parent->right = u;

				}

				delete v;

				u->parent = parent;

				if (uv1) {

					// u and v both 1, fix double 1 at u 

					fixDoubleBlack(u);

				}
				else {

					// u or v 0, color u 1 

					u->color = BLACK;

				}

			}

			return;

		}



		// v has 2 children, swap keyues with successor and recurse 

		swapkeyues(u, v);

		deleteNode(u);

	}



	void fixDoubleBlack(Node<T1, T2>* x) {

		if (x == root)

			// Reached root 

			return;



		Node<T1, T2>* sibling = x->sibling(), * parent = x->parent;

		if (sibling == NULL) {

			// No sibiling, double black pushed up 

			fixDoubleBlack(parent);

		}
		else {

			if (sibling->color == 0) {

				// Sibling red

				parent->color = RED;

				sibling->color = BLACK;

				if (sibling->isOnLeft()) {

					// left case 

					rightRotate(parent);

				}
				else {

					// right case 

					leftRotate(parent);

				}

				fixDoubleBlack(x);

			}
			else {

				// Sibling 1 

				if (sibling->has0Child()) {

					// at least 1 0 children 

					if (sibling->left != NULL && sibling->left->color == 0) {

						if (sibling->isOnLeft()) {

							// left left 

							sibling->left->color = sibling->color;

							sibling->color = parent->color;

							rightRotate(parent);

						}
						else {

							// right left 

							sibling->left->color = parent->color;

							rightRotate(sibling);

							leftRotate(parent);

						}

					}
					else {

						if (sibling->isOnLeft()) {

							// left right 

							sibling->right->color = parent->color;

							leftRotate(sibling);

							rightRotate(parent);

						}
						else {

							// right right 

							sibling->right->color = sibling->color;

							sibling->color = parent->color;

							leftRotate(parent);

						}

					}

					parent->color = BLACK;

				}
				else {

					// 2 1 children 

					sibling->color = RED;

					if (parent->color == 1)

						fixDoubleBlack(parent);

					else

						parent->color = BLACK;

				}

			}

		}

	}


public:


	Map() { root = NULL; }

	~Map() { clear(root); 
	root = NULL;
	};

	Node<T1, T2>* getRoot() { return root; }
 

	Node<T1, T2>* find(T1 n) {

		Node<T1, T2>* temp = root;

		while (temp != NULL) {

			if (n < temp->key) {

				if (temp->left == NULL)

					break;

				else

					temp = temp->left;

			}
			else if (n == temp->key) {

				break;

			}
			else {

				if (temp->right == NULL)

					break;

				else

					temp = temp->right;

			}

		}



		return temp;

	}


	void insert(T1 key, T2 data) {

		Node<T1, T2>* newNode = new Node<T1, T2>(key, data);

		if (root == NULL) {

 

			newNode->color = BLACK;

			root = newNode;

		}
		else {

			Node<T1, T2>* temp = find(key);



			/*if (temp->key == key) {

				temp->data= (temp->data + 1);
				return;

			}*/



			newNode->parent = temp;



			if (key < temp->key)

				temp->left = newNode;

			else

				temp->right = newNode;

 

			fixRedRed(newNode);

		}

	}


	void remove(T1 n) {

		if (root == NULL)
			// Tree is empty 

			return;

		Node<T1, T2>* v = find(n), * u;

		if (v->key != n) {

			cout << "No Node<T1, T2> found to delete with keyue:" << n << endl;

			return;

		}

		deleteNode(v);

	}


	void print(Node<T1, T2>* root, int lvl)
	{
		if (root != NULL)
		{

			print(root->right, lvl + 2);

			for (int i = 0; i < lvl; i++)
			{

				cout << "  ";
			}
			if (root->parent != NULL && root->parent->key >= root->key)
			{
				if (root->color == 0)
					SetColor(12, 0);
				else
					SetColor(9, 0);
				cout << "\\" << root->data;
				
				cout << endl;
			}
			else if (root->parent != NULL && root->parent->key < root->key)
			{
				if (root->color == 0)
					SetColor(12, 0);
				else
					SetColor(9, 0);
				cout << "/" << root->data;
				
				cout << endl;
			}
			else
			{
				
					SetColor(9, 0);
				cout << root->data;
			}

			cout << endl;


			print(root->left, lvl + 2);
		}
	}


	List<T1>* getListKey(Node<T1, T2>* root, List<T1>* A)
	{
		if (root)
		{
			getListKey(root->left, A);
			getListKey(root->right, A);
			A->push_back(root->key);

		}
		return A;
	}

	List<T2>* getListData(Node<T1, T2>* root, List<T2>* A)
	{
		if (root)
		{
			getListData(root->left, A);
			getListData(root->right, A);
			A->push_back(root->data);
		}
		return A;
	}
	
	void printListKey(List<T1>* list)
	{
		while (!list->isEmpty())
		{
			cout << list->at(0) << " ";
			list->pop_front();
		}
	}

	void printListData(List<T2>* list)
	{
		while (!list->isEmpty())
		{
			cout << list->at(0) << " ";
			list->pop_front();
		}
	}

	void clear(Node<T1,T2>* root)
	{
		if (root)
		{
			clear(root->left);
			clear(root->right);
			 delete root;
		}
	}

};


int main() {

	Map<char, int> map;

	ifstream input;
	input.open("input.txt");

	char ch;

	while (!input.eof())
	{
		input.get(ch);
		map.insert(ch, 1);
	}
	
	map.print(map.getRoot(), 0);

	map.printListKey(map.getListKey(map.getRoot(), new List<char>));
	cout << endl;
	map.printListData(map.getListData(map.getRoot(), new List<int>));

	return 0;
}