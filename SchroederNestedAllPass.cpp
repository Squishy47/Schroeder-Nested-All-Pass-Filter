//
//  SchroederNestedAllPass.cpp
//
//  Created by Squishy.
//
//  If you use this, please credit me :)

#include "SchroederNestedAllPass.hpp"

SchroederNestedAllPass::SchroederNestedAllPass(float inValue, float inG){
    delayLength = inValue;
    g = inG;
}

void SchroederNestedAllPass::process(float* samples, int bufferSize){
    for(int i = 0; i < bufferSize; i++)
        samples[i] = processSingleSample(samples[i]);
}

float SchroederNestedAllPass::processSingleSample(float sample){
    float delay = processSingleSample2(sample);
    CB1.write(sample + (delay * g));
    
    delay = delay * (1 - (g * g));
    
    float feedforward = sample * -g;
    
    return (delay + feedforward);
}

float SchroederNestedAllPass::processSingleSample2(float sample){
    float delay = CB2.read(delayLength, cubic);
    CB2.write(sample + (delay * g));
    
    delay = delay * (1 - (g * g));
    
    float feedforward = sample * -g;
    
    return (delay + feedforward);
}

void SchroederNestedAllPass::setFeedback(float inValue){
    g = inValue;
}

float SchroederNestedAllPass::getFeedback(){
    return g;
}

void SchroederNestedAllPass::setDelayLength(float inValue){
    delayLength = inValue;
    if (delayLength > CB1.getBufferLength())
        CB1.setBufferLength(delayLength);
    if (delayLength > CB2.getBufferLength())
        CB2.setBufferLength(delayLength);
}

float SchroederNestedAllPass::getDelayLength(){
    return delayLength;
}

void SchroederNestedAllPass::setFs(int inValue){
    Fs = inValue;
}
