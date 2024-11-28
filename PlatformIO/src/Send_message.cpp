/**
 * @file    Send_message.cpp
 * @brief   Send "toggle" message on the Serial port evers 2s
 * @author  jzupan
 * @date    2023
 * @note    Some useful informations
 * ```
 * PlatformIO IDE: 	"Send_message.cpp"
 * Arduino IDE:		"Send_message.ino"
 * Board: 			Arduino Nano
 * - Sending data over USB/CDC &| TTL
 * - Useful for testing RPI, PC, and other SBC apps.
 * ```
 */

#include <Arduino.h>

/** @brief Time in miliseconds */
unsigned long time;

/** @brief LED status mirror */
unsigned int toggle;

/**
 * @brief Init Serial and paralell IO's
 */
void setup() {
    Serial.begin(115200); 	/**< 115200 baud */
    time = millis(); 		/**< current time */
    pinMode(LED_BUILTIN, OUTPUT); 	/**< LED port is output */
    digitalWrite(LED_BUILTIN, LOW); /**< LED: LOW state */
    toggle = 0; 
}

/**
 * @brief Main loop
 */
void loop() {
    while ((millis() - time) < 2000L) {  	/**< every 2 seconds */
        if (Serial.available()) { 			/**< New data ? */
            String s = Serial.readString(); 
            Serial.print("Arduino: "); 		
            Serial.println(s); 				
        }
    }
    time = millis();
    toggle = toggle ? 0 : 1; 	

    digitalWrite(LED_BUILTIN, toggle ? HIGH : LOW); /**< LED toggle */
    Serial.print(toggle ? "'Hi'" : "'Lo'"); 		/**< new message */
    Serial.println(" there! :)"); 
}

/*
[env:nanoatmega328]
platform = atmelavr
board = nanoatmega328
framework = arduino
board_build.f_cpu = 16000000L
*/

// Še doddatna dokumentacija:
/**
 * @mainpage Moja mini Send_Serial prva stran <img src="SIflag.gif" alt="SI" style="float: right; height: 30px;">
 * 
 * @section uvod Uvod
 * 
 * Preprost testni program za oddajanje vzorcev besedila na serijski USB/CDC kanal 
 * 
 * @image   html "nano.png"  "Arduino NANO modul"  height=250px
 * 
 * @section sekcija1 Dodatno
 * 
 * Vzorci se oddajajo vsaki 2 sekundi.<br>
 * Hitrost prenosa je 115.200 baud.<br>
 * Program ja napisan za Arduino IDE in PlatformIO IDE.
 */