//program 9.2.2.cpp 非递归解汉诺塔问题
#include <iostream>
using namespace std;
struct Problem 
{
	int n;
	char src,mid,dest;
}; //一个Problem变量代表一个子问题，将src上的n个盘子，以mid为中介，移动到dest
Problem stack[200]; //用来模拟信封堆的栈，一个元素代表一个信封
                    //若有n个盘子，则栈的高度不超过 n * 3 
int main()
{
	cin >> stack[1].n;
	stack[1].src = 'A';
	stack[1].mid = 'B';
	stack[1].dest = 'C'; //上面初始化了第一个信封
	int problemNum = 1;  //相当于桌上信封数目
	while( problemNum > 0) { //只要还有信封，就继续处理
		Problem curProblem = stack[problemNum--]; //取最上面的信封，即当前问题
                                                    //problemNum-- 相当于丢弃一个信封
		if( curProblem.n == 1 ) 
			cout << curProblem.src << "->" << curProblem.dest << endl ;
		else { //分解子问题
			//先把分解得到的第3个子问题放入栈中
			stack[++problemNum].n = curProblem.n - 1;
			stack[problemNum].src = curProblem.mid;
			stack[problemNum].mid = curProblem.src;
			stack[problemNum].dest = curProblem.dest;
			//再把第2个子问题放入栈中
			stack[++problemNum].n = 1;
			stack[problemNum].src = curProblem.src;
			stack[problemNum].mid = curProblem.mid;
			stack[problemNum].dest = curProblem.dest;
			//最后放第1个子问题，后放入栈的子问题先被处理
			stack[++problemNum].n = curProblem.n - 1; 					
			stack[problemNum].src = curProblem.src;
			stack[problemNum].mid = curProblem.dest;
			stack[problemNum].dest = curProblem.mid;
		}
	}
	return 0;
}

