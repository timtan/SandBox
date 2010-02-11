/*
 *  Tutorial 
 *  http://curl.haxx.se/libcurl/c/libcurl-tutorial.html
 *
 *
 */
#include <stdio.h>
#include <curl/curl.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
typedef vector<char> charDatas;
size_t write_data( void * buffer , size_t size, size_t nmemb, void * userp ){
	int total_to_write = size * nmemb ;
  	ostringstream& sout = *static_cast< ostringstream * >( userp );
	if( sout.write( static_cast<char*>(buffer ), total_to_write  ) ){
		return total_to_write ;
	}
	else{
		return 0 ;
	}
}
int main(int argc, char** argv)
{
	curl_global_init( CURL_GLOBAL_ALL ) ;

	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();

	if(curl) {
		/*
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, curl_msg_callback);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, post_size);
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errorstr);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, alps_timeout);
		curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, alps_timeout);
		*/

		ostringstream sout;
		curl_easy_setopt(curl, CURLOPT_URL, "curl.haxx.se");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data ) ;
		curl_easy_setopt(curl, CURLOPT_WRITEDATA , & sout);
		res = curl_easy_perform(curl);
		cout<<sout.str() <<endl;
		/* always cleanup */ 
		curl_easy_cleanup(curl);
	}

	return 0;
}
