#include <iostream>

class Node {
private:
	int data;

public:
	Node(const int& data_); //(constructor).
	Node() = default; //(default-constructor).
	~Node() { std::cout << "destroy it" << std::endl; }

	Node(const Node& other);//(copy-contructor)
	Node(Node&& other);//(move-constructor).

	Node& operator=(const Node& other);//(copy-assignment-operator)
	Node& operator=(Node&& other);//(move-assignment-operator).

	void setData(const int& number);

	void printData()const;
};

Node::Node(const int& data_)
	:data(data_)
{
	//
	std::cout << "constructor" << std::endl;
	std::cout << "data: "<< data << std::endl;
	std::cout << "data_: "<< data_ << std::endl;
}

Node::Node(const Node& other)
	: data(other.data)
{
	std::cout << "copy constructor" << std::endl;
}

Node::Node(Node&& other)
	: data(std::move(other.data))  
{
	std::cout << "move constructor" << std::endl;
}

Node& Node::operator=(const Node& other)
{
	this->data = other.data;
	std::cout << "copy assign operator=&" << std::endl;

	return *this;
}

Node& Node::operator=(Node&& other)
{
	this->data = std::move(other.data); 
	std::cout << "move assign operator=&&" << std::endl;

	return *this;
}

void Node::setData(const int& number)
{
	this->data = number;
	std::cout << "setData: " << this->data << std::endl;
}

void Node::printData()const
{
	std::cout << "printData: " << (this->data) << std::endl;
}

int main()
{
	//case 1:
	//Node *n1 = new Node(20);  //normal operate  
    //n1->printData();   

    //Node&& n1 (Node(20)); //construct copy 20 to Node.
    //n1.printData();   

	//case 2:
	//Node n(10); //normal construct, copye 10 calue
    //n.printData();   
    //Node& n2 = n; //對n1的左值引用(lvalue-reference), //雖然n2引用了n1,但程式結束時,run n的desctruct.
    //n2.printData();   

	//case 3:
	//Node(30); 
	//std::cout << "---------------" << std::endl; 
    
    //case 4:
	//Node&& n3(40); //與Node n3(20);效果一樣. 
    //n3.printData();   

	//case 5:
#if 0
	Node&& n4(50); //ok.  Node&& n4(50); n4是一個右值引用(lvalue-ref)的左值(lvalue).
    n4.printData();   

	Node& n5 = n4; //ok, run n4 desctruct, when process done. 
    n5.printData();   

    n5.setData(500); 
    n4.printData();   
#endif

#if 1
	//case 6:
	Node n6(60); //normal construct
	//Node n7 = std::move(n6); //move construct
	Node n7(std::move(n6)); //move construct
    n7.printData();   

	//Node n8 = n6; //copy construct
	Node n8(n6); //copy construct
    n8.printData();   
#endif
	
#if 1
    //case 7:
	Node n9; //run n9 construct。
	n9 = Node(n9); //run n9 move assign operation.  
#endif
    
    return 0;
}
