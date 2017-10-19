//
// PROJECT:         Aspia Remote Desktop
// FILE:            protocol/category.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_PROTOCOL__CATEGORY_H
#define _ASPIA_PROTOCOL__CATEGORY_H

#include "base/macros.h"
#include "base/logging.h"

#include <list>
#include <memory>

namespace aspia {

class Category;
using CategoryList = std::list<std::unique_ptr<Category>>;

class Category
{
public:
    enum class Type { GROUP, INFO };
    using IconId = int;

    virtual ~Category() = default;

    Type type() const { return type_; }
    IconId Icon() const { return icon_id_; }
    const std::string& Name() const { return name_; }

    const CategoryList& child_list() const
    {
        DCHECK(type_ == Type::GROUP);
        return child_list_;
    }

    CategoryList* mutable_child_list()
    {
        DCHECK(type_ == Type::GROUP);
        return &child_list_;
    }

protected:
    Category(Type type, const std::string& name, IconId icon_id)
        : type_(type),
          name_(name),
          icon_id_(icon_id)
    {
        // Nothing
    }

private:
    const Type type_;
    const std::string name_;
    const IconId icon_id_;

    CategoryList child_list_;

    DISALLOW_COPY_AND_ASSIGN(Category);
};

} // namespace aspia

#endif // _ASPIA_PROTOCOL__CATEGORY_H
