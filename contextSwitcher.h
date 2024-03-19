class ContextSwitcher {
private:
static int currentContext;   

public:
    static void switchContext(int newContext);
    static int getContext();
};
