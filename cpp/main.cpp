/**
 * @file main.cpp
 * @brief
 * Given a string s of '(', ')' and lowercase of English characters.
 * Your task is to remove the minimum number of parentheses so that the resoulting parentheses string is valid and retun any valid string.
 */
#include <iostream>
#include <stack>
using namespace std;

string removeParentheses(string s) {
  stack<int> indices;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(') {
      indices.push(i);
    } else if (s[i] == ')') {
      if (!indices.empty()) {
        indices.pop();
      }else {
        s[i] = ' ';
      }
    }
  }

  while (!indices.empty()) {
    s[indices.top()] = ' ';
    indices.pop();
  }

  string result = "";
  for (char ch : s) {
    if (ch != ' ') {
      result += ch;
    }
  }
  return result;
}

int main() {
  string s = "))a)b(((c)d()"; // output: ab(c)d()

  string result = removeParentheses(s);
  cout << "Valid String: " << result << endl;

  return 0;
}
