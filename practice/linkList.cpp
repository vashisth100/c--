#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // operations :
    // {
    //     insertion,
    //     deletion,
    //     search
    // }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {

        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;

            head = head->next;
            temp->next = NULL;

            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
        }
    }

    void insert_val(int val, int pos)
    {
        if (pos < 0)
        {
            return;
        }
        else if (pos == 0)
        {
            push_front(val);
        }
        else
        {
            Node *newNode = new Node(val);

            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void delete_val(int val, int pos)
    {
        if (pos < 0)
        {
            return;
        }
        else if (pos == 0)
        {
            pop_front();
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            Node *delNode = temp->next;
            temp->next = delNode->next;

            delete delNode;
        }
    }

    int search(int val)
    {
        int idx = 0;
        Node *temp = head;
        while (temp != NULL)
        {

            if (temp->data == val)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // print list
    void print_list()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List lm;

    lm.push_front(1);
    lm.push_front(2);

    lm.push_back(4);
    lm.push_back(5);

    lm.pop_front();

    lm.pop_back();

    lm.insert_val(2, 1);
    lm.insert_val(0, 0);

    lm.delete_val(2, 2);

    lm.print_list();

    cout << lm.search(4) << endl;

    return 0;
}