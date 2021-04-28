        1 Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2
        2 Analog Electrical Conductivity Sensor / Meter Kit V2 (K=1.0), SKU: DFR0300.
  In order to guarantee precision, a temperature sensor such as DS18B20 is needed, to execute automatic temperature compensation.
  You can send commands in the serial monitor to execute the calibration.
  Serial Commands:
 
 *  PH Calibration：
 *   enterph -> enter the PH calibration mode
 *   calph   -> calibrate with the standard buffer solution, two buffer solutions(4.0 and 7.0) will be automaticlly recognized
 *   exitph  -> save the calibrated parameters and exit from PH calibration mode
 *
 *  EC Calibration：
 *   enterec -> enter the EC calibration mode
 *   calec   -> calibrate with the standard buffer solution, two buffer solutions(1413us/cm and 12.88ms/cm) will be automaticlly recognized
 *   exitec  -> save the calibrated parameters and exit from EC calibration mode
