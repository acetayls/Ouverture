//
//  findVideo.hpp
//  Ouverture
//
//  Created by Pierrick SAILLANT on 29/11/2016.
//
//

#ifndef findVideo_hpp
#define findVideo_hpp

#include <stdio.h>
class Video
{
public:
    findVideo(std::string search);
    
private:
    bool haveLink;
    bool haveVideo;
    int downloaded;
    void getVideoLink();
    std::string searchWord;
};


#endif /* findVideo_hpp */

