#pragma once
#include"NeuronCloudConst.h"

#include <cstdint>
#include<vector>

enum class NeuronCloudState : uint8_t
{
  /* free inside Cloud pool */
  Free,
  /* must wait next tick */
  New,
  /* can used inside process */
  Exist,
  /* must be deleted */
  Dead,
};

enum class NeuronState : uint8_t {
  /* Ready to sent signal */
  Active,
  /* Impulse was sent in this tick */
  Fired,
  /* no reaction on stimulation */
  Fatigued,
};

/*
  Use setupNeuronsInitialParams before start "thinking" (process)
*/
class NeuronCloud {
public:
  NeuronCloud(uint16_t cloud_size);


  void setupNeuronsInitialParams(uint16_t membrana_potential_init, uint16_t threshold, uint8_t signal_weight, uint8_t refractory_time);

  uint16_t getCount() const;
  /* update membrana potential , refractory */
  void process();
  /* send impule into outcoming synapses */
  void sendImpulse();
  /*
    use Swap&Pop algorithm for memory place optimization when use apoptosis 
    WARN: don't use this often
   */
  void defragmentation();

private:
  uint16_t active_count = 0;
  uint16_t capacity = UINT16_MAX;

  // Initial params
  uint16_t membrana_potential_init;
  uint16_t threshold;
  uint8_t  signal_weight;
  uint8_t  refractory_time;

  // Neuron params (SoA)
  std::vector<float> x;
  std::vector<float> y;
  std::vector<float> z;
  std::vector<uint16_t> membrana_potentials;
  std::vector<uint16_t> thresholds;
  std::vector<uint8_t> signal_weights;
  std::vector<uint8_t> refractory_ticks;
  std::vector<NeuronCloudState> cloud_states;
  std::vector<NeuronState> states;
};
