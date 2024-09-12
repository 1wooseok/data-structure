#pragma once

#include <cassert>
#include <stdint.h>
#include <cassert>

template<typename T>
class SinglyLinkedList
{
public:
	struct Node
	{
		T item = T();
		Node* next = nullptr;
	};

	SinglyLinkedList()
	{
	}

	SinglyLinkedList(const SinglyLinkedList& list)
	{
		// TODO: 연결 리스트 복사
		Node* current = list.first_;
		while (current != nullptr)
		{
			PushBack(current->item);
			current = current->next;
		}
	}

	~SinglyLinkedList()
	{
		Clear();
	}

	void Clear() // 모두 지워야(delete) 합니다.
	{
		while (first_)
		{
			Node* temp = first_->next;
			delete first_;
			first_ = temp;
		}
	}

	bool IsEmpty()
	{
		return first_ == nullptr;
	}

	int Size()
	{
		int size = 0;

		// TODO: size를 하나하나 세어서 반환
		Node* p = first_;

		while (p != nullptr)
		{
			++size;
			p = p->next;
		}

		return size;
	}

	T Front()
	{
		assert(first_);

		return T(); // TODO: 수정
	}

	T Back()
	{
		assert(first_);

		Node* current = first_;
		while (current->next)
		{
			current = current->next;
		}

		return current->item;
	}

	Node* Find(T item)
	{
		// TODO: item이 동일한 노드 포인터 반환
		Node* current = first_;
		while (current != nullptr)
		{
			if (current->item == item)
			{
				return current;
			}
			current = current->next;
		}

		return nullptr;
	}

	void InsertBack(Node* node, T item)
	{
		// TODO:
		Node* new_node = new Node;
		new_node->item = item;
		new_node->next = node->next;
		node->next = new_node;
	}

	void Remove(Node* n)
	{
		assert(first_);

		// 하나 앞의 노드를 찾아야 합니다.
		// TODO:
		Node* prev = first_;
		while (prev->next != nullptr)
		{
			if (prev->next == n)
			{
				break;
			}

			prev = prev->next;
		}

		prev->next = n->next;
		delete n;
	}

	void PushFront(T item)
	{
		// first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)
		if (first_ == nullptr)
		{
			first_ = new Node;
			first_->item = item;
			first_->next = nullptr;
			
			return;
		}
		// 새로운 노드 만들기
		// TODO:
		Node* new_node = new Node;
		new_node->item = item;
		// 연결 관계 정리
		// TODO:
		new_node->next = first_;
		first_ = new_node;
	}

	void PushBack(T item)
	{
		Node* new_node = new Node;
		new_node->item = item;
		new_node->next = nullptr;

		if (first_)
		{
			// TODO:
			Node* current = first_;

			while (current->next != nullptr)
			{
				current = current->next;
			}

			current->next = new_node;
		}
		else
		{
			// TODO:
			first_ = new_node;
		}
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

		// TODO: 메모리 삭제
		Node* next = first_->next;

		delete first_;

		first_ = next;
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

		if (first_->next == nullptr)
		{
			delete first_;
			first_ = nullptr;
			return;
		}

		// TODO: 메모리 삭제
		Node* current = first_;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}

		Node* new_next = current->next->next;
		delete current->next;
		current->next = new_next;
	}

	void Reverse()
	{
		// TODO: 
		if (first_ == nullptr || first_->next == nullptr)
		{
			return;
		}

		Node* prev = nullptr;
		Node* current = first_;
		while (current != nullptr)
		{
			Node* temp = prev;
			prev = current;
			current = current->next;
			prev->next = temp;
		}

		first_ = prev;
	}

	void SetPrintDebug(bool flag)
	{
		print_debug_ = flag;
	}

	void Print()
	{
		using namespace std;

		Node* current = first_;

		if (IsEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << "Size = " << Size() << " ";

			while (current)
			{
				if (print_debug_)
				{
					//cout << "[" << current << ", " << current->item << ", " << current->next << "]";

					// 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
					cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
						<< current->item << ", "
						<< reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
				}
				else
				{
					cout << current->item;
				}

				if (current->next)
					cout << " -> ";
				else
					cout << " -> NULL";

				current = current->next;
			}
			cout << endl;
		}
	}

	protected:
		Node* first_ = nullptr;

		bool print_debug_ = false;
};