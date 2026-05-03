#include "Brains.h"

Brains::Brains(uint32_t count_neurons, uint32_t max_neurons, uint16_t neuron_threshold, uint64_t max_synapses, uint64_t count_synapses)
{
  this->max_neurons = max_neurons;
  this->neuron_threshold = neuron_threshold;

  this->max_synapses = max_synapses;
}

Brains::~Brains()
{
  for (const auto& cloud : this->neurons_clouds)
  {
    delete cloud;
  }
}

uint32_t Brains::getCountNeurons() const
{
  uint32_t count = 0;
  for (const auto& cloud : this->neurons_clouds)
  {
    count += cloud->getCount();
  }
  return count;
}

uint64_t Brains::getCountSynapses() const
{
  return 0;
}