// ThreadPool.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ThreadPool.h"
#include <stdio.h>
#include <iostream>
using namespace std;
class Task
{
public:
	static int Task1(PVOID p) 
	{
		int i = 100;
		while (i >= 0)
		{
			printf("%d\n", i);
			//Sleep(100);
			i--;
		}
		return i;
	}
};

class TaskCallback
{
public:
	static void TaskCallback1(int result)
	{
		printf(" TaskCallback1  %d\n", result);
	}
};

int main()
{
	//(size_t minNumOfThread = 2, size_t maxNumOfThread = 10);
	ThreadPool threadPool(2, 10);
	/*for (size_t i = 0; i < 30; i++)
	{
		threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1);
	}*/
	threadPool.QueueTaskItem(Task::Task1, NULL, TaskCallback::TaskCallback1, TRUE);
	cout << "123213213" << endl;
	getchar();

    return 0;
}

