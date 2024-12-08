#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T item = T();

		Node* left = nullptr;
		Node* right = nullptr;

		// 참고: prev/next가 아니라 left/right
	};

	DoublyLinkedList()
	{
	}

	DoublyLinkedList(const DoublyLinkedList& list)
	{
		Node* p = list.first_;

		while (p != nullptr)
		{
			PushBack(p->item);
			p = p->right;
		}
	}

	~DoublyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		assert(first_->left == nullptr);

		// TODO:
		while (first_ != nullptr)
		{
			PopFront();
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr; // TODO:
	}

	int Size()
	{
		assert(first_->left == nullptr);

		int size = 0;

		// TODO:
		Node* p = first_;
		
		while (p != nullptr)
		{
			++size;
			p = p->right;
		}

		return size;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << endl;

			cout << " Forward: ";
			while (current->right != nullptr)
			{
				cout << current->item << " -> ";
				current = current->right;
			}
			cout << current->item;
			// TODO:
			cout << endl;

			cout << "Backward: ";
			// TODO:
			while (current->left != nullptr)
			{
				cout << current->item << " -> ";
				current = current->left;
			}
			cout << current->item;
			cout << endl;
		}
	}

	Node* Find(T item)
	{
		Node* p = first_;

		while (p != nullptr)
		{
			if (p->item == item)
			{
				return p;
			}

			p = p->right;
		}

		return nullptr; // TODO:
	}

	void InsertBack(Node* node, T item)
	{
		if (IsEmpty())
		{
			PushBack(item);
		}
		else
		{
			// TODO:
			Node* new_node = new Node;
			new_node->item = item;
			new_node->right = node->right;
			new_node->left = node;

			node->right->left = new_node;
			node->right = new_node;
		}
	}

	void PushFront(T item)
	{
		// TODO:
		Node* new_node = new Node;
		new_node->item = item;
		new_node->left = nullptr;
		new_node->right = first_;

		if (first_ != nullptr)
		{
			first_->left = new_node;
		}
		first_ = new_node;
	}

	void PushBack(T item)
	{
		// TODO:
		if (IsEmpty())
		{
			PushFront(item);
		}

		Node* p = first_;
		while (p->right != nullptr)
		{
			p = p->right;
		}

		Node* new_node = new Node;
		new_node->item = item;
		new_node->right = nullptr;
		new_node->left = p;

		p->right = new_node;
	}

	void PopFront()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopFront()" << endl;
			return;
		}

		assert(first_);

		// TODO:
		Node* temp = first_;
		first_ = first_->right;
		if (first_ != nullptr)
		{
			first_->left = nullptr;
		}
		delete temp;
	}

	void PopBack()
	{
		if (IsEmpty())
		{
			using namespace std;
			cout << "Nothing to Pop in PopBack()" << endl;
			return;
		}

		// 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

		assert(first_);

		// TODO:
		if (Size() == 1)
		{
			delete first_;
			first_ = nullptr;
		}
		else
		{
			Node* p = first_;
			while (p->right != nullptr)
			{
				p = p->right;
			}

			p->left->right = nullptr;
			delete p;
		}
	}

	void Reverse()
	{
		// TODO:
		Node* prev = nullptr;
		Node* curr = first_;

		while (curr != nullptr)
		{
			prev = curr;
			curr = curr->right;
			std::swap(prev->left, prev->right);
		}

		first_ = prev;
	}

	T Front()
	{
		assert(first_);

		return first_->item; // TODO:
	}

	T Back()
	{
		assert(first_);

		Node* p = first_;
		while (p->right != nullptr)
		{
			p = p->right;
		}

		return p->item; // TODO:
	}

protected:
	Node* first_ = nullptr;
};