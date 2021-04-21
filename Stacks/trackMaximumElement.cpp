#include <stack>
#include <iostream>

using namespace std;


void push(int x,stack<int> *s,stack<int> *strack)
{
	s->push(x);
	if(s->size() == 1)
	{
		strack->push(x);
		return;
	}

	//If current element is greater than top element of track stack,
	//push current element to track stack, otherwise push it to
	//top of track stack again, so that no problem would occur at popping elements.

	if(x>strack->top())
		strack->push(x);
	else
		strack->push(strack->top());
}

void pop(stack<int> *st,stack<int> *strack)
{
	st->pop();
	strack->pop();
}

int main()
{
	stack<int> st;
	stack<int> strack;

	push(20,&st,&strack);
	cout << strack.top() << endl;
	push(10,&st,&strack);
	cout << strack.top() << endl;
	push(50,&st,&strack);
	cout << strack.top() << endl;
	pop(&st,&strack);
	pop(&st,&strack);
	cout << strack.top() << endl;


	return 0;
}
