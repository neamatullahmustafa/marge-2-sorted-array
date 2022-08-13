#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int checksorted(stack<int> mystack)
{
	stack<int> temp;
	int x = 1,
		x1 = mystack.top();
	mystack.pop();
	int x2 = mystack.top();
	mystack.pop();
	while (!mystack.empty())
	{
		if (x1 >= x2)
		{
			x = 0;
			break;
		}
		temp.push(x1);
		x1 = x2;
		x2 = mystack.top();
		mystack.pop();
	}
	if (x1 >= x2)
		x = 0;
	mystack.push(x2);
	mystack.push(x1);
	while (!temp.empty())
	{
		mystack.push(temp.top());
		mystack.pop();
	}
	return x;
}
void merge_2_sorted(stack<int> mystack1, stack<int> mystack2, stack<int>
	mystack3)
{
	int x1 = mystack1.top(), x2 = mystack2.top();
	mystack1.pop();
	mystack2.pop();
	while (!mystack1.empty() && !mystack2.empty())
	{
		if (x1 < x2)
		{
			mystack3.push(x1);
			x1 = mystack1.top();
			mystack1.pop();
		}
		else
		{
			mystack3.push(x2);
			x2 = mystack2.top();
			mystack2.pop();
		}
	}
	while (!mystack1.empty())
	{
		if (x1 < x2)
		{
			mystack3.push(x1);
			x1 = mystack1.top();
			mystack1.pop();
		}
		else
		{
			mystack3.push(x2);
			x2 = 10000000;
		}
	}
	while (!mystack2.empty())
	{
		if (x2 < x1)
		{
			mystack3.push(x2);
			x2 = mystack2.top();
			mystack2.pop();
		}
		else
		{
			mystack3.push(x1);
			x2 = 10000000;
		}
	}
}
void insertnum(stack<int>mystack, int num)
{
	stack<int> temp;
	int x = mystack.top();
	mystack.pop();
	while (!mystack.empty())
	{
		if (x < num)
		{
			temp.push(x);
			x = mystack.top();
			mystack.pop();
		}
		else
		{
			mystack.push(num);
			break;
		}
	}
	mystack.push(x);
	while (!temp.empty())
	{
		mystack.push(temp.top());
		mystack.pop();
	}
}
int main()
{}