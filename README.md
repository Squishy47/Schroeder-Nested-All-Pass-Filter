# Schroeder-Nested-All-Pass-Filter
c++ implimentation of a schroeder nested all-pass filter

This is much the same as my schroeder all-pass implimentation but instead the delay-line in the first all-pass is replaced with a second 'nested' all-pass filter.
For info on the my circular buffer or schroeder all-pass implimentations please see my other repositories.
- (https://github.com/Squishy47/Circular-Buffer)
- (https://github.com/Squishy47/Schroeder-All-Pass-Filter)



Initialisation Create a new instance of the filter for every channel of audio data you wish to process.

The first constructor value is the delay length of the filter, the second is the feedback gain of the filter.

```SchroederNestedAllPass nap{10, 0.707};```

To process a block of samples at once call the process function with: 1: a pointer to where the audio data is stored. 2: the size of the audio block/buffer.

```nap.process(audioDataPointer, bufferSize);```

processSingleSample(audioData) will return a single processed sample. pass in the each element of the data you want processed.

```audioData[i] = nap.processSingleSample(audioData[i]);```

To change the filter feedback gain, call setFeedback(), with a float between 0.0 and 1.0;

```nap.setFeedback(0.707);```

To Change the delay length of the filter, call setDelayLength(), with a float between 1.0 and beyond...

```nap.setDelayLength(100);```

getFeedback() and getDelayLength() return floats for the respective values.
