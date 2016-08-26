#pragma once
#include<iostream>


using namespace std;


enum Color
{
	RED,
	BLACK
};


template<class K,class V>
struct RBTreeNode
{
	K _key;
	V _value;
	Color _col;
	RBTreeNode<K, V> *_left;
	RBTreeNode<K, V> *_right;
	RBTreeNode<K, V> *_parent;
	RBTreeNode(const K& key,const V& value)
		:_key(key)
		,_value(value)
		,_col(RED)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{

	}
};



template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}

	bool IsBlance()
	{
		if (_root->_col == RED)
		{
			return false;
		}
		int k = 0;
		int count = 0;
		return _IsBlance(_root, count, k);
	}
	bool _IsBlance(Node *root, int count, int &k)
	{
		if (root == NULL)
		{
			return true;
		}
		if (root->_col == BLACK)
		{
			count++;
		}
		if (root->_left == NULL && root->_right == NULL)
		{
			if (k == 0)
			{
				k = count;

			}
			else 
			{
				if (k != count)
				{
					return false;
				}
			}
		}
	
		return _IsBlance(root->_left, count, k) && _IsBlance(root->_right, count, k);
	}

	bool Insert(const K& key, const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}
		Node *cur = _root;
		Node *parent = NULL;
		while (cur)
		{
			parent = cur;
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (parent->_key > key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		//开始讨论三种情况
		while (cur != _root && parent->_col == RED)
		{
			Node *grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node *uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
				}
				else
				{
					if (parent->_right == cur)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			else
			{
				Node *uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
				}
				else
				{
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	Node *Find()
	{
		return NULL
	}

private:
	void RotateL(Node *parent)
	{
		Node *pp = parent->_parent;
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;
		subR->_parent = pp;
		if (pp == NULL)
		{
			_root = subR;
		}
		else
		{
			if (pp->_key > subR->_key)
			{
				pp->_left = subR;
			}
			else
			{
				pp->_right = subR;
			}
		}
	}
	void RotateR(Node *parent)
	{
		Node *pp = parent->_parent;
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		parent->_parent = subL;
		subL->_parent = pp;
		if (pp == NULL)
		{
			_root = subL;
		}
		else
		{
			if (pp->_key > subL->_key)
			{
				pp->_left = subL;
			}
			else
			{
				pp->_right = subL;
			}
		}
	}

private:
	Node *_root;
};


void testRBTree()
{
	RBTree<int, int> r;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); ++i)
	{
		r.Insert(a[i], a[i]);
	}
	cout << "Is Balance ?" << r.IsBlance() << endl;
}