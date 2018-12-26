[...]

class CPythonTextTail : public CSingleton<CPythonTextTail>
{
	public:
		typedef struct STextTail
		{
			[...]
			CGraphicTextInstance*			pGuildNameTextInstance;
#ifdef ENABLE_GAMEMASTER_PREFIX
			CGraphicTextInstance*			pGMTitleTextInstance;
#endif

			[...]
		} TTextTail;

		[...]

	public:
	
		[...]
		
#ifdef ENABLE_GAMEMASTER_PREFIX
		void AttachGMTitle(DWORD dwVID, const char * c_szRank);
		void DetachGMTitle(DWORD dwVID);
#endif

		[...]
};
