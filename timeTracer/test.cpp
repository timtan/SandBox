#include<iostream>
#include<cstdio>
#include"time_tracer.h"
#include"../Logger/logger.h"
#include"unistd.h"
using namespace std;
int main(int argc, const char *argv[])
{
	Timer t("T"); 
	t.begin();
	sleep(2);
	t.end();
	printf("%f" , t.duration() );

	return 0;
}
