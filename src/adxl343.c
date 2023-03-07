/*
 * adxl343.c
 *
 *  Created on: Mar 6, 2023
 *      Author: erich
 */

#include "src/adxl343.h"

#include <em_i2c.h>

struct z_axis_request_res adxl_readZ(void)
{
  struct z_axis_request_res res;
  res.success = false;

  uint8_t transferData[2];

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData[0]= DATAZ0_REG;
  seq.buf[0].data = transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 2;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          res.success=true;
          res.data[0]=transferData[0];
          res.data[1]=transferData[1];
        }
      return res;

    }
  else
    {
      return res;
    }

}

struct device_id_request_res adxl_readDevID(void)
{
  struct device_id_request_res res;
  res.success = false;

  uint8_t transferData;

  I2C_TransferSeq_TypeDef seq;

  seq.addr = ADXL_ADDR;
  seq.flags = I2C_FLAG_WRITE;
  transferData = DEVID_REG;
  seq.buf[0].data = &transferData;
  seq.buf[0].len = 1;

  I2C_TransferReturn_TypeDef ret;

  ret = I2C_TransferInit(I2C0,&seq);

  while(ret==i2cTransferInProgress)
    {
      ret = I2C_Transfer(I2C0);
    }

  if(ret==i2cTransferDone)
    {
      seq.flags = I2C_FLAG_READ;
      seq.buf[0].len = 1;

      ret = I2C_TransferInit(I2C0,&seq);

      while(ret==i2cTransferInProgress)
        {
          ret = I2C_Transfer(I2C0);
        }

      if(ret==i2cTransferDone)
        {
          res.success=true;
          res.data=transferData;
        }
      return res;

    }
  else
    {
      return res;
    }

}

