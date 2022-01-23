
#include "opengl.hpp"

namespace gl {

class WglSwap : public Swap {
public:
};

class WglPlatform : public Platform
{
public:
    WglPlatform() = default;

    bool initialize() override {
        return true;
    }

    //=========================================================================
    Swap* create_swap (const evgSwapInfo* setup) override {
        return nullptr;
    }

    void load_swap (const Swap* swap) override {}

    void swap_buffers() override {}

    //=========================================================================
    void* context_handle() const noexcept override { return nullptr; }
    void enter_context() override {}
    void leave_context() override {}
    void clear_context() override {}
};

Platform* create_platform()
{
    auto mp = new WglPlatform();
    return mp;    
}

void destroy_platform (Platform* p)
{
    delete dynamic_cast<WglPlatform*> (p);
}

}
