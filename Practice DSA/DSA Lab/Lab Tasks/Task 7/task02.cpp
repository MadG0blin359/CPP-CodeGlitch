//#include <iostream>
//#include <stack>
//using namespace std;
//
//class QueueUsingStack {
//private:
//    stack<int> s1; 
//
//    // Function to transfer elements from s1 to s2 recursively
//    void transferToTempStack(stack<int>& s2) {
//        if (s1.empty()) {
//            return;
//        }
//        // Pop the top element from s1
//        int temp = s1.top();
//        s1.pop();
//        s2.push(temp);
//
//        // Recursively call to pop the next element
//        transferToTempStack(s2);
//    }
//
//public:
//  
//    void enqueue(int value) {
//        cout << value << ", ";
//        s1.push(value);
//    }
//
//
//    int dequeue() {
//        if (s1.empty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//
//        stack<int> s2; // Temporary stack to hold elements
//        transferToTempStack(s2); // Transfer all elements to s2
//
//        // Now the top of s2 is the front of the queue
//        int frontValue = s2.top();
//        s2.pop();
//
//        // Transfer elements back to s1
//        while (!s2.empty()) {
//            s1.push(s2.top());
//            s2.pop();
//        }
//
//        return frontValue;
//    }
//
//    
//    bool isEmpty() {
//        return s1.empty();
//    }
//
//  
//    int front() {
//        if (s1.empty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//
//        stack<int> s2; // Temporary stack to hold elements
//        transferToTempStack(s2); // Transfer all elements to s2
//
//        int frontValue = s2.top();
//
//        // Transfer elements back to s1
//        while (!s2.empty()) {
//            s1.push(s2.top());
//            s2.pop();
//        }
//
//        return frontValue;
//    }
//};
//
//int main() {
//    QueueUsingStack q;
//
//    cout << "Enqueing Elements... " << endl;
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//    cout << "\n\nFront element : " << q.front() << endl;
//
//    cout << "Dequeued : " << q.dequeue() << endl;
//    cout << "Dequeued : " << q.dequeue() << endl;
//
//    cout << "Front element : " << q.front() << endl;
//
//    cout << "Enqueing Elements... " << endl;
//    q.enqueue(40);
//    q.enqueue(50);
//
//    cout << "\n\nDequeing All Elements... " << endl;
//    while (!q.isEmpty()) {
//        cout << "Dequeued : " << q.dequeue() << endl;
//    }
//
//    system("pause");
//    return 0;
//}
