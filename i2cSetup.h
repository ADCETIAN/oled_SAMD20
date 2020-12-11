/*
 * i2cSetup.h
 *
 * Created: 27-02-2018 17:52:26
 *  Author: Thingiot
 */ 


#ifndef I2CSETUP_H_
#define I2CSETUP_H_



/* Number of times to try to send packet if failed. */
#define TIMEOUT 10

void i2cConfig(void);
void i2cWriteToSlave(uint16_t slaveAddr,uint16_t dataLenght,uint8_t *data);
void i2cReadFromSlave(uint16_t slaveAddr,uint16_t dataLenght,uint8_t *data);
void i2cDisable(void);
void i2cEnable(void);
 


#endif /* I2CSETUP_H_ */