#include <iostream>

class queue
{
public :
	int size = 20;
	int arr[20];
	int head = 0;
	int tail = -1;

	int s() 
	{
		int n = 0;
		for (int i = head; i <= tail; i++)
		{
			n++;
		}
		return n;
	}

	bool empty() 
	{
		return s() == head;
	}

	bool full() 
	{
		return s() == size;
	}
	void Nqueue(int data) 
	{
		if (!full())
		{
			tail++;
			arr[tail % size] = data;
		}
		else
		{
			std::cout << "Full" << std::endl;
		}
	}

	int Dqueue() 
	{
		if (!empty())
		{	
			int temp;
			temp = arr[head % size];
			head++;
			return temp;
		}
		else
		{
			std::cout << "Empty" << std::endl;
		}
	}

	void printQ() 
	{
		for ( int i = head; i <= tail; i++)
		{
			std::cout << arr[i] << std:: endl;
		}
	}

};


int main()
{

	queue q;

	// Add elements
	q.Nqueue(10);
	q.Nqueue(20);
	q.Nqueue(30);

	// Print queue
	std::cout << "Queue after adding elements:" << std::endl;
	q.printQ();

	// Dequeue some elements
	std::cout << "Dequeued: " << q.Dqueue() << std::endl;
	std::cout << "Dequeued: " << q.Dqueue() << std::endl;

	// Print queue again
	std::cout << "Queue after removing elements:" << std::endl;
	q.printQ();

	// Add more elements
	q.Nqueue(40);
	q.Nqueue(50);

	// Print final queue
	std::cout << "Final queue:" << std::endl;
	q.printQ();

	return 0;
}