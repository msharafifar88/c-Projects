// Name Mohammad SHarfuafr         17/12019          lab section SAA
#pragma once
// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

void getSamples(int samples[], int noOfSamples);
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);
