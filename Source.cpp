#include <iostream>

#define MAX_SIZE 50
using namespace std;
struct stack
{
	char values[MAX_SIZE];
	int top;
};

typedef stack STACK;


char push(char inp, STACK *st1);
char pop(STACK *st1);
char top(STACK *st1);

int main()
{
	int check = 0;
	STACK s;
	s.top = 0;
	char st[64] = "(((()))))((()))((()))(";
	for (int i = 0; i < 64; i++)
	{
		if (st[i] == '\0')
			break;
		if (st[i] == '(')
			push('(', &s);
		else if (st[i] == ')')
		{
			if (pop(&s) == '?')
			{
				cout << "paranthesis are not standard...";
				check = 1;
				break;
			}
		}
	}
	if (check == 0)
	{
		if (top(&s) == '?')
			cout << "paranthesis are standard...";
		else
			cout << "paranthesis are not standard...";
	}
	
	return 0;
}

char push(char inp, STACK *st1)
{
	if (st1->top < MAX_SIZE - 1)
	{
		st1->values[st1->top] = inp;
		st1->top++;
	}
	else
	{
		return '?';
	}
}

char pop(STACK *st1)
{
	if (st1->top != 0)
	{
		st1->top--;
		return st1->values[st1->top];
	}
	return '?';
}

char top(STACK *st1)
{
	if (st1->top != 0)
		return st1->values[st1->top - 1];
	return '?';
}