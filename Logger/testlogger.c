#define LOGIT
#define LOG_LEVEL_ 2
#include "logger.h"
int main(int argc, const char *argv[])
{
	consoleLogger( 1 , "First" );	
	consoleLogger( 2 , "Second %s" , "TWO" );	
	consoleLogger( 3 , "Third %s %d" , "Third" , 3 );	
	
	return 0;
}
