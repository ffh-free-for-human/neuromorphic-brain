#pragma once

#include<stdint.h>

const uint16_t NEURONS_CLOUD_BASE_SIZE = 10000u;

const uint8_t NEURONS_SIGNAL_WEIGHT     = 1u;
const uint8_t NEURONS_SIGNAL_WEIGHT_ADD = 1u;
const uint8_t NEURONS_SIGNAL_WEIGHT_SUB = 1u;

const uint8_t NEURONS_REFRACTORY_TIME = 5u;

const uint16_t NEURONS_THRESHOLD       = 3000u;
const uint16_t NEURONS_THRESHOLD_MIN   = 1000u;
const uint16_t NEURONS_THRESHOLD_MAX   = 6000u;
const uint8_t  NEURONS_THRESHOLD_ADD   = 1u;
const uint8_t  NEURONS_THRESHOLD_SUB   = 1u;
const uint8_t  NEURONS_THRESHOLD_RELAX = 1u;

const uint16_t NEURONS_MEMBRANA_POTENTIAL_INIT = 2000u;

const float NEURONS_RADIUS   = 0.0005f;
const float NEURONS_DISTANCE = 0.005f;
