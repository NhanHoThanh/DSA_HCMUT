
#define CLOCKWISE true
#define COUNTERCLOCKWISE false

#include "main.h"
using namespace std;

// this is a form of doubly circular linked list

class imp_res : public Restaurant
{
public:
	// Atributes
	int size = 0;
	void changeSize()
	{
		size++;
	}
	customer *currentCustomer;
	customer *firstCustomer;

	class List // Double linked list
	{
	public:
		struct Node
		{
			customer *data;
			int position = 0;
			Node *next;
			Node *prev;
		};
		int queue_size = 0;
		int maxSize = MAXSIZE;
		Node *head = NULL;
		Node *tail = NULL;

		List()
		{
			head = NULL;
			tail = NULL;
		}

		int getSize() { return queue_size; };

		void enqueue(customer *newCustomer) // Add to tail
		{
			Node *newNode = new Node;
			newNode->data = newCustomer;
			newNode->next = NULL;

			if (head == NULL)
			{
				head = newNode;
				tail = newNode;
			}
			else
			{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			newNode->position = queue_size;
			queue_size++;
		}

		void dequeue() // remove head element
		{
			if (head == NULL)
			{
				return;
			}

			Node *temp = head;
			head = head->next;
			// head->prev = NULL;
			delete temp;
			queue_size--;
			update_list_pos();
		}

		void update_list_pos()
		{
			Node *currentNode = head;
			int currentPosition = 0;
			while (currentNode != NULL)
			{
				currentNode->position = currentPosition;
				currentNode = currentNode->next;
				currentPosition++;
			}
		}

		void push(customer *newCustomer) // Add to head
		{
			Node *newNode = new Node;
			newNode->data = newCustomer;
			newNode->prev = NULL;
			if (head == NULL)
			{
				head = newNode;
			}
			else
			{
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			queue_size++;
		}

		void pop() // Same as dequeue
		{
			dequeue();
		}

		bool empty() { return !queue_size; };

		customer *front() // return head->data
		{
			if (head == NULL)
			{
				return NULL;
			}
			return head->data;
		}

		customer *back() // return tail->data
		{
			if (tail == NULL)
			{
				return NULL;
			}
			return tail->data;
		}

		void insertionSort(Node *node, int n, int increment, int &step)
		{
			int plus = node->position;
			for (int i = increment; i < n; i += increment)
			{
				for (int j = i; j >= increment; j -= increment)
				{
					Node *node1 = getNode(j + plus);
					Node *node2 = getNode(j - increment + plus);
					if (node1->data->energy == node2->data->energy)
					{
						if (node1->position < node2->position)
						{
							swapValue(node1, node2);
							cout << "swap: " << node1->data->name << " and " << node2->data->name << endl;
							step++;
						}
					}
					else if (node1->data->energy > node2->data->energy)
					{
						swapValue(node1, node2);
						cout << "swap: " << node1->data->name << " and " << node2->data->name << endl;
						// increase step here
						step++;
					}
				}
			}
		}

		int shellSort(Node *One) // return swapped step
		{
			int step = 0;
			int n = One->position + 1; // size
			int gap = n / 2;
			for (int i = gap; i >= 2; i /= 2) // gap = 4
			{
				for (int j = 0; j < i; j++) // j < 4
				{
					insertionSort(getNode(j), n - j, i, step); // 8 - 0
				}
			}
			insertionSort(head, n, 1, step);
			// pass
			return step;
		}

		Node *maxEnergyCustomer()
		{
			if (!head)
			{
				return nullptr;
			}
			int max = 0;
			Node *maxEnergy;
			Node *temp = tail;
			for (int i = 0; i < queue_size; i++)
			{
				if (abs(temp->data->energy) > max)
				{
					max = abs(temp->data->energy);
					maxEnergy = temp;
				}
				temp = temp->prev;
			}

			cout << "MaxEnergy: " << maxEnergy->data->name << endl;
			return maxEnergy;
		}

		void swapValue(Node *pos1, Node *pos2)
		{
			customer *temp = pos1->data;
			pos1->data = pos2->data;
			pos2->data = temp;
		}

		Node *getNode(int position)
		{
			Node *temp = head;
			for (int i = 0; i < position; i++)
			{
				temp = temp->next;
			}
			return temp;
		}

		void removeNode(List::Node *nodeToDelete)
		{
			if (nodeToDelete == NULL)
			{
				return;
			}

			if (nodeToDelete == head)
			{
				head = nodeToDelete->next;
			}
			else if (nodeToDelete == tail)
			{
				tail = nodeToDelete->prev;
			}
			else
			{
				nodeToDelete->prev->next = nodeToDelete->next;
				nodeToDelete->next->prev = nodeToDelete->prev;
			}

			delete nodeToDelete;
			update_list_pos();
			queue_size--;
		}

		void removeNode(int position)
		{
			if (position < 0 || position >= queue_size)
			{
				return;
			}

			Node *nodeToDelete = head;
			for (int i = 0; i < position; i++)
			{
				nodeToDelete = nodeToDelete->next;
			}

			removeNode(nodeToDelete);
		}

		void deleteNodeByCustomer(customer *targetCustomer)
		{
			Node *currentNode = head;
			while (currentNode != NULL)
			{
				if (currentNode->data == targetCustomer)
				{
					removeNode(currentNode);
					return;
				}
				currentNode = currentNode->next;
			}
		}

		void printList()
		{
			// pass
		}
	};
	List waitingCustomers;
	List servingCustomers;
	List waitTimeRecord;

	// Additonal Functions
	imp_res()
	{
		size = 0;

		currentCustomer = NULL;

		firstCustomer = NULL;
	}

	customer *findRES(customer *head, string name, int energy)
	{
		customer *current = new customer(name, energy, nullptr, nullptr);
		customer *tmp = head;
		customer *index = nullptr;
		int res = 0, maxres = -2;
		for (int i = 0; i < size; i++)
		{
			res = abs(tmp->energy) - abs(current->energy);
			// if (res == maxres) {
			// 	break;
			// }
			if (res > maxres)
			{
				maxres = res;
				index = tmp;
			}
			tmp = tmp->next;
		}
		return index;
	}

	bool checkDuplicate(string name1)
	{
		if (currentCustomer == NULL)
		{
			return false;
		}
		if (size == 0)
		{
			return false;
		}

		List::Node *temp = servingCustomers.head;
		for (int i = 0; i < this->servingCustomers.getSize(); i++)
		{
			if (name1 == temp->data->name)
			{
				return true;
			}
			temp = temp->next;
		}

		List::Node *temp2 = waitingCustomers.head;
		for (int i = 0; i < this->waitingCustomers.getSize(); i++)
		{
			if (name1 == temp2->data->name)
			{
				return true;
			}
			temp2 = temp2->next;
		}

		return false;
	}

	void addBefore(customer *cus)
	{
		changeSize();
		currentCustomer->prev->next = cus;
		cus->next = currentCustomer;
		cus->prev = currentCustomer->prev;
		currentCustomer->prev = cus;
		currentCustomer = cus;
		this->servingCustomers.enqueue(cus);
	}

	void addAfter(customer *cus)
	{
		changeSize();
		cus->next = currentCustomer->next;
		currentCustomer->next = cus;
		cus->prev = cus->next->prev;
		cus->next->prev = cus;
		currentCustomer = cus;
		this->servingCustomers.enqueue(cus);
	}

	void removeServingCustomer(customer *One)
	{
		if (size == 1)
		{
			this->servingCustomers.dequeue();
			delete One;
			size = 0;
			this->currentCustomer = NULL;
			this->firstCustomer = NULL;
			return;
		}
		if (One->energy == currentCustomer->energy)
		{
			relocateCurrentCustomer();
		}
		One->next->prev = One->prev;
		One->prev->next = One->next;
		size--;
		this->servingCustomers.dequeue();
		delete One;

		// customer *temp = i;
		// temp->prev->next = temp->next;
		// temp->next->prev = temp->prev;
		// i = i->next;
		// if (temp->energy == currentCustomer->energy)
		// {
		// 	relocateCurrentCustomer();
		// }
		// delete temp;
	}

	void addWaitingCustomers()
	{
		while (waitingCustomers.queue_size && this->size < MAXSIZE)
		{
			customer *nextCustomer = waitingCustomers.front();
			waitingCustomers.dequeue();
			waitTimeRecord.deleteNodeByCustomer(nextCustomer);
			RED(nextCustomer->name, nextCustomer->energy);
			delete nextCustomer;
		}
	}

	void relocateCurrentCustomer()
	{
		if (currentCustomer->energy > 0)
		{
			currentCustomer = currentCustomer->next;
		}
		else
		{
			currentCustomer = currentCustomer->prev;
		}
	}

	customer *findNextEnergyType(customer *One, bool rotation)
	{
		customer *temp = One;

		if (rotation == COUNTERCLOCKWISE)
		{
			do
			{
				temp = temp->prev;
				if (temp->energy * One->energy > 0) // check if One and temp is of same type
				{
					return temp;
				}
			} while (temp != One);
		}
		else
		{
			do
			{
				temp = temp->next;
				if (temp->energy * One->energy > 0) // check if One and temp is of same type
				{
					return temp;
				}
			} while (temp != One);
		}
		return One;
	}

	void swapInfoCustomer(customer *&node1, customer *&node2) // change name and energy only
	{
		cout << "SWAPS: " << node1->name << " " << node1->energy << " and " << node2->name << " " << node2->energy << endl;
		int tempEnergy = node1->energy;
		string tempName = node1->name;
		node1->energy = node2->energy;
		node1->name = node2->name;
		node2->energy = tempEnergy;
		node2->name = tempName;
	}

	void reverseTable()
	{
		customer *holder = currentCustomer;

		// loop serving list one time to find the number of customers that has the same type of energy
		int numLoop = 0;
		List positiveCustomers;
		List negativeCustomers;
		customer *iter = currentCustomer;
		if (iter == NULL)
		{
			cout << "NULL LIST" << endl;
		}
		else
		{
			do
			{
				if (iter->energy > 0)
				{
					positiveCustomers.push(iter);
				}
				else
				{
					negativeCustomers.push(iter);
				}
				iter = iter->prev;
				numLoop++;
			} while (iter != currentCustomer);
			// pass
			if (iter != currentCustomer) // just to make sure
			{
				iter = currentCustomer;
			}
			List::Node *positiveHead = positiveCustomers.head;
			List::Node *negativeHead = negativeCustomers.head;
			for (int i = 0; i < numLoop / 2; i++)
			{
				if (iter->energy > 0)
				{
					swapInfoCustomer(positiveHead->data, iter);
					positiveHead = positiveHead->next;
				}
				else
				{
					swapInfoCustomer(negativeHead->data, iter);
					negativeHead = negativeHead->next;
				}
				iter = iter->prev;
			}
		}
		currentCustomer = holder; // just to make sure
	}

	void findSmallestChain(int &start, int &end)
	{
		if (size == 4)
		{
			customer *temp = currentCustomer;
			for (int i = 0; i < 4; i++)
			{
				cout << temp->name << "-" << temp->energy << "/n";
				temp = temp->next;
			}
			return;
		}
		if (size < 4)
		{
			return;
		}
		int sum = 0;
		int min_so_far = 9999;
		int last = 0;
		int j = 0;

		customer *temp = currentCustomer;
		customer *temp2 = currentCustomer;
		for (int i = 0; i < 4; i++)
		{
			sum += temp->energy;
			temp = temp->next;
		}

		min_so_far = min(min_so_far, sum);

		for (int i = 4; i < size; i++)
		{
			sum += temp->energy;
			last = temp2->energy;
			temp2 = temp2->next;

			if (sum <= min_so_far)
			{
				end = i;
			}
			min_so_far = min(sum, min_so_far);
			if (last > 0)
			{
				sum -= last;
				min_so_far = min(min_so_far, sum);
				last = 0;
				start++;
				if (sum <= min_so_far && end - start + 1 < 4)
				{
					end = i;
				}
			}
		}
	}

	void printTable()
	{
		customer *i = currentCustomer;
		if (i == NULL)
		{
			cout << "NULL LIST" << endl;
		}
		else
		{
			for (int j = 0; j < size; j++)
			{
				cout << i->energy << "<->";
				i = i->next;
			}
		}
		cout << endl;

		List::Node *temp = servingCustomers.head;
		cout << "Serving list: " << endl;
		if (temp == NULL)
		{
			cout << "NULL LIST" << endl;
		}
		else
		{
			for (int i = 0; i < servingCustomers.queue_size; i++)
			{
				cout << temp->data->name << " - " << temp->data->energy << endl;
				temp = temp->next;
			}
		}

		List::Node *temp2 = waitingCustomers.head;
		cout << "Waitting list: " << endl;
		if (temp2 == NULL)
		{
			cout << "NULL LIST" << endl;
		}
		else
		{
			for (int i = 0; i < waitingCustomers.queue_size; i++)
			{
				cout << temp2->data->name << " - " << temp2->data->energy << " pos: " << temp2->position << endl;
				temp2 = temp2->next;
			}
		}
		return;
	}

	// Main Methods
	void RED(string name, int energy)
	{
		// Dont take customer in
		if (energy == 0)
		{
			return;
		}
		if (checkDuplicate(name))
		{
			return;
		}
		// Definately take customer in
		customer *newCustomer = new customer(name, energy, nullptr, nullptr);

		if (!currentCustomer) // first customer
		{
			size++;
			currentCustomer = firstCustomer = newCustomer;
			currentCustomer->next = currentCustomer;
			currentCustomer->prev = currentCustomer;
			this->servingCustomers.enqueue(newCustomer);
		}
		else if (size >= MAXSIZE && this->waitingCustomers.getSize() < MAXSIZE) // add to waiting list
		{
			waitingCustomers.enqueue(newCustomer);
			waitTimeRecord.enqueue(newCustomer);
		}
		else if (size >= MAXSIZE / 2)
		{
			// int RES = 0;
			// int currentPos = 0;

			// for (int i = 0; i < size; i++)
			// {
			// 	int temp = energy - currentCustomer->energy;
			// 	if (RES < abs(temp))
			// 	{
			// 		RES = abs(temp);
			// 		currentPos = i;
			// 	}
			// }
			// customer *temp = currentCustomer;
			// for (int i = 0; i < currentPos; i++)
			// {
			// 	temp = temp->next;
			// }
			// if (energy >= currentCustomer->energy)
			// {
			// 	addAfter(newCustomer);
			// }
			// else
			// {
			// 	addBefore(newCustomer);
			// }

			currentCustomer = findRES(currentCustomer, name, energy);
			if (energy >= currentCustomer->energy)
			{
				addAfter(newCustomer);
			}
			else
			{
				addBefore(newCustomer);
			}
		}
		else // Normal case
		{
			if (energy >= currentCustomer->energy)
			{
				addAfter(newCustomer);
			}
			else
			{
				addBefore(newCustomer);
			}
		}

		cout << name << " " << energy << endl;

		return;
	}

	void BLUE(int num)
	{
		if (num >= MAXSIZE || num >= size)
		{
			num = size;
		}

		for (int i = 0; i < num; i++)
		{
			customer *temp = this->servingCustomers.front();
			removeServingCustomer(temp);
		}
		cout << "blue " << num << endl;
		addWaitingCustomers();
	}

	void PURPLE()
	{
		cout << "start purple" << endl;
		// List::Node *iter = waitingCustomers.head;
		// for (int i = 0; i < waitingCustomers.queue_size; i++)
		// {
		// 	waitTimeRecord.enqueue(iter->data);
		// 	iter = iter->next;
		// }
		int N = waitingCustomers.shellSort(waitingCustomers.maxEnergyCustomer());
		BLUE(N % MAXSIZE);
		cout << N << endl;
		cout << "purple" << endl;
	}

	void REVERSAL()
	{
		reverseTable();
		cout << "reversal" << endl;
	}

	void UNLIMITED_VOID()
	{

		int start = 0;
		int end = 3;
		findSmallestChain(start, end);
		customer *temp = currentCustomer;
		for (int i = 0; i < start; i++)
		{
			temp = temp->next;
		}
		for (int i = start; i <= end; i++)
		{
			cout << temp->name << "-" << temp->energy << "/n";
			temp = temp->next;
		}

		cout << "unlimited_void" << endl;
	}

	void DOMAIN_EXPANSION()
	{
		customer *i = currentCustomer;
		int sorcererEnergy = 0;
		int spiritEnergy = 0;
		if (i == NULL)
		{
			cout << "NULL LIST" << endl;
		}
		else
		{
			do
			{
				if (i->energy > 0)
				{
					sorcererEnergy += i->energy;
				}
				else
				{
					spiritEnergy += abs(i->energy);
				}
				i = i->next;
			} while (i != currentCustomer);
		}

		if (i != currentCustomer) // just to make sure
		{
			i = currentCustomer;
		}

		if (sorcererEnergy >= spiritEnergy)
		{
			int currentSize = size;
			for (int k = 0; k < currentSize; k++)
			{
				if (i->energy < 0)
				{
					cout << i->name << "-" << i->energy << "/n";
					customer *temp = i;
					i = i->next;
					removeServingCustomer(temp);
				}
				else
				{
					i = i->next;
				}
			}
			List::Node *it = waitTimeRecord.head;
			int currentQueueSize = waitTimeRecord.queue_size;
			for (int j = 0; j < currentQueueSize; j++)
			{
				if (it->data->energy < 0)
				{
					cout << it->data->name << "-" << it->data->energy << "/n";
					// delete it->data;
					waitingCustomers.deleteNodeByCustomer(it->data);
					it = it->next;
					waitTimeRecord.dequeue();
					//
				}
				else
				{
					it = it->next;
				}
			}
		}
		else
		{
			int currentSize = size; // When running the removeServingCustomer, the size also decrease
			for (int k = 0; k < currentSize; k++)
			{
				if (i->energy > 0)
				{
					cout << i->name << "-" << i->energy << "/n";
					customer *temp = i;
					i = i->next;
					removeServingCustomer(temp);

					// customer *temp = i;
					// temp->prev->next = temp->next;
					// temp->next->prev = temp->prev;
					// i = i->next;
					// if (temp->energy == currentCustomer->energy)
					// {
					// 	relocateCurrentCustomer();
					// }
					// delete temp;
				}
				else
				{
					i = i->next;
				}
			}

			List::Node *it = waitTimeRecord.head;
			int currentQueueSize = waitTimeRecord.queue_size;
			for (int j = 0; j < currentQueueSize; j++)
			{
				if (it->data->energy > 0)
				{
					cout << it->data->name << "-" << it->data->energy << "/n";
					// delete it->data;
					waitingCustomers.deleteNodeByCustomer(it->data);
					it = it->next;
					waitTimeRecord.dequeue();
					//
				}
				else
				{
					it = it->next;
				}
			}
		}
		addWaitingCustomers();

		cout << "domain_expansion" << endl;
	}

	void LIGHT(int num)
	{
		customer *temp = currentCustomer;
		if (num > 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << temp->name << "-" << temp->energy << "/n";
				temp = temp->next;
			}
		}
		else if (num < 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << temp->name << "-" << temp->energy << "/n";
				temp = temp->prev;
			}
		}
		else
		{
			List::Node *temp = waitingCustomers.head;
			for (int i = 0; i < waitingCustomers.queue_size; i++)
			{
				cout << temp->data->name << "-" << temp->data->energy << "/n";
				temp = temp->next;
			}
		}
		cout << "light " << num << endl;
	}
};