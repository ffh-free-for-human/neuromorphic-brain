#include"NeuronCloud.h"

NeuronCloud::NeuronCloud(uint16_t cloud_size)
{
  this->capacity = cloud_size;
}

void NeuronCloud::setupNeuronsInitialParams(uint16_t membrana_potential_init, uint16_t threshold, uint8_t signal_weight, uint8_t refractory_time)
{
  this->x.resize(capacity);
  this->y.resize(capacity);
  this->z.resize(capacity);

  this->membrana_potentials.resize(capacity);
  std::fill(this->membrana_potentials.begin(), this->membrana_potentials.end(), membrana_potential_init);

  this->thresholds.resize(capacity);
  std::fill(this->thresholds.begin(), this->thresholds.end(), threshold);
  this->signal_weights.resize(capacity);
  std::fill(this->signal_weights.begin(), this->signal_weights.end(), signal_weight);
  this->refractory_ticks.resize(capacity);
  std::fill(this->refractory_ticks.begin(), this->refractory_ticks.end(), refractory_time);

  this->cloud_states.resize(capacity);
  std::fill(this->cloud_states.begin(), this->cloud_states.end(), NeuronCloudState::Free);

  this->states.resize(capacity);
  std::fill(this->states.begin(), this->states.end(), NeuronState::Active);
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

// free dead neurons and move it to the end of the cloud
void NeuronCloud::defragmentation()
{
  uint16_t i = 0;

  while (i < this->active_count)
  {
    if (this->cloud_states[i] == NeuronCloudState::Dead)
    {
      uint16_t last = this->active_count - 1;
      
      // just erase the current dead element with the last alive
      this->x[i] = this->x[last];
      this->y[i] = this->y[last];
      this->z[i] = this->z[last];
      this->membrana_potentials[i] = this->membrana_potentials[last];
      this->thresholds[i] = this->thresholds[last];
      this->signal_weights[i] = this->signal_weights[last];
      this->refractory_ticks[i] = this->refractory_ticks[last];
      this->cloud_states[i] = this->cloud_states[last];
      this->states[i] = this->states[last];

      // now mark the old last place as free
      this->cloud_states[last] = NeuronCloudState::Free;
      
      this->active_count--;
      // i don't increase, to check the new element on this position
    }
    else
    {
      i++;
    }
  }
}