#include <time.h>
#include "StdAfx.h"

#pragma once
//磁盘信息结构体 24 bytes
struct disk
{
	char *disk_start;//磁盘开始位置指针	4 bytes
	unsigned long total_space;//磁盘大小 （单位：Bytes） 4 bytes
	unsigned long used_space;//磁盘已使用大小（单位：Bytes） 4 bytes
	char disk_name[12];//磁盘名 12 bytes
};
//文件控制块结构体 56 bytes
struct FCB
{
	char file_name[32];//文件名 32 bytes

	unsigned long file_start;//文件起始位置偏移（相对于磁盘起始位置） 4 bytes
	unsigned long file_size;//文件大小 4 bytes

	time_t create_time;//创建时间	4 bytes
	time_t update_time;//修改时间	4 bytes

	byte file_properties;//文件属性 1 byte [isindex][r][w][e] (0110) [0][0][0][0]
	char other_use[7];//备用 7bytes
};

//目录文件结构体 4*1024 bytes
struct index
{
	unsigned int file_number;//文件数目 4 bytes
	unsigned long fcb_index[1023];//fcb 数组下标 4*1023 bytes
};
//文件控制块列表信息结构体 4 bytes
struct FCB_list
{
	unsigned long FCB_number;//文件数目 4 bytes
};

//磁盘初始化
void init_disk(disk& v_disk,char* t_disk_start,char* t_disk_name,unsigned long t_disk_size);

//FCB初始化
void init_FCB_FILE(FCB& c_fcb);
void init_FCB_FOLDER(FCB& c_fcb);
//目录文件初始化
void init_index(index& c_index);

//创建文件
bool create_file(char* file_name,char* current_index);//假如当前目录中文件数目为1024创建失败
//删除文件
bool delete_file(char* file_name,char* current_index);//假如文件为只读删除失败
//移动文件
bool move_file(char* file_name,char* s_index,char* d_index);//假如目标目录数目为1024移动失败
//文件改名
bool update_file_name(char* file_name,char* new_file_name);//假如新文件名大于32bytes改名失败

void update_disk_used_size(unsigned int sz);//更新磁盘使用大小
void update_head_use(unsigned int sz);//更新管理空间使用大小
void update_file_offset(unsigned long f_offset);
void copy_fcb(FCB& f_fcb);
void copy_folder(index& t_index);
void copy_file(char* file,DWORD file_len);//文件复制到磁盘中
char* get_folder_start(CString folder_path);//根据文件夹路径，找到目录文件存储的物理地址

void add_file_to_folder(CString folder_path,unsigned int f_fcb_number);//根据文件夹路径，添加文件(FCB数组下标)
char* get_fcb_by_path(CString file_path);//通过文件路径找到fcb
CString get_fn_by_pth(CString file_path);//通过路径获取文件名
void del_file_by_path(CString file_path);//通过路径删除文件
//删除文件时，修改目录文件
void del_update_folder(CString file_pth);