#include <iostream>
#include <string>

using namespace std;

class StringList
{
public:
    StringList() { lastNode = NULL; }
    // usage functions
    void push(string str);
    void pop();
    bool isEmpty();
    int size();
    // scaffolding functions
    void printLastWord();
    void printAllWords();

private:
    struct node
    {
        string str;
        node *next;
    };
    node* lastNode;
};

int main()
{
    StringList container;
    container.push("word1");
    container.push("word2");
    container.push("word3");
    cout << container.size() << endl;
    container.printAllWords();
    container.pop();
    container.pop();
    cout << container.size() << endl;
    container.printLastWord();

    return 0;
}

void StringList::push(string str)
{
    node *n = new node;
    n->str = str;
    n->next = lastNode;
    lastNode = n;
}

void StringList::pop()
{
    node* temp = lastNode;
    lastNode = temp->next;
    delete temp;
}

bool StringList::isEmpty()
{
    if(lastNode == NULL) return true;
    else return false;
}

int StringList::size()
{
    int counter = 0;
    node* loopPtr = lastNode;
    while(loopPtr != NULL)
    {
        counter++;
        loopPtr = loopPtr->next;
    }
    return counter;
}

void StringList::printLastWord()
{
    if(lastNode != NULL)
        cout << lastNode->str << endl;
}

void StringList::printAllWords()
{
    node* loopPtr = lastNode;
    while(loopPtr != NULL)
    {
        cout << loopPtr->str << " ";
        loopPtr = loopPtr->next;
    }
    cout << endl;
}
