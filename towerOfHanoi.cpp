#include <iostream>
using namespace std;

class Stack {
private:
    string stackName;
    int size; 
    int top; 
    int *arr; 

public:
    Stack(int s, string name) {
        size = s;
        top = -1; 
        arr = new int[size];
        stackName  = name;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << stackName << " Overflow. Cannot push element.\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed " << value << " into the " << stackName << "\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << stackName << " Underflow. Cannot pop element.\n";
            return -1; 
        }
        int poppedValue = arr[top--];
        cout << "Popped " << poppedValue << " from the " << stackName << "\n";
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << stackName <<  " is empty.\n";
            return -1; 
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << stackName << " is empty.\n";
            return;
        }
        cout << stackName << " elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int totalElements(){
        return (top+1);
    }
};
void towerOfHanoi(int num, Stack *rod1, Stack *rod2, Stack *rod3){
    if(num == 1){
        rod3->push(rod1->pop());
        return;
    }
    towerOfHanoi(num - 1, rod1, rod3, rod2);
    rod3->push(rod1->pop());
    towerOfHanoi(num - 1, rod2, rod1,  rod3);
}

int main() {
    Stack rod1(4, "rod1");
    Stack rod2(4, "rod2");
    Stack rod3(4, "rod3");

    //pushing elements in first stack(rod1)
    rod1.push(10);
    rod1.push(7);
    rod1.push(4);
    rod1.push(1);

    //displaying the count of elements in each stack
    cout<< rod1.totalElements() << endl;
    cout<< rod2.totalElements() << endl;
    cout<< rod3.totalElements() << endl;

    //displaying elements of stacks (rods)
    rod1.display();
    rod2.display();
    rod3.display();

    //function solving the tower of hanoi
    towerOfHanoi(rod1.totalElements(), &rod1, &rod2, &rod3);
    cout<< rod1.totalElements() << endl;
    cout<< rod2.totalElements() << endl;
    cout<< rod3.totalElements() << endl;

    //displaying elements of stacks(rods)
    rod1.display();
    rod2.display();
    rod3.display();

    return 0;
}
