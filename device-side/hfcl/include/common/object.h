/*
** HFCL - HybridOS Foundation Class Library
**
** Copyright (C) 2018 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HFCL_COMMON_OBJECT_H_
#define HFCL_COMMON_OBJECT_H_

#include "../common/common.h"

namespace hfcl {

class Object {
public:
    Object();

    virtual ~Object();
};

/**
 * \class Noncopyable
 *
 * Noncopyable is the base class for objects that may do not want to
 * be copied. It hides its copy - constructor and its assignment - operator.
 */
class Noncopyable {
    public:
        Noncopyable() { }

    private:
        Noncopyable(const Noncopyable& aNoCopy);
        Noncopyable& operator=(const Noncopyable& aNoCopy);
};

/**
 * \class RefCount
 *
 * RefCount is the base class for objects that may be shared by multiple
 * objects. When a new owner wants a reference, it calls ref(). When an owner
 * wants to release its reference, it calls unref(). When the shared object's
 * reference count goes to zero as the result of an unref() call, its (virtual)
 * destructor is called. It is an error for the destructor to be called
 * explicitly (or via the object going out of scope on the stack or calling
 * delete) if getRefCnt() > 1.
 */
class RefCount : Noncopyable {
public:
    /**
     * Default construct, initializing the reference count to 1.
     */
    RefCount() : m_refCount(1) { }
    RefCount(int start_ref) : m_refCount(start_ref) { } //for special use

    /**
     * Destruct, asserting that the reference count is 1.
     */
    virtual ~RefCount() { }

    virtual void onNoRef () { HFCL_DELETE (this); }

    /**
     * Return the reference count.
     */
    int getRefCnt() const { return m_refCount; }

    inline int refInc() {return ++m_refCount;}
    inline int refDec() {return --m_refCount;}

    /**
     * Increment the reference count. Must be balanced by a call to unref().
     */
    int ref() {
        return refInc();
    }

    /**
     * Decrement the reference count. If the reference count is 1 before the
     * decrement, then call delete on the object. Note that if this is the
     * case, then the object needs to have been allocated via new, and not on
     * the stack.
     */
    int unref() {
        if (refDec () == 0) {
            onNoRef ();
            return 0;
        }
        return m_refCount;
    }

    /**
     * Helper version of ref(), that first checks to see if this is not null.
     * If this is null, then do nothing.
     */
    inline int safeRef() {
        return ref();
    }

    /**
     * Helper version of unref(), that first checks to see if this is not
     * null.
     * If this is null, then do nothing.
     */
    inline int safeUnref()
    {
        return unref();
    }

private:
    mutable int m_refCount;
};


class AutoPtr
{
protected:
    RefCount* _ptr;

public:
    AutoPtr() : _ptr(NULL) {}

    AutoPtr(RefCount* p_ptr) : _ptr(p_ptr)
    {
        if (_ptr)
            _ptr->ref();
    }

    AutoPtr(const AutoPtr& p)
    {
        _ptr = p.ptr();
        if (_ptr)
            _ptr->ref();
    }

    ~AutoPtr() {
        if(_ptr){
            _ptr->safeUnref();
        }
    }

    void set(RefCount* p_ptr)
    {
        if (_ptr == p_ptr)
            return;
        if (_ptr)
            _ptr->unref();
        _ptr = p_ptr;
        if (_ptr)
            _ptr->ref();
    }

    friend bool operator==(AutoPtr& ap1, AutoPtr& ap2)
    {
        if (ap1._ptr == ap2._ptr)
            return true;
        return false;
    }

    bool operator!() const { return _ptr == NULL; }

    RefCount* ptr() const { return _ptr; }
};

class CopyOnWriteable : public RefCount {
public:
    CopyOnWriteable () : RefCount () {}
    CopyOnWriteable (int start_ref) : RefCount (start_ref) { }

    virtual CopyOnWriteable *clone() { return NULL; }

    bool needCopy() { return getRefCnt () > 1; }
};

} // namespace hfcl

#define AUTOPTR(Base) \
    class Base##Ptr : public AutoPtr { \
        public: \
            Base##Ptr() { } \
            Base##Ptr(Base* p_ptr) : AutoPtr((RefCount*)p_ptr) { } \
            Base* ptr() const { return (Base*)AutoPtr::ptr(); } \
            Base* ptr() { return (Base*)AutoPtr::ptr(); } \
            Base* operator->() { return ptr(); } \
    };

#endif /* HFCL_COMMON_OBJECT_H_ */

