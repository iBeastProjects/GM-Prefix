[...]

int CInputMain::Chat(LPCHARACTER ch, const char * data, size_t uiBytes)
{
	[...]

	char chatbuf[CHAT_MAX_LEN + 1];
#if (defined ENABLE_GAMEMASTER_PREFIX && defined ENABLE_GAMEMASTER_PREFIX_IN_CHAT)
	char cGMTitle[256];
	sprintf(cGMTitle, "|cFFff0000|H|h[GM]|h|r");
	int len = snprintf(chatbuf, sizeof(chatbuf), "%s %s : %s", ch->IsGM()?cGMTitle:"",ch->GetName(), buf);
#else
	int len = snprintf(chatbuf, sizeof(chatbuf), "%s : %s", ch->GetName(), buf);
#endif

	[...]
}

[...]