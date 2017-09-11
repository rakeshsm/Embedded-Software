/*
 * frdm_msg.h
 *
 *  Created on: Oct 30, 2016
 *      Author: VIJOY-PC
 */


#ifndef INCLUDES_DEV_LAYER_FRDM_MSG_H_
#define INCLUDES_DEV_LAYER_FRDM_MSG_H_

typedef enum MSG_ERR {
	CHKSUM_FAIL = 0xE0,
	CHKSUM_PASS = 0xE1
}MSG_ERR_t;

void decode_packet (void);
void ack_nack_transmit (Cmds packet);
MSG_ERR_t checksum_validate (void);

void led_control (uint8_t payload);
void brightness_control (uint8_t payload);
void blink (Cmds blink_cmd);
void dance (Cmds dance_cmd);

#define HEAD_PACK_SIZE 4

#endif /* INCLUDES_DEV_LAYER_FRDM_MSG_H_ */
