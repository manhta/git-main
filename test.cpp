#include <iostream>
#include <string>

using namespace std;

struct Process {
    string id;
    string name; 
    int priority;   
};

struct node {
    Process process;
    node *pre;
    node *next;
};

struct Priority_Queue {
    node *head;
};

Process MakeProcess() {
    Process process;
    cout << "Nhap id: "; cin >> process.id;
    cout << "Nhap ten: "; cin.ignore(); getline(cin,process.name);
    cout << "Nhap muc do uu tien: "; cin >> process.priority; cout <<endl;
    return process;
}

node *MakeNode() {
    node *temp=new node;
    temp->next=NULL;
    temp->pre=NULL;
    temp->process=MakeProcess();
    return temp;
}

void ini(Priority_Queue &pr_queue) {
    pr_queue.head=NULL;
    return;
}

int Size(Priority_Queue pr_queue) {
    int size=0;
    node *p=pr_queue.head;
    while (p!=NULL) {
        size++;
        p=p->next;
    }
    return size;
} 

int findPos(Priority_Queue pr_queue, int node_priority) {
    int pos = 0;
    node *p=pr_queue.head;
    while (p!=NULL) {
        if (p->process.priority <= node_priority) {
            pos++;
        }
        p=p->next;
    }
    return pos;
}

void AddHead(Priority_Queue &pr_queue,node *temp) {
    temp->next=pr_queue.head;
    pr_queue.head->pre=temp;
    pr_queue.head=temp;
    return;
}

void AddTail(Priority_Queue &pr_queue, node *temp) {
    node *p=pr_queue.head;
    while (p->next != NULL) {
        p=p->next;
    }
    p->next=temp;
    temp->pre=p;
}

void AddAt(Priority_Queue &pr_queue,node *temp,int pos) {
    node *p=pr_queue.head;
    for (int i=0;i<pos-1;i++) {
        p=p->next;
    }
    temp->next=p->next;
    temp->pre=p;
    p->next->pre=temp;
    p->next=temp;
    return;
}

void Push(Priority_Queue &pr_queue) {
    if (pr_queue.head == NULL){
        pr_queue.head = MakeNode();
    } else {
        node *temp = MakeNode();
        int pos = findPos(pr_queue,temp->process.priority);
        if (pos == 0) {
            AddHead(pr_queue,temp);
        } else if (pos == (Size(pr_queue))) {
            AddTail(pr_queue,temp);
        } else {
            AddAt(pr_queue,temp,pos);
        }
    }
    return;
}

void Pop(Priority_Queue &pr_queue) {
    if (pr_queue.head == NULL) {
        return;
    } else {
        node *temp=pr_queue.head;
        pr_queue.head = pr_queue.head->next;
        pr_queue.head->pre=NULL;
        delete(temp);
    }
    return;
}

Process Front(Priority_Queue pr_queue) {
    return pr_queue.head->process;
}

Process Back(Priority_Queue pr_queue) {
    node *p=pr_queue.head;
    while (p->next!=NULL) {
        p=p->next;
    }
    return p->process;
}

void PrintProcess(Process p) {
    cout << "Id: " << p.id << endl;
    cout << "Name: " << p.name << endl;
    cout << "Priority: " << p.priority << endl;
    cout << "________________" << endl;
}

void Print(Priority_Queue pr_queue) {
    node *p=pr_queue.head;
    while (p!=NULL) {
        PrintProcess(p->process);
        p=p->next;
    }
}

int main() {
    Priority_Queue pr_queue;
    ini(pr_queue);
    int n; cin >> n;
    for (int i=1;i<=n;i++) {
        Push(pr_queue);
    }
    PrintProcess(Front(pr_queue));
    PrintProcess(Back(pr_queue));
}