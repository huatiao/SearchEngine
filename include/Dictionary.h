#ifndef __WD_DICTIONARY_H__
#define __WD_DICTIONARY_H__

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

class Dictionary
{
public:
    static Dictionary *getDictSigleInstance();
    void init(const string &dictPath, const string &dictIndexPath);
    vector<pair<string, int>> &getDict() { return *_dict; }    //获取词典
    map<string, set<int>> &getIndexTable() { return *_index; } //获取词典索引
private:
    Dictionary() {}
    ~Dictionary() {}

private:
    class AutoRelease //负责单例Dictionary类对象的释放
    {
    public:
        AutoRelease() {}

        ~AutoRelease()
        {
            if (_pDictSigleInstance != nullptr)
            {
                delete _pDictSigleInstance;
                _pDictSigleInstance = nullptr;
            }
        }
    };

private:
    shared_ptr<vector<pair<string, int>>> _dict;
    shared_ptr<map<string, set<int>>> _index;

    static Dictionary *_pDictSigleInstance;
    static AutoRelease _ar;
};

#endif