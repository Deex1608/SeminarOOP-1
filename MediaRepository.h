#ifndef MEDIAREPOSITORY_H
#define MEDIAREPOSITORY_H
#include <vector>
#include "Media.h"
#include <memory>
#include <algorithm>
class MediaRepository {
protected:
    std::vector<shared_ptr<Media>> items;
public:
    void addItem(shared_ptr<Media> m) {
        if (findByTitle(m->getTitle())!=shared_ptr<Media>(nullptr)) {
            throw invalid_argument("The item already exists!");
        }
        items.push_back(m);
    }

    void removeItem(string t) {
        std::vector<shared_ptr<Media>>::iterator result=std::find_if(items.begin(),items.end(),[t](shared_ptr<Media> el)->bool {
           return el->getTitle()==t;
        });
        if (result==items.end()) {
            throw runtime_error("The item doesn't exists!");
        }
        items.erase(result);
    }

    const std::vector<shared_ptr<Media>>& getAllItems() const { //Ca sa nu faca copie, punem & si returneaza efectiv items, nu o copie
        return items;
    }

    shared_ptr<Media> findByTitle(string t) {
      auto result= std::find_if(items.begin(),items.end(),[t](shared_ptr<Media> el)->bool {
           return el->getTitle()==t;
        });
        if (result==items.end()) {
            return shared_ptr<Media>(nullptr);
        }
        return *result;
    }
};

#endif //MEDIAREPOSITORY_H
