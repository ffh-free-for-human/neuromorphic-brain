#include "Brains.h"

#include <cmath>

Brains::Brains(uint32_t max_neurons, uint64_t max_synapses)
{
  this->max_neurons = max_neurons;
  this->max_synapses = max_synapses;
}

Brains::~Brains()
{
  for (const auto& cloud : this->neurons_clouds)
  {
    delete cloud;
  }
}

void Brains::allocateNeuronsClouds(uint16_t neurons_cloud_size)
{
  uint16_t neurons_clouds_count = static_cast<uint16_t>(std::ceil(max_neurons / neurons_cloud_size));

  this->neurons_clouds.resize(neurons_clouds_count);
  for (uint32_t i = 0; i < neurons_clouds_count; i++)
  {
    this->neurons_clouds[i] = new NeuronCloud(neurons_cloud_size);
  }
}

uint16_t Brains::allocateNeuronCloud(uint16_t neurons_cloud_size)
{
  this->neurons_clouds.push_back(new NeuronCloud(neurons_cloud_size));
  return this->neurons_clouds.size() - 1;
}

void Brains::setupAllNeuronsClouds(uint16_t membrana_potential_init, uint16_t threshold, uint8_t signal_weight, uint8_t refractory_time)
{
  for (auto& cloud : this->neurons_clouds)
  {
    cloud->setupNeuronsInitialParams(membrana_potential_init, threshold, signal_weight, refractory_time);
  }
}

void Brains::setupAtNeuronCloud(uint16_t neuron_cloud_index, uint16_t membrana_potential_init, uint16_t threshold, uint8_t signal_weight, uint8_t refractory_time)
{
  this->neurons_clouds[neuron_cloud_index]->setupNeuronsInitialParams(membrana_potential_init, threshold, signal_weight, refractory_time);
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