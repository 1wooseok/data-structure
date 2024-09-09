#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols)
{
	assert(values_ == nullptr);
	// TODO:
	num_rows_ = num_rows;
	num_cols_ = num_cols;
	values_ = new float[num_rows_ * num_cols_] { 0.0f, };

}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix& b)
{
	assert(values_ == nullptr);

	// TODO:
	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
	values_ = new float[num_rows_ * num_cols_] { 0.0f };
	memcpy(values_, b.values_, sizeof(float) * (num_rows_ * num_cols_));
}

Matrix::~Matrix()
{
	// TODO:
	if (values_)
	{
		delete[] values_;
		values_ = nullptr;
		num_rows_ = 0;
		num_cols_ = 0;
	}
}

void Matrix::SetValue(int row, int col, float value) const
{
	assert((0 <= row && row < num_rows_) && (0 <= col && col < num_cols_));

	// values_[TODO] = value;
	values_[(row * num_cols_) + col] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	return values_[(row * num_cols_) + col];
}

Matrix Matrix::Transpose()
{
	Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

	// TODO:
	for (int row = 0; row < num_rows_; ++row)
	{
		for (int col = 0; col < num_cols_; ++col)
		{
			temp.SetValue(col, row, GetValue(row, col));
		}
	}

	return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
	assert(b.num_cols_ == num_cols_);
	assert(b.num_rows_ == num_rows_);

	Matrix temp(num_rows_, num_cols_);

	// TODO:
	for (int row = 0; row < num_rows_; ++row)
	{
		for (int col = 0; col < num_cols_; ++col)
		{
			float sum = GetValue(row, col) + b.GetValue(row, col);
			temp.SetValue(row, col, sum);
		}
	}

	return temp;
}

void Matrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";

		cout << endl;
	}
}
