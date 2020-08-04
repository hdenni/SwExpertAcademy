/*
    1218. [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
*/
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    for(int test_case = 1; test_case <= 10; ++test_case)
	{
        int len;
        int flg = 1;
        int top = -1;
        cin >> len;
        
		char* stack = new char[len+1];
        char* input = new char[len+1];
        cin >> input;
        
        for(int i=0; i<len; i++){
            if(flg==0) break;
            if(input[i] == '{' || input[i] == '(' || input[i] == '<' || input[i] == '[') stack[++top] = input[i];
            else{
                if(top==-1) flg = 0;
                else{
                    char check = stack[(top)--];
                    if(input[i] == '}' && check == '{') continue;
                    else if (input[i] == ')' && check == '(') continue;
                    else if(input[i] == '>' && check == '<') continue;
                    else if(input[i] == ']' && check == '[') continue;
                    else flg = 0;
                }
            }
        }
        
        if(top!=-1) flg = 0;
        cout << "#" << test_case << " " << flg << endl;
	}
	return 0;
}
