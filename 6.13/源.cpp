#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX = 1001;
struct BigInt
{
	int len;
	int sign; // 0 -> positive 1->negative
	int digit[MAX]; 
};

BigInt MakeBigInt()
{
	BigInt A;
	A.sign = 0;
	A.len = 0;
	memset(A.digit, 0, sizeof(A.digit));
	return A;
}

BigInt MakeBigInt(string str)
{
	BigInt A;
	int len= str.length();
	A.len = 0;
	bool isNeg = false;
	memset(A.digit, 0, sizeof(A.digit));
	if (str[0] == '-')
	{
		A.sign = 1;
		isNeg = true;
	}
	if (isNeg == false)
	{
		for (int i = 0; i < len; i++)
		{
			A.digit[A.len++] = str[len - 1 - i]-'0';

		}
	}
	else {
		for (int i = 0; i < len-1; i++)
		{
			A.digit[A.len++] = str[len - 1 - i]-'0';
		}
	}

	return A;

}

BigInt ADD(BigInt A, BigInt B)
{
	BigInt C = MakeBigInt();
	int carry = 0;
	for (int i = 0; i < A.len || i < B.len; i++)
	{
		int current = carry + A.digit[i] + B.digit[i];
		carry = current / 10;
		C.digit[C.len++] = current % 10;
	}
	if (carry != 0)
	{
		C.digit[C.len++] = carry;
	}

	while (C.digit[C.len - 1] == 0 && C.len > 1) {
		C.len--;
	}

	return C;
	
}


//A>B
BigInt SUB(BigInt A, BigInt B)
{
	BigInt C = MakeBigInt();
	int carry = 0;
	for (int i = 0; i < A.len; i++)
	{
		int current = A.digit[i] - B.digit[i] - carry;
		if (current < 0)
		{
			current += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		C.digit[C.len++] = current;
	}
	while (C.digit[C.len - 1] == 0 && C.len > 1) {
		C.len--;
	}
	return C;
}


bool isABSBiger(BigInt A, BigInt B)
{
	if (A.len > B.len)return true;
	else if (A.len < B.len)return  false;
	else {
		for (int i = A.len - 1; i >= 0; i--)
		{
			if (B.digit[i] > A.digit[i])return  false;
		}
	}
	return true;
}


BigInt ADDI(BigInt A, BigInt B)
{
	BigInt C;
	if (A.sign == B.sign)
	{
		C = ADD(A, B);
		C.sign = A.sign;
		return C;
	}
	else {
		if (isABSBiger(A, B)) {
			C = SUB(A, B);
			C.sign = A.sign;
			return C;
		}
		else {
			C = SUB(B, A);
			C.sign = B.sign;
			return C;
		}
	}
}

void BigIntOut(const BigInt A)
{
	if (A.sign == 1)
		cout << "-";
	for (int i = A.len - 1; i >= 0; i--)
	{
		cout << A.digit[i];
	}
	
}

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		BigInt AI, BI;
		AI = MakeBigInt(A);
		BI = MakeBigInt(B);
		BigIntOut(ADDI(AI, BI));
		cout << endl;

		
	}

	return 0;
}