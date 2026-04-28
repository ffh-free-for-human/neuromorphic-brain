#include "params.h"

void main(int argc, char* argv[])
{
#ifdef DEBUG
  std::cout << "Debug mode ON\n";
#endif // DEBUG

  SParams params = readParams(argc, argv);

#ifdef DEBUG
  std::cout << "Count initial neurons: " << params.init_neurons << "\n";
  std::cout << "Count max neurons: " << params.max_neurons << "\n";
  std::cout << "Count neuron threshold: " << params.neuron_threshold << "\n";

#endif // DEBUG
}