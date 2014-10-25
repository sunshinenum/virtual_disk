// stdafx.cpp : source file that includes just the standard includes
//	virtual_disk.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"



//全局磁盘起始指针
char* disk_start;
char disk_name[12];
disk v_disk;
unsigned long disk_size;

unsigned long fcb_number=0;

FCB file_fcb;
FCB folder_fcb;

unsigned long file_start=4*1024*1024;

index t_index;//目录文件
unsigned long file_offset=0;//文件相对于4M的偏移量


CString g_folder_name;//目录名

bool g_is_copy=true;// copy:true,cut:false

bool g_is_test_stop=true;