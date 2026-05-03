#pragma once
#include"brains/NeuronCloud/NeuronCloudConst.h"
#include"brains/BrainsConst.h"

#include<stdint.h>
#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<optional>
#include<functional>

const uint64_t MAX_SYNAPSES      = UINT64_MAX;
const uint64_t MAX_INIT_SYNAPSES = UINT64_MAX;

struct BrainParams
{
  uint64_t max_neurons      = 0;
  uint64_t init_neurons     = 0;
  uint16_t neuron_threshold = 0;

  uint64_t max_synapses  = 0;
  uint64_t init_synapses = 0;
};

// params metadata
struct ParamDescription {
  std::string name;
  bool required;
  std::string description;
  std::string allowed_values;
  // Parser: take string and write result inside BrainParams
  std::function<bool(std::string_view, BrainParams&)> parser;
};

// Список всех доступных параметров
const std::vector<ParamDescription> SCHEME =
{
  {
    "--max-neurons",
    true,
    "max count neurons inside brains",
    "[0, " + std::to_string(BRAINS_MAX_NEURONS) + "]",
    [](std::string_view v, BrainParams& p)
    {
      try
      {
        auto val = std::stoull(std::string(v));
        if (val > BRAINS_MAX_NEURONS || val < 0) return false;
        p.max_neurons = val;
        return true;
      }
      catch (...) { return false; }
    }
  },
  {
    "--init-neurons",
    true,
    "initial neurons inside brains",
    "[0, " + std::to_string(BRAINS_MAX_INIT_NEURONS) + "]",
    [](std::string_view v, BrainParams& p)
    {
      try
      {
        auto val = std::stoull(std::string(v));
        if (val > BRAINS_MAX_INIT_NEURONS || val < 0) return false;
        p.init_neurons = val;
        return true;
      }
      catch (...) { return false; }
    }
  },
  {
    "--neuron-threshold",
    false,
    "membrana treshold for neuron activation",
    "[0, " + std::to_string(NEURONS_THRESHOLD_MAX) + "]",
    
    [](std::string_view v, BrainParams& p)
    {
      try {
        auto val = std::stoul(std::string(v));
        if (val > NEURONS_THRESHOLD_MAX || val < 0) return false;
        p.neuron_threshold = static_cast<uint16_t>(val);
        return true;
      }
      catch (...) { return false; }
    }
  },
  // synapses
  {
    "--max-synapses",
    true,
    "max count synapses inside brains",
    "[0, " + std::to_string(MAX_SYNAPSES) + "]",
    [](std::string_view v, BrainParams& p)
    {
      try
      {
        auto val = std::stoull(std::string(v));
        if (val > MAX_SYNAPSES || val < 0) return false;
        p.max_synapses = val;
        return true;
      }
      catch (...) { return false; }
    }
  },
  {
    "--init-synapses",
    true,
    "initial synapses inside brains",
    "[0, " + std::to_string(MAX_INIT_SYNAPSES) + "]",
    [](std::string_view v, BrainParams& p)
    {
      try
      {
        auto val = std::stoull(std::string(v));
        if (val > MAX_INIT_SYNAPSES || val < 0) return false;
        p.init_synapses = val;
        return true;
      }
      catch (...) { return false; }
    }
  }
};

void printHelp()
{
  std::cout << "Params rules: [name] [required] [allowed values/allowed_values]\n";
  std::cout << "Params:\n";

  for (const auto& p : SCHEME) {
    printf("  %-20s %-10s %s\n", p.name.data(), p.required ? "required" : "optional", p.allowed_values.data());
    printf(" description: %s\n\n", p.description.data());
  }
}

BrainParams readParams(int argc, char* argv[])
{
  if (argc == 1)
  {
    printHelp();
    exit(0);
  }

  BrainParams params;
  std::vector<std::string_view> args(argv, argv + argc);

  for (const auto& desc : SCHEME)
  {
    bool found = false;

    for (size_t i = 1; i < args.size(); ++i)
    {
      if (args[i] == desc.name)
      {
        if (i + 1 < args.size())
        {
          if (!desc.parser(args[++i], params))
          {
            std::cerr << "Error: Incorrect value for [ " << desc.name << "]\n";
            exit(1);
          }

          found = true;
          break;
        }
        else
        {
          std::cerr << "Error: Param " << desc.name << " required.\n";
          exit(1);
        }
      }
    }

    if (!found && desc.required)
    {
      std::cerr << "Error: Param " << desc.name << " required.\n";
      exit(1);
    }
  }


  return params;
}