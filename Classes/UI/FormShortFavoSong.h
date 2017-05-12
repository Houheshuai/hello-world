//----------------------------------------------------------------------------//
// Multak 3D GUI Project						
//
// Filename : FormShortFavoSong.h
//																	
// Description: 
// 
//----------------------------------------------------------------------------//
// History:
//
// v1.00 : first release
//
//----------------------------------------------------------------------------//
//
#pragma once

#ifndef _FORMSHORTFAVOSONG_H_
#define _FORMSHORTFAVOSONG_H_

#include "Widgets/M3D_Form.h"


namespace CEGUI
{
class M3D_PageListView;
class M3D_Item;
class M3D_ScrollBar;
class M3D_Label;
class FormShortFavoSong:public M3D_Form
{
public:

	FormShortFavoSong(const String& type, const String& name);
	virtual ~FormShortFavoSong(void);

	static const String EventNamespace; 			//!< Namespace for global events
	static const String WidgetTypeName; 			//!< Window factory name


	virtual void constructWindow(WndRes_t *wndRes);
	virtual void destructWindow(void);

	virtual void onShown(WindowEventArgs& e);
	virtual void onHidden(WindowEventArgs& e);

	virtual void onCreated(void);
	virtual void onDestroyed(void);

	virtual void onActivated(ActivationEventArgs& e);
	virtual void onDeactivated(ActivationEventArgs& e);

	virtual void onActionStart(void);
	virtual void onActionEnd(void); 
	
	virtual void onTimeout(EventArgs& e);

	virtual void onCharacter(KeyEventArgs& e);

private:
	void initFormData(void);
	void setupBinding(bool firsttime);
	void handleReloadData(M3D_Item *item, int position);
	void handlePageChange(int currentPage, int totalPage);
	void handleListClicked(M3D_Item *item, int position);
	bool handleProgClicked(void);
	bool handleInsertClicked(void);
	bool handleDeleteClicked(void);
		
	M3D_PageListView*	d_songlist;
	M3D_ScrollBar*		d_scrollbar;
	M3D_Label*			d_searchstr;
	
	int					d_dataCount;

	// search str
	int 				d_lastKey;
	int 				d_lastKeyIndex;
	int 				d_curPos;
	bool				d_confirm;
	char				d_str[Max_StrPara];

};

}

#endif