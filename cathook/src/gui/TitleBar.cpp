/*
 * TitleBar.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: nullifiedcat
 */

#include "TitleBar.h"

#include "GUI.h"

#include "../common.h"
#include "../sdk.h"

TitleBar::TitleBar(IWidget* parent, const char* name) : CBaseWidget(parent, "title") {
	strncpy(m_Text, name, 255);
	m_iDraggingStage = 0;
	m_nLastX = 0;
	m_nLastY = 0;
}

void TitleBar::GetSize(int& x, int& y) {
	int sx, sy;
	m_pParentWidget->GetSize(sx, sy);
	if (sx < 100) x = 100;
	else x = sx;
	y = 16;
	m_nSizeX = x;
	m_nSizeY = y;
}

void TitleBar::Draw() {
	int ox, oy;
	int sx, sy;
	GetAbsolutePosition(ox, oy);
	draw::DrawRect(ox, oy, m_nSizeX, m_nSizeY, colors::pink);
	int l, h;
	draw::GetStringLength(m_Text, l, h);
	draw::DrawString(draw::font_handle_menu, ox + (m_nSizeX - l) / 2, oy + 1, colors::white, "%s", m_Text);
}

void TitleBar::Update() {
	if (!m_bMousePressed) {
		m_iDraggingStage = 0;
		return;
	}
	if (m_iDraggingStage == 0) {
		m_iDraggingStage = 1;
	} else {
		int ox, oy;
		int dx = g_pGUI->m_iMouseX - m_nLastX;
		int dy = g_pGUI->m_iMouseY - m_nLastY;
		this->m_pParentWidget->GetOffset(ox, oy);
		this->m_pParentWidget->SetOffset(ox + dx, oy + dy);
		logging::Info("Dragging %s: NEW %i %i", this->m_pParentWidget->GetName(), ox + dx, oy + dy);
	}
	m_nLastX = g_pGUI->m_iMouseX;
	m_nLastY = g_pGUI->m_iMouseY;
}