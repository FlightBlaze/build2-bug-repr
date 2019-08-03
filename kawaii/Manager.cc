#include <vector>

export module kawaii.Manager;
export import kawaii.WindowImpl;

export namespace kawaii {
    
    class WindowGroup {
      
        std::vector<AbstractWindow*> _list;
        long _pid;
        
    public:
        
        WindowGroup(long pid): _pid(pid)
        {
        }
        
        AbstractWindow* getWindow(int index) {
            return _list[index];
        }
        
        long getPid() {
            return _pid;
        }
        
        int size() {
            return _list.size();
        }
        
    };
    
    class Manager {
        
        std::vector<AbstractWindow*> _sequence;
        std::vector<AbstractWindow*> _windows;
        std::vector<WindowGroup*> _groups;
        
    public:
        
        AbstractWindow* getWindow(int index) {
            return _windows[index];
        }
        
        AbstractWindow* getWindowByOrder(int order) {
            return _sequence[order];
        }
        
        WindowGroup* getWindowGroup(int index) {
            return _groups[index];
        }
        
        int getSequenceLength() {
            return _sequence.size();
        }
        
        int getAmountOfWindowGroups() {
            return _groups.size();
        }
        
        int getAmountOfWindows() {
            return _windows.size();
        }
        
        int getOrder(AbstractWindow* window)
        {
            for(int i = 0; i < _windows.size(); i++) {
                if(_windows[i] == window)
                    return i;
            }
            return -1;
        }
        
        void updateGroups() {
            //TODO: ...
        }
        
        ~Manager()
        {
            for(AbstractWindow *w: _windows)
                delete w;
            
            for(WindowGroup *g: _groups)
                delete g;
        }
        
    };
    
}
