
#include "StdAfx.h"
#include "file_system.h"
#include "time.h"
//磁盘初始化
void init_disk(disk& v_disk,char* t_disk_start,char* t_disk_name,unsigned long t_disk_size)
{
	v_disk.disk_start=t_disk_start;
	memcpy(v_disk.disk_name,t_disk_name,strlen(t_disk_name));
	v_disk.total_space=t_disk_size;
	v_disk.used_space=0;
	int x=0;
}
//文件FCB初始化
void init_FCB_FILE(FCB& c_fcb)

{
	memset(&c_fcb,0,56);
	//	struct tm *ptr;
	time_t lt;
	lt =time(NULL);
	c_fcb.create_time=lt;
	c_fcb.update_time=lt;
	c_fcb.file_properties=0x60;//普通文件，可读，可写，不可执行
	memset(c_fcb.other_use,0,7);
}

//目录FCB初始化
void init_FCB_FOLDER(FCB& c_fcb)
{
	//	struct tm *ptr;
	time_t lt;
	lt =time(NULL);
	c_fcb.create_time=lt;
	c_fcb.update_time=lt;
	c_fcb.file_properties=0xE0;//目录文件，可读，可写，不可执行（1110）
	memset(c_fcb.other_use,0,7);
	c_fcb.file_size=1024*4;
}


//目录文件初始化
void init_index(index& c_index)
{
	c_index.file_number=0;
}
/*
//创建文件
bool create_file(char* file_name,char* current_index);//假如当前目录中文件数目为1024创建失败

  //删除文件
  bool delete_file(char* file_name,char* current_index);//假如文件为只读删除失败
  //移动文件
  bool move_file(char* file_name,char* s_index,char* d_index);//假如目标目录数目为1024移动失败
  //文件改名
  bool update_file_name(char* file_name,char* new_file_name);//假如新文件名大于32bytes改名失败
*/
void update_disk_used_size(unsigned int sz)//更新磁盘使用大小
{
	file_offset+=sz;
	memcpy(disk_start+28,&file_offset,4);
}
void update_head_use(unsigned int sz)//更新管理空间使用大小
{
	v_disk.used_space+=sz;
	memcpy(disk_start,&v_disk,24);
}
void update_file_number()//更新文件数目到磁盘
{
	fcb_number+=1;
	memcpy(disk_start+24,&fcb_number,4);
}
void update_file_offset(unsigned long f_offset)
{
	file_offset+=f_offset;
	memcpy(disk_start+28,&file_offset,4);
}
void copy_fcb(FCB& f_fcb)//fcb复制到磁盘中
{
	memcpy(disk_start+v_disk.used_space,&f_fcb,sizeof(f_fcb));
	v_disk.used_space+=sizeof(f_fcb);
	memcpy(disk_start,&v_disk,sizeof(v_disk));
	
	fcb_number++;
	memcpy(disk_start+24,&fcb_number,4);
}
void copy_folder(index& t_index)//将目录存盘
{
	memcpy(disk_start+file_offset,&t_index,4096);
	file_offset+=4096;
	memcpy(disk_start+28,&file_offset,4);
}
void copy_file(char* file,DWORD file_len)//文件复制到磁盘中
{
	memcpy(disk_start+file_offset,file,file_len);
	file_offset+=file_len;
	memcpy(disk_start+28,&file_offset,4);
}
bool char_Z_compare(char* ch1,char* ch2)//数组比较
{
	if (strlen(ch1)==strlen(ch2))
	{
		CString str1=ch1;
		CString str2=ch2;
		if (!str1.Compare(ch2))
		{
			return true;
		}
	}
	return FALSE;
}
char* get_folder_start(CString folder_path)//根据文件夹路径，找到目录文件存储的物理地址
{
	if (!folder_path.Compare("/"))//根目录
	{
		return disk_start+4*1024*1024;
	}
	unsigned int index_level=0;//文件夹层数
	int i;
	for (i=0;i<folder_path.GetLength();i++)
	{
		if (folder_path.GetAt(i)=='/')
		{
			index_level++;
		}
	}
	char** folder=new char*[index_level];
	for (i=0;i<index_level;i++)
	{
		folder[i]=new char[32];
	}
	//将各个文件夹名放置到二维数组中
	folder[0]="/";//根目录
	int j=0;
	int cstr_index=1;
	for (i=1;i<index_level;i++)
	{
		j=0;
		while (folder_path.GetAt(cstr_index)!='/')
		{
			folder[i][j]=folder_path.GetAt(cstr_index);
			cstr_index++;
			j++;
		}
		folder[i][j]=0;
		j++;cstr_index++;
	}
	//依次找到二维数组中的文件夹
	char* folder_store;
	FCB f_fcb;
	index f_index;//文件夹文件
	folder_store=disk_start+4*1024*1024;
	for (i=1;i<index_level;i++)
	{
		memcpy(&f_index,folder_store,4*1024);
		for (j=0;j<f_index.file_number;j++)
		{
			memcpy(&f_fcb,disk_start+32+56*f_index.fcb_index[j],56);
			if (char_Z_compare(folder[i],f_fcb.file_name))
			{
				folder_store=disk_start+f_fcb.file_start;//磁盘开始位置+目录文件偏移
				break;
			}
		}
	}
	return folder_store;
}
void add_file_to_folder(CString folder_path,unsigned int f_fcb_number)
{
	char* folder_store;
	FCB f_fcb;
	index f_index;//目录文件
	folder_store=get_folder_start(folder_path);
	memcpy(&f_index,folder_store,4*1024);
	f_index.file_number++;
	f_index.fcb_index[f_index.file_number-1]=f_fcb_number;
	//回写目录文件
	memcpy(folder_store,&f_index,4*1024);
}
char* get_fcb_by_path(CString file_path)//通过文件路径找到fcb
{
	if (!file_path.Compare("/"))//根目录
	{
		return disk_start+32;
	}
	unsigned int index_level=0;//文件夹层数
	int i;
	for (i=0;i<file_path.GetLength();i++)
	{
		if (file_path.GetAt(i)=='/')
		{
			index_level++;
		}
	}
	char** folder=new char*[index_level];
	for (i=0;i<index_level;i++)
	{
		folder[i]=new char[32];
	}
	//将各个文件夹名放置到二维数组中
	folder[0]="/";//根目录
	int j=0;
	int cstr_index=1;
	for (i=1;i<index_level;i++)
	{
		j=0;
		while (file_path.GetAt(cstr_index)!='/')
		{
			folder[i][j]=file_path.GetAt(cstr_index);
			cstr_index++;
			j++;
		}
		folder[i][j]=0;
		j++;cstr_index++;
	}
	//依次找到二维数组中的文件夹
	char* folder_store;
	FCB f_fcb;
	index f_index;//文件夹文件
	folder_store=disk_start+4*1024*1024;
	int fcb_offset=0;
	for (i=1;i<index_level;i++)
	{
		memcpy(&f_index,folder_store,4*1024);
		for (j=0;j<f_index.file_number;j++)
		{
			fcb_offset=32+56*f_index.fcb_index[j];
			memcpy(&f_fcb,fcb_offset+disk_start,56);
			if (char_Z_compare(folder[i],f_fcb.file_name))
			{
				folder_store=disk_start+f_fcb.file_start;//磁盘开始位置+目录文件偏移
				break;
			}
		}
	}
	char* folder_fcb=disk_start+fcb_offset;
	
	if (file_path.Right(1).Compare(_T("/")))
	{
		//如果是文件
		char file_name[32];
		memset(file_name,0,32);
		CString cstr_file_name=file_path.Right(file_path.GetLength()-file_path.ReverseFind('/')-1);
		memcpy(file_name,cstr_file_name.GetBuffer(cstr_file_name.GetLength()),cstr_file_name.GetLength());
		memset(&f_index,0,4096);
		memcpy(&f_index,folder_store,4*1024);
		for (j=0;j<f_index.file_number;j++)
		{
			fcb_offset=32+56*f_index.fcb_index[j];
			memset(&f_fcb,0,56);
			memcpy(&f_fcb,fcb_offset+disk_start,56);
			if (char_Z_compare(file_name,f_fcb.file_name))
			{
				folder_store=disk_start+f_fcb.file_start;//磁盘开始位置+目录文件偏移
				break;
			}
		}
		char* file_fcb=disk_start+fcb_offset;
		return file_fcb;
	}
	return folder_fcb;
	
}
//通过文件路径获取文件名
CString get_fn_by_pth(CString file_path)
{
	CString cstr_file_name=file_path.Right(file_path.GetLength()-file_path.ReverseFind('/')-1);
	return cstr_file_name;
}
//通过目录删除文件
void del_file_by_path(CString file_path)
{
	char* pFcb=get_fcb_by_path(file_path);
	//将FCB拷贝出来
	memset(&folder_fcb,0,56);
	memcpy(&folder_fcb,pFcb,56);
	//依次移动FCB
	FCB tp_fcb;
	
	//被删除文件大小
	unsigned long tfile_size=folder_fcb.file_size;
	
	int fcb_offset=(pFcb-disk_start-32)/56;//被删文件的FCB数组下标
	int i=0;
	for (i=0;i<fcb_number-fcb_offset;i++)
	{
		memset(&tp_fcb,0,56);
		
		memcpy(&tp_fcb,pFcb+56,56);
		tp_fcb.file_start=tp_fcb.file_start-tfile_size;
		memcpy(pFcb,&tp_fcb,56);
		pFcb+=56;
	}

	fcb_number--;
	memcpy(disk_start+24,&fcb_number,4);

	//memmove函数，可以重叠拷贝,实现文件向上推进
	unsigned long tfile_start=folder_fcb.file_start;
	memmove(disk_start+tfile_start,disk_start+tfile_start+tfile_size,file_offset-tfile_start-tfile_size);

	//修改所有包含被移动FCB的目录文件
	FCB folder_fcb_tp;
	index folder_index_tp;
	char* folder_stt_tp;
	int fnum=0;
	int j;
	for (i=0;i<fcb_number;i++)
	{
		memset(&folder_fcb_tp,0,56);
		memcpy(&folder_fcb_tp,disk_start+32+56*i,56);
		if ((folder_fcb_tp.file_properties&0x80)==0)//判断是文件
		{
			continue;
		}else//是目录
		{
			folder_stt_tp=disk_start+folder_fcb_tp.file_start;
			memset(&folder_index_tp,0,4096);
			memcpy(&folder_index_tp,folder_stt_tp,4096);//拷贝出目录文件
			fnum=folder_index_tp.file_number;
			for (j=0;j<fnum;j++)
			{
				if (folder_index_tp.fcb_index[j]==fcb_offset)//正是被删除的文件
				{
					folder_index_tp.file_number--;
					for (int k=j;k<fnum-1;k++)
					{
						folder_index_tp.fcb_index[k]=folder_index_tp.fcb_index[k+1];
						if (folder_index_tp.fcb_index[k]>fcb_offset)
						{
							folder_index_tp.fcb_index[k]--;
						}	
					}
					break;
				}
				if (folder_index_tp.fcb_index[j]>fcb_offset)//被移动的都-1
				{
					folder_index_tp.fcb_index[j]--;
				}
			}
			memcpy(folder_stt_tp,&folder_index_tp,4096);//目录拷贝到磁盘
		}

	}
	//更新磁盘信息
	file_offset-=tfile_size;
	memcpy(disk_start+28,&file_offset,4);

	v_disk.used_space=v_disk.used_space-56;
	memcpy(disk_start,&v_disk,24);
}
//删除文件时，修改目录文件
void del_update_folder(CString file_pth)
{
	char* fcb_st=get_fcb_by_path(file_pth);
	int tfcb_number=(fcb_st-disk_start-32)/56;
	char* folder_st=get_folder_start(file_pth);
	index folder;
	memset(&folder,0,4096);
	memcpy(&folder,folder_st,4096);
	int i;
	for ( i=0;i<folder.file_number;i++)
	{
		if (folder.fcb_index[i]==tfcb_number)
		{
			break;
		}
	}
	for (i=i;i<folder.file_number;i++)
	{
		folder.fcb_index[i]=folder.fcb_index[i+1];
	}
	folder.file_number--;
	memcpy(folder_st,&folder,4096);
}