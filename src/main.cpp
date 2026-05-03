#include "params.h"

int main(int argc, char* argv[])
{
#ifdef DEBUG
  std::cout << "Debug mode ON\n";
#endif // DEBUG

  BrainParams params = readParams(argc, argv);

#ifdef DEBUG
  std::cout << "Count initial neurons: " << params.init_neurons << "\n";
  std::cout << "Count max neurons: " << params.max_neurons << "\n";
  std::cout << "Count neuron threshold: " << params.neuron_threshold << "\n";

  std::cout << "Count initial synapses: " << params.init_synapses << "\n";
  std::cout << "Count max synapses: " << params.max_synapses << "\n";

#endif // DEBUG

  return 0;
}