/*
 * BIT_MATH.h
 *
 *  Created on: Aug 10, 2023
 *      Author: HemaHawas
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Operations on BIT */

#define SET_BIT(REG, BIT_NUM)	(REG = REG | (1 << BIT_NUM))

#define CLR_BIT(REG, BIT_NUM) 	(REG = REG & (~(1 << BIT_NUM)))

#define TOG_BIT(REG, BIT_NUM)	(REG = REG ^ (1 << BIT_NUM))

#define GET_BIT(REG, BIT_NUM)	(((REG) >> (BIT_NUM)) & 1)


/*Operations on PORT */

#define SET_PORT(REG) 	(REG |= 0xff)

#define CLR_PORT(REG) 	(REG &= 0)

#define TOG_PORT(REG) 	(REG ^= 0xff)

#endif /* BIT_MATH_H_ */
