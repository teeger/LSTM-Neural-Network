/*
 * SawtoothNetwork.h
 *
 *  Created on: Jul 27, 2016
 *      Author: trabucco
 */

#ifndef LSTMNETWORK_H_
#define LSTMNETWORK_H_

#include <vector>
#include <omp.h>
#include "MemoryBlock.h"
#include "Neuron.h"
using namespace std;

class LSTMNetwork {
private:
	unsigned int inputSize;
	double learningRate;
	double decayRate;
	vector<MemoryBlock> blocks;
	vector<vector<Neuron> > layers;
	vector<double> timeSteps;
	int getPreviousNeurons();
public:
	LSTMNetwork(int is, int b, int c, double l, double d);
	virtual ~LSTMNetwork();
	vector<double> classify(vector<double> input);
	vector<double> train(vector<double> input, vector<double> target);
	void addLayer(int size);
};

#endif /* LSTMNETWORK_H_ */
