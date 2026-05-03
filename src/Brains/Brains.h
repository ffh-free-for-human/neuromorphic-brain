#pragma once

#include"NeuronCloud/NeuronCloud.h"

/* Brains with neurons uint32 and synapse uint64 */
class Brains
{
public:
  Brains(uint32_t max_neurons, uint32_t count_neurons, uint16_t neuron_threshold, uint64_t max_synapses, uint64_t count_synapses);
  Brains(const Brains&) = delete;
  Brains& operator=(const Brains&) = delete;

  ~Brains();

  uint32_t getCountNeurons() const;
  uint64_t getCountSynapses() const;

  /* activate neurons */
  //void process();

  /* WARN: not use with process */
  //void synapthogenesis();

private:
  uint32_t max_neurons;
  uint64_t max_synapses;
  uint16_t neuron_threshold;
  
  std::vector<NeuronCloud*> neurons_clouds;
};