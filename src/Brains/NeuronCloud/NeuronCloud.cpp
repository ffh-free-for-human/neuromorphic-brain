#include"NeuronCloud.h"

NeuronCloud::NeuronCloud(uint16_t cloud_size, uint16_t neurons_threshold)
{
  this->x.resize(cloud_size);
  this->y.resize(cloud_size);
  this->z.resize(cloud_size);

  this->membrana_potentials.resize(cloud_size);
  std::fill(this->membrana_potentials.begin(), this->membrana_potentials.end(), 1000);

  this->thresholds.resize(cloud_size);
  this->refractory_ticks.resize(cloud_size);

  this->cloud_states.resize(cloud_size);
  std::fill(this->cloud_states.begin(), this->cloud_states.end(), NeuronCloudState::Free);

  this->states.resize(cloud_size);
  std::fill(this->states.begin(), this->states.end(), NeuronState::Active);

  this->capacity = cloud_size;
}

uint16_t NeuronCloud::getCount() const
{
  return this->active_count;
}

void NeuronCloud::process()
{

}

void NeuronCloud::sendImpulse()
{

}

void NeuronCloud::defragmentation()
{

}