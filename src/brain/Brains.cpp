#include "Brains.h"

Brains::Brains(uint32_t count_neurons)
{
  this->count_neurons = count_neurons;
}

unsigned Brains::countNeurons()
{
  return this->count_neurons;
}