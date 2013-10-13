#include <cstddef>
#include <iostream>
#ifndef BST_H
#define BST_H
using namespace std;

template<class Item>
class bstNode
{
	public:
	//constructor
	bstNode(const Item& init_data, bstNode* init_left=NULL, bstNode* init_right= NULL, bstNode* init_parent = NULL)
		{
			data_field = init_data;
			left_field = init_left;
			right_field = init_right;
			parent = init_parent;
		}
	//helper functions if you need them ..
	//I think I haven't used any of them so far	
	//Item& get_data() {return data_field;}
	void set_data(Item& target) {data_field=target;}
	bstNode*& get_left() {return left_field;}
	bstNode*& get_right() {return right_field;}
	
	//FUNCTIONS YOU IMPLEMENT BELOW
	bool find(Item& targetData);
	void insert(Item& targetData);
	void remove(Item& targetData);
	int size();
	void traverse();
	
	//our private variables (we just have 3)
	private:
		Item data_field; //our data
		bstNode* left_field; //pointer to left child
		bstNode* right_field; //pointer to right child
		bstNode* parent;
};

//ALL OUR IMPLEMENTATIONS GO IN HERE-- NO .CPP FILE FOR BSTNODE BECUASE IT'S A TEMPLATE CLASS
template<class Item>
bool bstNode<Item>::find(Item& targetData)
{
	//check my self, check my children... if I find targetData I return true, else false
	if(targetData == data_field){
		return true;
	}
	
	else if (targetData < data_field){
		if(left_field != '\0'){
			if(left_field->find(targetData)){
				return true;
			}
		}
		else if (right_field != '\0'){
			if(right_field->find(targetData)){
				return true;
			}
		}
	}
	
	else if (targetData > data_field){
		if(left_field != '\0'){
			if(left_field->find(targetData)){
				return true;
			}
		}
		else if (right_field != '\0'){
			if(right_field->find(targetData)){
				return true;
			}
		}
		//~ if(get_right() == '\0'){
			//~ return false;
		//~ }
		//~ else{
			//~ return right_field->find(targetData);
		//~ }
	}
return false;
}

template<class Item>
void bstNode<Item>::insert(Item& targetData)
{
	//go through and find the correct place to insert a new node
	//with this data, remember that you print out the tree in 
	//that specific format after you insert!
	
	// call insert on whole thing, then call again on smaller subtree
	if (targetData <= data_field){
		if(left_field != NULL){
			left_field->insert(targetData);
			}
		else if (left_field == NULL){
			left_field = new bstNode(targetData, NULL, NULL, this);
			}
		}
	
	else if (targetData > data_field){
		if (right_field != NULL){
			right_field->insert(targetData);
			}
		else if (right_field == NULL){
			right_field = new bstNode(targetData, NULL, NULL, this);
			}
		}
	}
		

template<class Item>
void bstNode<Item>::traverse()
{
	//print out the sequence of data using IN ORDER traversal
	if(left_field != NULL){
		left_field->traverse();
		}
		
		cout << data_field << endl;
		
	if(right_field != NULL){
		right_field->traverse();
		}
}


//~ bstNode cursor = this;
template<class Item>
void bstNode<Item>::remove(Item& targetData)
{
	//go through and remove the item and remake the tree
	
	if(this == NULL){
		cout << "This root is pointing to NULL" << endl;
	}
	
	if(data_field > targetData){
		left_field->remove(targetData);
	}
	
	if(data_field < targetData){
		right_field->remove(targetData);
	}
	
	if(data_field == targetData){
		if(left_field == NULL && right_field == NULL && parent != NULL){
				cout << endl;
				cout << "There are no children, but there is a parent" << endl;
				if(this->data_field <= parent->data_field){
					cout<< "CASE 1A - Node is less than or equal to parent" << endl;
					cout<< "Changing pointer of parent to left field of Node" << endl << endl;
					bstNode* deleteThis = this;
					parent->left_field = deleteThis->left_field;
					//delete deleteThis;
				}
				if(this->data_field > parent->data_field){
					cout<< "Case 1B - Node is greater than parent"<< endl;
					cout<< "Changing pointer of parent to right field of Node" << endl << endl;
					bstNode* deleteThis = this;
					parent->right_field = deleteThis->right_field;
					//delete deleteThis;
				}
			}
		if(left_field == NULL && right_field != NULL && parent != NULL){
			cout << "CASE 2A - There is a Right Child and a Parent" << endl;
			bstNode* deleteThis = this;
			this->parent->right_field = deleteThis->right_field;
			this->right_field->parent = this->parent;
			//delete deleteThis;
		}
		
		if(left_field == NULL && right_field != NULL && parent == NULL){
			cout << "CASE 2B - There is a Right Child and no Parent" << endl;
			bstNode* deleteThis = this->right_field;
			this->left_field = deleteThis->left_field;
			this->data_field = deleteThis->data_field;
			this->right_field = deleteThis->right_field;
			//delete deleteThis;
		}
		
		else if(left_field != NULL){
			bstNode* cursor = left_field;
			while(cursor->right_field != NULL){
				cursor = cursor->right_field;}
				
			cout<< "The value of cursor is: " << cursor->data_field << endl;
				if(cursor->left_field == NULL){
					cout << "CASE 3 - There are no left children to the Cursor" << endl;
					cursor->parent->left_field = cursor->left_field;
					cursor->parent = this->parent;
					// left_field->parent = cursor->parent;
				}
				
				if(cursor->left_field != NULL){
					cout << "CASE 4 - There are two children" << endl;
					cursor->parent->left_field = cursor->left_field;
					//this->left_field->parent = this->parent;
					//cursor->left_field->parent = cursor->parent;
				}
			// delete cursor;
		}
	}
}

template<class Item>
int bstNode<Item>::size()
{
	//go through and count the number of nodes in this
	//check my self, check my children...
	
	if(this == NULL){
		return 0;
		}
		
	int mycount = 1;
	
	if(left_field != NULL){
		mycount = mycount + left_field->size();
		}
	
	if(right_field != NULL){
		mycount = mycount + right_field->size();
		}
		
	return mycount;
}
#endif


//~ if(find(targetData))
	//~ bstNode cursor = new bstNode(targetData)

//~ else if(left_field == NULL && right_field == NULL && parent == NULL){
			//~ cout << "SINGLE ROOT CASE" << endl;
			//~ bstNode<Item>* root=NULL;
			//~ //root = this;
		//~ }

//~ else if(right_field == NULL){
				//~ bstNode* deleteThis = this;
				//~ this->parent->left_field = deletethis->left_field;
				//~ delete deleteThis;
				//~ bstNode* temp2 = this;
				//~ this = right_field;
				//~ delete temp2;

//~ if(left_field != NULL){
		//~ left_field->size();
		//~ temp = temp + 1;
		//~ }
		//~ 
	//~ else if(right_field != NULL){
		//~ right_field->size();
		//~ temp = temp + 1;
		//~ }
	//~ 
	//~ cout << "this is temp" << temp << endl;
	//~ count = temp;
	// cout << count << endl;
	

//~ int count = 0;
		//~ if(left_field != NULL){
			//~ left_field->size();
			//~ }
		//~ else if (left_field == NULL){
			//~ count = count + 1;
			//~ }
		//~ else if (right_field != NULL){
			//~ right_field->size();
			//~ }
		//~ else if (right_field == NULL){
			//~ count = count + 1;
			//~ }
		//~ 
	//~ return count;


//~ if(targetData == this->data_field){
		//~ return true;
	//~ }
	//~ 
	//~ else if (targetData <= this->data_field){
		//~ if (get_left() == '\0'){
			//~ return false;
		//~ }
		//~ else{
			//~ return left_field->find(targetData);
		//~ }
	//~ }
	//~ 
	//~ else if (targetData > this->data_field){
		//~ if  (get_right() == '\0'){
			//~ return false;
		//~ }
		//~ else{
			//~ return right_field->find(targetData);
		//~ }
	//~ 
	//~ 

//~ if(left_field != '\0'){
			//~ if(left_field->find(targetData)){
				//~ return true;
			//~ }
		//~ }
		//~ else if (right_field != '\0'){
			//~ if(right_field->find(targetData)){
				//~ return true;
			//~ }
		//~ }
	//~ 
	//~ 
	
	//~ 
	//~ if(targetData == '\0'){
		//~ bstNode(targetData);
	//~ }
	//~ 
	//~ if (targetData < this->data_field){
		//~ if(get_left() == '\0'){
			//~ data_field.get_left() = bstNode(targetData);
		//~ }
		//~ else{
			//~ left_field->insert(targetData);
		//~ }
	//~ }
	//~ 
	//~ else if (targetData > this->data_field){
		//~ if(get_right() == '\0'){
			//~ bstNode(targetData);
		//~ }
		//~ else{
			//~ right_field->insert(targetData);
		//~ }
	//~ }

	//~ 
	//~ if(targetData == data_field){
		//~ return true;
	//~ }
	//~ else if(targetData == left_field->data_field){
		//~ return true;
	//~ }
	//~ else if(targetData == right_field->data_field){
		//~ return true;
	//~ }
	//~ else if(targetData != left_field->data_field){
		//~ return false;
		//~ set_data(left_field->data_field);
	//~ }
	//~ else if(targetData != right_field->data_field){
		//~ return false;
		//~ set_data(right_field->data_field);
	//~ }
	//~ else {
		//~ return false;
	//~ }
	
	//~ bstNode* temp1 = this;
				//~ this = left_field;
				//~ delete temp1;

//~ if(parent == NULL && left_field == NULL){
			//~ this->right_field->parent = NULL;

		//~ }
