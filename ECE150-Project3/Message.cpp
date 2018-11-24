#include <cmath>
#include <iostream>
#include "Message.h"

std::string add_diff_spaces(unsigned int a){
    std::string lel = "";
    for(int x = 1; x < a; x++){
        lel += "... ";
    }
    return lel;
}
//////////////////////////////////////END OF HELPER FUNCTIONS///////////////////////////////////////////////////////////
Node::Node(unsigned int id, std::string frag){
    this->identifier = id;
    this->fragment = frag;
    this->p_next = nullptr;
}
Node* Node::get_next(){
    return this->p_next;
}
std::string Node::get_fragment(){
    return this->fragment;
}
////////////////////////////////////////////END OF NODE CLASS///////////////////////////////////////////////////////////
Message::Message(){
    this->head = nullptr;
}
Message::~Message(){
    //TODO: deallocate Nodes properly
    Node*ptr = this->head;
    while(ptr != nullptr){
        Node* pt = ptr;
        ptr = pt->p_next;
        delete pt;
    }
}
void Message::insert(unsigned int id, std::string fragment){
    //TODO: insert node correctly
    if(this->head == nullptr){
        head = new Node(id, fragment);
    }
    else{
        Node * ptr = this->head;
        Node * p_ptr = ptr;
        Node * a = new Node(id, fragment);
        bool searching = true;
        if((this->head != nullptr) && (id < this->head->identifier)){
            a->p_next = this->head;
            this->head = a;
            searching = false;
        }
        while(searching){
            if(id < ptr->identifier){
                searching = false;
                p_ptr->p_next = a;
                a->p_next = ptr;
                break;
            }
            if(ptr->p_next == nullptr){
                searching = false;
                ptr->p_next = a;
                a->p_next = nullptr;
                break;
            }
            if(id > ptr->identifier){
                p_ptr = ptr;
                ptr = ptr->get_next();
            }
        }
    }
}
void Message::print_message(){
    //TODO: Print message properly
    Node* point = this->head;
    Node* pre_point = point;
    bool eot = false;
    std::string printer;
    while(point != nullptr){
        printer += add_diff_spaces(point->identifier - pre_point->identifier);
        if(point->get_fragment() == "EOT"){
            eot = true;
        }else{
            printer += point->get_fragment() + " ";
        }
        pre_point = point;
        point = point->get_next();
    }
    if(!eot){
        printer += "??? ";
    }
    printer = printer.substr(0, printer.length()-1);
    std::cout << printer << std::endl;
}
/////////////////////////////////////////END OF MESSAGE CLASS///////////////////////////////////////////////////////////
#ifndef MARMOSET_TESTING
int main(){
	Message m;
	bool key = true;
	while(key){
	    int num;
	    std::cin >> num;
	    if(num >= 0){
	        std::string input;
	        std::cin >> input;
	        m.insert(num, input);
	    }else if(num == -1){
	        m.print_message();
	    }else if(num == -2){
	        key = false;
	    }
	}
    /*m.insert(5,"5");
    m.insert(4,"4");
	m.insert(1,"1");
    m.print_message(); //Tests
	m.insert(2,"2");
    m.insert(6,"6");
    m.insert(7,"7");
    m.insert(3,"3");
    m.insert(8,"EOT");
    m.print_message();*/
    return 0;
}
#endif
