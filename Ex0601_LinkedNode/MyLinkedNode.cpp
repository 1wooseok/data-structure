struct Node
{
	int data;
	Node* next;
};

class MyLinkeNode
{
public:
	MyLinkeNode();
	~MyLinkeNode();

	void AddFirst(int value);
	void AddLast(int value);
	void Delete(int value);
	Node* Search(int value);

private:
	Node* start_;
	int size_;
};

MyLinkeNode::MyLinkeNode()
{
	start_ = nullptr;
}

MyLinkeNode::~MyLinkeNode()
{
	if (start_ != nullptr)
	{
		Node* p = start_;
		while (p != nullptr)
		{
			Node* next = p->next;
			delete p;
			p = next;
		}
	}
}

void MyLinkeNode::AddFirst(int value)
{
	if (start_ == nullptr)
	{
		Node new_node;
		new_node.data = value;
		new_node.next = nullptr;

		start_ = &new_node;
	}
}