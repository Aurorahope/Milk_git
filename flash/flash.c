//
// Created by lenovo on 2021/4/8.
//

#include "flash.h"
#include <string.h>

void FLASH_EEPROM_Write(uint32_t n)
{
    HAL_FLASH_Unlock();     //����
    uint32_t PageError = 0;
    FLASH_EraseInitTypeDef EraseInitStruct;
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.PageAddress = 0x0801FC00;
    EraseInitStruct.Banks = FLASH_BANK_1;
    EraseInitStruct.NbPages = 1;
    HAL_FLASHEx_Erase(&EraseInitStruct,&PageError) ;//����ṹ���е���ʼ��ַ0x0801FC00����һҳ�����ݲ����ɹ�������OK
    uint32_t writeFlashData = n;        //��д���ֵ
    uint32_t addr = 0x0801FC00;                  //д��ĵ�ַ
    HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,addr, writeFlashData); //��FLASH��д��
    HAL_FLASH_Lock();
}
/**
  * @brief  �����洢��ַ�е�����
  * @param  ��STM32��FLASH�洢�ռ�ģ��EEPROM�Ķ�д
  * @retval ����ֵ����FLASH�ж�������
  */
uint32_t FLASH_EEPROM_Read(void)
{
    HAL_FLASH_Unlock();
    uint32_t Page = 0;
    uint32_t addr = 0x0801FC00;                  //д��ĵ�ַ
    Page=*(__IO uint32_t*)addr;
    return Page;
}
