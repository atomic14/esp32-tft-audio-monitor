#include <Arduino.h>
#include <TFT_eSPI.h>
#include "Waveform.h"

Waveform::Waveform(TFT_eSPI &display, int x, int y, int width, int height, int num_samples) : Component(x, y, width, height)
{
  m_num_samples = num_samples;
  m_samples = static_cast<float *>(malloc(sizeof(float) * num_samples));
}

void Waveform::update(const float *samples)
{
  memcpy(m_samples, samples, sizeof(float) * m_num_samples);
}

void Waveform::_draw(TFT_eSPI &display)
{
  float x = 0;
  float x_step = (float)width / (float)m_num_samples;
  display.fillRect(x, y, width, height, 0);
  for (int i = 4; i < m_num_samples; i += 4)
  {
    display.drawLine(x, height / 2 + m_samples[i - 4] * 3, x + x_step * 4, height / 2 + m_samples[i] * 3, 0xfff);
    x += x_step * 4;
  }
}