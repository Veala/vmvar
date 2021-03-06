// -*- mode:c++; coding:utf-8; -*-
///
/// \file		N2Register.cpp
///
///	\brief 		Реестр библиотеки.
/// \details	Тут хранятся и создаются все необходимые объекты общего 
/// \details	использования.
/// \details	Реализован на основе паттерна Singleton.
///
/// \copyright  ЗАО НТЦ "Модуль"
/// \author 	Чихичин Д.А.
///
/// \date 		21.03.2014
/// \version 	0.1
///  
///  История изменений:
///  
/// 27.07.15 - добавлены функции определения дополнительных путей поиска
///

#include "../export/common/N2Register.h"

// Инициализация статического члена
N2Register*  N2Register::globalReg = NULL;
//ITreeNode* N2Register::pPrjTree_ = NULL;
void* N2Register::pPrjTree_ = NULL;
//N2Console*  N2Register::pConsole = NULL;


N2Register::N2Register() :
	pConsole(NULL)
{
	pLog_ = new N2Logbook();
	pEnv_ = new N2Environment();
}

N2Register::~N2Register()
{
}

N2Register::N2Register(const N2Register& r)
{
}

//! Получение статического указателя на реестр
N2Register* N2Register::self(void)
{
	if(globalReg == NULL) {
		globalReg = new N2Register();
		//deviceInfo_ = new N2ProjectSpecialInfo();

	}
	return globalReg;
}


N2Logbook*
N2Register::log(void)
{
	return pLog_;
}

N2ProjectSpecialInfo* 
N2Register::getDeviceInfo(void)
{
	return &deviceInfo_;
}


OLS_Heap* N2Register::getMemoryAllocator(void)
{
	return &memoryAllocator;
}

void 
N2Register::addPath(std_string path, PATH_FOR pf)
{
	if(path == EMPTY_STR)
		return;

	switch (pf)
	{
	case DEVICE_LIBRARY:
		deviceInfo_.pathsDevices.addPath(path);
		break;
	case TASK_FIND:
		deviceInfo_.pathsTasks.addPath(path);
		break;
	default:
		break;
	}

}

void 
N2Register::reset()
{
		deviceInfo_.pathsDevices.resetPaths();
		deviceInfo_.pathsTasks.resetPaths();
		deviceInfo_.modules.clear();
}

