//
//  main.cpp
//  Postfix_Tutoring
//
//  Created by Miguel Bazán on 10/6/15.
//  Copyright © 2015 MiguelBazan. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

int stoi2 (string st)
{
    int sale = 0;
    
    for (int iR = 0; iR< st.length(); iR++)
    {
        sale = sale * 10 + st[iR] - '0';
    }
    return sale;
}
int main(int argc, const char * argv[])
{
    string d,data;
    int num1,nume2;
    
    getline(cin,data);
    
    while (data != "#"){
        queue<int> listaqueue;
        stack<int>  listastack;
        priority_queue<int,vector<int>,greater<int> > listapriority;
        stringstream ss;
        
        ss<<data;
        
        while (ss >> d){
            
            if (d == "+"){
                //Stack
                num1 = listastack.top();
                listastack.pop();
                nume2 = listastack.top();
                listastack.pop();
                listastack.push(nume2 + num1);
                
                //Queue
                num1 = listaqueue.front();
                listaqueue.pop();
                nume2 = listaqueue.front();
                listaqueue.pop();
                listaqueue.push(nume2 + num1);
                
                //Priority
                num1 = listapriority.top();
                listapriority.pop();
                nume2 = listapriority.top();
                listapriority.pop();
                listapriority.push(nume2 + num1);

            }
            else if (d == "-"){
                //Stack
                num1 = listastack.top();
                listastack.pop();
                nume2 = listastack.top();
                listastack.pop();
                listastack.push(nume2 - num1);
                
                //Queue
                num1 = listaqueue.front();
                listaqueue.pop();
                nume2 = listaqueue.front();
                listaqueue.pop();
                listaqueue.push(nume2 - num1);
                
                // Priority
                num1 = listapriority.top();
                listapriority.pop();
                nume2 = listapriority.top();
                listapriority.pop();
                listapriority.push(nume2 - num1);
            }
            else if (d == "*"){
                //Stack
                num1 = listastack.top();
                listastack.pop();
                nume2 = listastack.top();
                listastack.pop();
                listastack.push(nume2 * num1);
                
                //Queue
                num1 = listaqueue.front();
                listaqueue.pop();
                nume2 = listaqueue.front();
                listaqueue.pop();
                listaqueue.push(nume2 * num1);
                
                //Priority
                num1 = listapriority.top();
                listapriority.pop();
                nume2 = listapriority.top();
                listapriority.pop();
                listapriority.push(nume2 * num1);
            }
            else {
            listaqueue.push(stoi2(d));
            listastack.push(stoi2(d));
            listapriority.push(stoi2(d));
            }
        }
        cout<<listastack.top()<<" "<<listaqueue.front()<<" "<<listapriority.top()<<endl;

        getline(cin,data);
    }
    
    return 0;
}
