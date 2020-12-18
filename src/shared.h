#ifndef H_SHARED

#define H_SHARED

#include "config.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 Display(
	SCREEN_WIDTH,
	SCREEN_HEIGHT,
	&Wire,
	OLED_RESET);

class Shared
{
private:
	static bool isNaughtyMode;

public:
	static void Setup()
	{
		if (!Display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
		{
			while (true)
			{
			}
		}

		Display.clearDisplay();

		pinMode(PIN_BTN_TX, OUTPUT);
		digitalWrite(PIN_BTN_TX, LOW);

		pinMode(PIN_BTN_RX, INPUT_PULLUP);

		Shared::isNaughtyMode = IsButtonPressed();
	}

	static bool IsButtonPressed()
	{
		return digitalRead(PIN_BTN_RX) == LOW;
	}

	static bool IsNaughtyMode()
	{
		return Shared::isNaughtyMode;
	}
};

bool Shared::isNaughtyMode = false;

#endif