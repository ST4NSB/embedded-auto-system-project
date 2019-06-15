/*
 * structuri.h
 *
 *  Created on: Jun 5, 2019
 *      Author: ESD
 */

#ifndef STRUCTURI_H_
#define STRUCTURI_H_

#define P_ID 0
#define P_SIZE 1
#define P_DATA 2
#define P_CHECKSUM 3

struct package {
	unsigned char ID;
	unsigned char size;
	unsigned char data[5];
	unsigned char checksum;
};

#endif /* STRUCTURI_H_ */
