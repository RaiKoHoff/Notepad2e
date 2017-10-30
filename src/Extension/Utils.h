#pragma once
#include <stddef.h>
#include <wtypes.h>

typedef enum
{
  CSS_SASSY = 1 << 0,
  CSS_LESS = 1 << 1,
  CSS_HSS = 1 << 2,
} ECSSSetting;

typedef enum
{
  SSM_NO = 0x0,
  SSM_ALL = 0x1,
  SSM_RECENT = 0x2
} ESaveSettingsMode;

typedef enum
{
  ELI_HIDE = 0,
  ELI_SHOW,
  ELI_SHOW_NON_US
} ELanguageIndicatorMode;

typedef enum
{
  EEM_DISABLED = 0,
  EEM_LINE,
  EEM_SELECTION
} EExpressionEvaluationMode;

typedef enum
{
  WNM_STANDARD = 0,
  WNM_ACCELERATED,
} EWordNavigationMode;

typedef enum
{
  SCP_LEGACY,
  SCP_THIRD,
  SCP_HALF
} EScrollYCaretPolicy;

#define N2E_INI_SECTION L"Notepad2e"
#define INI_SETTING_HIGHLIGHT_LINE_IF_WINDOW_INACTIVE L"HighlightLineIfWindowInactive"
#define INI_SETTING_SCROLL_Y_CARET_POLICY L"ScrollYCaretPolicy"
#define INI_SETTING_FIND_WORD_MATCH_CASE  L"FindWordMatchCase"
#define INI_SETTING_FIND_WRAP_AROUND  L"FindWordWrapAround"
#define INI_SETTING_MOVE_CARET_ON_RIGHT_CLICK L"MoveCaretOnRightClick"
#define INI_SETTING_MATH_EVAL L"MathEval"
#define INI_SETTING_LANGUAGE_INDICATOR L"TitleLanguage"
#define INI_SETTING_WORD_NAVIGATION_MODE  L"WordNavigationMode"

#define WM_N2E_RELOAD_SETTINGS	(WM_USER + 0xFF)
#define	N2E_MAX_PATH_N_CMD_LINE	MAX_PATH + 40

extern ECSSSetting	iCSSSettings;
extern ELanguageIndicatorMode iShowLanguageInTitle;

void n2e_InitInstance();
void n2e_ExitInstance();

void* n2e_Alloc(size_t size);
void n2e_Free(void* ptr);
void* n2e_Realloc(void* ptr, size_t len);
void n2e_Init();
LPCWSTR n2e_GetLastRun(LPCWSTR lpstrDefault);
void n2e_SetLastRun(LPCWSTR arg);
void n2e_ResetLastRun();
void n2e_LoadINI();
void n2e_SaveINI();
void n2e_Release();
void n2e_Reload_Settings();
BOOL n2e_CanSaveINISection(const BOOL bCheckSaveSettingsMode, const ESaveSettingsMode modeRequired);
BOOL n2e_IsTextEmpty(LPCWSTR txt);
BOOL n2e_OpenMRULast(LPWSTR fn);
void n2e_GetLastDir(LPTSTR out);
UINT_PTR CALLBACK n2e_OFNHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam);
BOOL n2e_GetGotoNumber(LPTSTR temp, int *out, const BOOL hex);
void n2e_InplaceRev(WCHAR * s);
int n2e_CompareFiles(LPCWSTR sz1, LPCWSTR sz2);
BOOL n2e_OpenFileByPrefix(LPCWSTR pref, LPWSTR dir, LPWSTR out);
void n2e_Grep(void* lpf, const BOOL grep);
void n2e_SetWheelScroll(const BOOL enable);
BOOL n2e_IsWordChar(const WCHAR ch);
BOOL n2e_IsSpace(const WCHAR ch);
BOOL n2e_IsKeyDown(const int key);

#define N2E_IS_LITERAL(CH) n2e_IsWordChar(CH)

BOOL n2e_SetClipboardText(const HWND hwnd, const wchar_t* text);
void n2e_UpdateWindowTitle(const HWND hwnd);
int n2e_GetCurrentShowTitleMenuID();
int n2e_GetCurrentLanguageIndicatorMenuID();

extern int iScrollYCaretPolicy;
extern HWND hwndStatus;
extern HWND hwndStatusProgressBar;
extern BOOL bShowProgressBar;

void n2e_CreateProgressBarInStatusBar();
void n2e_DestroyProgressBarInStatusBar();
void n2e_ShowProgressBarInStatusBar(LPCWSTR pProgressText, const long nCurPos, const long nMaxPos);
void n2e_HideProgressBarInStatusBar();
void n2e_UpdateProgressBarInStatusBar(const long nCurPos);
void n2e_AdjustProgressBarInStatusBar(const long nCurPos, const long nMaxPos);
