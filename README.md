Embedded Software Projects

1. SPI and DMA
  * Project Deliverables
    * Implement DMA functionality in FRDM kl25z board and profile the operation time for transferring
      10,100,1000 and 5000 bytes .Compare this time with the memmove and memzero functions
      used in the previous lab.
    * Design a message interface to be able to send commands between two devices. To create a
      generic command structure to send that has various supported operations that can turn on/off
      the RGB color LEDs in some fashion.
    * Configure the Serial Peripheral interface (SPI) for the Freedom Freescale KL25Z processor and the 
      BeagleBone and use these interfaces to interact with the Nordic nRF24L01+ module.



2. UART and Time Profiling
    * Project Deliverables
      * Build a UART interface and control the RGB led on board the FRDM KL25Z through seral terminal
        and also adjust the brightness with timer PWM
      * Attach circular buffer to the UART interface and perform unit tests on it
      * Code profiling of various functions using timer


3. CortexM0+basedTouchSensingAlarm
  ARM Cortex based Alarm with touch Interface 
    * The project was built on FRDMKL25Z with Arm Cortex m0+ processor.
    * The firmware is written in C for the following:
       * Interfacing Temperature Sensor(DS1631) through I2C protocol
       * Interfacing Capactive touch Slider through I2C protocol
       * Using inbuilt RTC for time alarm
       * UART protocol for displaying data from micro-controller to PC Terminal
