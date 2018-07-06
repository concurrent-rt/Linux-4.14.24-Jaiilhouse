
This directory contains to sources

Linux-4.14.24-Jailhouse

 - Linux-4.14.24-Jailhouse is Linux kernel source with jailhouse patches. This is stable 4.14 Linux Kernel
   with jailhouse patches. 

tty0tty

This is virtual serial port driver

steps to use tty0tty driver

 1)Modify DRAM_SHARED_MEM with shared memory start address of first non rootcell
 2) make clean
 3) make 
 4) insmod tty0tty.ko

        Note: Insert this driver module in Root cell before creating non root cell.

