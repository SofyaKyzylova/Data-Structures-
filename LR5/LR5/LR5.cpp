// LR5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>

using namespace std;

//реализация стека на одномерном динамическом массиве
const int MaxSize = 100;

struct Stack
{
	int S[MaxSize];
	int top = -1;
};

bool isEmpty(Stack& St)
{
	if (St.top == -1)
		return true;
	else
		return false;
}

void push(Stack& St, int val)
{
	if (St.top == MaxSize - 1)
		return;
	St.top++;
	St.S[St.top] = val;
}

int pop(Stack& St)
{
	if (isEmpty(St))
		return -1;
	St.top--;
	return St.S[St.top + 1];
}

int peek(Stack& St)
{
	if (!isEmpty(St))
		return St.S[St.top];
	else
		return 0;
}

int count(Stack& St)
{
	int count = 0;
	if (!isEmpty(St))
		return count;
	else
		count = MaxSize;
	return count;
}

bool clear(Stack& St)
{
	for (int i = 0; i < MaxSize; i++)
	{
		if (St.top != NULL)
		{
			St.top = NULL;
			St.top--;
		}
	}
		
	if (isEmpty(St))
		return true;
	else return false;
}



//реализация стека на односвязном динамическом списке 
struct  Node
{
	int data;
	Node* next;
};

Node* Push(Node*& top, int val)
{
	Node* temp = new Node;
	if (!temp)
		cout << "Стек переполнен" << endl;
	temp->data = val;
	temp->next = top;
	top = temp;

	return top;
}

void Pop(Node*& top)
{
	struct Node* temp;
	if (top == NULL)
		cout << "Вершина стека пуста" << endl;
	else
	{
		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);
	}
}

bool isEmpty(Node* top)
{
	return top == NULL;
}

int peek(Node* top)
{
	if (!isEmpty(top))
		return top->data;
	else
		return 0;
}

bool clear(Node* top)
{
	Node* temp = top;
	Node* ptr;
	while (temp != NULL)
	{
		ptr = temp->next;
		delete temp;
		temp = ptr;
	}
	top = NULL;
	if (isEmpty(top))
		return true;
	else return false;
}

int count(Node* top)
{
	int count = 0;
	Node* temp = top;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

void outList(Node* top)
{
	Node* temp = top;
	while (temp != NULL)
	{
		cout << setw(5) << temp->data << ' ';
		temp = temp->next;
	}
}



//реализация дека на односвязном кольцевом динамическом списке
struct Deque
{
	int a[1000];
	int head = 500;
	int tail = 500;

	void pushHead(int val)
	{
		head--;
		a[head] = val;
	}

	void pushTail(int val)
	{
		a[tail] = val;
		tail++;
	}

	int popHead()
	{
		if (head != tail)
		{
			head++;
			return a[head - 1];
		}
		else
			return 0;
	}

	int popTail()
	{
		if (head != tail)
		{
			tail--;
			return a[tail];
		}
		else
			return 0;
	}

	int peekHead() 
	{
		return a[head];
	}

	int peekTail()
	{
		return a[tail - 1];
	}

	bool isEmpty()
	{
		return head == tail;
	}

	int count()
	{
		return sizeof(a)/4;
	}

	void clear()
	{
		head = 500;
		tail = 500;
	}
};



//реализация очереди на двусвязном динамическом списке
struct node 
{
	int data;
	node* next;
	node* prev;
};

node* enqueue(node*& head, node*& tail, int val)
{
	node* temp = new node;
	temp->data = val;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		tail->next = NULL;
	}
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
		head->prev = NULL;
	}
	return head;
}

node* dequeue(node*& head)
{
	if (head == NULL)
		return 0;
	else
	{
		node* temp = head;
		head = temp->next;
		if (head != NULL)
			head->prev = NULL;
		delete temp;
	}
	return head;
}

int peekHead(node* head)
{
	int val = -1;
	if (head)
		val = head->data;
	return val;
}

int peekTail(node* tail)
{
	int val = -1;
	if (tail)
		val = tail->data;
	return val;
}

bool isEmpty(node* head)
{
	return head == NULL;
}

bool clear(node*& head)
{
	node* temp = head;
	node* ptr;
	while (temp != NULL)
	{
		ptr = temp->next;
		delete temp;
		temp = ptr;
	}
	head = NULL;
	if (isEmpty(head))
		return true;
	else return false;
}

int count(node* head)
{
	int count = 0;
	node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

void outList(node* head, node* tail)
{
	node* temp = head;
	tail = NULL;
	while (temp != NULL)
	{
		cout << setw(5) << temp->data << ' ';
		temp = temp->next;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	//стек
	Stack S;
	cout << "Реализация стека на динамическом одномерном массиве" << endl;
	push(S, 25);
	push(S, 35);
	push(S, 50);
	push(S, 14);
	push(S, 10);
	while (!isEmpty(S))
		cout << setw(5) << pop(S) << " ";
	cout << endl;
	cout << "Размер стека = " << count(S) << endl;

	push(S, 25);
	push(S, 35);
	push(S, 50);
	push(S, 14);
	push(S, 10);
	cout << "Значение первого элемента стека: " << peek(S) << endl;
	cout << "Удаление первого элемента стека:" << endl;
	pop(S);
	while (!isEmpty(S))
		cout << setw(5) << pop(S) << " ";
	cout << endl;

	push(S, 25);
	push(S, 35);
	push(S, 50);
	push(S, 14);
	push(S, 10);
	
	if (!isEmpty(S))
		cout << "Стек не пуст" << endl;

	clear(S);
	if (isEmpty(S))
		cout << "Стек очищен" << endl;
	cout << endl;


	//стек
	Node* top = NULL;
	cout << endl << "Реализация стека на односвязном списке" << endl;
	Push(top, 10);
	Push(top, 7);
	Push(top, -1);
	Push(top, 2);
	Push(top, 8);
	outList(top);
	cout << endl;

	cout << "Удаление первого элемента стека:" << endl;
	Pop(top);
	outList(top);
	cout << endl;

	cout << "Значение первого элемента стека: " << peek(top) << endl;
	cout << "Количество элементов в стеке = " << count(top) << endl;
	if (!isEmpty(top))
		cout << "Стек не пуст" << endl;

	if (clear(top))
		cout << "Стек очищен" << endl;
	cout << endl;



	//дек
	Deque D;
	cout << endl << "Реализация дека на кольцевом односвязном списке" << endl;
	cout << "Добавление элементов в начало дека:" << endl;
	D.pushHead(25);
	D.pushHead(45);
	D.pushHead(10);
	while (!D.isEmpty())
		cout << setw(5) << D.popHead();
	cout << endl;
	cout << "Добавление элементов в конец дека:" << endl;
	D.pushHead(25);
	D.pushHead(45);
	D.pushHead(10);
	D.pushTail(35);
	D.pushTail(55);
	D.pushTail(5);
	while (!D.isEmpty())
		cout << setw(5) << D.popHead();
	cout << endl;

	D.pushHead(25);
	D.pushHead(45);
	D.pushHead(10);
	D.pushTail(35);
	D.pushTail(55);
	D.pushTail(5);
	cout << "Значение начала дека: " << D.peekHead() << endl;
	cout << "Значение конца дека: " << D.peekTail() << endl;
	cout << "Размер дека = " << D.count() << endl;

	D.popTail();
	cout << "Удаление последнего элемента дека:" << endl;
	while (!D.isEmpty())
		cout << setw(5) << D.popHead();
	cout << endl;

	D.pushHead(25);
	D.pushHead(45);
	D.pushHead(10);
	D.pushTail(35);
	D.pushTail(55);
	D.pushTail(5);
	D.popHead();
	cout << "Удаление первого элемента дека:" << endl;
	while (!D.isEmpty())
		cout << setw(5) << D.popHead();
	cout << endl;

	D.pushHead(25);
	D.pushHead(45);
	D.pushHead(10);
	D.pushTail(35);
	D.pushTail(55);
	D.pushTail(5);
	D.popHead();
	if (!D.isEmpty())
		cout << "Дек не пуст" << endl;
	
	D.clear();
	if (D.isEmpty())
		cout << "Дек очищен" << endl;
	cout << endl;



	//очередь
	node* head = NULL; node* tail = NULL;

	cout << endl << "Реализация очереди на двусвязном списке" << endl;
	enqueue(head, tail, 3);
	enqueue(head, tail, 7);
	enqueue(head, tail, 1);
	enqueue(head, tail, 13);
	enqueue(head, tail, 6);
	enqueue(head, tail, 4);
	outList(head, tail);
	cout << endl;

	cout << "Удаление первого элемента очереди:" << endl;
	dequeue(head);
	outList(head, tail);
	cout << endl;

	if (peekHead(head) == -1)
		cout << "Очередь пуста" << endl;
	else
		cout << "Значение первого элемента очереди = " << peekHead(head) << endl;

	if (peekTail(tail) == -1)
		cout << "Очередь пуста" << endl;
	else
		cout << "Значение последнего элемента очереди = " << peekTail(tail) << endl;

	cout << "Количество элементов в очереди = " << count(head) << endl;

	if (!isEmpty(head))
		cout << "Очередь не пуста" << endl;

	if (clear(head))
		cout << "Очередь очищена" << endl;
	cout << endl;
}
