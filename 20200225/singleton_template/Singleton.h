//
//  Singleton.h
//  spellCorrection用户输入助手
//
//  Created by ChengWang on 3/7/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

template <typename T>
class Singleton
{
public:
    static T* getInstance()
    {
        return m_pInstance;
    }
private:
    static T* m_pInstance;
    
    Singleton(){} //构造函数为private
};

template <typename T>
T*  Singleton<T> :: m_pInstance = new T;


#endif /* Singleton_h */
