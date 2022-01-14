#include<iostream>
using namespace std;


const int MAX = 10000;

struct BigInt
{
	int len;
	int digit[MAX];
};



BigInt MakeBigInt()
{
	BigInt A;
	A.len = 0;
	memset(A.digit, 0, sizeof(A.digit));
	return A;
}

BigInt MakeBigInt(int n)
{
	BigInt A;
	A.len = 0;
	memset(A.digit, 0, sizeof(A.digit));

	while (n != 0)
	{
		A.digit[A.len++] = n % 10;
		n /= 10;
	}
	return A;
}

BigInt MakeBigInt(string str)
{
	BigInt A;
	int len = str.length();
	A.len = 0;

	memset(A.digit, 0, sizeof(A.digit));
	for (int i = 0; i < len; i++)
	{
		A.digit[A.len++] = str[len - 1 - i] - '0';

	}
	
	return A;
}

BigInt MUL(BigInt A, BigInt B)
{
	BigInt C = MakeBigInt();
	for (int i = 0; i < A.len; i++)
	{
		for (int j = 0; j < B.len; j++)
		{
			C.digit[i + j] += A.digit[i] * B.digit[j];
		}
	}

	for (int i = 0; i < A.len + B.len; i++) {
		if (C.digit[i] != 0) {
			C.digit[i + 1] += C.digit[i] / 10;
			C.digit[i] %= 10;
			C.len = i+1;
		}
	}

	while (C.len > 1&&C.digit[C.len - 1] == 0 )
	{
		C.len--;
	}
	return C;
}


void BigIntOut(const BigInt A)
{
	for (int i = A.len - 1; i >= 0; i--)
	{
		cout << A.digit[i];
	}

}

int main()
{

	int n;
	while (cin >> n)
	{
		BigInt A = MakeBigInt(1);
		for (int i = 2; i <= n; i++)
		{
			BigInt B=MakeBigInt(i);
			A = MUL(A, B);
		}
		BigIntOut(A);
		cout << endl;
	}

	return 0;
}