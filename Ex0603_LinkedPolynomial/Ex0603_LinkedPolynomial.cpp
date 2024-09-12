#include <iostream>
#include <cassert>
#include "../shared/SinglyLinkedList.h"

using namespace std;

struct Term
{
	float coef;
	int exp;
};

class LinkedPolynomial : public SinglyLinkedList<Term>
{
public:
	typedef SinglyLinkedList<Term>::Node Node;

	void NewTerm(float coef, int exp)
	{
		// TODO: NewTerm()에서 새로운 항을 추가할 때 exp를 기준으로 정렬하기
		if (coef == 0.0f)
			return;

		Term new_term;
		new_term.coef = coef;
		new_term.exp = exp;

		Node* current = first_;
		Node* prev = nullptr;
		while (current != nullptr && current->item.exp < exp)
		{
			assert(current->item.exp != exp);
			
			prev = current;
			current = current->next;
		}

		if (prev == nullptr)
			SinglyLinkedList::PushFront(new_term);
		else if (current == nullptr)
			SinglyLinkedList::PushBack(new_term);
		else
			SinglyLinkedList::InsertBack(prev, new_term);
	}

	float Eval(float x)
	{
		float temp = 0.0f;

		// TODO:
		Node* current = first_;
		while (current != nullptr)
		{
			temp += (current->item.coef * std::powf(x, float(current->item.exp)));
			current = current->next;
		}

		return temp;
	}

	LinkedPolynomial Add(const LinkedPolynomial& poly)
	{
		// this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
		// 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

		LinkedPolynomial temp;

		Node* i = this->first_;
		Node* j = poly.first_;

		// TODO:
		Node* p1 = first_;
		Node* p2 = poly.first_;

		while (p1 != nullptr && p2 != nullptr)
		{
			if (p1->item.exp == p2->item.exp)
			{
				Term sum;
				sum.coef = p1->item.coef + p2->item.coef;
				sum.exp = p1->item.exp;
			
				temp.PushBack(sum);
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1->item.exp < p2->item.exp)
			{
				temp.PushBack(p1->item);
				p1 = p1->next;
			}
			else
			{
				temp.PushBack(p2->item);
				p2 = p2->next;
			}
		}

		while (p1 != nullptr)
		{
			temp.PushBack(p1->item);
			p1 = p1->next;
		}

		while (p2 != nullptr)
		{
			temp.PushBack(p2->item);
			p2 = p2->next;
		}

		return temp;
	}

	void Print()
	{
		bool is_first = true; // 더하기 출력시 확인용

		// TODO:
		Node* current = first_;

		while (current != nullptr)
		{
			cout << current->item.coef;
			
			if (current->item.exp != 0)
			{
				cout << "*x^" <<  current->item.exp;
			}
			
			if (current->next != nullptr)
			{
				cout << " + ";
			}

			current = current->next;
		}

		cout << endl;
	}

private:
};

int main()
{
	using namespace std;

	LinkedPolynomial p1;

	// exp가 작은 항부터 추가한다고 가정
	p1.NewTerm(2.0f, 2);	// 2 * x^2
	p1.Print();
	p1.NewTerm(1.0f, 0);	// 1 * x^0 = 1
	p1.Print();
	p1.NewTerm(1.5f, 1);	// 1.5 * x^1
	p1.Print(); // 1 + 1.5*x^1 + 2*x^2

	cout << p1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
	cout << p1.Eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
	cout << p1.Eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

	cout << endl;

	// Add() Test1
	cout << "Add() Test" << endl;
	{
		LinkedPolynomial p1; // max_degree는 기본값으로 설정

		// exp가 작은 항부터 추가한다고 가정
		p1.NewTerm(1.0f, 0);
		p1.NewTerm(1.5f, 1);
		p1.NewTerm(2.0f, 2);

		p1.Print(); // 1 + 1.5*x^1 + 2*x^2

		LinkedPolynomial p2;

		// exp가 작은 항부터 추가한다고 가정
		p2.NewTerm(1.0f, 1);
		p2.NewTerm(3.0f, 2);
		p2.NewTerm(5.0f, 7);
		p2.NewTerm(2.0f, 11);

		p2.Print(); // 1*x^1 + 3*x^2 + 5*x^7 + 2*x^11

		cout << endl;

		LinkedPolynomial psum = p1.Add(p2);
		psum.Print(); // 1 + 2.5*x^1 + 5*x^2 + 5*x^7 + 2*x^11

		cout << endl;
	}

	// Add() Test2
	cout << "Add() Test2" << endl;
	{
		LinkedPolynomial p1; // max_degree는 기본값으로 설정

		// exp가 작은 항부터 추가한다고 가정
		p1.NewTerm(5.0f, 7);
		p1.NewTerm(1.0f, 0);
		p1.NewTerm(3.5f, 10);
		p1.NewTerm(1.5f, 1);
		p1.NewTerm(5.5f, 20);
		p1.NewTerm(5.0f, 1000);
		p1.NewTerm(2.0f, 2);

		p1.Print(); // 1 + 1.5*x^1 + 2*x^2 + 5*x^7 + 3.5*x^10 + 5.5*x^20 + 5*x^1000

		LinkedPolynomial p2;

		// exp가 작은 항부터 추가한다고 가정
		p2.NewTerm(3.0f, 2);
		p2.NewTerm(3.2f, 0);
		p2.NewTerm(2.0f, 11);
		p2.NewTerm(1.0f, 1);

		p2.Print(); // 3.2 + 1*x^1 + 3*x^2 + 2*x^11

		cout << endl;

		LinkedPolynomial psum = p1.Add(p2);
		psum.Print(); // 4.2 + 2.5*x^1 + 5*x^2 + 5*x^7 + 3.5*x^10 + 2*x^11 + 5.5*x^20 + 5*x^1000

		cout << endl;
	}

	return 0;
}
