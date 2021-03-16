#pragma once

#include <driver/i2s.h>

class UI;
class Processor;
class I2SSampler;
class TFT_eSPI;

class Application
{
private:
  int m_window_size;
  UI *m_ui;
  Processor *m_processor;
  I2SSampler *m_sampler;

  void process_samples();

public:
  Application(TFT_eSPI &display, int window_size);
  void begin(const i2s_config_t &i2s_config, const i2s_pin_config_t &i2s_pins);
  void loop();

  friend void processing_task(void *param);
};