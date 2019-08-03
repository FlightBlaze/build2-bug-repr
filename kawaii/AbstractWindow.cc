export module kawaii.AbstractWindow;

export namespace kawaii {
 
    class AbstractWindow {
        
        int _x, _y, _width, _height;
        
        bool _maximized   = false,
             _minimized   = false,
             _modal       = false,
             _decorated   = true,
             _deletable   = true,
             _fullscreen  = false,
             _above       = false,
             _below       = false,
             _rounded     = true,
             _blurbehind  = false,
             _popup;
             
        AbstractWindow *_transientfor = 0;
        
        char *_title;
        long _pid;
        
    protected:
        
        virtual void render() = 0;
        
    public:
        
        AbstractWindow(bool popup): _popup(popup)
        {
        }
        
        virtual ~AbstractWindow() = 0;
        
        virtual bool isActive() = 0;
        virtual void focus() = 0;
        virtual void blur() = 0;
        
        bool isMaximized() const {
            return _maximized;
        }
        
        void setMaximized(bool v) {
            _maximized = v;
        }
        
        bool isMinimized() const {
            return _minimized;
        }
        
        void setMinimized(bool v) {
            _minimized = v;
        }
        
        bool isModal() const {
            return _modal;
        }
        
        void setModal(bool v) {
            _modal = v;
        }
        
        bool isDecorated() const {
            return _decorated;
        }
        
        void setDecorated(bool v) {
            _decorated = v;
        }
        
        bool isDeletable() const {
            return _deletable;
        }
        
        void setDeletable(bool v) {
            _deletable = v;
        }
        
        bool isFullscreen() const {
            return _fullscreen;
        }
        
        void setFullscreen(bool v) {
            _fullscreen = v;
        }
        
        bool isAbove() const {
            return _above;
        }
        
        void setAbove(bool v) {
            _above = v;
        }
        
        bool isBelow() const {
            return _below;
        }
        
        void setBelow(bool v) {
            _below = v;
        }
        
        bool isPopup() const {
            return _popup;
        }
        
        void setPopup(bool v) {
            _popup = v;
        }
        
        bool isRounded() const {
            return _rounded;
        }
        
        void setRounded(bool v) {
            _rounded = v;
        }
        
        bool hasBlurBehind() const {
            return _blurbehind;
        }
        
        void setBlurBehind(bool v) {
            _blurbehind = v;
        }
        
        char* getTitle() {
            return _title;
        }
        
        void setTitle(char *t) {
            _title = t;
        }
        
        AbstractWindow *getTransientFor() const {
            return _transientfor;
        }
        
        void setTransientFor(AbstractWindow* w) {
            _transientfor = w;
        }
        
        long getPid() const {
            return _pid;
        }
        
        void setPid(long p) {
            _pid = p;
        }
        
        int getX() const {
            return _x;
        }
        
        void setX(int v) {
            _x = v;
        }
        
        int getY() const {
            return _y;
        }
        
        void setY(int v) {
            _y = v;
        }
        
        int getWidth() const {
            return _width;
        }
        
        void setWidth(int v) {
            if(v > 0)
            _width = v;
        }
        
        int getHeight() const {
            return _height;
        }
        
        void setHeight(int v) {
            if(v > 0)
            _height = v;
        }
        
    };
    
}
