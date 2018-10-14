#include <bits/stdc++.h>
using namespace std;
vector<string> preParse(char *str) //对中缀表达式进行预处理，分离出每个token
{
  vector<string> tokens;
  int len = strlen(str);
  char *p = (char *)malloc(
      (len + 1) *
      sizeof(
          char)); //注意不要用 char *p = (char *)malloc(sizeof(str))来申请空间
  int i = 0, j = 0;
  while (i < len) //去除表达式中的空格
  {
    if (str[i] == ' ') {
      i++;
      continue;
    }
    p[j++] = str[i++];
  }
  p[j] = '\0';
  j = 0;
  len = strlen(p);
  while (j < len) {
    char temp[2];
    string token;
    switch (p[j]) {
    case '+':
    case '*':
    case '^':
    case '/':
    case '(':
    case ')': {
      temp[0] = p[j];
      temp[1] = '\0';
      token = temp;
      tokens.push_back(token);
      break;
    }
    case '-': {
      if (p[j - 1] == ')' || isdigit(p[j - 1])) //作为减号使用
      {
        temp[0] = p[j];
        temp[1] = '\0';
        token = temp;
        tokens.push_back(token);
      } else //作为负号使用
      {
        temp[0] = '#';
        temp[1] = '\0';
        token = temp;
        tokens.push_back(token);
      }
      break;
    }
    default: //是数字
    {
      i = j;
      while (isdigit(p[i]) && i < len) {
        i++;
      }
      char *opd = (char *)malloc(i - j + 1);
      strncpy(opd, p + j, i - j);
      opd[i - j] = '\0';
      token = opd;
      tokens.push_back(token);
      j = i - 1;
      free(opd);
      break;
    }
    }
    j++;
  }
  free(p);
  return tokens;
}

int getPriority(string opt) {
  int priority;
  if (opt == "#")
    priority = 4;
  else if (opt == "^")
    priority = 3;
  else if (opt == "*" || opt == "/")
    priority = 2;
  else if (opt == "+" || opt == "-")
    priority = 1;
  else if (opt == "(")
    priority = 0;
  return priority;
}
void calculate(stack<int> &opdStack, string opt) {
  if (opt == "#") //进行负号运算
  {
    int opd = opdStack.top();
    int result = 0 - opd;
    opdStack.pop();
    opdStack.push(result);
  } else if (opt == "^") {
    int rOpd = opdStack.top();
    opdStack.pop();
    int lOpd = opdStack.top();
    opdStack.pop();
    int result = 1;
    for (int i = 1; i <= rOpd; ++i)
      result = result * lOpd;
    opdStack.push(result);
  } else if (opt == "+") {
    int rOpd = opdStack.top();
    opdStack.pop();
    int lOpd = opdStack.top();
    opdStack.pop();
    int result = lOpd + rOpd;
    opdStack.push(result);
  } else if (opt == "-") {
    int rOpd = opdStack.top();
    opdStack.pop();
    int lOpd = opdStack.top();
    opdStack.pop();
    int result = lOpd - rOpd;
    opdStack.push(result);
  } else if (opt == "*") {
    int rOpd = opdStack.top();
    opdStack.pop();
    int lOpd = opdStack.top();
    opdStack.pop();
    int result = lOpd * rOpd;
    opdStack.push(result);
  } else if (opt == "/") {
    int rOpd = opdStack.top();
    opdStack.pop();
    int lOpd = opdStack.top();
    opdStack.pop();
    int result = lOpd / rOpd;
    opdStack.push(result);
  }
}

int evaMidExpression(char *str) //中缀表达式直接求值
{
  vector<string> tokens = preParse(str);
  int i = 0;
  int size = tokens.size();

  stack<int> opdStack;    //存储操作数
  stack<string> optStack; //存储操作符
  for (i = 0; i < size; i++) {
    string token = tokens[i];
    if (token == "#" || token == "^" || token == "+" || token == "-" ||
        token == "*" || token == "/") {
      if (optStack.size() == 0) //如果操作符栈为空
      {
        optStack.push(token);
      } else {
        int tokenPriority = getPriority(token);   //当前操作符的优先级
        string topOpt = optStack.top();           //取栈顶操作符
        int topOptPriority = getPriority(topOpt); //栈顶操作符的优先级
        if (tokenPriority >
            topOptPriority) //如果当前的操作符的优先级高于栈顶操作符的优先级，则进栈
        {
          optStack.push(token);
        } else {
          while (tokenPriority <= topOptPriority) {
            optStack.pop();
            calculate(opdStack, topOpt);
            if (optStack.size() > 0) {
              topOpt = optStack.top();
              topOptPriority = getPriority(topOpt);
            } else
              break;
          }
          optStack.push(token);
        }
      }
    } else if (token == "(") {
      optStack.push(token);
    } else if (token == ")") {
      while (optStack.top() != "(") {
        string topOpt = optStack.top();
        calculate(opdStack, topOpt);
        optStack.pop();
      }
      optStack.pop(); //删掉"("
    } else            //如果是操作数，直接入操作数栈
    {
      opdStack.push(
          atoi(token.c_str())); // atoi (表示)是把字符串转换成整型数的一个函数，
    }
  }
  while (optStack.size() != 0) {
    string topOpt = optStack.top();
    calculate(opdStack, topOpt);
    optStack.pop();
  }
  return opdStack.top();
}

char buf[1000033];
int main() {
  // string str;
  // while(cin>>str)
  // {
  // std::getline(cin, str);
  //      char *str = "((3+5*2)+3)/5+(-6)/4*2+3"
  gets(buf);
  cout << evaMidExpression(buf) << endl;
  // }

  return 0;
}
