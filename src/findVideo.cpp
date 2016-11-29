//
//  findVideo.cpp
//  Ouverture
//
//  Created by Pierrick SAILLANT on 29/11/2016.
//
//

#include "findVideo.hpp"
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <tidy/tidy.h>
#include <tidy/buffio.h>


using namespace std;

Video::Video(string search)
{
    
    haveLink = false;
    haveVideo = false;
    downloaded = -1;
    Video::searchWord = search;
    cout << findVideo::searchWord << endl ;
    getVideoLink();
}


void Video::getVideoLink(){
    CURL *curl;
    CURLcode res;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, ("https://www.youtube.com/results?search_query="+Video::searchWord).c_str());
        
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        res
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    
    curl_global_cleanup();
}