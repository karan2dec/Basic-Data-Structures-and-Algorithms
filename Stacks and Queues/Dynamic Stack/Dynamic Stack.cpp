#include <iostream>
#include <conio.h> // For getch()

using namespace std;

struct node
{
	int data;
	node* next;
};

class stack
{
	private:
		node* top;

	public:
		stack() // Constructor
		{
			top = NULL;
		}

		void push();
		void pop();
		void display();
		
		~stack(); // Destructor	
};

void stack :: push()
{
	node* temp;
	temp = new node;

	cout << "\n Data : ";
	cin >> temp->data;

	temp->next = top;
	top = temp;
}

void stack :: pop()
{
	if(top == NULL)
		cout << "\n Error : Stack is empty";
	else
	{
		node* temp = top;
		cout << "\n Element " << top->data << " has been popped";
		top = top->next;
		delete temp;
	}
}

void stack :: display()
{
	if(top == NULL)
		cout << "\n Stack is empty";
	else
	{
		node* temp = top;
		while(temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	getch();
}

stack :: ~stack()
{
	while(top != NULL)
	{
		node* temp = top;
		top = top->next;
		delete temp;
	}
}

int main()
{
	stack s;
	int choice;
	
	do
	{
		system("cls");

		cout << "\n Select operation : \n";
		cout << "\n     1. Push      ";
		cout << "\n     2. Pop       ";
		cout << "\n     3. Display   ";
		cout << "\n     4. Exit    \n";
		cout << "\n Enter choice : ";
		cout << "\n don't know what to do" ;
		cin >> choice;

		switch(choice)
		{
			case 1 : s.push(); break;
			case 2 : s.pop(); break;
			case 3 : s.display(); break;
			case 4 : return 0;
			default : return 0;
		}
	}while(choice != 4);

	return 0;
}
