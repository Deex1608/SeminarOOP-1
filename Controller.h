#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "MediaRepository.h"
#include "Song.h"
#include <stack>
#include <utility>
class UndoAction {
public:
    virtual void executeUndo()=0;
    virtual ~UndoAction()=default;
};

class UndoRemove: public UndoAction {
private:
    shared_ptr<Media> deletedMedia;
    MediaRepository& repo; //referinta-> pasezi prin CONSTRUCTOR
public:
    UndoRemove(shared_ptr<Media> d, MediaRepository& r): deletedMedia(std::move(d)),repo(r){}
    void executeUndo() override {
        repo.addItem(deletedMedia);
    }
};

class UndoAdd: public UndoAction {
private:
    shared_ptr<Media> addedMedia;
    MediaRepository& repo;
public:
    UndoAdd(shared_ptr<Media> a, MediaRepository& r):addedMedia(a), repo(r) {}
    void executeUndo() override {
        repo.removeItem(addedMedia->getTitle());
    }
};
class Controller {
private:
    MediaRepository& m;
    stack<unique_ptr<UndoAction>> actions;
public:
    Controller(MediaRepository& ms): m(ms){}
    void addItem(string& url, string& title, int duration, string& artist) {
        shared_ptr<Media> s1=std::make_shared<Song>(url,title,duration,artist);
        m.addItem(s1);
        std::unique_ptr<UndoAction> act = std::make_unique<UndoAdd>(s1,m);
       // act->executeUndo();
        actions.push(act);
    }

    void undo() {
        if (!actions.empty()) {

        }
    }

};
#endif //CONTROLLER_H
