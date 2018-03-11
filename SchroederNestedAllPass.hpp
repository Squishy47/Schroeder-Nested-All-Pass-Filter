//
//  SchroederNestedAllPass.hpp
//
//  Created by Squishy.
//
//  If you use this, please credit me :)

#ifndef SchroederNestedAllPass_hpp
#define SchroederNestedAllPass_hpp

#include <stdio.h>
#include "CircularBuffer.hpp"

//delay 1.7 - 5 ms

class SchroederNestedAllPass{
    CircularBuffer CB1{44100}, CB2{44100};
    
    int Fs;
    float delayLength;
    float g;
public:
    SchroederNestedAllPass(float inValue, float inG);
    
    void process(float* samples, int bufferSize);
    
    float processSingleSample(float sample);
    
    float processSingleSample2(float sample);
    
    void setFeedback(float inValue);
    
    float getFeedback();
    
    void setDelayLength(float inValue);
    
    float getDelayLength();
    
    void setFs(int inValue);
};

#endif /* SchroederNestedAllPass_hpp */
