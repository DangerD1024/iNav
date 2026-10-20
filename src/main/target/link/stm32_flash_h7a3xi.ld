/*
*****************************************************************************
**
**  File        : stm32_flash_h7a3xi.ld
**
**  Abstract    : Linker script for STM32H7A3xI Device with
**                2048KByte FLASH (2 banks, 8KB sectors)
**                1024K AXI-RAM mapped onto AXI bus on CD domain
**                 128K AHB-SRAM1 + AHB-SRAM2 on CD domain
**                  32K SRD-SRAM on SRD domain
**                  64K ITCM
**                 128K DTCM
**
*****************************************************************************
*/

/* Stack & Heap sizes */
_Min_Heap_Size = 0;
_Min_Stack_Size = 0x1800;

/*
0x00000000 to 0x0000FFFF   64K ITCM
0x20000000 to 0x2001FFFF  128K DTCM
0x24000000 to 0x2403FFFF  256K AXI SRAM1, CD domain, main RAM
0x24040000 to 0x2409FFFF  384K AXI SRAM2, CD domain, main RAM
0x240A0000 to 0x240FFFFF  384K AXI SRAM3, CD domain, main RAM
0x30000000 to 0x3000FFFF   64K AHB SRAM1, CD domain
0x30010000 to 0x3001FFFF   64K AHB SRAM2, CD domain
0x38000000 to 0x38007FFF   32K SRD SRAM, SRD domain, unused
0x38800000 to 0x38800FFF    4K BACKUP SRAM, Backup domain, unused

0x08000000 to 0x081FFFFF 2048K full flash,
0x08000000 to 0x08003FFF   16K isr vector, startup code,    // Sectors 0-1 (bank 1)
0x08004000 to 0x08007FFF   16K config,                      // Sectors 2-3 (bank 1)
0x08008000 to 0x081FFFFF 2016K firmware,
*/

/* Specify the memory areas */
MEMORY
{
    FLASH (rx)        : ORIGIN = 0x08000000, LENGTH = 16K
    FLASH_CONFIG (r)  : ORIGIN = 0x08004000, LENGTH = 16K
    FLASH1 (rx)       : ORIGIN = 0x08008000, LENGTH = 2016K

    ITCM_RAM (rwx)    : ORIGIN = 0x00000000, LENGTH = 64K
    DTCM_RAM (rwx)    : ORIGIN = 0x20000000, LENGTH = 128K
    RAM (rwx)         : ORIGIN = 0x24000000, LENGTH = 1024K

    D2_RAM (rwx)      : ORIGIN = 0x30000000, LENGTH = 128K /* AHB SRAM1 + AHB SRAM2 */

    MEMORY_B1 (rx)    : ORIGIN = 0x60000000, LENGTH = 0K
}

REGION_ALIAS("STACKRAM", DTCM_RAM)
REGION_ALIAS("FASTRAM",  DTCM_RAM)
REGION_ALIAS("SLOWRAM",  D2_RAM)

INCLUDE "stm32_flash_h7_split.ld"
