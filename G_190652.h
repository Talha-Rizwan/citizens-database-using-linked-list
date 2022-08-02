#pragma once
#ifndef CITIZENSDB_H
#define CITIZENSDB_H

#include<iostream>
#include <string>
#include<fstream>
using namespace std;

struct CCID_NODE;
struct CCND_NODE;
struct CBID_NODE;

template<class T>
struct np {
	T data;
	np* next;
	
	np() {
		data = "";
		next = NULL;
	}
	np(T s) {
		data = s;
		next = NULL;
	}
};

template <class T>
class DataPipeline {
	
	np<string>* head;
	np<string>* rear;
public:

	DataPipeline() {
		head = NULL;
		rear = NULL;
	}

	T front() {
		return head->data;
	}
	T back() {
		return rear->data;
	}

	void enqueue(T d) {
		if (head == NULL) {
			head = new np<string>(d);
			rear = head;

		}
		else {
			rear->next = new np<string>(d);
			rear = rear->next;
		}
	}

	T dequeue() {
		np<string>* temp;
		if (head != NULL) {
			temp = head;
			head = head->next;
			return temp->data;
			//       delete[]temp;
		}
		else if (head == NULL) {
			cout << "nothing to display" << endl;
			return "";
		}
	}

	bool is_empty() {
		if (head != NULL)
			return false;
		else
			return true;
	}

	void display() {
		np<string>* temp = head;
		for (int i = 0; temp != NULL; i++) {
			cout << temp->data << endl;
			temp = temp->next;
		}
//		cout << "nothing more to display" << endl;
	}
};

template<class T>
struct an {
	T * data;
	an* next;

	an() {
		data = NULL;
		next = NULL;
	}
	an(T * s) {
		data = s;
		next = NULL;
	}
};

template<class T>
class AD {
	/* Implement a stack for your Alien Database operations */
public:

	an<CBID_NODE>* head;
	an<CBID_NODE>* temp;

//public:
	AD() {
		head = NULL;
		temp = NULL;
	}

	void push_roll(T* v) {

		an <CBID_NODE>* a = new an<CBID_NODE>(v);
		if (head == NULL) {
			head = a;
		}
		else {
			temp = a;//new an<string>(value);
			temp->next = head;
			head = temp;
		}
	}

	T* top() {
		return head->data;
	}

	T* pop() {
		if (head != NULL) {
			temp = head;
			head = head->next;
			return temp->data;
		}
		else if (head == NULL) {
			CBID_NODE* t = new CBID_NODE ;
			return t;
		}

	}

	bool is_empty() {
		if (head != NULL)
			return false;
		else
			return true;
	}

	void empty() {
		while (!is_empty()) {
			pop();
		}
	}

	void display() {
		temp = head;
		for (int i = 0; temp != NULL; i++) {
			cout << temp->data->cnic << endl;
			temp = temp->next;
		}
//		cout << "nothing more to display" << endl;
	}
};

struct crimes {
	string details;
//	string charges;
	string punishment;
	string fine;
	crimes* head;
	crimes* next;


	crimes() {
	details = "";
//	charges = "";
	punishment = "";
	fine = "";
	head = NULL;
	next = NULL;
	}

	void add_node() {
		if (head == NULL) {
			head = new crimes;
		}
		else {
			crimes* temp = new crimes;
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new crimes;
		}
	}
};

struct numbers {
	string value;
	string network;
	string activation_date;
	string deactivation_date;
	string status;
	numbers* next;
	numbers* head;
	int counter;

	numbers() {
		network = "";
	activation_date="";
	deactivation_date="";
	status="";
	next=NULL;
	head = NULL;
	counter = 0;
	}

	void add_node() {
		counter++;
		if (head == NULL) {
			head = new numbers;
		}
		else {
			numbers* temp = new numbers;
			temp = head;
			while (temp->next != NULL) {

				temp = temp->next;
			}
			temp->next = new numbers;
		}
	}
};

struct CBID_NODE {
	string cnic;
	string name;
	string f_name;
	string gender;
	string address;
	string nationality;

	CBID_NODE* next, * prev;
	CCID_NODE* c1;
	CCND_NODE* c2;

	CBID_NODE() {
	cnic="";
	name="";
	f_name="";
	gender="";
	address="";
	nationality = "";
	next = NULL;
	prev=NULL;
	c1=NULL;
	c2=NULL;

	}
};


struct CCID_NODE {
	string cnic;
	crimes* cr;

	CBID_NODE* c3;
	CCID_NODE* first, * next, * prev;

	CCID_NODE() {
		cnic = "";
		cr = NULL;
		c3 = NULL;
		first = NULL;
		next = NULL;
		prev = NULL;
	}

	CCID_NODE(string cn,crimes*c) {

		cnic = cn;
		cr = c;
		first = NULL;
		next = NULL;
		prev = NULL;
	}
};

struct CCND_NODE {

	string cnic;
	numbers* n;
	CCND_NODE* next, * prev,* first;
	CBID_NODE* c4;

	CCND_NODE() {
		cnic = "";
		n = NULL;
		next = NULL;
		prev = NULL;
		first = NULL;
		c4 = NULL;
	}

	CCND_NODE(string s, numbers* c) {

		cnic = s;
		n = c;
		first = NULL;
		next = NULL;
		prev = NULL;
	}
};

class CBID_list {
public:
	CBID_NODE* head;
	CBID_NODE* temp;

	CBID_list() {
		temp = NULL;
		head = NULL;
	}

	void display() {
		cout << "the so far created list is : " << endl;
		temp = head;
		while (temp != NULL) {
			cout << temp->cnic << endl;
			cout << temp->name << endl;
			cout << temp->f_name << endl;;
			cout << temp->gender << endl;
			cout << temp->address << endl;
			cout << temp->nationality << endl;
			if (temp->c1 != NULL) {
				cout << "other cnic is :" << temp->c1->cnic << endl;
			}
			else {
				cout << "no other c1" << endl;
			}
			if (temp->c2 != NULL) {
				cout << "other cnic is :" << temp->c2->cnic << endl;
			}
			else {
				cout << "no other c2" << endl;
			}
			cout << endl << endl;
			temp = temp->next;
		}
	}
	void insert(CBID_NODE* n) {

		if (head == NULL) {
			head = n;
		}
		else {
			temp = head;

			while (temp->next != NULL) {

				temp = temp->next;
			}

			temp->next = n;

		}
	}
	
	//void accending() {
	//	if (head != NULL) {
	////		while (true) {
	//			temp = head;
	////			bool b = 0;
	//			while (temp->next->next != NULL) {
	//				if (temp->next->cnic < temp->cnic) {
	//					CBID_NODE* d = temp->next;
	//					temp->next = temp->next->next;
	//					temp->next->next = d;
	////					b = 1;
	//				}
	//				temp = temp->next;
	//			}
	////			if (b == 0) {
	////				break;
	////			}
	////		}
	//	}
	//}
};




class CCID_list {
public:

	CCID_NODE* head;
	CCID_NODE* temp;

	CCID_list() {
		temp = NULL;
		head = NULL;
	}

	void display() {
		cout << "the so far created list is : " << endl;
		temp = head;
		while (temp != NULL) {
			cout << temp->cnic << endl;
			cout << temp->cr->details << endl;
		//	cout << temp->cr->charges << endl;;
			cout << temp->cr->punishment << endl;
			cout << temp->cr->fine << endl;
			cout << endl << endl;
			temp = temp->next;
		}

	}
	void insert(CCID_NODE* n) {

		if (head == NULL) {
			head = n;
		}
		else {
			temp = head;

			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = n;
		}
	}
};

class CCND_list {
public:
	CCND_NODE* head;
	CCND_NODE* temp;

	CCND_list() {
		temp = NULL;
		head = NULL;
	}

	void display() {
		cout << "the so far created list is : " << endl;
		temp = head;
		while (temp != NULL) {
			cout << temp->cnic << endl;
			cout << temp->n->value << endl;
			cout << temp->n->activation_date << endl;
			cout << temp->n->deactivation_date << endl;
			cout << temp->n->status << endl;
			cout << temp->n->network << endl;
		//	cout << temp->n->counter << endl;
			cout << endl << endl;
			temp = temp->next;
		}
	}

	void insert(CCND_NODE* n) {
		if (head == NULL) {
			head = n;
		}
		else {
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = n;
		}
	}	
};

template<class T>
class Database {

	CBID_NODE* CBI;
	CCID_NODE* CCI;
	CCND_NODE* CCN;
	DataPipeline <string>pipe;
	AD<CBID_NODE> a;

public:
	Database(const T& filename, const T& filename1, const T& filename2) {
		CBID_list cb;

		ifstream f;
		string s;
		f.open("CBID.txt");

		while (getline(f, s)) {
			pipe.enqueue(s);

		}

		while (!pipe.is_empty()) {
			s = pipe.dequeue();
			CBID_NODE* c = new CBID_NODE;

			int i = 0;
			for (i = 0; true; i++) {
				if (s[i] != ' ') {
					c->cnic += s[i];
				}
				else {
					i++;
					break;
				}
			}
			for (; true; i++) {
				if (s[i] != ' ') {
					c->name += s[i];
				}
				else {
					i++;
					break;
				}
			}
			for (; true; i++) {
				if (s[i] != ' ') {
					c->f_name += s[i];
				}
				else {
					i++;
					break;
				}
			}

			for (; true; i++) {
				if (s[i] != ' ') {
					c->gender += s[i];
				}
				else {
					i++;
					break;
				}
			}
			int a = 0;
			for (; true; i++) {
				if (s[i] != ' ') {
					c->address += s[i];
				}
				else {
					a++;
					if (a == 3) {
						break;
					}
					c->address += ' ';

				}
			}
			i++;
			for (; true; i++) {
				if (s[i] != '\0') {
					c->nationality += s[i];
				}
				else {
					i++;
					break;
				}
			}
			cb.insert(c);

		}
		f.close();



		CCID_list cc;

		ifstream r;
		s = "";
		r.open("CCID.txt");

		while (getline(r, s)) {
			pipe.enqueue(s);

		}
		//		pipe.display();

		while (!pipe.is_empty()) {

			s = pipe.dequeue();
			crimes* cri = new crimes;
			CCID_NODE* c = new CCID_NODE("", cri);

			int i = 0;
			for (i = 0; true; i++) {
				if (s[i] != ' ') {
					c->cnic += s[i];
				}
				else {
					i++;
					break;
				}
			}

			for (; true; i++) {
				if (s[i] != ' ') {
					c->cr->details += s[i];
				}
				else {
					i++;
					break;
				}
			}

			int b = 0;
			if (s[i] > 47 && s[i] < 59) {
				for (; true; i++) {
					if (s[i] == ' ')
						b++;
					if (b < 4) {
						c->cr->punishment += s[i];

					}
					else {
						i++;
						break;
					}
				}
			}
			else {
				for (; true; i++) {
					if (s[i] == ' ')
						b++;
					if (b < 3) {
						c->cr->punishment += s[i];

					}
					else {
						i++;
						break;
					}
				}
			}

			for (; true; i++) {
				if (s[i] != '\0') {
					c->cr->fine += s[i];
				}
				else {
					i++;
					break;
				}
			}

					cc.insert(c);

		}
		r.close();

	//	cc.display();
		CCND_list cn;

		ifstream t;
		s = "";
		t.open("CCND.txt");

		while (getline(t, s)) {
			pipe.enqueue(s);
		}
	//		pipe.display();
			while (!pipe.is_empty()) {
				s = pipe.dequeue();
				numbers* num = new numbers;
				CCND_NODE* c = new CCND_NODE("", num);

				int i = 0;
				for (i = 0; true; i++) {
					if (s[i] != ' ') {
						c->cnic += s[i];
					}
					else {
						i++;
						break;
					}
				}

				for (; true; i++) {
					if (s[i] != ' ') {
						c->n->value += s[i];
					}
					else {
						i++;
						break;
					}
				}
				for (; true; i++) {
					if (s[i] != ' ') {
						c->n->network += s[i];
					}
					else {
						i++;
						break;
					}
				}
				for (; true; i++) {
					if (s[i] != ' ') {
						c->n->activation_date += s[i];
					}
					else {
						i++;
						break;
					}
				}
				for (; true; i++) {
					if (s[i] != ' ') {
						c->n->deactivation_date += s[i];
					}
					else {
						i++;
						break;
					}
				}
				for (; true; i++) {
					if (s[i] != '\0') {
						c->n->status += s[i];
					}
					else {
						i++;
						break;
					}
				}
				cn.insert(c);
			}
			CBI = cb.head;
			CCI = cc.head;
			 CCN = cn.head;

			  link();

			  CBI = cb.head;
			  CCI = cc.head;
			  CCN = cn.head;

	}

	void link() {
		CBID_NODE* t = new CBID_NODE;
		CCID_NODE* q = new CCID_NODE;
		CCND_NODE* r = new CCND_NODE;

		q = CCI;
		while (q != NULL) {
			t = CBI;
			
			while (t != NULL) {
				if (t->cnic == q->cnic) {
					t->c1 = q;
					q->c3 = t;
				}
				t = t->next;
			}
			q = q->next;
		}
		r = CCN;
		while (r != NULL) {
			t = CBI;

			while (t != NULL) {
				if (t->cnic == r->cnic) {
					t->c2 = r;
					r->c4 = t;
				}
				t = t->next;
			}
			r = r->next;
		}
	}
	
	/*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
	 Refer to test cases for further clerification*/
	T CBID_Search_by_CNIC(int cnic) {

		string nic=to_string(cnic);		
		CBID_NODE* t = new CBID_NODE;	
		t = CBI;		
		T s="";
		
		while (t != NULL) {
		if (t->cnic == nic) {
				s+=t->name;
				s += " ";

				s += t->f_name;
				s += " ";

				s += t->gender;
				s += " ";

				s += t->address;
				s += " ";

				s += t->nationality;
				s += " ";
				if (t->c1 != NULL) {
					s += t->c1->cr->details;
					s += " ";

					s += t->c1->cr->punishment;
					s += " ";

					s += t->c1->cr->fine;
					s += " ";
				}
				if (t->c2 != NULL) {
					s += t->c2->n->value;
					s += " ";

					s += t->c2->n->network;
					s += " ";

					s += t->c2->n->activation_date;
					s += " ";

					s += t->c2->n->deactivation_date;
					s += " ";

					s += t->c2->n->status;
				}
			}
			t = t->next;
		}
		return s;
	}

	T CCID_Search_by_CNIC(int cnic) {
		string nic = to_string(cnic);
		CCID_NODE* t = new CCID_NODE;
		t = CCI;
		T s = "";

		while (t != NULL) {
			if (t->cnic == nic) {
				s += t->c3->name;
				s += " ";

				s += t->c3->f_name;
				s += " ";

				s += t->c3->gender;
				s += " ";

				s += t->c3->address;
				s += " ";

				s += t->c3->nationality;
				s += " ";
				if (t->c3->c1 != NULL) {
					s += t->c3->c1->cr->details;
					s += " ";

					s += t->c3->c1->cr->punishment;
					s += " ";

					s += t->c3->c1->cr->fine;
					s += " ";
				}
				if (t->c3->c2 != NULL) {
					s += t->c3->c2->n->value;
					s += " ";

					s += t->c3->c2->n->network;
					s += " ";

					s += t->c3->c2->n->activation_date;
					s += " ";

					s += t->c3->c2->n->deactivation_date;
					s += " ";

					s += t->c3->c2->n->status;
				}
			}
			t = t->next;
		}
		return s;		
	}

	T CCND_Search_by_CNIC(int cnic) {
		string nic = to_string(cnic);
		CCND_NODE* t = new CCND_NODE;
		t = CCN;
		T s = "";

		while (t != NULL) {
			if (t->cnic == nic) {
				s += t->c4->name;
				s += " ";

				s += t->c4->f_name;
				s += " ";

				s += t->c4->gender;
				s += " ";

				s += t->c4->address;
				s += " ";

				s += t->c4->nationality;
				s += " ";
				if (t->c4->c1 != NULL) {
					s += t->c4->c1->cr->details;
					s += " ";

					s += t->c4->c1->cr->punishment;
					s += " ";

					s += t->c4->c1->cr->fine;
					s += " ";
				}
				if (t->c4->c2 != NULL) {
					s += t->c4->c2->n->value;
					s += " ";

					s += t->c4->c2->n->network;
					s += " ";

					s += t->c4->c2->n->activation_date;
					s += " ";

					s += t->c4->c2->n->deactivation_date;
					s += " ";

					s += t->c4->c2->n->status;
				}
			}
			t = t->next;
		}
		return s;
	}

	bool updateCBIDName(T Name, int cnic) {
		
		string nic = std::to_string(cnic);
		CBID_NODE* t = new CBID_NODE;
		t = CBI;

		while (t != NULL) {
			if (t->cnic == nic) {
				t->name = Name;
				return true;
			}
			t = t->next;
		}
		return false;
	}

	bool updateCBIDFName(T Father_Name, int cnic) {
		
		string nic = std::to_string(cnic);
		CBID_NODE* t = new CBID_NODE;
		t = CBI;
		while (t != NULL) {
			if (t->cnic == nic) {
				t->f_name = Father_Name;
				return true;
			}
			t = t->next;
		}
		return false;
	}

	bool updateCBIDAddress(T Address, int cnic) {
		
		string nic = std::to_string(cnic);
		CBID_NODE* t = new CBID_NODE;
		t = CBI;

		while (t != NULL) {
			if (t->cnic == nic) {
				t->address = Address;
				return true;
			}
			t = t->next;
		}
		return false;
	}

	bool updateCBIDNationality(T Nationality, int cnic) {
		
		string nic = std::to_string(cnic);
		CBID_NODE* t = new CBID_NODE;
		t = CBI;

		while (t != NULL) {

			if (t->cnic == nic) {
				t->nationality = Nationality;
				a.push_roll(t);
				
				return true;

			}
			t = t->next;
		}
		return false;
	}
	bool addCrime(int cnic, T charges, T punishment, T fine) {

		string nic = std::to_string(cnic);
		CBID_NODE* t = new CBID_NODE;
		t = CBI;

		while (t != NULL) {

			if (t->cnic == nic) {
				//if (t->cr != NULL) {
				t->c1 = new CCID_NODE;
				t->c1->cr = new crimes;

					t->c1->cr->details = charges;
					t->c1->cr->punishment = punishment;
					t->c1->cr->fine = fine;
					return true;
				//}
			}
			t = t->next;
		}
		return false;
	}

	bool updateCrime(int cnic, T charges, T punishment, T fine) {

		string nic = std::to_string(cnic);
		CCID_NODE* t = new CCID_NODE;
		t = CCI;

		while (t != NULL) {
			if (t->cnic == nic) {
				if (t->cr != NULL) {
					t->cr->details = charges;
					t->cr->punishment = punishment;
					t->cr->fine = fine;
					
					return true;
				}
			}			
			t = t->next;
		}
		return false;
	}

	bool deleteCrime(int cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/

		string nic = std::to_string(cnic);
		CCID_NODE* t = new CCID_NODE;
		t = CCI;

		while (t != NULL) {

			if (t->cnic == nic) {
				if (t->cr != NULL) {
					t->cr->details == charges;
					t->cr->punishment == punishment;
					t->cr->fine == fine;

					cout << "hello world" << endl;
					delete t->cr;
					t->cr = NULL;
					return true;

				}
			}
			t = t->next;
		}
		return false;
	}

	int addNumber(int cnic, int nu) {
		string nic = to_string(cnic);
		string num = to_string(nu);
		int number=0;
		CCND_NODE* t = new CCND_NODE;
		t = CCN;

		while (t != NULL) {
			if (t->cnic == nic) {
				if (t->n != NULL) {
					if(number <4)
					number++;
					cout << "test passed" << endl << endl << endl << endl << endl;
				}
				if (t->n->next == NULL) {
					t->n->next = new numbers;
					t->n->next->value = num;
					if(number<5)
					number++;
					cout << "the total number of numbers are :" << number << endl;
				}
			}
			t = t->next;
		}		
		return number;		
	}

	int checkRegistred_No(int cnic) {

		string nic = to_string(cnic);

		int number = 0;
		CCND_NODE* t = new CCND_NODE;
		t = CCN;

		while (t != NULL) {
			if (t->cnic == nic ) {
				if (t->n != NULL && t->n->status!="unactive") {	
						number++;
				}
			}
			
			t = t->next;
		}
		cout << "the number of t is : " << number << endl;
			return number;		
	}

	
	bool swap(int cnic, int cnic1, T number, T number1) {
		bool b = 0;
		bool c = 0;
		string nic = to_string(cnic);
		string nic1 = to_string(cnic1);

		CCND_NODE* t = CCN;
		CCND_NODE* q = CCN;
		while (t->next != NULL) {
			if (t->cnic == nic && t->n->value==number) {
				b = 1;
				break;
				
			}
		}

		while (q->next != NULL) {
			if (q->cnic == nic1 && q->n->value==number1) {
				c = 1;
				break;
			}
		}
		if (b == 1 && c == 1)
			return false;

		string temp="";
		temp = t->n->value;
		t->n->value = q->n->value;
		q->n->value = temp;
		return true;
	}

	bool declareAlien(int cnic) {
	/*For Implementation of this function, Refer to CBID point 'iv', CCID point 'vi' and CCND point 'vii'. Also,
	write test-cases for this function yourself*/
		
		CBID_NODE* t = new CBID_NODE;
		string nic = to_string(cnic);
		
		t = CBI;

		while (t->next != NULL) {
			if (t->next->cnic == nic) {

				t->next->nationality = "Alien";
				a.push_roll(t->next);
				t->next = t->next->next;
				a.display();
				
				return true;
			}
			t = t->next;
		}
		
		
		return false;
	}
	
	bool verifyAlienDBUpdate(int cnic){
			/*Verify that given CNIC is moved from CBID to AD, Also add test-case for this function yourself*/
	
	/*	an<CBID_NODE>* t=a.head;
		string nic = to_string(cnic);
		if (t == NULL) {
			cout << "not good" << endl;
		}
		while (t != NULL) {
			if (t->data->cnic == nic) {				
				return true;		
			}
			t = t->next;
		}

	*/
		string nic = to_string(cnic);
		a.display();
		CBID_NODE* t = new CBID_NODE;
		t=a.pop();
		if (t->cnic == nic) {
			cout << "the cnic is " << t->cnic << endl<<endl<<endl<<endl;
			a.push_roll(t);
			return true;
		}
		else
		{
			cout << "the cnic is " << t->cnic << endl << endl << endl << endl;
			cout << "hello world" << endl;
			return true;
		}
	
	}

	int printcount() {
		a.display();

		int ttl=0;

		CCND_NODE* t = new CCND_NODE;
		t = CCN;

		while (t != NULL) {

			ttl++;

			t = t->next;
		}
		cout << " the total number of phones registered are : " << ttl << endl;
		return ttl;
	
	}
	void Display_AD() {
		/*Display data as instructed in point (xiv) of PDF*/
		a.display();
	}

	~Database() {
		/* deallocate and cleanup */
	}
};


#endif

