/*
 * ItemSublist.hpp
 *
 *  Created on: Mar 26, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "menu/ncc/Item.hpp"
#include "menu/ncc/List.hpp"

class CatVar;

namespace menu::ncc
{

class List; // ????

class ItemSublist : public Item
{
public:
    ItemSublist(std::string title, List *list);

    virtual void SetParent(IWidget *) override;
    virtual bool IsHovered() override;
    virtual void Update() override;
    virtual void Draw(int x, int y) override;
    virtual void OnKeyPress(ButtonCode_t code, bool repeated) override;
    virtual void OnMouseEnter();
    virtual void OnMouseLeave();

public:
    List *const list;
    const std::string title;
};
}
