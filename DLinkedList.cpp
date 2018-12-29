/*
 * DLinkedList.cpp
 *
 *  Created on: 12 déc. 2018
 *      Author: kkeita
 */

#include "DLinkedList.hpp"

DLinkedList::DLinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    size = 0;
}

DLinkedList::DLinkedList(Node *hd, Node *tl)
{
    this->head = hd;
    this->tail = tl;
    size = 0;

}

DLinkedList::~DLinkedList() {
    // TODO Auto-generated destructor stub
}
void DLinkedList::setHead(Node *node)
{
	this->head = node;
}

void DLinkedList::setTail(Node *node)
{
	this->tail = node;
}

Node* DLinkedList::getHead()
{
	if(head == NULL)
		throw string("We don't need null object");
	return head;
}

Node* DLinkedList::getTail()
{
	if(tail == NULL)
		throw string("We don't need null object");
	return tail;
}

void DLinkedList::push_front(Node *node) // add an element to the front
{
    if(!node)
	throw invalid_argument(" Non-empty list pointer can't be null");

    if( head == NULL)
    {
    	head = node;
    	tail = node;
    	head->setNext(NULL);
    }
    else
    {
    	node->setNext(head);
    	head->setPrevious(node);
    	head = node;
    }

    head->setPrevious(NULL);
    size++;
}

void DLinkedList::push_back(Node *node) // add an element to the end
{
    if(!node)
	throw invalid_argument(" Non-empty list pointer can't be null");

    if( head==NULL )
    {
    	head = node;
    	tail = node;
    	tail->setPrevious(NULL);
    }
    else
    {
    	 node->setPrevious(tail);
    	 tail->setNext(node);
    	 tail = node;
    }

    tail->setNext(NULL);

    size++;
}

void DLinkedList::insert(int position, Node *node) // modify insert function
{
	if(!node)
		throw invalid_argument("Non-empty list pointer can't be null");

	Node *tmp = head;
	Node *oldTmp = NULL;
	int i = 0;

	while(tmp != NULL && i < position)
	{
		oldTmp = tmp;
		tmp = tmp->getNext();
		i++;
	}

	if(tmp == NULL )
	{
		if(oldTmp == NULL)
		{
			head = node;
			tail = node;
	    	tail->setPrevious(NULL);
		}
		else
		{
	    	 node->setPrevious(tail);
	    	 tail->setNext(node);
	    	 tail = node;
		}

		 tail->setNext(NULL);

	}
	else if(tmp != NULL)
	{
		if(tmp->getPrevious() == NULL)
		{
			node->setNext(head);
			head->setPrevious(node);
			head = node;

	    	head->setPrevious(NULL);
		}
		else
		{
			//order is important
			tmp->getPrevious()->setNext(node);
			node->setNext(tmp);
			node->setPrevious(tmp->getPrevious());
			tmp->setPrevious(node);

		}

	}

	size++;

}

Node* DLinkedList::find(int position)
{
	Node *ret = NULL;
	if(head != NULL)
	{
		Node *tmp = head;
		int i = 0;

		while(tmp != NULL && i != position)
		{
			tmp = tmp->getNext();
			i++;
		}

		ret = tmp;
	}

	return ret;
}


Node* DLinkedList::pop_front()
{

    // kairaba : on peut imaginer aussi que quand la tête est NULL,
    // kairaba : on retourne NULL. C'est une question de goût
    if(!head)
	throw out_of_range("Can't delete from empty list");

    Node *tmp = NULL;
    tmp = head;
    head = tmp->getNext();
    head->setPrevious(NULL);
    size--;

    return tmp;

}

Node* DLinkedList::pop_back()
{
    if(!tail)
	throw string("Cannot delete from empty queue");

    Node *tmp = NULL;
    tmp = tail;
    tail = tmp->getPrevious();
    tail->setNext(NULL);

    size--;

    return tmp;
}

Node* DLinkedList::pop_position(int position)
{
	Node *tmp = NULL;
	if(head != NULL)
	{
		tmp = head;
		int i = 0;

		while(tmp != NULL && i < position)
		{
			tmp = tmp->getNext();
			i++;
		}

		if(tmp->getNext() == NULL)
		{
			tail = tmp->getPrevious();
			tail->setNext(NULL);
		}
		else if(tmp->getPrevious() == NULL)
		{
			head = tmp->getNext();
			head->setPrevious(NULL);
		}
		else
		{
			tmp->getNext()->setPrevious(tmp->getPrevious());
			tmp->getPrevious()->setNext(tmp->getNext());
		}

		size--;
	}

	return tmp;
}

void DLinkedList::delete_list()
{
	Node *tmp = head;
	while(tmp)
	{
		Node *current = tmp;
		tmp = tmp->getNext();

		delete current;
	}

	head = NULL;
	tail = NULL;
	size = 0;
}

void DLinkedList::show()
{
	cout << " list : " ;

	Node *tmp = head;
	int num = 0;

	while(tmp)
	{
	//	cout << "Element " << num  << " Id = " << tmp->getClient()->getId() << " index = " << tmp->getClient()->getIndex() ;
		cout << tmp->getClient()->getId() << "--"  ;
		tmp = tmp->getNext();
		num++;
	}

	cout << endl;
}


