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
  int16_t *m_sample_buffer;
  UI *m_ui;
  Processor *m_processor;
  I2SSampler *m_sampler;

  void process_samples();

public:
  Application(TFT_eSPI &display);
  void begin();
  void loop();

  friend void processing_task(void *param);
};