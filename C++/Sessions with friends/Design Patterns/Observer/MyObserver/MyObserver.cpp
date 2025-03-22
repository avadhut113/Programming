#include <iostream>
#include <unordered_map>
#include <string>
/*
* 1. We can make additional segregation in event/state type and we can maintain separate list of obesrvers for each even type. And,
* we can do that using map data structure i.e. std::unordered_map < EventType, std::list<IObservers list> >
* 2. Use list data type for storing a list of obesvers because delation might be happened at any position.
* 3. TODO: Try to implement observer for accross processes.
* 4. TODO: Check boost::single or QT example
*/

enum class EventFile
{
    Save = 0,
    Open
};

std::ostream& operator<< (std::ostream& out, EventFile& event)
{
    switch (event)
    {
    case EventFile::Open: out << "Open"; break;
    case EventFile::Save: out << "Save"; break;
    }
    return out;
}

class IListener;

class EventManager //Subject
{
protected:
    std::unordered_map <EventFile, std::list<IListener*>> subsribers;

public:

    void Attach(EventFile type, IListener* ob)
    {
        std::list<IListener*>& Observers = subsribers[type];
        Observers.emplace_back(ob);
    }

    void Detach(EventFile type, IListener* ob)
    {
        std::list<IListener*>& Observers = subsribers[type];
        Observers.remove(ob);
    }

    void Notify(EventFile type);
};

class IListener // Abstract Observer
{
public:
    virtual void Update(EventFile event) = 0;
};

class EmailAlertListener : public IListener // concreate Observer
{
public:
    EmailAlertListener(EventFile event, EventManager* sub)
    {
        sub->Attach(event, this);
    }


    void Update(EventFile event) override
    {
        std::cout << "EmailAlertListener got the notification for event type : " << event << std::endl;
    }
};

class LogginAlertListerner : public IListener // concreate Observer
{
public:
    LogginAlertListerner(EventFile event, EventManager* sub)
    {
        sub->Attach(event, this);
    }

    void Update(EventFile event) override
    {
        std::cout << "LogginAlertListerner got the notification for event type : " << event << std::endl;
    }
};

class Editor
{
    EventManager* manager;
public:
    Editor() {
        manager = new EventManager();
    }

    EventManager* getManager() const {
        return manager;
    }

    void SaveFile() {
        manager->Notify(EventFile::Save);
    }

    void OpenFile() {
        manager->Notify(EventFile::Open);
    }
};

void EventManager::Notify(EventFile type)
{
    for (const auto& listner : subsribers[type])
    {
        listner->Update(type);
    }
}

int main()
{
    Editor* edit = new Editor();
    IListener* LogListner = new LogginAlertListerner(EventFile::Save, edit->getManager());
    IListener* EmailListener1 = new EmailAlertListener(EventFile::Open, edit->getManager());
    IListener* EmailListener2 = new EmailAlertListener(EventFile::Save, edit->getManager());


    edit->OpenFile();
    edit->SaveFile();

    return 0;
}