#include<string>
#include<time.h>

#include<iostream>
using namespace std;
//using namespace tr1;
typedef  void (*Logger)( int , const char* , ... );
//typedef Logger function< int( int , const char* , ... )>;


class Timer {
public:
	Timer ( const string& key): key_( key ) {
	}
	void begin(){
		start_ = clock();
	}
	void end(){
		end_   = clock();
	}
	float duration(){
		return ((float)( end_ - start_ ))/CLOCKS_PER_SEC ;
	}
	const string& key(){ return key_ ; }
	virtual ~Timer (){
	};

private:
	/* data */
	clock_t start_ , end_ ;
	string key_;
};

