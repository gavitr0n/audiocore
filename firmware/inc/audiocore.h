#ifndef HIFICORE_H_
#define HIFICORE_H_
#include <string>
#include "application.h"
#include "global.h"

#include "SparkIntervalTimer.h"
#include "defines.h"
#include "coms.h"
#include "es9018k2m_driver.h"
#include "stm32_driver.h"

//--spark function externs
extern int tinkerDigitalWrite(String command);
extern int tinkerAnalogWrite(String command);

//--audiocore function externs
extern int audiocore_reset();
#endif
