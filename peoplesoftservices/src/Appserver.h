/*
 * Appserver.h
 *
 *  Created on: Sep 6, 2018
 *      Author: psadm2
 */

#ifndef APPSERVER_H_
#define APPSERVER_H_
#include "PSutils.h"


//class Appserver: public PSutils {
class Appserver {
private:
	bool Appserver_status;


public:
	void status();
	void start();
	void stop();
	void restart();
	Appserver();
	~Appserver();
};

#endif /* APPSERVER_H_ */
