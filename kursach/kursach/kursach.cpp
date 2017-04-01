#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <conio.h>
using namespace std;
 
class element   
{
public:
int value;
element* next;
};//класс эл-та
 
class Queue 
{
public:
int size;
element* head;
element* headTmp;
element* tail;
element* tailTmp;
element* first;
element* tail1;
 
Queue()
{
	first=NULL;
size=0;tail1=NULL;
head=0;headTmp=0;
tail=0;tailTmp=0;

}
 
void Enqueue(int);
void Dequeue();
int isEmpty();
int getQueueSize();
void printQueueSize();
void printQueueElements();
void sortQueueElements();
void printQueueMenu();
int getVal(int n);
void setVal(int n, int nul);
void reset(){head=first;}
};
 
void Queue::Enqueue(int ele) //Добавление элементов
{
    if(head==0)            // первый эл-т
    {
        head=new element;
        tail=head;       //head==tail если 1-ин эл-т
        head->value=ele;
        head->next=0;
    }
    else
    {
        tail->next=new element;
        tail->next->value=ele;
        tail->next->next=0;
        cout<<tail->next->value<<endl;
        tail=tail->next;
    }
       size++;
 
//printQueueElements();
}
 
void Queue::Dequeue()//Удаление элементов
{
if(getQueueSize()==0)
return;
else if(head==tail)
{
head=0;
}
else
{
element *curr; //удаление первого эл-та
curr=head;           //и присвоение головы второму
head=curr->next;
curr=0;
}
size--;
}
 
int Queue::isEmpty()
{
    if(getQueueSize()==0)
    return 1;
 
    return 0;
}
 
int Queue::getQueueSize()
{
return size;
}//returns size of the Queue

int Queue::getVal(int n){
	 element* curr2;
        curr2= head;
	reset();
	for (int i = 1; i <= n; i++)
		curr2 = head->next;
	return curr2->value;


}
 
void Queue::printQueueSize() // Размер очереди
{
cout<<"\nРазмер очереди: "<<size<<"\n";
}
 
void Queue::printQueueElements()
{
    element* curr2;
        curr2= head;
        cout<<"\n-------\n";
        cout<<"Очередь\n";
        cout<<"-------\n";
        cout<<"Размер: "<<getQueueSize()<<endl<<endl;
    while(curr2!=0)
        {
            cout<<" |"<<curr2->value<<"|";
            curr2=curr2->next;
        }
        cout<<endl;
}// печать очереди
 void Queue::setVal(int n, int val){
	 reset();
	 element* curr2;
	 curr2=head;
		for (int i = 1; i < n; i++){
		if (curr2->next == NULL){
			tail1 = new element;
			curr2->next = new element;
			tail1 = head->next;
			tail1->next = NULL;
			tail1->value = 0;
			curr2 = head->next;
		}else	
			curr2 = head->next;
		tail1 = NULL;
	}
		
	curr2->value = val;

}

void Queue::sortQueueElements() //Сортировка
{ int i,j,a;
//Queue head;
for (i = size - 1; i >= 0; i--){
reset();
for (j = 0; j<i; j++)
if (getVal(j)>getVal(j + 1)){
a = getVal(j);
setVal(j, getVal(j + 1));
setVal(j + 1, a);
 }
}
}
void Queue::printQueueMenu()
{system("CLS");
cout<<"\tДобро пожаловать \n\n";
cout<<"1. Добавить элемент\n";
cout<<"2. Удалить элемент\n";
cout<<"3. Отобразить всю очередь\n";
cout<<"4. Размер очереди\n";
cout<<"5. Отсортировать очередь\n";
cout<<"0. Выйти\n";
}
 
void main()
{
    setlocale (LC_ALL, "");
    Queue qt;
    char Option=0;
    int val;
    while(1)
        {
        qt.printQueueMenu();
        Option = _getch();
        switch(Option)
        {
        case '1':
            cout<<"Введите число: \n";
        cin>>val;
        qt.Enqueue(val);
        break;
        case '2':
        qt.Dequeue();
        break;
        case '3':
        qt.printQueueElements();
        break;
        case '4':
        qt.printQueueSize();
        break;
        case '5':
        qt.sortQueueElements();
        break;
        case '0':
        exit(0);
        break;
        }
        system("PAUSE");
    }       
}