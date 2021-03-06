#include "VISUAL_SEARCH.h"

#define MAX_LOADSTRING 100

void dfs(HWND hwnd, int x, int y);

static const int MAP_WALKED = 1024;
static const int MAP_HEIGHT = 30;
static const int MAP_WIDTH = 30;
static const int MAP_START_FLAG = 1;
static const int MAP_END_FLAG = -1;


volatile bool paintable = 1;

int map[MAP_HEIGHT][MAP_WIDTH]={0};

int startX = 0;
int startY = 0;
int endX = 29; 
int endY =29;


HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];      
HDC hdc;


ATOM                MyRegisterClass(HINSTANCE hInstance);
bool                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow){
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_VISUALSEARCH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    if (!InitInstance (hInstance, nCmdShow)){
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VISUALSEARCH));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VISUALSEARCH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_VISUALSEARCH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

bool InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW^WS_THICKFRAME,
      0, 0, 930, 1000, nullptr, nullptr, hInstance, nullptr);
   if (!hWnd){
      return false;
   }
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message){
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId){
        case ID_WORK: {
            dfs(hwnd, startX, startY);
        }
        break;
        case IDM_START: 
        {
            int x = startX*MAP_WIDTH;
            int y = startY*MAP_HEIGHT;
            map[startX][startY] = MAP_START_FLAG;
            HDC hdc = GetDC(hwnd);
            HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 225));
            RECT rect;
            SetRect(&rect, x, y, x + 30, y + 30);
            FillRect(hdc, &rect, hBrush);
        }
        break;
        case IDM_END:
        {
            int x = endX*MAP_WIDTH;
            int y = endY*MAP_HEIGHT;
            map[endX][endY] = MAP_END_FLAG;
            HDC hdc = GetDC(hwnd);
            HBRUSH hBrush = CreateSolidBrush(RGB(0,139,0));
            RECT rect;
            SetRect(&rect, x, y, x + 30, y + 30);
            FillRect(hdc, &rect, hBrush);
        }
        break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hwnd);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:{
        PAINTSTRUCT ps;
        HPEN borderPen = NULL;
        HDC hdc = BeginPaint(hwnd, &ps);
        for (int i = 0; i <= 30; i++){
            if (i == 30) {
                borderPen = CreatePen(PS_SOLID, 6, RGB(163, 212, 137));
                SelectObject(hdc, borderPen);
            }
            MoveToEx(hdc, i*30, 0, NULL);
            LineTo(hdc, i*30 , 900);
            MoveToEx(hdc, 0, i * 30, NULL);
            LineTo(hdc, 900, i*30);
        }
        DeleteObject(borderPen);
        EndPaint(hwnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void dfs(HWND hwnd,int x,int y) {
    if (map[x][y] == MAP_END_FLAG) {
        paintable = false;
        return;
    }

    if (paintable) {
        int nx = x*MAP_WIDTH;
        int ny = y*MAP_HEIGHT;
        HDC hdc = GetDC(hwnd);
        HBRUSH hBrush = CreateSolidBrush(RGB(238, 0, 0));
        RECT rect;
        SetRect(&rect, nx, ny, nx + 30, ny + 30);
        FillRect(hdc, &rect, hBrush);
    }

    Sleep(15);
    int randPos = rand() % (4 - 1 + 1) + 1;

    switch (randPos){
    case 1: {
        if ((x + 1) < MAP_WIDTH && map[x + 1][y] != MAP_WALKED) {

            map[x + 1][y] = MAP_WALKED;
            dfs(hwnd, x + 1, y);
        }
        if ((x - 1) >= 0 && map[x - 1][y] != MAP_WALKED) {
            map[x - 1][y] = MAP_WALKED;
            dfs(hwnd, x - 1, y);
        }
        if ((y + 1) < MAP_HEIGHT && map[x][y + 1] != MAP_WALKED) {
            map[x][y + 1] = MAP_WALKED;
            dfs(hwnd, x, y + 1);
        }
        if ((y - 1) >= 0 && map[x][y - 1] != MAP_WALKED) {
            map[x][y - 1] = MAP_WALKED;
            dfs(hwnd, x, y - 1);
        }
    }break;

    case 2: {
        if ((x + 1) < MAP_WIDTH && map[x + 1][y] != MAP_WALKED) {
            map[x + 1][y] = MAP_WALKED;
            dfs(hwnd, x + 1, y);
        }
        if ((y + 1) < MAP_HEIGHT && map[x][y + 1] != MAP_WALKED) {
            map[x][y + 1] = MAP_WALKED;
            dfs(hwnd, x, y + 1);
        }
        if ((x - 1) >= 0 && map[x - 1][y] != MAP_WALKED) {
            map[x - 1][y] = MAP_WALKED;
            dfs(hwnd, x - 1, y);
        }
        if ((y - 1) >= 0 && map[x][y - 1] != MAP_WALKED) {
            map[x][y - 1] = MAP_WALKED;
            dfs(hwnd, x, y - 1);
        }
    }break;

    case 3:{
        if ((y + 1) < MAP_HEIGHT && map[x][y + 1] != MAP_WALKED) {
            map[x][y + 1] = MAP_WALKED;
            dfs(hwnd, x, y + 1);
        }
        if ((x - 1) >= 0 && map[x - 1][y] != MAP_WALKED) {
            map[x - 1][y] = MAP_WALKED;
            dfs(hwnd, x - 1, y);
        }
        if ((x + 1) < MAP_WIDTH && map[x + 1][y] != MAP_WALKED) {
            map[x + 1][y] = MAP_WALKED;
            dfs(hwnd, x + 1, y);
        }
        if ((y - 1) >= 0 && map[x][y - 1] != MAP_WALKED) {
            map[x][y - 1] = MAP_WALKED;
            dfs(hwnd, x, y - 1);
        }
    }break;
    case 4: {
        if ((y + 1) < MAP_HEIGHT && map[x][y + 1] != MAP_WALKED) {
            map[x][y + 1] = MAP_WALKED;
            dfs(hwnd, x, y + 1);
        }
        if ((y - 1) >= 0 && map[x][y - 1] != MAP_WALKED) {
            map[x][y - 1] = MAP_WALKED;
            dfs(hwnd, x, y - 1);
        }
        if ((x + 1) < MAP_WIDTH && map[x + 1][y] != MAP_WALKED) {
            map[x + 1][y] = MAP_WALKED;
            dfs(hwnd, x + 1, y);
        }
        if ((x - 1) >= 0 && map[x - 1][y] != MAP_WALKED) {
            map[x - 1][y] = MAP_WALKED;
            dfs(hwnd, x - 1, y);
        }
    }break;
    default:
        break;
    }
}