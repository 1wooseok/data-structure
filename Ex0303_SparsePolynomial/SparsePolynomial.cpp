#include "SparsePolynomial.h"

#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

// 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함

// exp항이 이미 존재하면 거기에 coef를 더해준다.
// 존재하지 않는다면 exp 오름 차순으로 정렬된 상태로 새로 추가한다.
void SparsePolynomial::NewTerm(float coef, int exp)
{
	if (coef == 0.0f) return; // 0이면 추가하지 않음

	if (num_terms_ >= capacity_)
	{
		// capacity 증가 (num_terms는 일단 고정)
		capacity_ = capacity_ > 0 ? capacity_ * 2 : 1; // 2배씩 증가
		Term* new_term = new Term[capacity_];

		// 원래 가지고 있던 데이터 복사
		memcpy(new_term, terms_, sizeof(Term) * num_terms_);

		// 메모리 교체
		if (terms_) delete[] terms_;
		terms_ = new_term;
	}

	terms_[num_terms_].coef = coef;
	terms_[num_terms_].exp = exp;

	num_terms_++;
}

float SparsePolynomial::Eval(float x)
{
	float temp = 0.0f;

	// TODO:
	for (int i = 0; i < num_terms_; ++i)
	{
		float coef = terms_[i].coef;
		int exp = terms_[i].exp;

		temp += (coef * std::powf(x, float(exp)));
	}

	return temp;
}

SparsePolynomial SparsePolynomial::SimpleAdd(const SparsePolynomial& poly)
{
	// this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
	// 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

	// 간단한 방법 (메모리를 더 사용하는 방법)
	// - 1. 최대 exp를 찾는다.
	// - 2. 필요한 크기의 Polynomial을 만든다. (Sparse 아님)
	// - 3. 더하면서 Polynomial에 업데이트 한다. 구조가 고정되어 있어서 쉽다.
	// - 4. Polynomial을 SparsePolynomial로 변환한다.

	SparsePolynomial temp;

	int t1_max_exp = -1;
	for (int i = 0; i < num_terms_; ++i)
	{
		int exp = terms_[i].exp;
		if (t1_max_exp < exp)
		{
			t1_max_exp = exp;
		}
	}
	int t2_max_exp = -1;
	for (int i = 0; i < poly.num_terms_; ++i)
	{
		int exp = poly.terms_[i].exp;
		if (t2_max_exp < exp)
		{
			t2_max_exp = exp;
		}
	}
	int max_exp = (t1_max_exp > t2_max_exp ? t1_max_exp : t2_max_exp) + 1;

	float* t1 = new float[max_exp] { 0.0f, };
	for (int i = 0; i < num_terms_; ++i)
	{
		int exp = terms_[i].exp;
		float coef = terms_[i].coef;
		if (coef > 0.0f)
		{
			t1[exp] = coef;
		}
	}
	float* t2 = new float[max_exp] { 0.0f };
	for (int i = 0; i < poly.num_terms_; ++i)
	{
		int exp = poly.terms_[i].exp;
		float coef = poly.terms_[i].coef;
		if (coef > 0.0f)
		{
			t2[exp] = coef;
		}
	}

	for (int i = 0; i < max_exp; ++i)
	{
		float sum = t1[i] + t2[i];
		if (sum > 0.0f)
		{
			temp.NewTerm(sum, i);
		}
	}

	delete[] t2;
	delete[] t1;

	return temp;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
	// this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
	// 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

	SparsePolynomial temp;

	int t1 = 0;
	int t2 = 0;

	size_t max_length = num_terms_ > poly.num_terms_ ? num_terms_ : poly.num_terms_;

	while (!(t1 == max_length || t2 == max_length))
	{
		int t1_exp = terms_[t1].exp;
		int t2_exp = poly.terms_[t2].exp;
		float t1_coef = terms_[t1].coef;
		float t2_coef = poly.terms_[t2].coef;

		if (t1 == num_terms_)
		{
			temp.NewTerm(t2_coef, t2_exp);
			++t2;
			continue;
		}
		else if (t2 == poly.num_terms_)
		{
			temp.NewTerm(t1_coef, t1_exp);
			++t1;
			continue;
		}

		if (t1_exp == t2_exp)
		{
			float sum = t1_coef + t2_coef;
			temp.NewTerm(sum, t1_exp);

			++t1;
			++t2;
		}
		else if (t1_exp < t2_exp)
		{
			temp.NewTerm(t1_coef, t1_exp);
			++t1;
		}
		else
		{
			temp.NewTerm(t2_coef, t2_exp);
			++t2;
		}
	}

	return temp;
}

void SparsePolynomial::Print()
{
	bool is_first = true; // 더하기 출력시 확인용

	for (int i = 0; i < num_terms_; i++)
	{
		// 0이 아닌 항들만 골라서 출력할 필요가 없음

		if (!is_first)
			cout << " + "; // 첫 항이 아니라면 사이사이에 더하기 출력

		cout << terms_[i].coef;

		if (terms_[i].exp != 0) cout << "*" << "x^" << terms_[i].exp;

		is_first = false;
	}

	cout << endl;
}
