#include <cctype>
#include <map>
#include <sstream>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <stack>
#include <stdio.h>

using namespace std;

int summa(string s)
{
    string srpn;
    string::size_type ind;
    while ((ind = s.find(' ')) != string::npos)
    {
        s.erase(ind, 1);
    }
    map<char, size_t> map;
    map.insert(make_pair('*', 3));
    map.insert(make_pair('/', 3));
    map.insert(make_pair('+', 2));
    map.insert(make_pair('-', 2));
    map.insert(make_pair('(', 1));
    stack<char> stack;
    for (auto c : s)
    {
        if (!isdigit(c)) {
            srpn += ' ';
            if (')' == c) {
                while (stack.top() != '(')
                {
                    srpn += stack.top();
                    stack.pop();
                    srpn += ' ';
                    std::cout << srpn << std::endl;
                }
                stack.pop();
            }
            else if ('(' == c) {
                stack.push(c);
            }
            else if (stack.empty() || (map[stack.top()] < map[c])) {
                stack.push(c);
            }
            else
            {
                do
                {
                    
                    srpn += stack.top();
                    srpn += ' ';
                    stack.pop();
                    std::cout << srpn << std::endl;
                } while (!(stack.empty() || (map[stack.top()] < map[c])));
                stack.push(c);
            }
            
        }
        else {
            srpn += c;
            std::cout << srpn << std::endl;
        }
    }
    while (!stack.empty())
    {
        srpn += stack.top();
        srpn += ' ';
        stack.pop();
        std::cout << srpn << std::endl;
    }

    std:: stack<double> dstack;
    stringstream ss(srpn);
    double d, d1;
    char c;
    while (ss.get(c))
    {
        if (isdigit(c))
        {
            ss.unget();
            ss >> d;
            dstack.push(d);
        }
        else if (!isspace(c))
        {
            d1 = dstack.top();
            dstack.pop();
            d = dstack.top();
            dstack.pop();
            switch (c)
            {
                case '+':
                    dstack.push(d + d1);
                    break;
                case '-':
                    dstack.push(d - d1);
                    break;
                case '*':
                    dstack.push(d * d1);
                    break;
                case '/':
                    dstack.push(d / d1);
                    break;
            }
        }
    }
    int k;
    if (!dstack.empty())
    {
        k = dstack.top();
        dstack.pop();

    }
    return k;
}


int main() {
    std::string buffer;
    std::getline(std::cin, buffer);
    std::cout << summa(buffer);
    return 0;
}