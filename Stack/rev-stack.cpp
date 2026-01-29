#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack <int> &s, int val){ //O(n)
    if(s.empty()){ //base case
        s.push(val); //push at the bottom of stack
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

void reverseStack(stack <int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

void printStack(stack <int> s){
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    stack <int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);

    reverseStack(s);
    printStack(s);

    
    return 0;
}

/*
DRY RUN & EXPLANATION:

Initial Stack: [3, 2, 1] (top is 1)

=== reverseStack(s) Execution ===

Call 1: reverseStack(s)
- temp = 1
- pop() → Stack becomes [3, 2]
- Call reverseStack(s)

Call 2: reverseStack(s)
- temp = 2
- pop() → Stack becomes [3]
- Call reverseStack(s)

Call 3: reverseStack(s)
- temp = 3
- pop() → Stack becomes []
- Call reverseStack(s)

Call 4: reverseStack(s)
- Stack is empty → RETURN (base case)

=== Stack Unwinding (Backtracking) ===

Back to Call 3:
- Stack is []
- temp = 3
- Call pushAtBottom(s, 3)
  - Stack is empty → push(3) → Stack becomes [3]
- Stack: [3]

Back to Call 2:
- Stack is [3]
- temp = 2
- Call pushAtBottom(s, 2)
  - Remove 3: temp2 = 3, Stack becomes []
  - Call pushAtBottom(s, 2)
    - Stack empty → push(2) → Stack becomes [2]
  - Push back 3 → Stack becomes [2, 3]
- Stack: [2, 3]

Back to Call 1:
- Stack is [2, 3]
- temp = 1
- Call pushAtBottom(s, 1)
  - Remove 3: temp = 3, Stack becomes [2]
  - Call pushAtBottom(s, 1)
    - Remove 2: temp = 2, Stack becomes []
    - Call pushAtBottom(s, 1)
      - Stack empty → push(1) → Stack becomes [1]
    - Push back 2 → Stack becomes [1, 2]
  - Push back 3 → Stack becomes [1, 2, 3]
- Final Stack: [1, 2, 3] (top is 3)

=== How Reversal Works ===
1. reverseStack() uses recursion to pop all elements, storing them in the call stack
2. During unwinding, each popped element is inserted at the BOTTOM using pushAtBottom()
3. pushAtBottom() recursively removes all elements, pushes the new value when stack is empty,
   then pushes back all removed elements
4. The last element popped (3) gets pushed at bottom first, then 2, then 1 - reversing the order!

Output:
1 2 3  (original - top to bottom)
3 2 1  (reversed - top to bottom)
*/