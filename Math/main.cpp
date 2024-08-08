#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "LinkedList.hpp"
using namespace std;

enum op{
    ADD,SUB,MUL,DIV,LB,RB,EQ,TOTAL_SYMBAL
};
char op_str[] = {
    '+','-','*','/','(',')','='
};
int op_priority[] = {
    1,1,2,2,0,-1,-1
};

typedef struct
{
    bool is_symbal; // symbal or number
    union
    {
        double value; // number use value
        int    op;   // symbal use op
    };
}token;

int stoop(char c) // string to operator code
{
    for(int i = 0;i < TOTAL_SYMBAL;i++)
    {
        if(op_str[i] == c) return i;
    }
    cout << "Operator Symbal Error: "<< c << endl;
    exit(-1);
}

double calculate(double a, double b, int op)
{
    double ans;
    switch (op)
    {
    case ADD:
        ans = a + b;
        break;
    case SUB:
        ans = a - b;
        break;
    case MUL:
        ans = a * b;
        break;
    case DIV:
        ans = a / b;
        break;
    default:
        ans = 0;
        break;
    }
    return ans;
}

int main(int argc, char* argv[])
{
    /*
        1,"+",2,"+",3 (infix)
        1,2,"+",3,"+" (posfix)
    */

   /*
        1+2*3 (infix)
        123*+ (posfix)
    */

   /*
        (1+2)*3 (infix)
        12+3* (posfix)
    */
   /*
        1. infix to postfix
        2. postfix to calculate answer
        use STACK
   */

    /* 0. parse string
        -> a. number (string to double)
        -> b. operator symbal (string to int code)
    */
    if(argc != 2){
        cout << "usage: Type in the Mathematical expressions." << endl;
        return 0;
    }

    string s = argv[1]; // get the expressions from CLI
    string temp = "";
    vector<token> parsed;
    for(char c : s)
    {
        if(c >= '0' && c <= '9' || c == '.') // ASCII: 如果該字(char)是數字(0~9)或是小數點(.)
        {
            temp+=c; // 視為同一串"數值字串"，因此加入 tmep string 當中
        }
        else{ // 該 char 是一個運算符號(operator symbal)
            token t;
            if(temp!="") // 如果temp有累積數字，就一並轉換成 double 並存成 token
            {
                t.is_symbal = false;
                t.value = stod(temp);// string to double
                parsed.push_back(t);
            }
            // 存入一個 symbal token
            t.is_symbal = true;
            t.op = stoop(c);
            parsed.push_back(t);
            temp = "";
        }
    }
    // print out for check
    for(auto t : parsed)
    {
        if(t.is_symbal) cout << op_str[t.op] << " ";
        else cout << t.value << " ";
    }
    cout << endl;

    /* 1. infix to postfix */
    Stack<token> stack;
    vector<token> postfix;
    for(auto t:parsed) // parsed (infix)
    {
        if(t.is_symbal){
            // compare priority
            if(t.op == LB) {
                stack.push(t);
            }
            else if(t.op == RB){
                while (stack.peek().op != LB)
                {
                    postfix.push_back(stack.pop());
                }
                // erease "("
                stack.pop();
            }
            else if(t.op == EQ) // clear stack
            {
                while(!stack.empty()){
                    postfix.push_back(stack.pop());
                }
                postfix.push_back(t); // push "=" to postfix
            }
            else
            {
                // stack 不是空的並且 priority 比手上的(t) 還要高或是相等，需要先將其 pop 出來
                while(!stack.empty() && op_priority[t.op] <= op_priority[stack.peek().op])
                {
                    postfix.push_back(stack.pop());
                }
                stack.push(t); // 再將手上的 token push 到 stack
            }
        }
        else{
            postfix.push_back(t); // number;
        }
    }
    // print out for check
    for(auto t : postfix)
    {
        if(t.is_symbal) cout << op_str[t.op] << " ";
        else cout << t.value << " ";
    }
    cout << endl;

    /* 2. postfix to calculate answer */
    stack.clear();
    double a,b;

    for(auto t:postfix)
    {
        if(t.is_symbal){
            if(t.op == EQ)
            {
                cout << stack.pop().value << endl; // pop the last value in the stack
            }
            else{
                // 1. pop two number
                b = stack.pop().value; // FILO (right)
                a = stack.pop().value; // FILO (left)
                // 2. calculate
                token ans;
                ans.is_symbal = false;
                ans.value = calculate(a,b,t.op); // calculate(val, val, operand)
                // 3. push answer
                stack.push(ans);
            }
        }
        else{
            // push number to stack
            stack.push(t);
        }
    }

    return 0;
}
