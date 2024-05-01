#include <windows.h>
#include <commctrl.h>

// Function prototype for the Dialog Procedure
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Entry point of the application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Initialize common controls. Required for some Windows elements.
    INITCOMMONCONTROLSEX icc;
    icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icc.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&icc);

    // Create and display the dialog box
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_MYDIALOG), NULL, DialogProc);
    return 0;
}

// Dialog Procedure to handle events
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_INITDIALOG:
            // Set dialog title
            SetWindowText(hwndDlg, "WARNING");

            // Load and display the PNG image in the dialog
            // Ensure your project includes the necessary PNG file
            HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, "path_to_image.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            SendDlgItemMessage(hwndDlg, IDC_STATIC_IMG, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
            return (INT_PTR)TRUE;

        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case IDOK:
                case IDCANCEL:
                    EndDialog(hwndDlg, LOWORD(wParam));
                    return (INT_PTR)TRUE;
            }
            break;

        case WM_CLOSE:
            EndDialog(hwndDlg, 0);
            return (INT_PTR)TRUE;
    }
    return (INT_PTR)FALSE;
}
