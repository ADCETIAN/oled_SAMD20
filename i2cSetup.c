/*
 * i2cSetup.c
 *
 * Created: 27-02-2018 17:51:53
 *  Author: Thingiot
 */ 

#include "main.h"



struct i2c_master_module i2c_master_instance;

struct i2c_master_packet packet = {
	
	.ten_bit_address = false,
	.high_speed      = false,
	.hs_master_code  = 0x0,
	
};

void i2cConfig(void){
	
	struct i2c_master_config config_i2c_master;
	i2c_master_get_config_defaults(&config_i2c_master);
	
	config_i2c_master.buffer_timeout = 10000;

	config_i2c_master.pinmux_pad0    = PINMUX_PA22C_SERCOM3_PAD0;
	config_i2c_master.pinmux_pad1    = PINMUX_PA23C_SERCOM3_PAD1;

	
	i2c_master_init(&i2c_master_instance, SERCOM3, &config_i2c_master);
	
	i2c_master_enable(&i2c_master_instance);
	
}

void i2cWriteToSlave(uint16_t slaveAddr,uint16_t dataLenght,uint8_t *data){
	
	uint8_t timeOut=0;
	
	packet.address = slaveAddr;
	packet.data_length = dataLenght;
	packet.data = data;	
	
	while (i2c_master_write_packet_wait(&i2c_master_instance, &packet) !=
	STATUS_OK) {
		//serialWriteNL("packet not sent to slave");
		/* Increment timeout counter and check if timed out. */
		
		if (timeOut++ == TIMEOUT) {
			serialWriteNL("inside loop of sending_failed");
			break;
		}
	}


}

void i2cReadFromSlave(uint16_t slaveAddr,uint16_t dataLenght,uint8_t *data){
	
	uint8_t timeOut=0;
	
	packet.address = slaveAddr;
	packet.data_length = dataLenght;
	packet.data =(uint8_t *) data;

	while (i2c_master_read_packet_wait(&i2c_master_instance, &packet) !=
	STATUS_OK) {
		//serialWriteNL("reading from slave failed") ;
		/* Increment timeout counter and check if timed out. */
		if (timeOut++ == TIMEOUT) {
			break;
		}
	}
}


void i2cEnable(void) {
	
	i2c_master_enable(&i2c_master_instance);
	
}

void i2cDisable(void) {
	
	i2c_master_disable(&i2c_master_instance);
	
}