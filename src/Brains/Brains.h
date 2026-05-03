#pragma once

#include"NeuronCloud/NeuronCloud.h"

/* Brains with neurons uint32 and synapse uint64 */
class Brains
{
public:
  Brains(uint32_t max_neurons, uint64_t max_synapses);
  Brains(const Brains&) = delete;
  Brains& operator=(const Brains&) = delete;

  ~Brains();

  /* allocate neurons clouds with same size */
  void allocateNeuronsClouds(uint16_t neurons_cloud_size = NEURONS_CLOUD_BASE_SIZE);

  /* allocate one neuron cloud and return index which can be used in setupAtNeuronCloud */
  uint16_t allocateNeuronCloud(uint16_t neurons_cloud_size);

  /* setup same params for all neurons clouds */
  void setupAllNeuronsClouds(
    uint16_t membrana_potential_init = NEURONS_MEMBRANA_POTENTIAL_INIT,
    uint16_t threshold = NEURONS_THRESHOLD,
    uint8_t signal_weight = NEURONS_SIGNAL_WEIGHT,
    uint8_t refractory_time = NEURONS_REFRACTORY_TIME
  );

  /* setup params for one neuron cloud */
  void setupAtNeuronCloud(
    uint16_t neuron_cloud_index,
    uint16_t membrana_potential_init = NEURONS_MEMBRANA_POTENTIAL_INIT,
    uint16_t threshold = NEURONS_THRESHOLD,
    uint8_t signal_weight = NEURONS_SIGNAL_WEIGHT,
    uint8_t refractory_time = NEURONS_REFRACTORY_TIME
  );

  uint32_t getCountNeurons() const;
  uint64_t getCountSynapses() const;

  /* activate neurons */
  //void process();

  /* WARN: not use with process */
  //void synapthogenesis();

private:
  uint32_t max_neurons;
  uint64_t max_synapses;
  
  std::vector<NeuronCloud*> neurons_clouds;
};