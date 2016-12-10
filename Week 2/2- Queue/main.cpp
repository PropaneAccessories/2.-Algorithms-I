#include <iostream>
#include <string>

using namespace std;

class StringQueue
{
public:
    StringQueue() { lastNode = NULL;
                    firstNode = NULL; }
    // usage functions
    void queue(string str);
    void dequeue();
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
    node* firstNode;
};

int main()
{
    StringQueue container;
    container.queue("word1");
    container.queue("word2");
    container.queue("word3");
    cout << container.size() << endl;
    container.printAllWords();
    container.dequeue();
    container.dequeue();
    cout << container.size() << endl;
    container.printLastWord();

    return 0;
}

void StringQueue::queue(string str)
{
    node *n = new node;
    n->str = str;
    n->next = lastNode;
    lastNode = n;
}

void StringQueue::dequeue()
{
    node* temp = lastNode;
    lastNode = temp->next;
    delete temp;
}

bool StringQueue::isEmpty()
{
    if(lastNode == NULL) return true;
    else return false;
}

int StringQueue::size()
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

void StringQueue::printLastWord()
{
    if(lastNode != NULL)
        cout << lastNode->str << endl;
}

void StringQueue::printAllWords()
{
    node* loopPtr = lastNode;
    while(loopPtr != NULL)
    {
        cout << loopPtr->str << " ";
        loopPtr = loopPtr->next;
    }
    cout << endl;
}
