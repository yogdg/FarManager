﻿#include "NetCommon.hpp"
#include "NetCfg.hpp"
#include "NetFavorites.hpp"
#include <PluginSettings.hpp>

struct Options Opt;

struct PluginStartupInfo Info;
struct FarStandardFunctions FSF;
NETRESOURCE CommonCurResource;
NETRESOURCE *PCommonCurResource = NULL;

BOOL IsFirstRun=TRUE;

void WINAPI SetStartupInfoW(const struct PluginStartupInfo *Info)
{
	::Info=*Info;
	::FSF=*Info->FSF;
	::Info.FSF=&::FSF;
	PluginSettings settings(MainGuid, ::Info.SettingsControl);
	Opt.AddToDisksMenu = settings.Get(0,StrAddToDisksMenu,1);
	Opt.AddToPluginsMenu = settings.Get(0,StrAddToPluginsMenu,1);
	Opt.LocalNetwork = settings.Get(0,StrLocalNetwork,TRUE);
	Opt.HiddenShares = settings.Get(0,StrHiddenShares,1);
	Opt.ShowPrinters = settings.Get(0,StrShowPrinters,0);
	Opt.FullPathShares = settings.Get(0,StrFullPathShares,TRUE);
	Opt.FavoritesFlags = settings.Get(0,StrFavoritesFlags,int(FAVORITES_DEFAULTS));
	Opt.RootDoublePoint = settings.Get(0,StrNoRootDoublePoint,TRUE);
	Opt.DisconnectMode = settings.Get(0,StrDisconnectMode, FALSE);
	Opt.HiddenSharesAsHidden = settings.Get(0,StrHiddenSharesAsHidden, TRUE);
	Opt.NavigateToDomains = settings.Get(0,StrNavigateToDomains, FALSE);
	CommonRootResources = new NetResourceList;
	NetResourceList::InitNetResource(CommonCurResource);
}

intptr_t WINAPI ConfigureW(const ConfigureInfo* Info)
{
	return Config();
}

BOOL DlgCreateFolder(wchar_t* lpBuffer, int nBufferSize)
{
	BOOL res = (BOOL)Info.InputBox(&MainGuid,
	                         nullptr,
	                         L"Make Folder",
	                         L"Folder name:",
	                         L"NewFolder",
	                         NULL,
	                         lpBuffer,
	                         nBufferSize,
	                         NULL,
	                         FIB_BUTTONS
	                        );
	return res;
}

/* NO NEED THIS
wchar_t* NextToken(wchar_t *szSource, wchar_t *szToken, int nBuff)
{
  if(!szSource||!szToken)
    return NULL;
  lstrcpyn(szToken, szSource, nBuff);
  return szSource + lstrlen(szSource);
}
*/
