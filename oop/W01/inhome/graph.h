// Name Mohammad SHarfuafr         20/1/2019          lab section SAA    Student ID : 143473171
#ifndef graph_HEADERFILENAME_H 
#define graph_HEADERFILENAME_H

#pragma once
// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

namespace sict
{
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples);
}
#endif