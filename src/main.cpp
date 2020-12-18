#include "config.h"
#include "shared.h"

#include "00_intro.h"
#include "05_loading.h"
#include "10_waiting.h"

void setup()
{
  Shared::Setup();

  Intro::Render();
  Loading::Render();
  Waiting::Render();
}

void loop()
{
}
