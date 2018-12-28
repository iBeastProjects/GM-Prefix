[...]

void CPythonTextTail::ArrangeTextTail()
{
	[...]

	for (itor = m_CharacterTextTailList.begin(); itor != m_CharacterTextTailList.end(); ++itor)
	{
		[...]		
#ifdef ENABLE_GAMEMASTER_PREFIX
		CGraphicTextInstance * prGMTitle = pTextTail->pGMTitleTextInstance;
#endif
		if (pMarkInstance && pGuildNameInstance)
		{
			[...]

		}
		
#ifdef ENABLE_GAMEMASTER_PREFIX			
		if (prGMTitle)
		{
			fxAdd = 6.0f;

			int iNameWidth, iNameHeight;
			pTextTail->pTextInstance->GetTextSize(&iNameWidth, &iNameHeight);

			if (pTextTail->pTitleTextInstance)
			{
				int iTitleWidth, iTitleHeight;
				pTextTail->pTitleTextInstance->GetTextSize(&iTitleWidth, &iTitleHeight);

				prGMTitle->SetPosition(pTextTail->x + (iNameWidth/2) + (iTitleWidth/2) + fxAdd, pTextTail->y, pTextTail->z);
			}
			else
				prGMTitle->SetPosition(pTextTail->x + iNameWidth + fxAdd, pTextTail->y, pTextTail->z);

			prGMTitle->Update();
		}
#endif

		[...]
}

void CPythonTextTail::Render()
{
	TTextTailList::iterator itor;

	for (itor = m_CharacterTextTailList.begin(); itor != m_CharacterTextTailList.end(); ++itor)
	{
		[...]
		
		if (pTextTail->pTitleTextInstance)
		{
			pTextTail->pTitleTextInstance->Render();
		}
#ifdef ENABLE_GAMEMASTER_PREFIX
		if (pTextTail->pGMTitleTextInstance)
		{
			pTextTail->pGMTitleTextInstance->Render();
		}
#endif
		[...]
	}

	[...]
}

void CPythonTextTail::RegisterCharacterTextTail(DWORD dwGuildID, DWORD dwVirtualID, const D3DXCOLOR & c_rColor, float fAddHeight)
{
	[...]
	pTextTail->pTitleTextInstance=NULL;
#ifdef ENABLE_GAMEMASTER_PREFIX
	pTextTail->pGMTitleTextInstance=NULL;
#endif

	[...]
}

[...]

CPythonTextTail::TTextTail * CPythonTextTail::RegisterTextTail(DWORD dwVirtualID, const char * c_szText, CGraphicObjectInstance * pOwner, float fHeight, const D3DXCOLOR & c_rColor)
{
	[...]
	pTextTail->pTitleTextInstance = NULL;
#ifdef ENABLE_GAMEMASTER_PREFIX
	pTextTail->pGMTitleTextInstance = NULL;
#endif
	pTextTail->pLevelTextInstance = NULL;
	return pTextTail;
}

void CPythonTextTail::DeleteTextTail(TTextTail * pTextTail)
{
	[...]
	
	if (pTextTail->pTitleTextInstance)
	{
		CGraphicTextInstance::Delete(pTextTail->pTitleTextInstance);
		pTextTail->pTitleTextInstance = NULL;
	}
#ifdef ENABLE_GAMEMASTER_PREFIX
	if (pTextTail->pGMTitleTextInstance)
	{
		CGraphicTextInstance::Delete(pTextTail->pGMTitleTextInstance);
		pTextTail->pGMTitleTextInstance = NULL;
	}
#endif

	[...]
}

#ifdef ENABLE_GAMEMASTER_PREFIX
void CPythonTextTail::AttachGMTitle(DWORD dwVID, const char * c_szGMTitle)
{
	if (!bPKTitleEnable)
		return;

	TTextTailMap::iterator itor = m_CharacterTextTailMap.find(dwVID);
	if (m_CharacterTextTailMap.end() == itor)
		return;

	TTextTail * pTextTail = itor->second;

	CGraphicTextInstance *& prGMTitle = pTextTail->pGMTitleTextInstance;
	if (!prGMTitle)
	{
		prGMTitle = CGraphicTextInstance::New();
		prGMTitle->SetTextPointer(ms_pFont);
		prGMTitle->SetOutline(true);

		if (LocaleService_IsEUROPE())
			prGMTitle->SetHorizonalAlign(CGraphicTextInstance::HORIZONTAL_ALIGN_CENTER);
		else
			prGMTitle->SetHorizonalAlign(CGraphicTextInstance::HORIZONTAL_ALIGN_CENTER);
		prGMTitle->SetVerticalAlign(CGraphicTextInstance::VERTICAL_ALIGN_BOTTOM);
	}

	prGMTitle->SetValue(c_szGMTitle);
	prGMTitle->SetColor(255.0f, 0.0f, 0.0f);
	prGMTitle->Update();
}

void CPythonTextTail::DetachGMTitle(DWORD dwVID)
{
	if (!bPKTitleEnable)
		return;

	TTextTailMap::iterator itor = m_CharacterTextTailMap.find(dwVID);
	if (m_CharacterTextTailMap.end() == itor)
		return;

	TTextTail * pTextTail = itor->second;

	if (pTextTail->pGMTitleTextInstance)
	{
		CGraphicTextInstance::Delete(pTextTail->pGMTitleTextInstance);
		pTextTail->pGMTitleTextInstance = NULL;
	}
}
#endif
