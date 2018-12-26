[...]

void CInstanceBase::UpdateTextTailLevel(DWORD level)
{
	[...]

#ifdef ENABLE_GAMEMASTER_PREFIX
	if (IsGameMaster())
		CPythonTextTail::instance().AttachGMTitle(GetVirtualID(), "|cFFff0000|H|h[GM]|h|r");
#endif

}

[...]