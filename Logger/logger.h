#ifdef LOGIT 
#ifndef LOG_LEVEL_
#define LOG_LEVEL_ 100  //level below LOG_LEVEL_ will be loged 
#endif  
#include<pthread.h>
#include<stdarg.h>
#include<stdio.h>

#define RESET		0
#define BRIGHT 		1
#define DIM		2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

static
void textcolor(int attr, int fg, int bg);
pthread_mutex_t mutex;
inline 
void consoleLogger( int level , const char* msg, ... ){
	if( level > LOG_LEVEL_){
		return ;
	}
    va_list vl ;
    va_start(vl, msg);
    FILE * logdevice = stdout;

    pthread_mutex_lock( &mutex );
	textcolor( BRIGHT, level , BLACK );

    vfprintf(logdevice ,msg , vl);
    fprintf( logdevice , "\n" );
	textcolor( RESET, WHITE, BLACK );

    pthread_mutex_unlock( &mutex );
    va_end(vl);

    return ;
}
/**  usage.
int main()
{	textcolor(BRIGHT, RED, BLACK);	
	printf("In color\n");
	textcolor(RESET, WHITE, BLACK);	
	return 0;
}
**/
inline static 
void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}


#else
inline void consoleLogger( int level , const char* msg, ... )
{return; }
#endif
