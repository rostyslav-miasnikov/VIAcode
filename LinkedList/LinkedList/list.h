#pragma once

#include <utility>
#include <iostream>

namespace my
{
	template <class T>
	class Node		
	{
	public:
		typedef Node *_Nodeptr;
		typedef T _ValType;

	public:
		// default ctr
		Node(): _next(NULL), _prev(NULL), _val(T())
		{
		}

		T operator*() const
		{
			return _val;
		}
		
		void swap(Node& right)
		{
			if (this == &right)
				;	// same object, do nothing
			else
				std::swap(_val, right._val);
		}

		_Nodeptr _next;
		_Nodeptr _prev;
		T		 _val;
	};

	template<class T>
	class list
	{
	public:
		typedef Node<T> _Node;
		typedef typename _Node::_Nodeptr _Nodeptr;
		typedef typename _Node::_ValType _ValType;
		typedef unsigned int size_type;

	public:
		list() : _head(new _Node), _size(0)
		{
		}

		~list()
		{
		}

		size_type size() const
		{
			return _size;
		}
		
		bool is_empty() const
		{
			return (_size == 0);
		}

		_ValType first()
		{
			if ( is_empty() )
			{
				return T();
			}
			return **_head->_next;
		}

		_ValType last()
		{
			if ( is_empty() )
			{
				return T();
			}
			return **_head->_prev;
		}

		_Nodeptr begin()
		{
			if ( _head->_next != NULL)
				return _head->_next;
			return end();
		}

		_Nodeptr end()
		{
			return _head;
		}

		// insert element at end
		void push_back(const T& val)
		{
			_Nodeptr newNode = new _Node;
			_Nodeptr lastNode = NULL; // list alway has last element

			if ( _head->_next == NULL )
			{
				// first node
				lastNode = _head;
			}
			else
			{
				// continue list
				lastNode = _head->_prev;
			}
 
			newNode->_val = val;	// store value

			lastNode->_next = newNode;	// add new value to the end, now it's a new last value
			_head->_prev = newNode;		// Head alwas knows about list end (last value)
			newNode->_next = _head;		// bind new last value with Head
			newNode->_prev = lastNode;	// bind new last value with prevoius last value

			_size++; // increment count of nodes
		}

		_Nodeptr at( size_type pos )
		{
			if ( pos >= _size )
			{
				return end();
			}
			else if ( pos == 0 )
			{
				return begin();
			}
			else if ( pos == (_size-1) )
			{
				return _head->_prev;
			}
			else
			{
				_Nodeptr node = _head->_next;
				for (size_type _i=0; _i<pos; ++_i)
				{
					node = node->_next;
				}
				return node;
			}
		}

		void erase(_Nodeptr _node)
		{
			if ( !!_node && _node != _head )
			{
				_Nodeptr prev = _node->_prev; // just helpers
				_Nodeptr next = _node->_next;

				prev->_next = next;	// bind next and prev
				next->_prev = prev;	// to each other

				delete _node;	// bye _node

				if ( (--_size) == 0 )
				{
					_head->_next = NULL;
					_head->_prev = NULL;
				}
			}
		}

		void sort() // bubble sort
		{
			// order sequence, using operator<
			if (2 <= _size)
			{
				for(_Nodeptr i_node = _head->_next; i_node != end(); i_node = i_node->_next )
				{
					for(_Nodeptr bubble = i_node->_next; bubble != end(); bubble = bubble->_next )
					{
						if( bubble->_val < i_node->_val )
						{
							i_node->swap(*bubble);
						}
					}
				}
			}
		}

		void print() // print helper method
		{
			if ( _size == 0)
			{
				std::cout << "List is empty." << std::endl;
				return;
			}
			
			std::cout << "List: ";
			for(_Nodeptr node = _head->_next; node != end(); node = node->_next )
			{
				std::cout << **node << " ";
			}
			std::cout << std::endl;
		}

	private:
		_Nodeptr	_head;
		size_type	_size;
	};
}