#pragma once

#include<stdint.h>
#include<iostream>

#include<string>
#include<string_view>
#include<vector>
#include<optional>
#include<functional>

const uint64_t MAX_NEURONS = UINT64_MAX;
const uint64_t MAX_INIT_NEURONS = UINT64_MAX;
const uint16_t MAX_NEURON_THRESHOLD = 1000u;

typedef struct SParams
{
  uint64_t max_neurons = 0;
  uint64_t init_neurons = 0;
  uint16_t neuron_threshold = 0;
};

// params metadata
struct ParamDescription {
  std::string name;
  bool required;
  std::string description;
  std::string allowed_values;
  // Функция-обработчик: берет строку и записывает результат в структуру SParams
  std::function<bool(std::string_view, SParams&)> parser;
};

// Список всех доступных параметров
const std::vector<ParamDescription> SCHEME =
{
  {
    "--max-neurons",
    true,
    "max count neurons inside brains",
    "[0, " + std::to_string(MAX_NEURONS) + "]",
    [](std::string_view v, SParams& p)
    {
      try
      {
        p.max_neurons = std::stoull(std::string(v)); 
        return true;
      }
      catch (...) { return false; }
    }
  },
  {
    "--init-neurons",
    true,
    "initial neurons inside brains",
    "[0, " + std::to_string(MAX_INIT_NEURONS) + "]",
    [](std::string_view v, SParams& p)
    {
      try
      {
        p.init_neurons = std::stoull(std::string(v));
        return true;
      }
      catch (...) { return false; }
    }
  },
  {
    "--neuron-threshold",
    true,
    "membrana treshold for neuron activation",
    "[0, " + std::to_string(MAX_NEURON_THRESHOLD) + "]",
    
    [](std::string_view v, SParams& p)
    {
      try {
        auto val = std::stoul(std::string(v));
        if (val > MAX_NEURON_THRESHOLD) return false;
        p.neuron_threshold = static_cast<uint16_t>(val);
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

SParams readParams(int argc, char* argv[])
{
  if (argc == 1)
  {
    printHelp();
    exit(0);
  }

  SParams params;
  std::vector<std::string_view> args(argv, argv + argc);

  for (size_t i = 1; i < args.size(); ++i)
  {
    bool found = false;

    for (const auto& desc : SCHEME)
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

    if (!found)
    {
      printHelp();
      exit(0);
    }
  }


  return params;
}